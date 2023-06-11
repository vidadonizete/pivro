#include <pivro/display.h>

#include <ili9341/display.h>

void pivro_display_initialize(
    uint16_t width,
    uint16_t height)
{
    ili9341_display_initialize(
        width,
        height);
}

void pivro_display_resize(
    uint16_t x1,
    uint16_t x2,
    uint16_t y1,
    uint16_t y2)
{
    ili9341_display_resize(x1, x2, y1, y2);
}

void pivro_display_draw_buffer(
    uint16_t *buffer,
    size_t size)
{
    ili9341_display_draw_buffer(buffer, size);
}

bool pivro_display_tick(size_t ms)
{
    return true;
}

void pivro_display_terminate()
{
    ili9341_display_terminate();
}
