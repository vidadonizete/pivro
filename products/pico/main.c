#include <stdlib.h>
#include <pico/stdlib.h>
#include <pivro/display.h>

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320
#define BUFFER_SIZE SCREEN_WIDTH *SCREEN_HEIGHT

static uint16_t buffer[BUFFER_SIZE];

int main()
{
    pivro_display_initialize();
    while (1)
    {
        for (size_t i = 0; i < SCREEN_HEIGHT; i++)
        {
            uint16_t* row = buffer + i * SCREEN_WIDTH;
            uint16_t color = rand();
            for (size_t j = 0; j < SCREEN_WIDTH; j++)
            {
                row[j] = color;
            }
        }
        pivro_display_draw_buffer(buffer, BUFFER_SIZE);
        sleep_ms(5000);
    }
    pivro_display_terminate();
}