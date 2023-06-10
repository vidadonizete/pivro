#ifndef _ILI9341_HAL_DISPLAY_H_
#define _ILI9341_HAL_DISPLAY_H_

#include <stdint.h>
#include <stddef.h>

void ili9341_hal_display_initialize();

void ili9341_hal_display_write_command(
    uint8_t _cmd);

void ili9341_hal_display_write_data(
    uint8_t *_data,
    size_t _size);

void ili9341_hal_display_write_data_byte(
    uint8_t _data);

void ili9341_hal_display_write_data_short(
    uint16_t _data);

void ili9341_hal_display_draw_buffer(
    uint16_t *_buffer,
    size_t _size);

void ili9341_hal_display_terminate();

#endif //_ILI9341_HAL_DISPLAY_H_