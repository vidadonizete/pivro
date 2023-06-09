#ifndef _PIVRO_DISPLAY_H_
#define _PIVRO_DISPLAY_H_

#include <stdint.h>
#include <stddef.h>

void pivro_display_initialize();

void pivro_display_draw_buffer(
    uint8_t* _buffer, 
    size_t _size);

void pivro_display_terminate();

#endif //_PIVRO_DISPLAY_H_