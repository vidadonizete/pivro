#ifndef ILI9341_HAL_H
#define ILI9341_HAL_H

#include <ili9341/common.h>

void ili9341_hal_initialize(struct ili9341_display_t *);

void ili9341_hal_write_command(uint8_t, struct ili9341_display_t *);

void ili9341_hal_terminate(struct ili9341_display_t *);

#endif