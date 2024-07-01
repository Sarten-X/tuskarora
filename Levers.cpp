#include "Levers.h"

// 321098765432109876543210
// Bank 3  Bank 2  Bank 1

void Levers::init() {
  // At initialization, assume all levers are forward
  leverState = 0;
  for (int i=0; i < 24; i++) {
    leverState = leverState << 1;
    leverState = leverState | LEVER_FORWARD;
  }
}

void Levers::setLever(uint8_t leverNumber, bool state) {
  // Set a single bit to a given state
  if (state) {
    // If setting the bit true, use a bitwise OR (|)
    leverState = leverState | (0b1 << leverNumber);
  } else {
    // If setting the bit true, use a bitwise AND (&)
    leverState = leverState & ~(0b1 << leverNumber);
  }
}

void Levers::setLevers(uint32_t state) {
  // Set a block of 32 levers according to the bitfield given
  leverState = state;
}

uint8_t Levers::getLeverBank(uint8_t startLever) {
  // Retrieve 8 bits from the state variable, starting with a given bit
  return leverState >> startLever & 0b11111111;
}

uint32_t Levers::getLevers() {
  // Retrieve 24 bits from the state variable
//  return (this->getLeverBank(16) << 16) | (this->getLeverBank(8) << 8) | (this->getLeverBank(0));
  return leverState & 0b111111111111111111111111;
}

bool Levers::getLever(uint8_t lever) {
  // Retrieve a single bit from the state variable
  return (leverState & (0b1 << lever) ? 0b1 : 0b0);
}
