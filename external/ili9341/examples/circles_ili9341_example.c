#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <pico/stdlib.h>

#include <ili9341/display.h>

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320
#define BUFFER_SIZE SCREEN_WIDTH *SCREEN_HEIGHT

static uint16_t buffer[BUFFER_SIZE];

struct point_2
{
    int16_t x;
    int16_t y;
};

struct circle_t
{
    struct point_2 position;
    struct point_2 direction;
    uint16_t radius;
    uint16_t color;
};

// h^2 = c^2 + c^2;
static inline uint8_t intersect(
    uint16_t x1,
    uint16_t x2,
    uint16_t y1,
    uint16_t y2,
    uint8_t radius)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) <= radius;
}

static inline void draw_circle(struct circle_t *circle)
{
    uint16_t radius = circle->radius;
    for (uint16_t y = circle->position.y - radius; y < (circle->position.y + radius) && y < SCREEN_HEIGHT; y++)
    {
        for (uint16_t x = circle->position.x - radius; x < (circle->position.x + radius) && x < SCREEN_WIDTH; x++)
        {
            if (intersect(x, circle->position.x, y, circle->position.y, radius)) // heavy as fuck
            {
                buffer[y * SCREEN_WIDTH + x] = circle->color;
            }
        }
    }
}

#define CIRCLES 30

void main()
{
    ili9341_display_initialize(
        SCREEN_WIDTH,
        SCREEN_HEIGHT);

    struct circle_t circles[CIRCLES];

    for (uint8_t i = 0; i < CIRCLES; i++)
    {
        struct circle_t *circle = circles + i;
        circle->position.x = rand() % SCREEN_WIDTH;
        circle->position.y = rand() % SCREEN_HEIGHT;
        circle->direction.x = rand() % 10 + 2;
        circle->direction.y = rand() % 10 + 2;
        circle->radius = rand() % 6 + 2; // a bigger radius will cause more intercept() calls
        circle->color = rand();
    }

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        for (uint8_t i = 0; i < CIRCLES; i++)
        {
            struct circle_t *circle = circles + i;
            if ((circle->position.x + circle->radius) > SCREEN_WIDTH || (circle->position.x - circle->radius) < 0)
            {
                circle->direction.x *= -1;
            }
            if ((circle->position.y + circle->radius) > SCREEN_HEIGHT || (circle->position.y - circle->radius) < 0)
            {
                circle->direction.y *= -1;
            }
            circle->position.x += circle->direction.x;
            circle->position.y += circle->direction.y;
            draw_circle(circle);
        }
        ili9341_display_draw_buffer(buffer, BUFFER_SIZE);
    }
    ili9341_display_terminate();
}