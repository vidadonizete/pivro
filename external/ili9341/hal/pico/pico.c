#include <ili9341/hal.h>

#include <pico/stdlib.h>
#include <hardware/spi.h>

void ili9341_hal_write_command(uint8_t cmd, struct ili9341_display_t *display)
{
    gpio_put(display->wr, 0);
    gpio_put(display->cs, 0);
    static uint8_t src[1];
    src[0] = cmd;
    spi_write_blocking(spi_default, src, 1);
    gpio_put(display->cs, 1);
}

void ili9341_hal_initialize(struct ili9341_display_t *display)
{
    spi_init(spi_default, 40 * 1000 * 1000);

    gpio_set_function(display->rs, GPIO_FUNC_SPI);
    gpio_set_function(display->sdi, GPIO_FUNC_SPI);

#define INIT(gpio, out, value) \
    gpio_init(gpio);           \
    gpio_set_dir(gpio, out);   \
    gpio_put(gpio, value);

    INIT(display->cs, GPIO_OUT, true)
    INIT(display->wr, GPIO_OUT, false)
    INIT(display->rst, GPIO_OUT, true)
}

void ili9341_hal_terminate(struct ili9341_display_t *display)
{
}