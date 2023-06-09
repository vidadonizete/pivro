#include <pico/stdlib.h>

#include <ili9341/display.h>
#include <ili9341/hal/display.h>

int main()
{
    struct ili9341_display_t *display = &(struct ili9341_display_t){
        // RST
        .rst = 14,
        // CS
        .cs = 13,
        // SCLK
        .rs = 6,
        // DC
        .dc = 15,
        // MOSI
        .sdi = 7,
    };
    ili9341_display_initialize(display);
    ili9341_display_terminate(display);

    while (1)
    {
    }
}