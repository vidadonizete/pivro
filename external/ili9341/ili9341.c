#include <ili9341/display.h>
#include <ili9341/hal/display.h>

#include <hardware/sleep.h>

void ili9341_display_initialize(struct ili9341_display_t *display)
{
    ili9341_hal_display_initialize(display);

    ili9341_hal_display_write_command(ILI9341_CMD_SWRESET, display);
    hardware_sleep_ms(100);
    ili9341_hal_display_write_command(ILI9341_CMD_SLPOUT, display);
    hardware_sleep_ms(100);
    ili9341_hal_display_write_command(ILI9341_CMD_DISPLAY_ON, display);
    hardware_sleep_ms(100);
}

void ili9341_display_terminate(struct ili9341_display_t *display)
{
    ili9341_hal_display_terminate(display);
}