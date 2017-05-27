#include <unistd.h>
#include "../i2c/lp55231.h"

int main(void) {
  LP55231* leds = new LP55231("/dev/i2c-2");
  leds->setLedRgb(LP55231_LED_1, 0xb0, 0x17, 0x1f); // crimson
  leds->setLedRgb(LP55231_LED_2, 0x94, 0x00, 0xd3); // purple
  leds->setLedRgb(LP55231_LED_3, 0x00, 0xbf, 0xff); // light blue
  sleep(3);
  for (uint8_t i = 0; i < 0xff; i++) {
    leds->setLedRgb(LP55231_LED_1, i, 0x00, 0x00);
    leds->setLedRgb(LP55231_LED_2, 0x00, i, 0x00);
    leds->setLedRgb(LP55231_LED_3, 0x00, 0x00, i);
    usleep(40000);
  }
  leds->setLedOff(LP55231_LED_1);
  leds->setLedOff(LP55231_LED_2);
  leds->setLedOff(LP55231_LED_3);
}
