#ifndef _ILI9341_TOUCH_H_
#define _ILI9341_TOUCH_H_

#include <stdint.h>

struct ili9341_touch_t
{
    // SCLK/SCK
    uint8_t sclk;
    // CS/SS
    uint8_t cs;
    // SDI
    uint8_t mosi;
    // SDO
    uint8_t miso;
};

#endif //_ILI9341_TOUCH_H_