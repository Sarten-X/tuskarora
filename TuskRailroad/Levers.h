#ifndef _Levers
#define _Levers

#define LEVER_FORWARD 0
#define LEVER_BACK 1

#include <stdint.h>
#include "debug.h"

class Levers
{
  // State object for tracking the state of the 24 levers
  public:
    void init();
    void setLever(uint8_t lever, bool state); // Set a single lever to a given state
    void setLevers(uint32_t state); // Set a block of 32 levers according to the bitfield given
    bool getLever(uint8_t lever); // Retrieve a single lever state
    uint32_t getLevers(); // Retrieve all lever states at once
  private:
    uint8_t getLeverBank(uint8_t startLever); // Retrieve 8 bits from the state variable, starting with a given bit
    uint32_t leverState;
};

#endif
