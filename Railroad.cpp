// Logic code for all railroad-specific functions
#include "Railroad.h"

// Initialize the railroad
void Railroad::init(Signals signals) {
  Serial.println("Initializing railroad configuration...");
  // The initialization must include making all of the signal connections.
  // Signal states are managed by the Signals object, provided here for use.

  // Signals are referenced in the code by an ID, here using convenient
  // preprocessor declarations (SIGNAL_SAMPLE). This should be a number between 0
  // and MAX_SIGNALS that is used to identify the signal itself. To change a
  // signal in this design, the dialogue with the Signals class is, for example,
  // "change SIGNAL_SAMPLE to red", and the Signals class will handle controlling
  // the individual requests to the required I/O chips to turn off unneeded LEDs,
  // for both the model element and the operator display panels.

  // Signal connection definitions are required for both the layout signal and the
  // display panels. For signals with missing lights (like the yellow light on a
  // red/green signal), the special flag value NO_CONNECTION should be used, 
  // either listed here or in definitions in Railroad.h.
  
  // Repeat this for each signal definition
//  signals.registerSignal(
//    SIGNAL_SAMPLE,  // Define the signal ID.
//    SIGNAL_SAMPLE_RED_CHIP, SIGNAL_SAMPLE_RED_PIN,  // Chip & pin for the red line to the actual signal.
//    SIGNAL_SAMPLE_YELLOW_CHIP, SIGNAL_SAMPLE_YELLOW_PIN,
//    SIGNAL_SAMPLE_GREEN_CHIP, SIGNAL_SAMPLE_GREEN_PIN,
//    PANEL_SAMPLE_RED_CHIP, PANEL_SAMPLE_RED_PIN,
//    PANEL_SAMPLE_YELLOW_CHIP, PANEL_SAMPLE_YELLOW_PIN,
//    PANEL_SAMPLE_GREEN_CHIP, PANEL_SAMPLE_GREEN_PIN
//  );
  signals.registerSignal(
    SIGNAL_S2,  // Define the signal ID.
    SIGNAL_S2_RED_CHIP, SIGNAL_S2_RED_PIN,  // Chip & pin for the red line to the actual signal.
    SIGNAL_S2_YELLOW_CHIP, SIGNAL_S2_YELLOW_PIN,
    SIGNAL_S2_GREEN_CHIP, SIGNAL_S2_GREEN_PIN,
    PANEL_S2_RED_CHIP, PANEL_S2_RED_PIN,
    PANEL_S2_YELLOW_CHIP, PANEL_S2_YELLOW_PIN,
    PANEL_S2_GREEN_CHIP, PANEL_S2_GREEN_PIN
  );
  signals.registerSignal(
    SIGNAL_S3,  // Define the signal ID.
    SIGNAL_S3_RED_CHIP, SIGNAL_S3_RED_PIN,  // Chip & pin for the red line to the actual signal.
    SIGNAL_S3_YELLOW_CHIP, SIGNAL_S3_YELLOW_PIN,
    SIGNAL_S3_GREEN_CHIP, SIGNAL_S3_GREEN_PIN,
    PANEL_S3_RED_CHIP, PANEL_S3_RED_PIN,
    PANEL_S3_YELLOW_CHIP, PANEL_S3_YELLOW_PIN,
    PANEL_S3_GREEN_CHIP, PANEL_S3_GREEN_PIN
  );
  signals.registerSignal(    
    SIGNAL_S4,  // Define the signal ID.
    SIGNAL_S4_RED_CHIP, SIGNAL_S4_RED_PIN,  // Chip & pin for the red line to the actual signal.
    SIGNAL_S4_YELLOW_CHIP, SIGNAL_S4_YELLOW_PIN,
    SIGNAL_S4_GREEN_CHIP, SIGNAL_S4_GREEN_PIN,
    PANEL_S4_RED_CHIP, PANEL_S4_RED_PIN,
    PANEL_S4_YELLOW_CHIP, PANEL_S4_YELLOW_PIN,
    PANEL_S4_GREEN_CHIP, PANEL_S4_GREEN_PIN
  );
  signals.registerSignal(    
    SIGNAL_S7,  // Define the signal ID.
    SIGNAL_S7_RED_CHIP, SIGNAL_S7_RED_PIN,  // Chip & pin for the red line to the actual signal.
    SIGNAL_S7_YELLOW_CHIP, SIGNAL_S7_YELLOW_PIN,
    SIGNAL_S7_GREEN_CHIP, SIGNAL_S7_GREEN_PIN,
    PANEL_S7_RED_CHIP, PANEL_S7_RED_PIN,
    PANEL_S7_YELLOW_CHIP, PANEL_S7_YELLOW_PIN,
    PANEL_S7_GREEN_CHIP, PANEL_S7_GREEN_PIN
  );
  signals.registerSignal(    
    SIGNAL_S8,  // Define the signal ID.
    SIGNAL_S8_RED_CHIP, SIGNAL_S8_RED_PIN,  // Chip & pin for the red line to the actual signal.
    SIGNAL_S8_YELLOW_CHIP, SIGNAL_S8_YELLOW_PIN,
    SIGNAL_S8_GREEN_CHIP, SIGNAL_S8_GREEN_PIN,
    PANEL_S8_RED_CHIP, PANEL_S8_RED_PIN,
    PANEL_S8_YELLOW_CHIP, PANEL_S8_YELLOW_PIN,
    PANEL_S8_GREEN_CHIP, PANEL_S8_GREEN_PIN
  );
  signals.registerSignal(    
    SIGNAL_S10,  // Define the signal ID.
    SIGNAL_S10_RED_CHIP, SIGNAL_S10_RED_PIN,  // Chip & pin for the red line to the actual signal.
    SIGNAL_S10_YELLOW_CHIP, SIGNAL_S10_YELLOW_PIN,
    SIGNAL_S10_GREEN_CHIP, SIGNAL_S10_GREEN_PIN,
    PANEL_S10_RED_CHIP, PANEL_S10_RED_PIN,
    PANEL_S10_YELLOW_CHIP, PANEL_S10_YELLOW_PIN,
    PANEL_S10_GREEN_CHIP, PANEL_S10_GREEN_PIN
  );
  signals.registerSignal(
    SIGNAL_S11,  // Define the signal ID.
    SIGNAL_S11_RED_CHIP, SIGNAL_S11_RED_PIN,  // Chip & pin for the red line to the actual signal.
    SIGNAL_S11_YELLOW_CHIP, SIGNAL_S11_YELLOW_PIN,
    SIGNAL_S11_GREEN_CHIP, SIGNAL_S11_GREEN_PIN,
    PANEL_S11_RED_CHIP, PANEL_S11_RED_PIN,
    PANEL_S11_YELLOW_CHIP, PANEL_S11_YELLOW_PIN,
    PANEL_S11_GREEN_CHIP, PANEL_S11_GREEN_PIN
  );
  signals.registerSignal(
    SIGNAL_S13,  // Define the signal ID.
    SIGNAL_S13_RED_CHIP, SIGNAL_S13_RED_PIN,  // Chip & pin for the red line to the actual signal.
    SIGNAL_S13_YELLOW_CHIP, SIGNAL_S13_YELLOW_PIN,
    SIGNAL_S13_GREEN_CHIP, SIGNAL_S13_GREEN_PIN,
    PANEL_S13_RED_CHIP, PANEL_S13_RED_PIN,
    PANEL_S13_YELLOW_CHIP, PANEL_S13_YELLOW_PIN,
    PANEL_S13_GREEN_CHIP, PANEL_S13_GREEN_PIN
  );
  signals.registerSignal(
    SIGNAL_S14,  // Define the signal ID.
    SIGNAL_S14_RED_CHIP, SIGNAL_S14_RED_PIN,  // Chip & pin for the red line to the actual signal.
    SIGNAL_S14_YELLOW_CHIP, SIGNAL_S14_YELLOW_PIN,
    SIGNAL_S14_GREEN_CHIP, SIGNAL_S14_GREEN_PIN,
    PANEL_S14_RED_CHIP, PANEL_S14_RED_PIN,
    PANEL_S14_YELLOW_CHIP, PANEL_S14_YELLOW_PIN,
    PANEL_S14_GREEN_CHIP, PANEL_S14_GREEN_PIN
  );
  signals.registerSignal(
    SIGNAL_S16,  // Define the signal ID.
    SIGNAL_S16_RED_CHIP, SIGNAL_S16_RED_PIN,  // Chip & pin for the red line to the actual signal.
    SIGNAL_S16_YELLOW_CHIP, SIGNAL_S16_YELLOW_PIN,
    SIGNAL_S16_GREEN_CHIP, SIGNAL_S16_GREEN_PIN,
    PANEL_S16_RED_CHIP, PANEL_S16_RED_PIN,
    PANEL_S16_YELLOW_CHIP, PANEL_S16_YELLOW_PIN,
    PANEL_S16_GREEN_CHIP, PANEL_S16_GREEN_PIN
  );
  signals.registerSignal(
    SIGNAL_S18,  // Define the signal ID.
    SIGNAL_S18_RED_CHIP, SIGNAL_S18_RED_PIN,  // Chip & pin for the red line to the actual signal.
    SIGNAL_S18_YELLOW_CHIP, SIGNAL_S18_YELLOW_PIN,
    SIGNAL_S18_GREEN_CHIP, SIGNAL_S18_GREEN_PIN,
    PANEL_S18_RED_CHIP, PANEL_S18_RED_PIN,
    PANEL_S18_YELLOW_CHIP, PANEL_S18_YELLOW_PIN,
    PANEL_S18_GREEN_CHIP, PANEL_S18_GREEN_PIN
  );
  signals.registerSignal(
    SIGNAL_S22,  // Define the signal ID.
    SIGNAL_S22_RED_CHIP, SIGNAL_S22_RED_PIN,  // Chip & pin for the red line to the actual signal.
    SIGNAL_S22_YELLOW_CHIP, SIGNAL_S22_YELLOW_PIN,
    SIGNAL_S22_GREEN_CHIP, SIGNAL_S22_GREEN_PIN,
    PANEL_S22_RED_CHIP, PANEL_S22_RED_PIN,
    PANEL_S22_YELLOW_CHIP, PANEL_S22_YELLOW_PIN,
    PANEL_S22_GREEN_CHIP, PANEL_S22_GREEN_PIN
  );
  signals.registerSignal(
    SIGNAL_S23,  // Define the signal ID.
    SIGNAL_S23_RED_CHIP, SIGNAL_S23_RED_PIN,  // Chip & pin for the red line to the actual signal.
    SIGNAL_S23_YELLOW_CHIP, SIGNAL_S23_YELLOW_PIN,
    SIGNAL_S23_GREEN_CHIP, SIGNAL_S23_GREEN_PIN,
    PANEL_S23_RED_CHIP, PANEL_S23_RED_PIN,
    PANEL_S23_YELLOW_CHIP, PANEL_S23_YELLOW_PIN,
    PANEL_S23_GREEN_CHIP, PANEL_S23_GREEN_PIN
  );
  signals.registerSignal(
    SIGNAL_STATUS,  // Define the signal ID.
    SIGNAL_STATUS_RED_CHIP, SIGNAL_STATUS_RED_PIN,  // Chip & pin for the red line to the actual signal.
    SIGNAL_STATUS_YELLOW_CHIP, SIGNAL_STATUS_YELLOW_PIN,
    SIGNAL_STATUS_GREEN_CHIP, SIGNAL_STATUS_GREEN_PIN,
    PANEL_STATUS_RED_CHIP, PANEL_STATUS_RED_PIN,
    PANEL_STATUS_YELLOW_CHIP, PANEL_STATUS_YELLOW_PIN,
    PANEL_STATUS_GREEN_CHIP, PANEL_STATUS_GREEN_PIN
  );
  Serial.println("Railroad initialization complete");
}

// Reset turnouts to initial position.
void Railroad::resetTurnouts(MultiMCP23017 io) {
  io.digitalWrite(TURNOUT_T1_CHIP, TURNOUT_T1_PIN, TO_DIVERGE);
  delay(250);
  io.digitalWrite(TURNOUT_T6_CHIP, TURNOUT_T6_PIN, TO_DIVERGE);
  delay(250);
  io.digitalWrite(TURNOUT_T15_CHIP, TURNOUT_T15_PIN, TO_DIVERGE);
  delay(250);
  io.digitalWrite(TURNOUT_T17_CHIP, TURNOUT_T17_PIN, TO_DIVERGE);
  delay(250);
  io.digitalWrite(TURNOUT_T19_CHIP, TURNOUT_T19_PIN, TO_DIVERGE);
  delay(250);
  io.digitalWrite(TURNOUT_T20_CHIP, TURNOUT_T20_PIN, TO_DIVERGE);
  delay(250);
  io.digitalWrite(TURNOUT_T24_CHIP, TURNOUT_T24_PIN, TO_DIVERGE);
  delay(250);
  io.digitalWrite(TURNOUT_T1_CHIP, TURNOUT_T1_PIN, TO_STRAIGHT);
  delay(250);
  io.digitalWrite(TURNOUT_T6_CHIP, TURNOUT_T6_PIN, TO_STRAIGHT);
  delay(250);
  io.digitalWrite(TURNOUT_T15_CHIP, TURNOUT_T15_PIN, TO_STRAIGHT);
  delay(250);
  io.digitalWrite(TURNOUT_T17_CHIP, TURNOUT_T17_PIN, TO_STRAIGHT);
  delay(250);
  io.digitalWrite(TURNOUT_T19_CHIP, TURNOUT_T19_PIN, TO_STRAIGHT);
  delay(250);
  io.digitalWrite(TURNOUT_T20_CHIP, TURNOUT_T20_PIN, TO_STRAIGHT);
  delay(250);
  io.digitalWrite(TURNOUT_T24_CHIP, TURNOUT_T24_PIN, TO_STRAIGHT);
  delay(250);
}

// Interlocking/fault logic
// Return true if action is a fault.
bool Railroad::checkFaults(uint8_t leverNumber, Levers levers, Signals signals) {
  // Objects are provided as parameters to allow accessing the state of other
  // levers and signals.

  // For convenience, note the current state of the switched lever
  // Note that since the lever state is prior to the lever being changed,
  bool leverState = !levers.getLever(leverNumber);

  // For convenience, define some variables to simplify logic

  bool mainSafeE = (levers.getLever(LEVER_L19) == LEVER_BACK) || (levers.getLever(LEVER_L20) == LEVER_BACK) || (levers.getLever(LEVER_L22) == LEVER_FORWARD);
  bool sidingSafeE = (levers.getLever(LEVER_L16) == LEVER_FORWARD) && ((levers.getLever(LEVER_L20) == LEVER_FORWARD) || (levers.getLever(LEVER_L22) == LEVER_FORWARD));

  bool mainSafeW = (levers.getLever(LEVER_L4) == LEVER_FORWARD) || (levers.getLever(LEVER_L6) == LEVER_BACK);
  bool sidingSafeW = ((levers.getLever(LEVER_L6) == LEVER_FORWARD) && (levers.getLever(LEVER_L3) == LEVER_FORWARD)) || ((levers.getLever(LEVER_L6) == LEVER_BACK) && (levers.getLever(LEVER_L4) == LEVER_FORWARD));
  
  // Select the appropriate logic for the changed lever
  switch (leverNumber) {
    // Add the rest of the levers that can fault in this section. Most readable if entered in order by lever
    // the cases above here are/were for testing.
    // Lever faults when changed if other levers are not in correct postion. Info is in IO spreadsheet

    case LEVER_L1:
      if (leverState == LEVER_BACK){
        return false;
      } else{
        return false;
      }
      break;

    case LEVER_L2:
      if (leverState == LEVER_BACK){
        if (levers.getLever(LEVER_L4) == LEVER_BACK){
          return false;
        }
        else {
          return true;
        }
      } else {
        return false;
      }
      break;

    case LEVER_L3:
      if (leverState == LEVER_BACK){
        if ((levers.getLever(LEVER_L6) == LEVER_FORWARD) && (levers.getLever(LEVER_L8) == LEVER_FORWARD) && sidingSafeE){
          return false;
        }
        else {
          return true;
        }
      } else if (leverState == LEVER_FORWARD) {
        return false;
      }
      else {
        return true;
      }
      break;
      
    case LEVER_L4:
      if (leverState == LEVER_BACK){
        if ((levers.getLever(LEVER_L5) == LEVER_BACK) && 
               (((levers.getLever(LEVER_L6) == LEVER_FORWARD) && (levers.getLever(LEVER_L7) == LEVER_FORWARD) && mainSafeE) 
             || ((levers.getLever(LEVER_L6) == LEVER_BACK) && (levers.getLever(LEVER_L8) == LEVER_FORWARD) && sidingSafeE))){
          return false;
        }
        else {
          return true;
        }
      } else if (leverState == LEVER_FORWARD) {
        if (levers.getLever(LEVER_L2) == LEVER_FORWARD) {
          return false;
      }
        else {
         return true;
        }
      }
      break;


    case LEVER_L5:
      if (leverState == LEVER_BACK){
        return false;
      } 
      else if (leverState == LEVER_FORWARD) {
        if ((levers.getLever(LEVER_L3) == LEVER_FORWARD) && (levers.getLever(LEVER_L4) == LEVER_FORWARD) && (levers.getLever(LEVER_L7) == LEVER_FORWARD) && (levers.getLever(LEVER_L8) == LEVER_FORWARD)) {
          return false;
        }
        else {
          return true;
        }
      } 
      else {
        return true;
      }
      break;

    case LEVER_L6:
      if (leverState == LEVER_BACK){
        if (levers.getLever(LEVER_L5) == LEVER_FORWARD) {
          return false;
        }
        else {
          return true;
        }
      } else if (leverState == LEVER_FORWARD) {
        if (levers.getLever(LEVER_L5) == LEVER_FORWARD) {
          return false;
        }
        else {
          return true;
        }
      }
      break;


    case LEVER_L7:
      if (leverState == LEVER_BACK){
        if ((levers.getLever(LEVER_L4) == LEVER_FORWARD) && (levers.getLever(LEVER_L5) == LEVER_BACK) && (levers.getLever(LEVER_L6) == LEVER_FORWARD)) {
          return false;
        }
        else {
          return true;
        }
      } else if (leverState == LEVER_FORWARD) {
        if (mainSafeE) {
          return false;
        }
        else {
          return true;
        }
      }
      else {
        return true;
      }
      break;

    case LEVER_L8:
      if (leverState == LEVER_BACK) {
        if ((levers.getLever(LEVER_L6) == LEVER_FORWARD && levers.getLever(LEVER_L3) == LEVER_FORWARD) || (levers.getLever(LEVER_L6) == LEVER_BACK && levers.getLever(LEVER_L5) == LEVER_BACK && levers.getLever(LEVER_L4) == LEVER_FORWARD)) {
          return false;
        } else {
          return true;
        }
      } else if (leverState == LEVER_FORWARD) {
        if (sidingSafeE) {
          return false;
        } else {
          return true;
        }
      }
      break;

    case LEVER_L9:
      if (leverState == LEVER_BACK){
        return false;
      } else if (leverState == LEVER_FORWARD) {
        return false;
      }
      else {
        return true;
      }
      break;

    case LEVER_L10:
      if (leverState == LEVER_BACK){
        return false;
      } else if (leverState == LEVER_FORWARD) {
        return false;
      }
      else {
        return true;
      }
      break;

    case LEVER_L11:
      if (leverState == LEVER_BACK){
        return false;
      } else if (leverState == LEVER_FORWARD) {
        return false;
      }
      else {
        return true;
      }
      break;

    case LEVER_L12:
      if (leverState == LEVER_BACK){
        return false;
      } else if (leverState == LEVER_FORWARD) {
        return false;
      }
      else {
        return true;
      }
      break;

    case LEVER_L13:
      if (leverState == LEVER_BACK){
        if (levers.getLever(LEVER_L19) == LEVER_FORWARD && levers.getLever(LEVER_L20) == LEVER_FORWARD && levers.getLever(LEVER_L21) == LEVER_BACK && levers.getLever(LEVER_L22) == LEVER_FORWARD) {
          return false;
        } else {
          return true;
        }
      } else if (leverState == LEVER_FORWARD) {
        if (mainSafeW) {
          return false;
        } else {
          return true;
        }
      } else {
        return true;
      }
      break;

    case LEVER_L14:
      if (leverState == LEVER_BACK){
        if ((levers.getLever(LEVER_L15) == LEVER_BACK && levers.getLever(LEVER_L16) == LEVER_FORWARD) || (levers.getLever(LEVER_L15) == LEVER_FORWARD && levers.getLever(LEVER_L20) == LEVER_BACK && levers.getLever(LEVER_L21) == LEVER_BACK && levers.getLever(LEVER_L22) == LEVER_FORWARD)) {
          return false;
        } else {
          return true;
        }
      } else if (leverState == LEVER_FORWARD) {
        if (sidingSafeW) {
          return false;
        } else {
          return true;
        }
      }
      else {
        return true;
      }
      break;

    case LEVER_L15:
      if (leverState == LEVER_BACK){
        if (levers.getLever(LEVER_L14) == LEVER_FORWARD && (levers.getLever(LEVER_L20) == LEVER_FORWARD || levers.getLever(LEVER_L22) == LEVER_FORWARD)) {
          return false;
        } else {
          return true;
        }
      } else if (leverState == LEVER_FORWARD) {
        if (levers.getLever(LEVER_L14) == LEVER_FORWARD && levers.getLever(LEVER_L16) == LEVER_FORWARD && (levers.getLever(LEVER_L20) == LEVER_FORWARD || levers.getLever(LEVER_L22) == LEVER_FORWARD)) {
          return false;
        } else {
          return true;
        }
      }
      else {
        return true;
      }
      break;

    case LEVER_L16:
      if (leverState == LEVER_BACK){
        if ((levers.getLever(LEVER_L14) == LEVER_FORWARD && levers.getLever(LEVER_L15) == LEVER_BACK && sidingSafeW)) {
          return false;
        } else {
          return true;
        }
      } else if (leverState == LEVER_FORWARD) {
        return false;
      }
      else {
        return true;
      }
      break;

    case LEVER_L17:
      if (leverState == LEVER_BACK){
        return false;
      } else if (leverState == LEVER_FORWARD) {
        return false;
      }
      else {
        return true;
      }
      break;

    case LEVER_L18:
      if (leverState == LEVER_BACK){
        if (levers.getLever(LEVER_L19) == LEVER_BACK && levers.getLever(LEVER_L20) == LEVER_FORWARD && levers.getLever(LEVER_L21) == LEVER_BACK && levers.getLever(LEVER_L22) == LEVER_FORWARD) {
          return false;
        } else {
          return true;
        }
      } else if (leverState == LEVER_FORWARD) {
        return false;
      }
      else {
        return true;
      }
      break;

    case LEVER_L19:
      if (leverState == LEVER_BACK){
        if (levers.getLever(LEVER_L13) == LEVER_FORWARD && levers.getLever(LEVER_L20) == LEVER_FORWARD && levers.getLever(LEVER_L21) == LEVER_BACK && levers.getLever(LEVER_L22) == LEVER_FORWARD) {
          return false;
        } else {
          return true;
        }
      } else if (leverState == LEVER_FORWARD) {
        if (levers.getLever(LEVER_L18) == LEVER_FORWARD && levers.getLever(LEVER_L22) == LEVER_FORWARD) {
          return false;
        } else {
          return true;
        }
      }
      else {
        return true;
      }
      break;

    case LEVER_L20:
      if (leverState == LEVER_BACK){
        if (levers.getLever(LEVER_L21) == LEVER_FORWARD) {
          return false;
        } else {
          return true;
        }
      } else if (leverState == LEVER_FORWARD) {
        if (levers.getLever(LEVER_L21) == LEVER_FORWARD) {
          return false;
        } else {
          return true;
        }
      }
      else {
        return true;
      }
      break;

    case LEVER_L21:
      if (leverState == LEVER_BACK){
         return false;
      }
      else if (leverState == LEVER_FORWARD) {
        if (levers.getLever(LEVER_L13) == LEVER_FORWARD &&
          (levers.getLever(LEVER_L14) == LEVER_FORWARD || levers.getLever(LEVER_L15) == LEVER_BACK) &&
           levers.getLever(LEVER_L18) == LEVER_FORWARD && levers.getLever(LEVER_L22) == LEVER_FORWARD) {
          return false;
        } 
	else {
          return true;
        }
      }
      else {
        return true;
      }
      break;

    case LEVER_L22:
      if (leverState == LEVER_BACK){
        if (levers.getLever(LEVER_L21) == LEVER_BACK &&
            ((levers.getLever(LEVER_L13) == LEVER_FORWARD && levers.getLever(LEVER_L20) == LEVER_FORWARD && levers.getLever(LEVER_L19) == LEVER_FORWARD && mainSafeW) ||
             (levers.getLever(LEVER_L20) == LEVER_FORWARD && levers.getLever(LEVER_L19) == LEVER_BACK && levers.getLever(LEVER_L18) == LEVER_FORWARD) ||
             (levers.getLever(LEVER_L20) == LEVER_BACK && levers.getLever(LEVER_L15) == LEVER_FORWARD && levers.getLever(LEVER_L14) == LEVER_FORWARD && sidingSafeW))) {
          return false;
        } else {
          return true;
        }
      } else if (leverState == LEVER_FORWARD) {
        if (levers.getLever(LEVER_L23) == LEVER_FORWARD) {
          return false;
        } else {
          return true;
        }
      }
      else {
        return true;
      }
      break;

    case LEVER_L23:
      if (leverState == LEVER_BACK){
        if (levers.getLever(LEVER_L22) == LEVER_BACK) {
          return false;
        } else {
          return true;
        }
      } else if (leverState == LEVER_FORWARD) {
        return false;
      }
      else {
        return true;
      }
      break;

    case LEVER_L24:
      if (leverState == LEVER_BACK){
        return false;
      } else if (leverState == LEVER_FORWARD) {
        return false;
      }
      else {
        return true;
      }
      break;
  }

  // By default, levers don't cause faults.
  return false;
}

// Action logic for levers being pulled back
void Railroad::leverBack(uint8_t leverNumber, Levers levers, Signals signals, MultiMCP23017 io) {
  // Objects are provided as parameters to allow accessing the state of other
  // levers and signals, and for directly controlling outputs.

  // Select the appropriate logic for the changed lever
  switch (leverNumber) {

    case LEVER_L1:
      // This lever is a turnout, and it affects no signals
      // Move the turnout
      io.digitalWrite(TURNOUT_T1_CHIP, TURNOUT_T1_PIN, TO_DIVERGE);
      break;
    
    case LEVER_L2:
      // This signal lever impacts signal 2,13,14 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S2, levers, signals);
      this->updateSignal(SIGNAL_S13, levers, signals);
      this->updateSignal(SIGNAL_S14, levers, signals);
      break; 
    
    case LEVER_L3:
      // This signal lever impacts signal 3,so run that signal's aspect logic
      this->updateSignal(SIGNAL_S3, levers, signals);
      break; 


    case LEVER_L4:
      // This signal lever impacts signal 4 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S4, levers, signals);
      break; 
 
    case LEVER_L5:
      // This lever is a point lock, and it only is used in fault logic
      break;

    case LEVER_L6:
      // This lever is a turnout, but it affects signals 2, 4, and 8
      this->updateSignal(SIGNAL_S2, levers, signals);
      this->updateSignal(SIGNAL_S4, levers, signals);
      this->updateSignal(SIGNAL_S8, levers, signals);
      // Move the turnout
      io.digitalWrite(TURNOUT_T6_CHIP, TURNOUT_T6_PIN, TO_DIVERGE);
      break;
      
    case LEVER_L7:
      // This lever impacts signal 7,22 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S7, levers, signals);
      this->updateSignal(SIGNAL_S22, levers, signals);
      break; 
    
    case LEVER_L8:
      // This lever impacts signal 8,22 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S8, levers, signals);
      this->updateSignal(SIGNAL_S22, levers, signals);
      break;

    case LEVER_L9:
      // This lever is used for sequence selection only
      this->enableSound = false;
      break;
      
    case LEVER_L10:
      // This lever impacts signal 10 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S10, levers, signals);
      break; 

    case LEVER_L11:
      // This lever impacts signal 11 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S11, levers, signals);
      break; 

    case LEVER_L12:
      // This lever is used for sequence control only
      this->mainMode = MODE_OVERRIDE;
      signals.setSignalState(SIGNAL_STATUS, SignalState::Yellow);
      break;
      
    case LEVER_L13:
      // This lever impacts signal 13,4 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S13, levers, signals);
      this->updateSignal(SIGNAL_S4, levers, signals);
      break; 

    case LEVER_L14:
      // This lever impacts signal 14,4 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S14, levers, signals);
      this->updateSignal(SIGNAL_S4, levers, signals);
      break; 

    case LEVER_L15:
      // This lever is a turnout, and it affects signal 14
      this->updateSignal(SIGNAL_S14, levers, signals);
      // Move the turnout
      io.digitalWrite(TURNOUT_T15_CHIP, TURNOUT_T15_PIN, TO_DIVERGE);
      break;
    
    case LEVER_L16:
      // This lever impacts signal 16, so run that signal's aspect logic
      this->updateSignal(SIGNAL_S16, levers, signals);
      break; 

    case LEVER_L17:
      // This lever is a turnout, and it affects no signals
      // Move the turnout
      io.digitalWrite(TURNOUT_T17_CHIP, TURNOUT_T17_PIN, TO_DIVERGE);
      break;

    case LEVER_L18:
      // This lever impacts signal 18 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S18, levers, signals);
      break; 

    case LEVER_L19:
      // This lever is a turnout, and it affects no signals
      // Move the turnout
      io.digitalWrite(TURNOUT_T19_CHIP, TURNOUT_T19_PIN, TO_DIVERGE);
      break;

    case LEVER_L20:
      // This lever is a turnout, and it affects signals 22, and 23
      this->updateSignal(SIGNAL_S22, levers, signals);
      this->updateSignal(SIGNAL_S23, levers, signals);
      // Move the turnout
      io.digitalWrite(TURNOUT_T20_CHIP, TURNOUT_T20_PIN, TO_DIVERGE);
      break;

    case LEVER_L21:
      // This lever is a point lock, and it only is used in fault logic
      break;
      
    case LEVER_L22:
      // This lever impacts signal 22 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S22, levers, signals);
      break; 
      
    case LEVER_L23:
      // This lever impacts signals 7, 8 and 23 so run those updates
      this->updateSignal(SIGNAL_S7, levers, signals); 
      this->updateSignal(SIGNAL_S8, levers, signals);
      this->updateSignal(SIGNAL_S23, levers, signals);
      break;

    case LEVER_L24:
      // This lever is a turnout, and it does not affect signals
      // Move the turnout
      io.digitalWrite(TURNOUT_T24_CHIP, TURNOUT_T24_PIN, TO_DIVERGE);
      break;
      
    
    default:
      // By default, do nothing
      break;
  }
}

// Action logic for levers being pushed forward
void Railroad::leverForward(uint8_t leverNumber, Levers levers, Signals signals, MultiMCP23017 io) {
  // Objects are provided as parameters to allow accessing the state of other
  // levers and signals, and for directly controlling outputs.
  
  // Select the appropriate logic for the changed lever
  switch (leverNumber) {

    case LEVER_L1:
      // This lever is a turnout, and it affects no signals
      // Move the turnout
      io.digitalWrite(TURNOUT_T1_CHIP, TURNOUT_T1_PIN, TO_STRAIGHT);
      break;


    case LEVER_L2:
      // This lever impacts signal 2,13,14 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S2, levers, signals);
      this->updateSignal(SIGNAL_S13, levers, signals);
      this->updateSignal(SIGNAL_S14, levers, signals);
      break; 
    
    case LEVER_L3:
      // This lever impacts signal 3,so run that signal's aspect logic
      this->updateSignal(SIGNAL_S3, levers, signals);
      break; 


    case LEVER_L4:
      // This lever impacts signal 4 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S4, levers, signals);
      break;

    case LEVER_L5:
      // This lever is a point lock, and it only is used in fault logic
      break;

    case LEVER_L6:
      // This lever is a turnout, but it affects signals 2, 4, and 8
      this->updateSignal(SIGNAL_S2, levers, signals);
      this->updateSignal(SIGNAL_S4, levers, signals);
      this->updateSignal(SIGNAL_S8, levers, signals);
      // Move the turnout
      io.digitalWrite(TURNOUT_T6_CHIP, TURNOUT_T6_PIN, TO_STRAIGHT);

    case LEVER_L7:
      // This lever impacts signal 7,22 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S7, levers, signals);
      this->updateSignal(SIGNAL_S22, levers, signals);
      break; 
    
    case LEVER_L8:
      // This lever impacts signal 8,22 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S8, levers, signals);
      this->updateSignal(SIGNAL_S22, levers, signals);
      break;

    case LEVER_L9:
      // This lever is used for sequence selection only
      this->enableSound = true;
      break;

    case LEVER_L10:
      // This lever impacts signal 10 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S10, levers, signals);
      break; 

    case LEVER_L11:
      // This lever impacts signal 11 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S11, levers, signals);
      break; 

    case LEVER_L12:
      // This lever is used for sequence control only
      // When pushed forward, this lever sets the Railroad object into operate
      // mode, enabling faults.
      this->mainMode = MODE_OPERATE;

      // If all levers are forward, run the setup again
      if (true) {
        bool leversForward = true;
        for (int i = 0; i < 24; i++) {
          if (levers.getLever(i) == LEVER_BACK) { leversForward = false; }
        }
        if (leversForward) {
          this->mainMode = MODE_SETUP;
        }
      }
      
      signals.setSignalState(SIGNAL_STATUS, SignalState::Red);
      break;

    case LEVER_L13:
      // This lever impacts signal 13,4 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S13, levers, signals);
      this->updateSignal(SIGNAL_S4, levers, signals);
      break; 

    case LEVER_L14:
      // This lever impacts signal 14,4 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S14, levers, signals);
      this->updateSignal(SIGNAL_S4, levers, signals);
      break; 

    case LEVER_L15:
      // This lever is a turnout, and it affects signal 14
      this->updateSignal(SIGNAL_S14, levers, signals);
      // Move the turnout
      io.digitalWrite(TURNOUT_T15_CHIP, TURNOUT_T15_PIN, TO_STRAIGHT);
      break;

    case LEVER_L16:
      // This lever impacts signal 16, so run that signal's aspect logic
      this->updateSignal(SIGNAL_S16, levers, signals);
      break; 

    case LEVER_L17:
      // This lever is a turnout, and it affects no signals
      // Move the turnout
      io.digitalWrite(TURNOUT_T17_CHIP, TURNOUT_T17_PIN, TO_STRAIGHT);
      break;

    case LEVER_L18:
      // This lever impacts signal 18 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S18, levers, signals);
      break; 

    case LEVER_L19:
      // This lever is a turnout, and it affects no signals
      // Move the turnout
      io.digitalWrite(TURNOUT_T19_CHIP, TURNOUT_T19_PIN, TO_STRAIGHT);
      break;

    case LEVER_L20:
      // This lever is a turnout, and it affects signals 22, and 23
      this->updateSignal(SIGNAL_S22, levers, signals);
      this->updateSignal(SIGNAL_S23, levers, signals);
      // Move the turnout
      io.digitalWrite(TURNOUT_T20_CHIP, TURNOUT_T20_PIN, TO_STRAIGHT);
      break;

    case LEVER_L21:
      // This lever is a point lock, and it only is used in fault logic
      break;

    case LEVER_L22:
      // This lever impacts signal 22 so run that signal's aspect logic
      this->updateSignal(SIGNAL_S22, levers, signals);
      break; 
      
    case LEVER_L23:
      // This lever impacts signals 7, 8 and 23 so run those updates
      this->updateSignal(SIGNAL_S7, levers, signals); 
      this->updateSignal(SIGNAL_S8, levers, signals);
      this->updateSignal(SIGNAL_S23, levers, signals);
      break;

    case LEVER_L24:
      // This lever is a turnout, and it does not affect signals
      // Move the turnout
      io.digitalWrite(TURNOUT_T24_CHIP, TURNOUT_T24_PIN, TO_STRAIGHT);
      break;
      
    default:
      break;  
  }
}

// Update signal aspect for a given signal number, based on lever states
void Railroad::updateSignal(uint8_t signalNumber, Levers levers, Signals signals) {
  Serial.print("Changing signal ");
  Serial.println(signalNumber);
  
  switch (signalNumber) {

 
    // This is the logic for signal lever 2
    case SIGNAL_S2:
      if (levers.getLever(LEVER_L2) == LEVER_FORWARD) {
        signals.setSignalState(signalNumber, SignalState::Red);
      } else {
        if (levers.getLever(LEVER_L6) == LEVER_FORWARD) {
          signals.setSignalState(signalNumber, SignalState::Green);
        } else {
          signals.setSignalState(signalNumber, SignalState::Yellow);
        }
      }
      break;    
    
    // This is the logic for signal lever 3
    case SIGNAL_S3:
      if (levers.getLever(LEVER_L3) == LEVER_FORWARD) {
        signals.setSignalState(signalNumber, SignalState::Red);
      } else {
          signals.setSignalState(signalNumber, SignalState::Green);
      }
      break;   
    
    // This is the logic for signal lever 4
    case SIGNAL_S4:
      if (levers.getLever(LEVER_L4) == LEVER_FORWARD) {
        signals.setSignalState(signalNumber, SignalState::Red);
      } else {
        if ((levers.getLever(LEVER_L6) == LEVER_FORWARD)&&(levers.getLever(LEVER_L13) == LEVER_BACK)||(levers.getLever(LEVER_L6) == LEVER_BACK)&&(levers.getLever(LEVER_L14) == LEVER_BACK)) {
          signals.setSignalState(signalNumber, SignalState::Green);
        } else {
          if ((levers.getLever(LEVER_L6) == LEVER_FORWARD)&&(levers.getLever(LEVER_L13) == LEVER_FORWARD)||(levers.getLever(LEVER_L6) == LEVER_BACK)&&(levers.getLever(LEVER_L14) == LEVER_FORWARD)) { 
            signals.setSignalState(signalNumber, SignalState::Yellow);
          }
        }
      }
      break;

    
    
    
    // This is the logic for signal lever 7
    case SIGNAL_S7:
      if (levers.getLever(LEVER_L7) == LEVER_FORWARD) {
        signals.setSignalState(signalNumber, SignalState::Red);
      } else {
        if (levers.getLever(LEVER_L23) == LEVER_FORWARD) {
          signals.setSignalState(signalNumber, SignalState::Yellow);
        } else {
          signals.setSignalState(signalNumber, SignalState::Green);
        }
      }
      break;

    // This is the logic for signal lever 8
    case SIGNAL_S8:
      if (levers.getLever(LEVER_L8) == LEVER_FORWARD) {
        signals.setSignalState(signalNumber, SignalState::Red);
      } else {
        if ((levers.getLever(LEVER_L6) == LEVER_FORWARD)||(levers.getLever(LEVER_L6) == LEVER_BACK && levers.getLever(LEVER_L23) == LEVER_FORWARD)) {
          signals.setSignalState(signalNumber, SignalState::Yellow);
        } else {
          if ((levers.getLever(LEVER_L6) == LEVER_BACK)&&(levers.getLever(LEVER_L23) == LEVER_BACK)) { 
            signals.setSignalState(signalNumber, SignalState::Green);
          }
        }
      }
      break;



    // This is the logic for signal lever 10
    case SIGNAL_S10:
      if (levers.getLever(LEVER_L10) == LEVER_FORWARD) {
        signals.setSignalState(signalNumber, SignalState::Red);
      } else {
        signals.setSignalState(signalNumber, SignalState::Green);
      }
      break;

    // This is the logic for signal lever 11
    case SIGNAL_S11:
      if (levers.getLever(LEVER_L11) == LEVER_FORWARD) {
        signals.setSignalState(signalNumber, SignalState::Red);
      } else {
        signals.setSignalState(signalNumber, SignalState::Green);
      }
      break;

    // This is the logic for signal lever 13
    case SIGNAL_S13:
      if (levers.getLever(LEVER_L13) == LEVER_FORWARD) {
        signals.setSignalState(signalNumber, SignalState::Red);
      } else {
        if (levers.getLever(LEVER_L2) == LEVER_FORWARD) {
          signals.setSignalState(signalNumber, SignalState::Yellow);
        } else {
          signals.setSignalState(signalNumber, SignalState::Green);
        }
      }
      break;    

    // This is the logic for signal lever 14
    case SIGNAL_S14:
      if (levers.getLever(LEVER_L14) == LEVER_FORWARD) {
        signals.setSignalState(signalNumber, SignalState::Red);
      } else {
        if ((levers.getLever(LEVER_L15) == LEVER_BACK)||(levers.getLever(LEVER_L15) == LEVER_FORWARD && levers.getLever(LEVER_L2) == LEVER_FORWARD)) {
          signals.setSignalState(signalNumber, SignalState::Yellow);
        } else {
          if ((levers.getLever(LEVER_L15) == LEVER_FORWARD)&&(levers.getLever(LEVER_L2) == LEVER_BACK)) { 
            signals.setSignalState(signalNumber, SignalState::Green);
          }
        }
      }
      break;




    // This is the logic for signal 16
    case SIGNAL_S16:
      if (levers.getLever(LEVER_L16) == LEVER_FORWARD) {
        signals.setSignalState(signalNumber, SignalState::Red);
      } else {
        signals.setSignalState(signalNumber, SignalState::Green);
      }
      break;

    // This is the logic for signal 18
    case SIGNAL_S18:
      if (levers.getLever(LEVER_L18) == LEVER_FORWARD) {
        signals.setSignalState(signalNumber, SignalState::Red);
      } else {
        signals.setSignalState(signalNumber, SignalState::Green);
      }
      break; 

    // This is the logic for signal 22
    case SIGNAL_S22:
      if (levers.getLever(LEVER_L22) == LEVER_FORWARD) {
        signals.setSignalState(signalNumber, SignalState::Red);
      } else {
        if (((levers.getLever(LEVER_L20) == LEVER_FORWARD)&&(levers.getLever(LEVER_L7) == LEVER_FORWARD))||(levers.getLever(LEVER_L20) == LEVER_BACK && levers.getLever(LEVER_L8) == LEVER_FORWARD)) {
          signals.setSignalState(signalNumber, SignalState::Yellow);
        } else {
          if (((levers.getLever(LEVER_L20) == LEVER_FORWARD)&&(levers.getLever(LEVER_L7) == LEVER_BACK))||(levers.getLever(LEVER_L20) == LEVER_BACK && levers.getLever(LEVER_L8) == LEVER_BACK)) { 
            signals.setSignalState(signalNumber, SignalState::Green);
          }
        }
      }
      break;



     // This is the logic for signal 23
    case SIGNAL_S23:
      if (levers.getLever(LEVER_L23) == LEVER_FORWARD) {
        signals.setSignalState(signalNumber, SignalState::Red);
      } else {
        if (levers.getLever(LEVER_L20) == LEVER_FORWARD) {
          signals.setSignalState(signalNumber, SignalState::Green);
        } else {
          signals.setSignalState(signalNumber, SignalState::Yellow);
        }
      }
      break;
  }
}
