#include <ili9341/hal/sleep.h>
#include <pico/stdlib.h>

void ili9341_hal_sleep_ms(uint32_t ms)
{
    sleep_ms(ms);
}