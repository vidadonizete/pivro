#include <stdint.h>

#include <ili9341/display.h>
#include <ili9341/hal/display.h>

#include <hardware/sleep.h>

static uint8_t INIT_DISPLAY_DATA[] = {
    0xEF, 3, 0x03, 0x80, 0x02,
    ILI9341_CMD_SWRESET, 0,
    ILI9341_CMD_PWCTRB, 3, 0x00, 0xC1, 0x30,
    ILI9341_CMD_POSC, 4, 0x64, 0x03, 0x12, 0x81,
    ILI9341_CMD_DTCA, 3, 0x85, 0x00, 0x78,
    ILI9341_CMD_PWCTRA, 5, 0x39, 0x2C, 0x00, 0x34, 0x02,
    ILI9341_CMD_PUMPRC, 1, 0x20,
    ILI9341_CMD_DTCB, 2, 0x00, 0x00,
    ILI9341_CMD_PWCTR1, 1, 0x23,       // Power control VRH[5:0]
    ILI9341_CMD_PWCTR2, 1, 0x10,       // Power control SAP[2:0];BT[3:0]
    ILI9341_CMD_VMCTR1, 2, 0x3E, 0x28, // VCM control
    ILI9341_CMD_VMCTR2, 1, 0x86,       // VCM control2
    ILI9341_CMD_MADCTL, 1, 0x48,       // Memory Access Control
    // ILI9341_CMD_VSCRSADD,   1, 0x00,                        // Vertical scroll zero
    ILI9341_CMD_PIXFMT, 1, 0x55,
    ILI9341_CMD_FRMCTR1, 2, 0x00, 0x1F,
    ILI9341_CMD_DFUNCTR, 3, 0x08, 0x82, 0x27,        // Display Function Control
    ILI9341_CMD_ENABLE3G, 1, 0x00,                   // 3Gamma Function Disable
    ILI9341_CMD_GAMMASET, 1, 0x01,                   // Gamma curve selected
    ILI9341_CMD_GMCTRP1, 15, 0x0F, 0x31, 0x2B, 0x0C, // Set Gamma
    0x0E, 0x08, 0x4E, 0xF1,
    0x37, 0x07, 0x10, 0x03,
    0x0E, 0x09, 0x00,
    ILI9341_CMD_GMCTRN1, 15, 0x00, 0x0E, 0x14,
    0x03, 0x11, 0x07, // Set Gamma
    0x31, 0xC1, 0x48,
    0x08, 0x0F, 0x0C,
    0x31, 0x36, 0x0F,
    ILI9341_CMD_SLPOUT, 0,     // Exit Sleep
    ILI9341_CMD_DISPLAY_ON, 0, // Display on
    ILI9341_CMD_NORON, 0,
    ILI9341_CMD_NOP // End of list
};

void ili9341_display_initialize(struct ili9341_display_t *display)
{
    ili9341_hal_display_initialize(display);
    uint8_t *ptr = INIT_DISPLAY_DATA;
    uint8_t cmd, size;
    while (cmd = *ptr++)
    {
        size = *ptr++;
        ili9341_hal_display_write_command(display, cmd);
        hardware_sleep_ms(100);
        if (size)
        {
            ili9341_hal_display_write_byte(display, ptr, size);
            hardware_sleep_ms(100);
        }
        ptr += size;
    }
}

void ili9341_display_reset(struct ili9341_display_t *display)
{
    ili9341_hal_display_write_command(display, ILI9341_CMD_SWRESET);
}

void ili9341_display_draw_pixel(
    struct ili9341_display_t *display,
    uint8_t x,
    uint8_t y,
    uint16_t color)
{
    ili9341_hal_display_write_command(display, ILI9341_CMD_SET_COLUMN);
    ili9341_hal_display_write_byte(display, &x, 1);

    ili9341_hal_display_write_command(display, ILI9341_CMD_SET_PAGE);
    ili9341_hal_display_write_byte(display, &y, 1);

    ili9341_hal_display_write_command(
        display,
        ILI9341_CMD_WRITE_RAM);

    ili9341_hal_display_write_short(
        display,
        &color);
}

void ili9341_display_terminate(struct ili9341_display_t *display)
{
    ili9341_hal_display_terminate(display);
}