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
    pivro_setup_window(
        0, SCREEN_WIDTH - 1,
        0, SCREEN_HEIGHT - 1
    );

    uint16_t color = 0;
    while (1)
    {
        for (size_t i = 0; i < SCREEN_HEIGHT; i++, color++)
        {
            uint16_t* row = buffer + i * SCREEN_WIDTH;
            for (size_t j = 0; j < SCREEN_WIDTH; j++)
            {
                row[j] = color;
            }
        }
        pivro_display_draw_buffer(buffer, BUFFER_SIZE);
        sleep_ms(1000);
    }
    pivro_display_terminate();
}