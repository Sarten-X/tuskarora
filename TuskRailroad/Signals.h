#ifndef _Signals
#define _Signals

// The maximum number of signals in the system. Reduce this to save some memory.
// Increase it to add support for more signals.
#define MAX_SIGNALS 15

// A flag value indicating that a given chip or pin connection is not present
// for a signal.
#define NO_CONNECTION 255

#include <stdint.h>
#include "MultiMCP.h"
#include "debug.h"

// An enumeration of possible signal states.
enum SignalState {
  Red,
  Yellow,
  Green
};

// The Signal class is a data structure representing the state and connections
// of a single signal. 
class Signal {
  public:
    SignalState state = SignalState::Red;
    uint8_t signalRedChip = NO_CONNECTION;
    uint8_t signalRedPin = NO_CONNECTION;
    uint8_t signalYellowChip = NO_CONNECTION;
    uint8_t signalYellowPin = NO_CONNECTION;
    uint8_t signalGreenChip = NO_CONNECTION;
    uint8_t signalGreenPin = NO_CONNECTION;
    uint8_t panelRedChip = NO_CONNECTION;
    uint8_t panelRedPin = NO_CONNECTION;
    uint8_t panelYellowChip = NO_CONNECTION;
    uint8_t panelYellowPin = NO_CONNECTION;
    uint8_t panelGreenChip = NO_CONNECTION;
    uint8_t panelGreenPin = NO_CONNECTION;
};

// The Signals object tracks the state of several signals.
class Signals {
  public:
    // Initialize the Signals object with a given I/O controller object
    void init(MultiMCP23017 io);

    // Set the state of a single signal.
    void setSignalState(uint8_t signalNumber, SignalState state);

    // Get the state of a single signal.
    SignalState getSignalState(uint8_t signalNumber);

    // Register a signal's connections with the controller.
    void registerSignal(
      uint8_t signalNumber,
      uint8_t signalRedChip,
      uint8_t signalRedPin,
      uint8_t signalYellowChip,
      uint8_t signalYellowPin,
      uint8_t signalGreenChip,
      uint8_t signalGreenPin,
      uint8_t panelRedChip,
      uint8_t panelRedPin,
      uint8_t panelYellowChip,
      uint8_t panelYellowPin,
      uint8_t panelGreenChip,
      uint8_t panelGreenPin
    );
    
  private:
    // Internal array holding the data for all tracked signals
    Signal* signalStates[MAX_SIGNALS];

    // Reference to the I/O controller to be used
    MultiMCP23017 io;

    // Configurable state of debugging messages
    uint8_t DEBUG;
};

#endif
