#include "Signals.h"

// Initialize the Signals objects with a given I/O controller
void Signals::init(uint8_t DEBUG, MultiMCP23017 io) {
  this->DEBUG = DEBUG;
  this->io = io;
  for (int i = 0; i < MAX_SIGNALS; i++) {
    this->signalStates[i] = new Signal();
  }
}

// Register a signal definition with the handler
void Signals::registerSignal(uint8_t signalNumber,
  uint8_t signalRedChip, uint8_t signalRedPin,
  uint8_t signalYellowChip, uint8_t signalYellowPin,
  uint8_t signalGreenChip, uint8_t signalGreenPin,
  uint8_t panelRedChip, uint8_t panelRedPin,
  uint8_t panelYellowChip, uint8_t panelYellowPin,
  uint8_t panelGreenChip, uint8_t panelGreenPin) {

  this->signalStates[signalNumber]->signalRedChip = signalRedChip;
  this->signalStates[signalNumber]->signalRedPin = signalRedPin;
  this->signalStates[signalNumber]->signalYellowChip = signalYellowChip;
  this->signalStates[signalNumber]->signalYellowPin = signalYellowPin;
  this->signalStates[signalNumber]->signalGreenChip = signalGreenChip;
  this->signalStates[signalNumber]->signalGreenPin = signalGreenPin;
  this->signalStates[signalNumber]->panelRedChip = panelRedChip;
  this->signalStates[signalNumber]->panelRedPin = panelRedPin;
  this->signalStates[signalNumber]->panelYellowChip = panelYellowChip;
  this->signalStates[signalNumber]->panelYellowPin = panelYellowPin;
  this->signalStates[signalNumber]->panelGreenChip = panelGreenChip;
  this->signalStates[signalNumber]->panelGreenPin = panelGreenPin;
  // At initialization, all signals are set to red
  this->signalStates[signalNumber]->state = SignalState::Red;

  Signal* sig = signalStates[signalNumber];
  
//  Serial.print("Registering signal in array position # ");
//  Serial.print(signalNumber);
//  Serial.println("Signal chip/pins, for red, yellow, green:");
//  Serial.print(sig->signalRedChip);
//  Serial.print("/");
//  Serial.print(sig->signalRedPin);
//  Serial.print("/");
//  Serial.print(sig->panelRedChip);
//  Serial.print("/");
//  Serial.println(sig->panelRedPin);
//  Serial.print(sig->signalYellowChip);
//  Serial.print("/");
//  Serial.print(sig->signalYellowPin);
//  Serial.print("/");
//  Serial.print(sig->panelYellowChip);
//  Serial.print("/");
//  Serial.println(sig->panelYellowPin);
//  Serial.print(sig->signalGreenChip);
//  Serial.print("/");
//  Serial.print(sig->signalGreenPin);
//  Serial.print("/");
//  Serial.print(sig->panelGreenChip);
//  Serial.print("/");
//  Serial.println(sig->panelGreenPin);
}
    
void Signals::setSignalState(uint8_t signalNumber, SignalState state) {
  // When a signal state is set, each I/O line for that signal must be set
  // appropriately for the state.

  // Record the state being set
  signalStates[signalNumber]->state = state;
  
  // For convenience, retrieve the Signal object from the signalStates
  // array
  Signal* sig = signalStates[signalNumber];

  if (DEBUG >= DEBUG_TRACE) {
    Serial.print("Set signal in array position # ");
    Serial.print(signalNumber);
    Serial.print(" to ");
    switch (state) {
      case SignalState::Red: Serial.println("red"); break;
      case SignalState::Yellow: Serial.println("yellow"); break;
      case SignalState::Green: Serial.println("green"); break;
    }
//    
//    Serial.println("Signal chip/pins, for red, yellow, green:");
//    Serial.print(sig->signalRedChip);
//    Serial.print("/");
//    Serial.print(sig->signalRedPin);
//    Serial.print("/");
//    Serial.print(sig->panelRedChip);
//    Serial.print("/");
//    Serial.println(sig->panelRedPin);
//    Serial.print(sig->signalYellowChip);
//    Serial.print("/");
//    Serial.print(sig->signalYellowPin);
//    Serial.print("/");
//    Serial.print(sig->panelYellowChip);
//    Serial.print("/");
//    Serial.println(sig->panelYellowPin);
//    Serial.print(sig->signalGreenChip);
//    Serial.print("/");
//    Serial.print(sig->signalGreenPin);
//    Serial.print("/");
//    Serial.print(sig->panelGreenChip);
//    Serial.print("/");
//    Serial.println(sig->panelGreenPin);
  }
  
  switch (state) {
    case SignalState::Red:
      // Set output states for red
      if (sig->signalRedChip != NO_CONNECTION && sig->signalRedPin != NO_CONNECTION) { this->io.digitalWrite(sig->signalRedChip, sig->signalRedPin, HIGH); }
      if (sig->signalYellowChip != NO_CONNECTION && sig->signalYellowPin != NO_CONNECTION) { this->io.digitalWrite(sig->signalYellowChip, sig->signalYellowPin, LOW); }
      if (sig->signalGreenChip != NO_CONNECTION && sig->signalGreenPin != NO_CONNECTION) { this->io.digitalWrite(sig->signalGreenChip, sig->signalGreenPin, LOW); }
      if (sig->panelRedChip != NO_CONNECTION && sig->panelRedPin != NO_CONNECTION) { this->io.digitalWrite(sig->panelRedChip, sig->panelRedPin, HIGH); }
      if (sig->panelYellowChip != NO_CONNECTION && sig->panelYellowPin != NO_CONNECTION) { this->io.digitalWrite(sig->panelYellowChip, sig->panelYellowPin, LOW); }
      if (sig->panelGreenChip != NO_CONNECTION && sig->panelGreenPin != NO_CONNECTION) { this->io.digitalWrite(sig->panelGreenChip, sig->panelGreenPin, LOW); }
      break;
    case SignalState::Yellow:
      // Set output states for yellow
      if (sig->signalRedChip != NO_CONNECTION && sig->signalRedPin != NO_CONNECTION) { this->io.digitalWrite(sig->signalRedChip, sig->signalRedPin, LOW); }
      if (sig->signalYellowChip != NO_CONNECTION && sig->signalYellowPin != NO_CONNECTION) { this->io.digitalWrite(sig->signalYellowChip, sig->signalYellowPin, HIGH); }
      if (sig->signalGreenChip != NO_CONNECTION && sig->signalGreenPin != NO_CONNECTION) { this->io.digitalWrite(sig->signalGreenChip, sig->signalGreenPin, LOW); }
      if (sig->panelRedChip != NO_CONNECTION && sig->panelRedPin != NO_CONNECTION) { this->io.digitalWrite(sig->panelRedChip, sig->panelRedPin, LOW); }
      if (sig->panelYellowChip != NO_CONNECTION && sig->panelYellowPin != NO_CONNECTION) { this->io.digitalWrite(sig->panelYellowChip, sig->panelYellowPin, HIGH); }
      if (sig->panelGreenChip != NO_CONNECTION && sig->panelGreenPin != NO_CONNECTION) { this->io.digitalWrite(sig->panelGreenChip, sig->panelGreenPin, LOW); }
      break;
    case SignalState::Green:
      // Set output states for green
      if (sig->signalRedChip != NO_CONNECTION && sig->signalRedPin != NO_CONNECTION) { this->io.digitalWrite(sig->signalRedChip, sig->signalRedPin, LOW); }
      if (sig->signalYellowChip != NO_CONNECTION && sig->signalYellowPin != NO_CONNECTION) { this->io.digitalWrite(sig->signalYellowChip, sig->signalYellowPin, LOW); }
      if (sig->signalGreenChip != NO_CONNECTION && sig->signalGreenPin != NO_CONNECTION) { this->io.digitalWrite(sig->signalGreenChip, sig->signalGreenPin, HIGH); }
      if (sig->panelRedChip != NO_CONNECTION && sig->panelRedPin != NO_CONNECTION) { this->io.digitalWrite(sig->panelRedChip, sig->panelRedPin, LOW); }
      if (sig->panelYellowChip != NO_CONNECTION && sig->panelYellowPin != NO_CONNECTION) { this->io.digitalWrite(sig->panelYellowChip, sig->panelYellowPin, LOW); }
      if (sig->panelGreenChip != NO_CONNECTION && sig->panelGreenPin != NO_CONNECTION) { this->io.digitalWrite(sig->panelGreenChip, sig->panelGreenPin, HIGH); }
      break;
  } 
}

// A getter for a given signal's last-set state
SignalState Signals::getSignalState(uint8_t signalNumber) {
  return signalStates[signalNumber]->state;
}
