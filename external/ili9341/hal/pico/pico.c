#include <pico/stdlib.h>
#include <hardware/spi.h>

#include <ili9341/hal/display.h>

void ili9341_hal_display_initialize(struct ili9341_display_t *display)
{
    spi_init(spi_default, 62500000); //62.5kHz

#define SPI(gpio) gpio_set_function(gpio, GPIO_FUNC_SPI);
    SPI(display->rs)
    SPI(display->sdi)

#define INIT(gpio, out, value) \
    gpio_init(gpio);           \
    gpio_set_dir(gpio, out);   \
    gpio_put(gpio, value);

    INIT(display->cs, GPIO_OUT, true)
    INIT(display->dc, GPIO_OUT, false)
    INIT(display->rst, GPIO_OUT, true)
}

void ili9341_hal_display_write_command(
    struct ili9341_display_t *display,
    uint8_t cmd)
{
    gpio_put(display->cs, 0);
    gpio_put(display->dc, 0);
    spi_write_blocking(spi_default, &cmd, 1);
    gpio_put(display->cs, 1);
}

void ili9341_hal_display_write_byte(
    struct ili9341_display_t *display,
    uint8_t *data,
    uint8_t size)
{
    gpio_put(display->cs, 0);
    gpio_put(display->dc, 1);
    spi_write_blocking(spi_default, data, size);
    gpio_put(display->cs, 1);
}

void ili9341_hal_display_write_short(
    struct ili9341_display_t *display,
    uint16_t *data)
{
    static uint8_t buffer[2];
    buffer[0] = *data >> 8;
    buffer[1] = *data;
    ili9341_hal_display_write_byte(
        display,
        buffer,
        2);
}

void ili9341_hal_display_terminate(struct ili9341_display_t *display)
{
}