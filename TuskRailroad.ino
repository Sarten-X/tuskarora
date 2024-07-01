// If nonzero, DEBUG enables the use of a serial console for state observation.

// DEBUG_NONE is for normal operations
#define DEBUG_NONE 0
// DEBUG_TRACE monitors major program flow
#define DEBUG_TRACE 1
// DEBUG_STEP adds delays that will prevent audio playback from working properly
#define DEBUG_STEP 2
// DEBUG_VERBOSE sends verbose status messages to the serial console
#define DEBUG_VERBOSE 3

// Set the debug level here
#define DEBUG DEBUG_NONE


// Standard libraries
#include <stdint.h>
#include <Wire.h>
#include <Arduino.h>

// XT DAC audio library
#include "MusicDefinitions.h"
#include "SoundData.h"
#include "XT_DAC_Audio.h"

// Railroad.h contains all of the connection information for the railroad layout
#include "Railroad.h"

// Audio player objects
XT_DAC_Audio_Class DacAudio(25,0);                                              // The main player class object. Use GPIO 25, one of the 2 DAC pins and timer 0
XT_Wav_Class LeverSound(LeverSoundData);                                        // create WAV objects and pass in the WAV data from SoundData.h
XT_Wav_Class EightSound(EightSoundData);
XT_Wav_Class ElevenSound(ElevenSoundData);
XT_Wav_Class FaultSound(FaultSoundData);
XT_Wav_Class FifSound(FifSoundData);
XT_Wav_Class FiveSound(FiveSoundData);
XT_Wav_Class FourSound(FourSoundData);
XT_Wav_Class NineSound(NineSoundData);
XT_Wav_Class OneSound(OneSoundData);
XT_Wav_Class SevenSound(SevenSoundData);
XT_Wav_Class SixSound(SixSoundData);
XT_Wav_Class TeenSound(TeenSoundData);
XT_Wav_Class TenSound(TenSoundData);
XT_Wav_Class ThirSound(ThirSoundData);
XT_Wav_Class ThreeSound(ThreeSoundData);
XT_Wav_Class TwelveSound(TwelveSoundData);
XT_Wav_Class TwentySound(TwentySoundData);
XT_Wav_Class TwoSound(TwoSoundData);
//XT_MusicScore_Class faultSound(TwinkleTwinkle,TEMPO_ALLEGRO,INSTRUMENT_PIANO);  // The music score objct, pass in the music data from above
XT_Sequence_Class faultSoundSequence;                                           // A sequence object for playing multiple sounds

// MultiMCP23017 is a facade to control I/O to 8 MCP23017 chips
MultiMCP23017 io = MultiMCP23017();

// Levers is a 24-bit field, with methods to support easy access to those bits
// This instance is a buffer to hold the known state of levers, without needing
// I/O for each lookup
Levers levers = Levers();

// Old lever state, used for comparison and fault checking
Levers oldLevers = Levers();

// The Signals class handles state management and I/O for signals, including the
// panel display.
Signals signals = Signals();

// The Railroad class contains all of the "business logic" for the layout.
Railroad railroad = Railroad();

// Limit the fault sound to a single initialization cycle
bool faultSoundInitialized = false;

// This constant limits some of the operational checks for inputs. For normal
// operation, it should be set to 24.
#define MAX_LEVERS 24 // Reduce lever checks for debugging

// Initialization routine
void setup() {
  // Delay to allow peripheral boards to start up
  delay(4000);
  
  // Initialize serial console for debugging
  if (DEBUG) {
    Serial.begin(115200);
    Serial.println("Tusk Railroad is initialized.");
  }
  
  // Initialize IO expander interface
  Wire.begin();
  io.init();
  
  // Initialize railroad objects
  signals.init(io);
  railroad.init(signals);
  levers.init();
  
  // Initialize input ports and buffers
  io.setPortMode(LEVER_CHIP_1, LEVER_PORT_1, 0b11111111);   // A "1" bit sets the given pin to an input
  io.setPortMode(LEVER_CHIP_2, LEVER_PORT_2, 0b11111111);
  io.setPortMode(LEVER_CHIP_3, LEVER_PORT_3, 0b11111111);
  // Read initial lever states
  uint8_t newLeverState1 = io.digitalRead(LEVER_CHIP_1, LEVER_PORT_1);
  uint8_t newLeverState2 = io.digitalRead(LEVER_CHIP_2, LEVER_PORT_2);
  uint8_t newLeverState3 = io.digitalRead(LEVER_CHIP_3, LEVER_PORT_3);
  // Construct a 24-bit field from the observed states
  uint32_t newLeverState = (newLeverState1) | (newLeverState2 << 8) | (newLeverState3 << 16);
  // Set the lever state buffer to match the hardware state
  levers.setLevers(newLeverState);
  
  // Initialize output pins
  pinMode(LED_BUILTIN, OUTPUT);  // The builtin LED will light with faults

  // Initialize sound playback
  DacAudio.StopAllSounds();

  // Change operational state to "setup" mode.
  railroad.mainMode = MODE_SETUP;

  if (DEBUG >= DEBUG_TRACE) {
    Serial.println("System is In MODE_SETUP ");
  }
}

void loop() {
  // Allow the audio player to fill its buffer with sound samples.
  DacAudio.FillBuffer();

  // Display the registers of the lever I/O expanders
  if (DEBUG >= DEBUG_VERBOSE) {
    Serial.println("Input chip 1 state:");
    io.dump(LEVER_CHIP_1);
    Serial.println("Input chip 2 state:");
    io.dump(LEVER_CHIP_2);
    Serial.println("Input chip 3 state:");
    io.dump(LEVER_CHIP_3);
  }
  
  // Read current lever state
  uint8_t newLeverState1 = io.digitalRead(LEVER_CHIP_1, LEVER_PORT_1);
  uint8_t newLeverState2 = io.digitalRead(LEVER_CHIP_2, LEVER_PORT_2);
  uint8_t newLeverState3 = io.digitalRead(LEVER_CHIP_3, LEVER_PORT_3);
  uint32_t newLeverState = (newLeverState1) | (newLeverState2 << 8) | (newLeverState3 << 16);
  if (DEBUG >= DEBUG_VERBOSE) {
    Serial.print("New state is ");
    Serial.println(newLeverState, BIN);
  }

  if (railroad.mainMode == MODE_SETUP) {
    // Setup mode. Raise a fault for every lever that's pulled back.
    faultSoundInitialized = false;  // Reset the state of fault sound initialization (necessary for runtime state resets)
    railroad.faults.setLevers(newLeverState);
    // Try to get to operate mode
    railroad.mainMode = MODE_OPERATE;
    // Check each lever. If any are pulled back, stay in setup mode

    for (int leverNum = 0; leverNum < MAX_LEVERS; leverNum++) {
      if ((newLeverState >> leverNum) & 0b1 == LEVER_BACK) {
        if (DEBUG >= DEBUG_TRACE) {
          Serial.print("Lever still back - lever array position: ");
          Serial.println(leverNum);
        }
        railroad.mainMode = MODE_SETUP;
      }
    }
    
    // Update the lever buffer with the current lever state
    levers.setLevers(newLeverState);

    if (railroad.mainMode == MODE_OPERATE) {  // All the levers are forward for the first time
      if (DEBUG >= DEBUG_TRACE) {
        Serial.println("System is going to MODE_OPERATE");
      }
      
      signals.setSignalState(SIGNAL_STATUS, SignalState::Red);  // set status indicator to red
      
    // turn all signals to green for 2 seconds then to yellow then to what is required by lever position which is red
     for (int i = 0; i < MAX_SIGNALS-1; i++) {
       signals.setSignalState(i, SignalState::Green);
       delay(250);
     }
      delay(1000);  
     for (int i = 0; i < MAX_SIGNALS-1; i++) {
      signals.setSignalState(i, SignalState::Yellow);
      delay(250);
     }
      delay(1000);  
      
      // Update all signal aspects to match the lever state
      for (int i = 0; i < MAX_SIGNALS-1; i++) {
        railroad.updateSignal(i, levers, signals);
        delay(250);
      }
      delay(1000); 
      
      // Set all turnouts to initial position
      railroad.resetTurnouts(io);

      // Set the status indicator to show normal operation
      signals.setSignalState(SIGNAL_STATUS, SignalState::Green);

      // Clear the audio buffer
      DacAudio.StopAllSounds();

      if (DEBUG >= DEBUG_TRACE) {
        Serial.println("System is ready to OPERATE");
      }
    }
    
  } else if (railroad.mainMode == MODE_OPERATE || railroad.mainMode == MODE_OVERRIDE) {
    // Operate or override modes
    // Retrieve old lever state to compare & find changes
    oldLevers.setLevers(levers.getLevers());
    if (DEBUG >= DEBUG_VERBOSE) {
      Serial.print("Old state is ");
      Serial.println(oldLevers.getLevers(), BIN);
    }
    
    // Update the lever buffer
    levers.setLevers(newLeverState);
    
    // Check if levers have changed
    if (oldLevers.getLevers() != newLeverState) {
      
      // Play lever sound, with mixing option
      if (railroad.enableSound) {
        DacAudio.Play(&LeverSound, true);
      }
      
      // Identify changed levers
      for (int leverNum = 0; leverNum < MAX_LEVERS; leverNum++) {

        // Compare each lever's current state to the last-seen value
        bool currentState = (newLeverState >> leverNum) & 0b1;
        bool oldState = (oldLevers.getLevers() >> leverNum) & 0b1;

        // If values differ, the lever has been toggled
        if (currentState != oldState) {
          
          if (DEBUG >= DEBUG_TRACE) {
            Serial.print("Change on lever array position # ");
            Serial.println(leverNum); 
            if (DEBUG >= DEBUG_STEP) {
              delay(5000);
            }
          }
          
          // If the lever was faulted (and not overridden), just clear it.
          if (railroad.faults.getLever(leverNum) && railroad.mainMode == MODE_OPERATE) {
            railroad.faults.setLever(leverNum, false);
          }
          else {  // If the lever wasn't faulted
          
            // Check for current fault conditions
            bool fault = false;
            if (railroad.checkFaults(leverNum, oldLevers, signals)) {
              // Record the fault in the fault object
              railroad.faults.setLever(leverNum, true);
              fault = true;
            }
  
            // If no fault was found, or if faults are being overridden
            // then actions will be run
            if (!fault || railroad.mainMode == MODE_OVERRIDE) {
              // Take action for changed levers based on their current state
              if (currentState == LEVER_BACK) {
                railroad.leverBack(leverNum, levers, signals, io);
              } else {
                railroad.leverForward(leverNum, levers, signals, io);
              }
            }
          } // End non-faulted lever change
          
        } // End single-lever change detected
      } // End loop through levers
    } // End large change detected
  } // End operation mode

  // Play alarm for any faulted levers
  // Alarms are not active in override mode.
  if (railroad.mainMode != MODE_OVERRIDE) {
    
    // If a fault alarm is not playing, try to construct
    // an appropriate sequence of sounds

  
    if (faultSoundSequence.Playing==false) {
      if (faultSoundInitialized == false) {
        
        // Start higher than the observed lever count
        uint8_t faultNum = MAX_LEVERS;
  
        // Check each pin in the fault bitfield to find the lowest-numbered
        // faulting pin
        for (int leverNum = MAX_LEVERS - 1; leverNum >= 0; leverNum--) {
          if ((railroad.faults.getLevers()) & (0b1 << leverNum)) {
            faultNum = leverNum;
            if (DEBUG >= DEBUG_TRACE) {
              Serial.print("Lever faulted - array position ");
              Serial.println(faultNum);
            }
          }
        }
  
        // If no faults were found, the faultNum will remain at the high value
        if (faultNum < MAX_LEVERS) {
          // Must have found a fault, so build a sound sequence
          DacAudio.RemoveFromPlayList(&faultSoundSequence);
          faultSoundSequence.RemoveAllPlayItems();
          faultSoundSequence.AddPlayItem(&FaultSound);
          
          // Build a fault alert based on the lowest-numbered faulted lever
          switch (faultNum) {
            case LEVER_L1: faultSoundSequence.AddPlayItem(&OneSound); break;
            case LEVER_L2: faultSoundSequence.AddPlayItem(&TwoSound); break;
            case LEVER_L3: faultSoundSequence.AddPlayItem(&ThreeSound); break;
            case LEVER_L4: faultSoundSequence.AddPlayItem(&FourSound); break;
            case LEVER_L5: faultSoundSequence.AddPlayItem(&FiveSound); break;
            case LEVER_L6: faultSoundSequence.AddPlayItem(&SixSound); break;
            case LEVER_L7: faultSoundSequence.AddPlayItem(&SevenSound); break;
            case LEVER_L8: faultSoundSequence.AddPlayItem(&EightSound); break;
            case LEVER_L9: faultSoundSequence.AddPlayItem(&NineSound); break;
            case LEVER_L10: faultSoundSequence.AddPlayItem(&TenSound); break;
            case LEVER_L11: faultSoundSequence.AddPlayItem(&ElevenSound); break;
            case LEVER_L12: faultSoundSequence.AddPlayItem(&TwelveSound); break;
            case LEVER_L13: faultSoundSequence.AddPlayItem(&ThirSound); faultSoundSequence.AddPlayItem(&TeenSound); break;
            case LEVER_L14: faultSoundSequence.AddPlayItem(&FourSound); faultSoundSequence.AddPlayItem(&TeenSound); break;
            case LEVER_L15: faultSoundSequence.AddPlayItem(&FifSound); faultSoundSequence.AddPlayItem(&TeenSound); break;
            case LEVER_L16: faultSoundSequence.AddPlayItem(&SixSound); faultSoundSequence.AddPlayItem(&TeenSound); break;
            case LEVER_L17: faultSoundSequence.AddPlayItem(&SevenSound); faultSoundSequence.AddPlayItem(&TeenSound); break;
            case LEVER_L18: faultSoundSequence.AddPlayItem(&EightSound); faultSoundSequence.AddPlayItem(&TeenSound); break;
            case LEVER_L19: faultSoundSequence.AddPlayItem(&NineSound); faultSoundSequence.AddPlayItem(&TeenSound); break;
            case LEVER_L20: faultSoundSequence.AddPlayItem(&TwentySound); break;
            case LEVER_L21: faultSoundSequence.AddPlayItem(&TwentySound); faultSoundSequence.AddPlayItem(&OneSound); break;
            case LEVER_L22: faultSoundSequence.AddPlayItem(&TwentySound); faultSoundSequence.AddPlayItem(&TwoSound); break;
            case LEVER_L23: faultSoundSequence.AddPlayItem(&TwentySound); faultSoundSequence.AddPlayItem(&ThreeSound); break;
            case LEVER_L24: faultSoundSequence.AddPlayItem(&TwentySound); faultSoundSequence.AddPlayItem(&FourSound); break;
            default: break;
          }
          
          // Play the assembled fault sound sequence
          DacAudio.Play(&faultSoundSequence, true);
          faultSoundInitialized = true;
          DacAudio.FillBuffer();
          
          // Toggle the builtin LED & indicator signal
          digitalWrite(LED_BUILTIN, LOW);
          signals.setSignalState(SIGNAL_STATUS, SignalState::Red);
        } else {
          // No new fault was found.
          // Turn on the LED.
          digitalWrite(LED_BUILTIN, HIGH);
          if (signals.getSignalState(SIGNAL_STATUS) != SignalState::Green) {
            signals.setSignalState(SIGNAL_STATUS, SignalState::Green);
          }
  
        }
      } // End fault sound was already initialized
    } else { // End fault sound isn't playing
      // fault sound is playing. Allow reinitializing.
      faultSoundInitialized = false;
    }
  } // End operate mode

  // Delay for the main loop.
  // This should be a long enough delay to allow levers to debounce, but not so
  // long as to interfere with audio playback.
  delay(25);
  
  if (DEBUG >= DEBUG_STEP) {
    delay(2000);
  }
}
