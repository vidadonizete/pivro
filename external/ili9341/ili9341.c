#include <stdint.h>

#include <ili9341/display.h>
#include <ili9341/hal/display.h>
#include <ili9341/hal/sleep.h>

static uint8_t INIT_DISPLAY_DATA[] = {
    0xEF, 3,
    0x03, 0x80, 0x02,
    ILI9341_CMD_SWRESET, 0,
    ILI9341_CMD_PWCTRB, 3,
    0x00, 0xC1, 0x30,
    ILI9341_CMD_POSC, 4,
    0x64, 0x03, 0x12, 0x81,
    ILI9341_CMD_DTCA, 3,
    0x85, 0x00, 0x78,
    ILI9341_CMD_PWCTRA, 5,
    0x39, 0x2C, 0x00, 0x34, 0x02,
    ILI9341_CMD_PUMPRC, 1,
    0x20,
    ILI9341_CMD_DTCB, 2,
    0x00, 0x00,
    ILI9341_CMD_PWCTR1, 1, // Power control VRH[5:0]
    0x23,
    ILI9341_CMD_PWCTR2, 1, // Power control SAP[2:0];BT[3:0]
    0x10,
    ILI9341_CMD_VMCTR1, 2, // VCM control
    0x3E, 0x28,
    ILI9341_CMD_VMCTR2, 1, // VCM control2
    0x86,
    ILI9341_CMD_MADCTL, 1, // Memory Access Control
    0x48,
    ILI9341_CMD_VSCRSADD, 1, // Vertical scroll zero
    0x00,
    ILI9341_CMD_PIXFMT, 1,
    0x55,
    ILI9341_CMD_FRMCTR1, 2,
    0x00, 0x1F,
    ILI9341_CMD_DFUNCTR, 3, // Display Function Control
    0x08, 0x82, 0x27,
    ILI9341_CMD_ENABLE3G, 1, // 3Gamma Functiohardware_sleep_msn Disable
    0x00,
    ILI9341_CMD_GAMMASET, 1, // Gamma curve selected
    0x01,
    ILI9341_CMD_GMCTRP1, 15, // Set Gamma
    0x0F, 0x31, 0x2B, 0x0C, 0x0E, 0x08, 0x4E, 0xF1,
    0x37, 0x07, 0x10, 0x03, 0x0E, 0x09, 0x00,
    ILI9341_CMD_GMCTRN1, 15, // Set Gamma
    0x00, 0x0E, 0x14, 0x03, 0x11, 0x07, 0x31, 0xC1,
    0x48, 0x08, 0x0F, 0x0C, 0x31, 0x36, 0x0F,
    ILI9341_CMD_SLPOUT, 0,     // Exit Sleep
    ILI9341_CMD_DISPLAY_ON, 0, // Display on
    ILI9341_CMD_NORON, 0,
    ILI9341_CMD_NOP           // End of list
};

void ili9341_display_initialize()
{
    ili9341_hal_display_initialize();
    uint8_t *ptr = INIT_DISPLAY_DATA;
    uint8_t cmd, size;
    while ( (cmd = *ptr++) > 0)
    {
        size = *ptr++;
        ili9341_hal_display_write_command(cmd);
        if (size)
        {
            ili9341_hal_display_write_data(ptr, size);
        }
        ili9341_hal_sleep_ms(100);
        ptr += size;
    }
}

void ili9341_setup_window(
    uint16_t x1,
    uint16_t x2,
    uint16_t y1,
    uint16_t y2)
{
    ili9341_hal_display_write_command(ILI9341_CMD_SET_COLUMN);
    ili9341_hal_display_write_data_short(x1);
    ili9341_hal_display_write_data_short(x2);

    ili9341_hal_display_write_command(ILI9341_CMD_SET_PAGE);
    ili9341_hal_display_write_data_short(y1);
    ili9341_hal_display_write_data_short(y2);
}

void ili9341_display_draw_buffer(
    uint16_t* buffer,
    size_t size)
{
    ili9341_hal_display_write_command(ILI9341_CMD_WRITE_RAM);
    ili9341_hal_display_draw_buffer(buffer, size);
}

void ili9341_display_terminate()
{
    ili9341_hal_display_terminate();
}