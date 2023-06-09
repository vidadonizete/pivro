#ifndef _PIVRO_DISPLAY_H_
#define _PIVRO_DISPLAY_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

void pivro_display_initialize(
    uint16_t _width,
    uint16_t _height);

void pivro_display_resize(
    uint16_t _x1,
    uint16_t _x2,
    uint16_t _y1,
    uint16_t _y2);

void pivro_display_draw_buffer(
    uint16_t *_buffer,
    size_t _size);

bool pivro_display_tick(size_t _ms);

void pivro_display_terminate();

#endif //_PIVRO_DISPLAY_H_