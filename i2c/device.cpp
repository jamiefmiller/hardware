#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <string>
#include "device.h"

Device::Device(const char i2cBus[], uint8_t addr) {
  i2cBus_ = open(i2cBus, O_RDWR);
  addr_ = addr;
}

uint8_t Device::read(uint8_t address) {
  ioctl(i2cBus_, I2C_SLAVE, addr_);
  return i2c_smbus_read_byte_data(i2cBus_, address);
}

void Device::write(uint8_t address, uint8_t value) {
  ioctl(i2cBus_, I2C_SLAVE, addr_);
  i2c_smbus_write_byte_data(i2cBus_, address, value);
}

int main(void) {
  Device* dev = new Device("/dev/i2c-2", 0x32);
  dev->write(0x00, 0x40);
  dev->write(0x36, 0x53);
  dev->write(0x16, 0);
  printf("%d\n", dev->read(0x00));
}
