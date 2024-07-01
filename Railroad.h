#ifndef _Railroad
#define _Railroad
/* 
 *  Input pins
 *  Input selections include a chip number (0-7) and 
 *  a pin number (0-7 for GPIOA 0-7, 8-15 for GPIOB 0-7)
 *  
 */

// Include objects referenced in this class
#include "MultiMCP.h"
#include "Levers.h"
#include "Signals.h"

// Define constants for turnout status
#define TO_DIVERGE HIGH
#define TO_STRAIGHT LOW

// Define lever input connections.
// This framework assumes that the input levers are three ports of 8 contiguous
// pins each.
#define LEVER_CHIP_1 3
#define LEVER_PORT_1 MCP23017Port::A
#define LEVER_CHIP_2 4
#define LEVER_PORT_2 MCP23017Port::A
#define LEVER_CHIP_3 5
#define LEVER_PORT_3 MCP23017Port::A

// Define constant names for each lever.
//#define LEVER_ALWAYS_FAULT 0
//#define LEVER_SIGNAL_RED 1
//#define LEVER_SIGNAL_YG 2
//#define LEVER_TURNOUT 3
//#define LEVER_FAULT_IF_GREEN 4
//#define LEVER_FAULT_IF_TURNOUT 5
//#define LEVER_OVERRIDE 6

// Define constant names for each lever.
#define LEVER_L1 7
#define LEVER_L2 6
#define LEVER_L3 5
#define LEVER_L4 4
#define LEVER_L5 3
#define LEVER_L6 2
#define LEVER_L7 1
#define LEVER_L8 0
#define LEVER_L9 15
#define LEVER_L10 14
#define LEVER_L11 13
#define LEVER_L12 12
#define LEVER_L13 11
#define LEVER_L14 10
#define LEVER_L15 9
#define LEVER_L16 8
#define LEVER_L17 23
#define LEVER_L18 22
#define LEVER_L19 21
#define LEVER_L20 20
#define LEVER_L21 19
#define LEVER_L22 18
#define LEVER_L23 17
#define LEVER_L24 16




// Define signals (and panel indicators)

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
// either listed here or in definitions in Railroad.cpp.
// Scott's example


//#define SIGNAL_SAMPLE 0
//#define SIGNAL_SAMPLE_RED_CHIP    1
//#define SIGNAL_SAMPLE_RED_PIN     0
//#define SIGNAL_SAMPLE_YELLOW_CHIP NO_CONNECTION
//#define SIGNAL_SAMPLE_YELLOW_PIN  NO_CONNECTION
//#define SIGNAL_SAMPLE_GREEN_CHIP  1
//#define SIGNAL_SAMPLE_GREEN_PIN   1
//#define PANEL_SAMPLE_RED_CHIP     1
//#define PANEL_SAMPLE_RED_PIN      7
//#define PANEL_SAMPLE_YELLOW_CHIP  NO_CONNECTION
//#define PANEL_SAMPLE_YELLOW_PIN   NO_CONNECTION
//#define PANEL_SAMPLE_GREEN_CHIP   1
//#define PANEL_SAMPLE_GREEN_PIN    6


#define SIGNAL_S2 1
#define SIGNAL_S2_RED_CHIP    1
#define SIGNAL_S2_RED_PIN     8
#define SIGNAL_S2_YELLOW_CHIP 1
#define SIGNAL_S2_YELLOW_PIN  10
#define SIGNAL_S2_GREEN_CHIP  1
#define SIGNAL_S2_GREEN_PIN   9
#define PANEL_S2_RED_CHIP     3
#define PANEL_S2_RED_PIN      14
#define PANEL_S2_YELLOW_CHIP  3
#define PANEL_S2_YELLOW_PIN   12
#define PANEL_S2_GREEN_CHIP   3
#define PANEL_S2_GREEN_PIN    11


#define SIGNAL_S3 2
#define SIGNAL_S3_RED_CHIP    1
#define SIGNAL_S3_RED_PIN     6
#define SIGNAL_S3_YELLOW_CHIP NO_CONNECTION
#define SIGNAL_S3_YELLOW_PIN  NO_CONNECTION
#define SIGNAL_S3_GREEN_CHIP  1
#define SIGNAL_S3_GREEN_PIN   7
#define PANEL_S3_RED_CHIP     3
#define PANEL_S3_RED_PIN      13
#define PANEL_S3_YELLOW_CHIP  NO_CONNECTION
#define PANEL_S3_YELLOW_PIN   NO_CONNECTION
#define PANEL_S3_GREEN_CHIP   3
#define PANEL_S3_GREEN_PIN    15


#define SIGNAL_S4 3
#define SIGNAL_S4_RED_CHIP    1
#define SIGNAL_S4_RED_PIN     3
#define SIGNAL_S4_YELLOW_CHIP 1
#define SIGNAL_S4_YELLOW_PIN  5
#define SIGNAL_S4_GREEN_CHIP  1
#define SIGNAL_S4_GREEN_PIN   4
#define PANEL_S4_RED_CHIP     6
#define PANEL_S4_RED_PIN      12
#define PANEL_S4_YELLOW_CHIP  6
#define PANEL_S4_YELLOW_PIN   10
#define PANEL_S4_GREEN_CHIP   6
#define PANEL_S4_GREEN_PIN    8


#define SIGNAL_S7 4
#define SIGNAL_S7_RED_CHIP    0
#define SIGNAL_S7_RED_PIN     12
#define SIGNAL_S7_YELLOW_CHIP 0
#define SIGNAL_S7_YELLOW_PIN  14
#define SIGNAL_S7_GREEN_CHIP  0
#define SIGNAL_S7_GREEN_PIN   13
#define PANEL_S7_RED_CHIP     6
#define PANEL_S7_RED_PIN      13
#define PANEL_S7_YELLOW_CHIP  6
#define PANEL_S7_YELLOW_PIN   11
#define PANEL_S7_GREEN_CHIP   6
#define PANEL_S7_GREEN_PIN    9


#define SIGNAL_S8 5  
#define SIGNAL_S8_RED_CHIP    1
#define SIGNAL_S8_RED_PIN     0
#define SIGNAL_S8_YELLOW_CHIP 1
#define SIGNAL_S8_YELLOW_PIN  2
#define SIGNAL_S8_GREEN_CHIP  1
#define SIGNAL_S8_GREEN_PIN   1
#define PANEL_S8_RED_CHIP     4
#define PANEL_S8_RED_PIN      15
#define PANEL_S8_YELLOW_CHIP  3
#define PANEL_S8_YELLOW_PIN   9
#define PANEL_S8_GREEN_CHIP   3
#define PANEL_S8_GREEN_PIN    8

#define SIGNAL_S10 6  
#define SIGNAL_S10_RED_CHIP    0
#define SIGNAL_S10_RED_PIN     8
#define SIGNAL_S10_YELLOW_CHIP NO_CONNECTION
#define SIGNAL_S10_YELLOW_PIN  NO_CONNECTION
#define SIGNAL_S10_GREEN_CHIP  0
#define SIGNAL_S10_GREEN_PIN   9
#define PANEL_S10_RED_CHIP     4
#define PANEL_S10_RED_PIN      12
#define PANEL_S10_YELLOW_CHIP  NO_CONNECTION
#define PANEL_S10_YELLOW_PIN   NO_CONNECTION
#define PANEL_S10_GREEN_CHIP   4
#define PANEL_S10_GREEN_PIN    14

#define SIGNAL_S11 7  
#define SIGNAL_S11_RED_CHIP    0
#define SIGNAL_S11_RED_PIN     10
#define SIGNAL_S11_YELLOW_CHIP NO_CONNECTION
#define SIGNAL_S11_YELLOW_PIN  NO_CONNECTION
#define SIGNAL_S11_GREEN_CHIP  0
#define SIGNAL_S11_GREEN_PIN   11
#define PANEL_S11_RED_CHIP     4
#define PANEL_S11_RED_PIN      8
#define PANEL_S11_YELLOW_CHIP  NO_CONNECTION
#define PANEL_S11_YELLOW_PIN   NO_CONNECTION
#define PANEL_S11_GREEN_CHIP   4
#define PANEL_S11_GREEN_PIN    10

#define SIGNAL_S13 8  
#define SIGNAL_S13_RED_CHIP    2
#define SIGNAL_S13_RED_PIN     0
#define SIGNAL_S13_YELLOW_CHIP 2
#define SIGNAL_S13_YELLOW_PIN  2
#define SIGNAL_S13_GREEN_CHIP  2
#define SIGNAL_S13_GREEN_PIN   1
#define PANEL_S13_RED_CHIP     4
#define PANEL_S13_RED_PIN      9
#define PANEL_S13_YELLOW_CHIP  4
#define PANEL_S13_YELLOW_PIN   11
#define PANEL_S13_GREEN_CHIP   6
#define PANEL_S13_GREEN_PIN    6

#define SIGNAL_S14 9  
#define SIGNAL_S14_RED_CHIP    2
#define SIGNAL_S14_RED_PIN     3
#define SIGNAL_S14_YELLOW_CHIP 2
#define SIGNAL_S14_YELLOW_PIN  5
#define SIGNAL_S14_GREEN_CHIP  2
#define SIGNAL_S14_GREEN_PIN   4
#define PANEL_S14_RED_CHIP     4
#define PANEL_S14_RED_PIN      13
#define PANEL_S14_YELLOW_CHIP  6
#define PANEL_S14_YELLOW_PIN   5
#define PANEL_S14_GREEN_CHIP   6
#define PANEL_S14_GREEN_PIN    7

#define SIGNAL_S16 10  
#define SIGNAL_S16_RED_CHIP    2
#define SIGNAL_S16_RED_PIN     8
#define SIGNAL_S16_YELLOW_CHIP NO_CONNECTION
#define SIGNAL_S16_YELLOW_PIN  NO_CONNECTION
#define SIGNAL_S16_GREEN_CHIP  2
#define SIGNAL_S16_GREEN_PIN   9
#define PANEL_S16_RED_CHIP     6
#define PANEL_S16_RED_PIN      1
#define PANEL_S16_YELLOW_CHIP  NO_CONNECTION
#define PANEL_S16_YELLOW_PIN   NO_CONNECTION
#define PANEL_S16_GREEN_CHIP   6
#define PANEL_S16_GREEN_PIN    3

#define SIGNAL_S18 11  
#define SIGNAL_S18_RED_CHIP    2
#define SIGNAL_S18_RED_PIN     6
#define SIGNAL_S18_YELLOW_CHIP NO_CONNECTION
#define SIGNAL_S18_YELLOW_PIN  NO_CONNECTION
#define SIGNAL_S18_GREEN_CHIP  2
#define SIGNAL_S18_GREEN_PIN   7
#define PANEL_S18_RED_CHIP     6
#define PANEL_S18_RED_PIN      4
#define PANEL_S18_YELLOW_CHIP  NO_CONNECTION
#define PANEL_S18_YELLOW_PIN   NO_CONNECTION
#define PANEL_S18_GREEN_CHIP   6
#define PANEL_S18_GREEN_PIN    2

#define SIGNAL_S22 12  
#define SIGNAL_S22_RED_CHIP    2
#define SIGNAL_S22_RED_PIN     10
#define SIGNAL_S22_YELLOW_CHIP 2
#define SIGNAL_S22_YELLOW_PIN  12
#define SIGNAL_S22_GREEN_CHIP  2
#define SIGNAL_S22_GREEN_PIN   11
#define PANEL_S22_RED_CHIP     5
#define PANEL_S22_RED_PIN      14
#define PANEL_S22_YELLOW_CHIP  5
#define PANEL_S22_YELLOW_PIN   12
#define PANEL_S22_GREEN_CHIP   6
#define PANEL_S22_GREEN_PIN    0

#define SIGNAL_S23 13  
#define SIGNAL_S23_RED_CHIP    2
#define SIGNAL_S23_RED_PIN     13
#define SIGNAL_S23_YELLOW_CHIP 2
#define SIGNAL_S23_YELLOW_PIN  15
#define SIGNAL_S23_GREEN_CHIP  2
#define SIGNAL_S23_GREEN_PIN   14
#define PANEL_S23_RED_CHIP     5
#define PANEL_S23_RED_PIN      13
#define PANEL_S23_YELLOW_CHIP  5
#define PANEL_S23_YELLOW_PIN   11
#define PANEL_S23_GREEN_CHIP   5
#define PANEL_S23_GREEN_PIN    9

#define SIGNAL_STATUS 14  
#define SIGNAL_STATUS_RED_CHIP    NO_CONNECTION
#define SIGNAL_STATUS_RED_PIN     NO_CONNECTION
#define SIGNAL_STATUS_YELLOW_CHIP NO_CONNECTION
#define SIGNAL_STATUS_YELLOW_PIN  NO_CONNECTION
#define SIGNAL_STATUS_GREEN_CHIP  NO_CONNECTION
#define SIGNAL_STATUS_GREEN_PIN   NO_CONNECTION
#define PANEL_STATUS_RED_CHIP     5
#define PANEL_STATUS_RED_PIN      15
#define PANEL_STATUS_YELLOW_CHIP  5
#define PANEL_STATUS_YELLOW_PIN   8
#define PANEL_STATUS_GREEN_CHIP   5
#define PANEL_STATUS_GREEN_PIN    10



// Define turnouts as chip/pin addresses. These are used when making direct I/O
// requests.
//#define TURNOUT_SAMPLE_CHIP   0
//#define TURNOUT_SAMPLE_PIN    3



#define TURNOUT_T1_CHIP       0
#define TURNOUT_T1_PIN        0

#define TURNOUT_T6_CHIP       0
#define TURNOUT_T6_PIN        1

#define TURNOUT_T15_CHIP      0
#define TURNOUT_T15_PIN       2

#define TURNOUT_T17_CHIP      0
#define TURNOUT_T17_PIN       3

#define TURNOUT_T19_CHIP      0
#define TURNOUT_T19_PIN       4

#define TURNOUT_T20_CHIP      0
#define TURNOUT_T20_PIN       5

#define TURNOUT_T24_CHIP      0
#define TURNOUT_T24_PIN       6



// Define operating modes for the system
#define MODE_STARTUP 0  // Delay to allow all chips/boards to power fully
#define MODE_SETUP 1    // All levers must be moved forward to go to OPERATE
#define MODE_OPERATE 2  // Normal operations
#define MODE_OVERRIDE 4 // Fault conditions are overridden. All actions succeed.

// This is the class definition for the railroad logic handler.
class Railroad {
  public:
    // This class can hold any required state variables. The main operating mode
    // is used elsewhere in the framework, but additional variables may be added
    // as needed.
    uint8_t mainMode = MODE_STARTUP;  // Operating mode
    bool enableSound = true;  // Enable lever audio
    
    // Since faults are handled using the same bitfield logic as the lever buffer,
    // we use the same class. 
    Levers faults = Levers();

    // Initialize the railroad logic.
    void init(Signals signals);

    // Reset turnouts to initial position.
    void resetTurnouts(MultiMCP23017 io);
    
    // Interlocking/fault logic. Return true if action is a fault.
    bool checkFaults(uint8_t leverNumber, Levers levers, Signals signals);

    // Executes actions when a given lever is pulled back.
    void leverBack(uint8_t leverNumber, Levers levers, Signals signals, MultiMCP23017 io);

    // Executes actions when a given lever is pushed forward.
    void leverForward(uint8_t leverNumber, Levers levers, Signals signals, MultiMCP23017 io);

    // Update a given signal aspect based on lever state
    void updateSignal(uint8_t signalNumber, Levers levers, Signals signals);
};


#endif
