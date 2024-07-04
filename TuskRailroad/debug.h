#ifndef _Debug
#define _Debug

// If nonzero, DEBUG enables the use of a serial console for state observation.

// DEBUG_NONE is for normal operations
#define DEBUG_NONE 0
// DEBUG_TRACE monitors major program flow
#define DEBUG_TRACE 1
// DEBUG_STEP adds delays that will prevent audio playback from working properly
#define DEBUG_STEP 2
// DEBUG_VERBOSE sends verbose status messages to the serial console
#define DEBUG_VERBOSE 3

// Pin numbers for verbosity switches, with switch 1 as least-significant bit
#define DEBUG_SWITCH_1 36
#define DEBUG_SWITCH_2 37

// Pin number for the run-enable switch
#define DEBUG_ENABLE_RUN 39

extern uint8_t DEBUG;

#endif