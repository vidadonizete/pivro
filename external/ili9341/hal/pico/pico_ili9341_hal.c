#include <pico/stdlib.h>
#include <hardware/spi.h>

#include <ili9341/display.h>

#define SPI_PORT spi_default
#define PIN_MISO 14
#define PIN_CS 13
#define PIN_SCK 6
#define PIN_MOSI 7
#define PIN_DC 15
#define PIN_RST 14
#define PIN_LED 25

static inline void init_spi()
{
    spi_init(SPI_PORT, 62500000);

    gpio_set_function(PIN_MISO, GPIO_FUNC_SPI);
    gpio_set_function(PIN_SCK, GPIO_FUNC_SPI);
    gpio_set_function(PIN_MOSI, GPIO_FUNC_SPI);

    gpio_init(PIN_CS);
    gpio_init(PIN_DC);
    gpio_init(PIN_RST);

    gpio_set_dir(PIN_CS, GPIO_OUT);
    gpio_set_dir(PIN_DC, GPIO_OUT);
    gpio_set_dir(PIN_RST, GPIO_OUT);
    gpio_put(PIN_CS, 1);
    gpio_put(PIN_DC, 0);
    gpio_put(PIN_RST, 0);
}

static inline void reset_display()
{
    gpio_put(PIN_RST, 0);
    gpio_put(PIN_RST, 1);
}

static inline void cs_select()
{
    gpio_put(PIN_CS, 0);
}

static inline void cs_deselect()
{
    gpio_put(PIN_CS, 1);
}

static inline void dc_select()
{
    gpio_put(PIN_DC, 0);
}

static inline void dc_deselect()
{
    gpio_put(PIN_DC, 1);
}

void ili9341_hal_display_initialize()
{
    init_spi();
    reset_display();
}

void ili9341_hal_display_write_command(
    uint8_t cmd)
{
    dc_select();
    cs_select();
    spi_write_blocking(SPI_PORT, &cmd, 1);
    dc_deselect();
    cs_deselect();
}

void ili9341_hal_display_write_data(
    uint8_t *data,
    size_t size)
{
    cs_select();
    dc_deselect();
    spi_write_blocking(SPI_PORT, data, size);
    cs_deselect();
}

void ili9341_hal_display_write_data_byte(
    uint8_t data)
{
    ili9341_hal_display_write_data(&data, 1);
}

void ili9341_hal_display_write_data_short(
    uint16_t data)
{
    static uint8_t buffer[2];
    buffer[0] = data >> 8;
    buffer[1] = data;
    ili9341_hal_display_write_data(buffer, 2);
}

void ili9341_hal_display_initialize_draw_mode()
{
    cs_select();
    dc_deselect();
}

void ili9341_hal_display_draw_buffer(
    uint8_t *buffer,
    size_t size)
{
    spi_write_blocking(SPI_PORT, buffer, size);
}

void ili9341_hal_display_terminate()
{
}