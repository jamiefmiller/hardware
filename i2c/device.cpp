#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <string>
#include "device.h"

Device::Device (const char i2cBus[], int addr) {
	i2cBus_ = open(i2cBus, O_RDWR);
	addr_ = addr;
}

int Device::read (int address) {
	ioctl(i2cBus_, I2C_SLAVE, addr_);
	return i2c_smbus_read_byte_data(i2cBus_, address);
}

int main(void) {
	Device* dev = new Device("/dev/i2c-2", 0x1d);
	printf("%d\n", dev->read(0x0d));
}
