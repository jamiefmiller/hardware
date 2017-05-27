#ifndef HARDWARE_I2C_DEVICE_H
#define HARDWARE_I2C_DEVICE_H

#include <stdint.h>
#include <vector>

class Device {
  public:
    Device(const char i2cBus[], uint8_t addr);
    uint8_t read(uint8_t address);
    std::vector<uint8_t> readMany(uint8_t address, uint8_t length);
    void write(uint8_t address, uint8_t value);
    void writeMany(
        uint8_t address,
        std::vector<uint8_t> const &values);
  private:
    int i2cBus_;
    uint8_t addr_;
};

#endif

