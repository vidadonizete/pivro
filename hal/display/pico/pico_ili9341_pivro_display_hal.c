#include <pivro/display.h>

#include <ili9341/display.h>

void pivro_display_initialize()
{
    ili9341_display_initialize();
}

void pivro_display_draw_buffer(
    uint8_t *buffer,
    size_t size)
{
    ili9341_display_draw_buffer(buffer, size);
}

void pivro_display_terminate()
{
    ili9341_display_terminate();
}
