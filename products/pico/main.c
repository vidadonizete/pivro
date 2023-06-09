#include <pico/stdlib.h>

#include <pivro/display.h>

#include <stdlib.h>

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320
#define SCREEN_TOTAL_PIXELS SCREEN_WIDTH *SCREEN_HEIGHT
#define BUFFER_SIZE SCREEN_TOTAL_PIXELS * 2

static uint8_t buffer[BUFFER_SIZE];

struct square_t
{
    int16_t x;
    int16_t y;
    int16_t w;
    int16_t h;
    int8_t xVelocity;
    int8_t yVelocity;
    uint16_t color;
};

static void inline draw_rectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{
    for (int i = y * SCREEN_WIDTH * 2; i < (SCREEN_WIDTH * y * 2) + (h * SCREEN_WIDTH * 2); i += SCREEN_WIDTH * 2)
    {
        for (int j = x * 2; j < (x * 2) + (w * 2); j += 2)
        {
            buffer[i + j] = color >> 8;
            buffer[i + j + 1] = color;
        }
    }
}

void update(struct square_t player[], uint playerCount)
{
    for (int i = 0; i < playerCount; i++)
    {
        player[i].x += player[i].xVelocity;
        player[i].y += player[i].yVelocity;

        if (player[i].x <= 0)
        {
            player[i].x = 0;
            player[i].xVelocity = -player[i].xVelocity;
        }

        if (player[i].x >= SCREEN_WIDTH - player[i].w)
        {
            player[i].x = SCREEN_WIDTH - player[i].w;
            player[i].xVelocity = -player[i].xVelocity;
        }

        if (player[i].y <= 0)
        {
            player[i].y = 0;
            player[i].yVelocity = -player[i].yVelocity;
        }

        if (player[i].y >= SCREEN_HEIGHT - player[i].h)
        {
            player[i].y = SCREEN_HEIGHT - player[i].h;
            player[i].yVelocity = -player[i].yVelocity;
        }
    }
}

static inline void clear_buffer()
{
    for (uint i = 0; i < BUFFER_SIZE; i++)
    {
        buffer[i] = 0x00;
    }
}

int main()
{
    pivro_display_initialize();
    const uint8_t player_count = 50;
    struct square_t players[player_count];

    for (uint8_t i = 0; i < player_count; i++)
    {
        struct square_t *player = players + i;
        player->x = rand() % 209;
        player->y = rand() % 289;
        player->w = 30;
        player->h = 30;
        player->xVelocity = rand() % 4 - 2;
        player->yVelocity = rand() % 4 - 2;

        if (player->xVelocity == 0 && player->yVelocity == 0)
        {
            player->xVelocity = 3;
            player->yVelocity = 3;
        }

        player->color = 0xFFF;
    }

    while (1)
    {
        update(players, player_count);
        clear_buffer();
        for (int i = 0; i < player_count; i++)
        {
            draw_rectangle(players[i].x, players[i].y, players[i].w, players[i].h, players[i].color);
        }
        pivro_display_draw_buffer(buffer, BUFFER_SIZE);
    }
    pivro_display_terminate();
}