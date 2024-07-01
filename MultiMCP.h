#ifndef _MultiMCP23017
#define _MultiMCP23017

#define IO_DIR_OUTPUT 0
#define IO_DIR_INPUT 1

#include "MCP23017.h"
#include <stdint.h>

class MultiMCP23017 {
  // A single class with support for 8 MCP23017 I/O expanders
  public:
    MultiMCP23017();
    void dump(uint8_t chip);  // Dump a chip's status to the serial console for debugging
    void init(); // Initialize the chip interfaces
    void setPinMode(uint8_t chip, uint8_t pin, uint8_t mode); // Set the direction of a single pin
    void setPortMode(uint8_t chip, MCP23017Port port, uint8_t directions, uint8_t pullups = 0xFF, uint8_t inverted = 0x00); // Set the direction (and other options) of an entire port
    
    void digitalWrite(uint8_t chip, uint8_t pin, uint8_t level); // Set a single pin's state
    
    uint16_t digitalRead(uint8_t chip); // Read both ports of a single chip
    uint8_t digitalRead(uint8_t chip, MCP23017Port port); // Read a single port of a single chip
    bool digitalRead(uint8_t chip, uint8_t pin); // Read a single pin from a chip

  private:
    MCP23017* chips[8]; // Array of MCP23017 interfaces 
};

#endif
