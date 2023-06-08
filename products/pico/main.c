#include <ili9341/display.h>
#include <pico/stdlib.h>

int main()
{
    gpio_init(28);
    gpio_set_dir(28, 1);
    gpio_put(28, 1);

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
    ili9341_display_initialize(&display);
    ili9341_display_terminate(&display);

    while (1)
    {
    }
}