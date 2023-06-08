#ifndef _ILI9341_HAL_DISPLAY_H_
#define _ILI9341_HAL_DISPLAY_H_

#include <stdint.h>
#include <ili9341/display.h>

void ili9341_hal_display_initialize(struct ili9341_display_t *);

void ili9341_hal_display_write_command(uint8_t, struct ili9341_display_t *);

void ili9341_hal_display_sleep_ms(uint32_t ms);

void ili9341_hal_display_terminate(struct ili9341_display_t *);

#endif //_ILI9341_HAL_DISPLAY_H_