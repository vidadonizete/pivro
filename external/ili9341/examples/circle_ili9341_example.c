#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>

#include <pico/stdlib.h>

#include <ili9341/display.h>

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320
#define BUFFER_SIZE SCREEN_WIDTH *SCREEN_HEIGHT

static uint16_t buffer[BUFFER_SIZE];

struct vector_t
{
    int16_t x;
    int16_t y;
};

struct circle_t
{
    struct vector_t position;
    struct vector_t direction;
    uint16_t radius;
};
// h^2 = c^2 + c^2;
static inline uint8_t intersect(
    uint16_t x1,
    uint16_t x2,
    uint16_t y1,
    uint16_t y2,
    uint8_t radius)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) > radius;
}

void main()
{
    ili9341_display_initialize();
    ili9341_setup_window(
        0, SCREEN_WIDTH - 1,
        0, SCREEN_HEIGHT - 1);

    struct circle_t circle = {
        .position = {
            .x = 10,
            .y = 10,
        },
        .direction = {
            .x = 30,
            .y = 30,
        },
        .radius = 10,
    };

    while (1)
    {
        circle.position.x += circle.direction.x;
        circle.position.y += circle.direction.y;

        for (size_t i = 0; i < SCREEN_HEIGHT; i++)
        {
            uint16_t *row = buffer + i * SCREEN_WIDTH;
            for (size_t j = 0; j < SCREEN_WIDTH; j++)
            {
                if (intersect(j, circle.position.x, i, circle.position.y, circle.radius))
                {
                    row[j] = 0x0;
                }
                else
                {
                    row[j] = 0xFFFF;
                }
            }
        }
        ili9341_display_draw_buffer(buffer, BUFFER_SIZE);
        if ((circle.position.x + circle.radius) > SCREEN_WIDTH || (circle.position.x - circle.radius) < 0)
        {
            circle.direction.x *= -1;
        }
        if ((circle.position.y + circle.radius) > SCREEN_HEIGHT || (circle.position.y - circle.radius) < 0)
        {
            circle.direction.y *= -1;
        }
    }
    ili9341_display_terminate();
}