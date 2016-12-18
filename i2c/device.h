#ifndef HARDWARE_I2C_DEVICE_H
#define HARDWARE_I2C_DEVICE_H

class Device
{
public:
  Device(const char i2cBus[], int addr);
  int read(int address);
private:
  int i2cBus_;
  int addr_;
};

#endif

