#ifndef _PIVRO_DISPLAY_H_
#define _PIVRO_DISPLAY_H_

#include <stdint.h>
#include <stddef.h>

void pivro_display_initialize();

void pivro_setup_window(
    uint16_t _x1,
    uint16_t _x2,
    uint16_t _y1,
    uint16_t _y2);

void pivro_display_draw_buffer(
    uint16_t *_buffer,
    size_t _size);

void pivro_display_terminate();

#endif //_PIVRO_DISPLAY_H_