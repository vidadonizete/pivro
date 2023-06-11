#include <stdlib.h>

#include <pivro/display.h>

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

int main()
{
    pivro_display_initialize(
        SCREEN_WIDTH,
        SCREEN_HEIGHT);
    while (1)
    {
        pivro_display_tick();
    }
    pivro_display_terminate();
}