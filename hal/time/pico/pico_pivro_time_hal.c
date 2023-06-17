#include <pico/stdlib.h>

#include <pivro/time.h>

uint64_t pivro_time_us_64()
{
    return time_us_64();
}