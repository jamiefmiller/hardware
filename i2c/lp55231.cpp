#include <vector>
#include <stdint.h>
#include "lp55231.h"

LP55231::LP55231(const char i2cBus[]) : Device(i2cBus, 0x32) {
  // Magic setup bits that it doesn't work without.
  write(0x00, 0x40);
  write(0x36, 0x53);

  // Use log brightness to match human perception of color.
  std::vector<uint8_t> logBrightness;
  logBrightness.assign(9, 0x20);
  writeMany(0x06, logBrightness);
}

void LP55231::setLedRgb(uint8_t led, uint8_t r, uint8_t g, uint8_t b) {
  // Green and blue are in opposite positions than the documentation
  // indicates.
  write(0x16 + led * 2, g);
  write(0x17 + led * 2, b);
  write(0x1c + led, r);
}

void LP55231::setLedOff(uint8_t led) {
  setLedRgb(led, 0x00, 0x00, 0x00);
}
