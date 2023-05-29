#include <stdio.h>

#include <ili9341/common.h>

int main()
{
    struct ili9341_display_t display = {
        // RST
        .rst = 14,
        // CS
        .cs = 13,
        // SCLK
        .rs = 6,
        // DC
        .wr = 15,
        // MOSI
        .sdi = 7,
    };
    ili9341_initialize(&display);
    ili9341_terminate(&display);

    while (1) {

    }
}