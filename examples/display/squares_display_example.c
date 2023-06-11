#include <stdlib.h>
#include <string.h>

#include <pivro/display.h>
#include <pivro/time.h>

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320
#define BUFFER_SIZE SCREEN_WIDTH *SCREEN_HEIGHT

static uint16_t buffer[BUFFER_SIZE];

struct point_2
{
    int16_t x;
    int16_t y;
};

struct square_t
{
    struct point_2 position;
    struct point_2 direction;
    uint8_t size;
    uint16_t color;
};

#define SQUARES 30

static inline void draw_square(struct square_t *square)
{

    for (uint16_t i = square->position.y; i < (square->position.y + square->size) && i < SCREEN_HEIGHT; i++)
    {
        for (uint16_t j = square->position.x; j < (square->position.x + square->size) && j < SCREEN_WIDTH; j++)
        {
            buffer[i * SCREEN_WIDTH + j] = square->color;
        }
    }
}

void main()
{
    pivro_display_initialize(
        SCREEN_WIDTH,
        SCREEN_HEIGHT);

    struct square_t squares[SQUARES] = {};

    for (uint8_t i = 0; i < SQUARES; i++)
    {
        struct square_t *square = squares + i;
        square->position.x = rand() % SCREEN_WIDTH;
        square->position.y = rand() % SCREEN_HEIGHT;
        square->color = rand();
        square->size = rand() % 6 + 2;
        square->direction.x = rand() % 10 + 1;
        square->direction.y = rand() % 10 + 1;
    }

    while (pivro_display_tick(0))
    {
        memset(buffer, 0, sizeof(buffer));
        for (uint8_t i = 0; i < SQUARES; i++)
        {
            struct square_t *square = squares + i;

            if ((square->position.x + square->size) > SCREEN_WIDTH || square->position.x < 0)
            {
                square->direction.x *= -1;
            }
            if ((square->position.y + square->size) > SCREEN_HEIGHT || square->position.y < 0)
            {
                square->direction.y *= -1;
            }
            square->position.x += square->direction.x;
            square->position.y += square->direction.y;

            draw_square(square);
        }
        pivro_display_draw_buffer(buffer, BUFFER_SIZE);
    }
    pivro_display_terminate();
}