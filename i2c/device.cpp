#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <string>
#include <vector>
#include "device.h"

Device::Device(const char i2cBus[], uint8_t addr) {
  i2cBus_ = open(i2cBus, O_RDWR);
  addr_ = addr;
}

uint8_t Device::read(uint8_t address) {
  ioctl(i2cBus_, I2C_SLAVE, addr_);
  return i2c_smbus_read_byte_data(i2cBus_, address);
}

std::vector<uint8_t> Device::readMany(uint8_t address, uint8_t length) {
  uint8_t* rawRead = new uint8_t[length];
  i2c_smbus_read_block_data(
      i2cBus_,
      address,
      rawRead);
  std::vector<uint8_t> result;
  for (uint8_t i = 0; i < length; i++) {
    result.push_back(rawRead[i]);
  }
  return result;
}

void Device::write(uint8_t address, uint8_t value) {
  ioctl(i2cBus_, I2C_SLAVE, addr_);
  i2c_smbus_write_byte_data(i2cBus_, address, value);
}

void Device::writeMany(
    uint8_t address,
    std::vector<uint8_t> const &values) {
  ioctl(i2cBus_, I2C_SLAVE, addr_);
  i2c_smbus_write_block_data(
      i2cBus_,
      address,
      values.size(),
      values.data());
}

int main(void) {
  Device* dev = new Device("/dev/i2c-2", 0x32);
  dev->write(0x00, 0x40);
  dev->write(0x36, 0x53);
  dev->write(0x16, 0);
  printf("%d\n", dev->read(0x00));
}
