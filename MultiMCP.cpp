#include "MultiMCP.h"

// Empty constructor
MultiMCP23017::MultiMCP23017() { }

// Initialize routine creates the interface objects
void MultiMCP23017::init() {
  this->chips[0] = new MCP23017(0x20);
  this->chips[1] = new MCP23017(0x21);
  this->chips[2] = new MCP23017(0x22);
  this->chips[3] = new MCP23017(0x23);
  this->chips[4] = new MCP23017(0x24);
  this->chips[5] = new MCP23017(0x25);
  this->chips[6] = new MCP23017(0x26);
  this->chips[7] = new MCP23017(0x27);
  for (int i = 0; i < 8; i++) {
    // Initialize all ports to low
    this->chips[i]->writeRegister(MCP23017Register::GPIO_A, 0b00);
    this->chips[i]->writeRegister(MCP23017Register::GPIO_B, 0b00);
    // Initialize all ports to output mode
    this->chips[i]->portMode(MCP23017Port::A, 0b0);
    this->chips[i]->portMode(MCP23017Port::B, 0b0);
  }
}

 // Set the direction (and other options) of an entire port
void MultiMCP23017::setPortMode(uint8_t chip, MCP23017Port port, uint8_t directions, uint8_t pullups, uint8_t inverted) {
  this->chips[chip]->portMode(port, directions, pullups, inverted);
}

// Set the direction of a single pin
void MultiMCP23017::setPinMode(uint8_t chip, uint8_t pin, uint8_t mode) {
  this->chips[chip]->pinMode(pin, mode);
}

// Read both ports of a single chip
uint16_t MultiMCP23017::digitalRead(uint8_t chip) {
  return this->chips[chip]->read();  
}

// Read a single port of a single chip
uint8_t MultiMCP23017::digitalRead(uint8_t chip, MCP23017Port port) {
  // Read the whole chip
  uint16_t buffer = this->digitalRead(chip);
//  Serial.print("Chip read: ");
//  Serial.print(buffer, BIN);

  // Mask off the required bits for the intended port
  uint8_t output = 0;
  if (port == MCP23017Port::A) {
    output = buffer & 0b0000000011111111;
  } else {
    output = ((buffer & 0b1111111100000000) >> 8);
  }
//  Serial.print("\tPort read: ");
//  Serial.println(output, BIN);
  return output;
}

// Read a single pin from a chip
bool MultiMCP23017::digitalRead(uint8_t chip, uint8_t pin) {
  uint16_t buffer = this->digitalRead(chip);
  return buffer & (0x1 << pin);
}

// Set a single pin's state
void MultiMCP23017::digitalWrite(uint8_t chip, uint8_t pin, uint8_t level) {
  this->chips[chip]->digitalWrite(pin, level);
  //  Serial.print("Chip/pin/level ");
  //  Serial.print(chip);
  //  Serial.print(pin);
  //  Serial.println(level);
}

// Dump a chip's status to the serial console for debugging
void MultiMCP23017::dump(uint8_t chip) {
  MCP23017 mcp = *this->chips[chip];
  
  uint8_t conf = mcp.readRegister(MCP23017Register::IODIR_A);
  Serial.print("IODIR_A : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);
  
  conf = mcp.readRegister(MCP23017Register::IODIR_B);
  Serial.print("IODIR_B : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);

  conf = mcp.readRegister(MCP23017Register::IPOL_A);
  Serial.print("IPOL_A : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);

  conf = mcp.readRegister(MCP23017Register::IPOL_B);
  Serial.print("IPOL_B : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);

  conf = mcp.readRegister(MCP23017Register::GPINTEN_A);
  Serial.print("GPINTEN_A : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);

  conf = mcp.readRegister(MCP23017Register::GPINTEN_B);
  Serial.print("GPINTEN_B : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);

  conf = mcp.readRegister(MCP23017Register::DEFVAL_A);
  Serial.print("DEFVAL_A : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);

  conf = mcp.readRegister(MCP23017Register::DEFVAL_B);
  Serial.print("DEFVAL_B : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);

  conf = mcp.readRegister(MCP23017Register::INTCON_A);
  Serial.print("INTCON_A : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);

  conf = mcp.readRegister(MCP23017Register::INTCON_B);
  Serial.print("INTCON_B : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);

  conf = mcp.readRegister(MCP23017Register::IOCON);
  Serial.print("IOCON : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);

  //conf = mcp.readRegister(IOCONB);
  //Serial.print("IOCONB : ");
  //Serial.print(conf, BIN);
  //Serial.println();

  conf = mcp.readRegister(MCP23017Register::GPPU_A);
  Serial.print("GPPU_A : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);

  conf = mcp.readRegister(MCP23017Register::GPPU_B);
  Serial.print("GPPU_B : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);

  conf = mcp.readRegister(MCP23017Register::INTF_A);
  Serial.print("INTF_A : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);

  conf = mcp.readRegister(MCP23017Register::INTF_B);
  Serial.print("INTF_B : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);

  conf = mcp.readRegister(MCP23017Register::INTCAP_A);
  Serial.print("INTCAP_A : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);

  conf = mcp.readRegister(MCP23017Register::INTCAP_B);
  Serial.print("INTCAP_B : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);

  conf = mcp.readRegister(MCP23017Register::GPIO_A);
  Serial.print("GPIO_A : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);

  conf = mcp.readRegister(MCP23017Register::GPIO_B);
  Serial.print("GPIO_B : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);

  conf = mcp.readRegister(MCP23017Register::OLAT_A);
  Serial.print("OLAT_A : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(20);

  conf = mcp.readRegister(MCP23017Register::OLAT_B);
  Serial.print("OLAT_B : ");
  Serial.print(conf, BIN);
  Serial.println();
  delay(2000);
}
