#ifndef HARDWARE_I2C_LP55231_H
#define HARDWARE_I2C_LP55231_H

#define LP55231_LED_1 0
#define LP55231_LED_2 1
#define LP55231_LED_3 2

#include <stdint.h>
#include "device.h"

class LP55231: public Device {
  public:
    LP55231(const char i2cBus[]);
    void setLedRgb(uint8_t led, uint8_t r, uint8_t g, uint8_t b);
    void setLedOff(uint8_t led);
};

#endif
