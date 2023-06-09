#ifndef _ILI9341_HAL_DISPLAY_H_
#define _ILI9341_HAL_DISPLAY_H_

#include <stdint.h>
#include <ili9341/display.h>

void ili9341_hal_display_initialize(
    struct ili9341_display_t *_display);

void ili9341_hal_display_write_command(
    struct ili9341_display_t *_display,
    uint8_t _cmd);

void ili9341_hal_display_write_byte(
    struct ili9341_display_t *_display,
    uint8_t *_data,
    uint8_t _size);

void ili9341_hal_display_write_short(
    struct ili9341_display_t *_display,
    uint16_t *_data);

void ili9341_hal_display_terminate(
    struct ili9341_display_t *_display);

#endif //_ILI9341_HAL_DISPLAY_H_