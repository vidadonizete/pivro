#include <pico/stdlib.h>

#include <ili9341/common.h>
#include <ili9341/hal.h>

void ili9341_initialize(struct ili9341_display_t *display)
{
    ili9341_hal_initialize(display);

    ili9341_hal_write_command(ILI9341_CMD_SWRESET, display);
    sleep_ms(100);
    ili9341_hal_write_command(ILI9341_CMD_SLPOUT, display);
    sleep_ms(100);
    ili9341_hal_write_command(ILI9341_CMD_DISPLAY_ON, display);
    sleep_ms(100);
}

void ili9341_terminate(struct ili9341_display_t *display)
{
    ili9341_hal_terminate(display);
}