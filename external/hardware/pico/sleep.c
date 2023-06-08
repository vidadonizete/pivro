#include <hardware/sleep.h>

#include <pico/stdlib.h>

void hardware_sleep_ms(uint32_t ms)
{
    sleep_ms(ms);
}