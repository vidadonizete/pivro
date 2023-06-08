#ifndef _ILI9341_DISPLAY_H_
#define _ILI9341_DISPLAY_H_

#include <stdint.h>

enum ili9341_display_enum
{
    // Command constants from ILI9341 datasheet
    ILI9341_CMD_NOP = 0x00,                      // No-op
    ILI9341_CMD_SWRESET = 0x01,                  // Software reset
    ILI9341_CMD_RDDID = 0x04,                    // Read display ID info
    ILI9341_CMD_RDDST = 0x09,                    // Read display status
    ILI9341_CMD_SLPIN = 0x10,                    // Enter sleep mode
    ILI9341_CMD_SLPOUT = 0x11,                   // Exit sleep mode
    ILI9341_CMD_PTLON = 0x12,                    // Partial mode on
    ILI9341_CMD_NORON = 0x13,                    // Normal display mode on
    ILI9341_CMD_RDMODE = 0x0A,                   // Read display power mode
    ILI9341_CMD_RDMADCTL = 0x0B,                 // Read display MADCTL
    ILI9341_CMD_RDPIXFMT = 0x0C,                 // Read display pixel format
    ILI9341_CMD_RDIMGFMT = 0x0D,                 // Read display image format
    ILI9341_CMD_RDSELFDIAG = 0x0F,               // Read display self-diagnostic
    ILI9341_CMD_INVOFF = 0x20,                   // Display inversion off
    ILI9341_CMD_INVON = 0x21,                    // Display inversion on
    ILI9341_CMD_GAMMASET = 0x26,                 // Gamma set
    ILI9341_CMD_DISPLAY_OFF = 0x28,              // Display off
    ILI9341_CMD_DISPLAY_ON = 0x29,               // Display on
    ILI9341_CMD_SET_COLUMN = 0x2A,               // Column address set
    ILI9341_CMD_SET_PAGE = 0x2B,                 // Page address set
    ILI9341_CMD_WRITE_RAM = 0x2C,                // Memory write
    ILI9341_CMD_READ_RAM = 0x2E,                 // Memory read
    ILI9341_CMD_PTLAR = 0x30,                    // Partial area
    ILI9341_CMD_VSCRDEF = 0x33,                  // Vertical scrolling definition
    ILI9341_CMD_MADCTL = 0x36,                   // Memory access control
    ILI9341_CMD_VSCRSADD = 0x37,                 // Vertical scrolling start address
    ILI9341_CMD_PIXFMT = 0x3A,                   // COLMOD: Pixel format set
    ILI9341_CMD_WRITE_DISPLAY_BRIGHTNESS = 0x51, // Brightness hardware dependent!
    ILI9341_CMD_READ_DISPLAY_BRIGHTNESS = 0x52,
    ILI9341_CMD_WRITE_CTRL_DISPLAY = 0x53,
    ILI9341_CMD_READ_CTRL_DISPLAY = 0x54,
    ILI9341_CMD_WRITE_CABC = 0x55,         // Write Content Adaptive Brightness Control
    ILI9341_CMD_READ_CABC = 0x56,          // Read Content Adaptive Brightness Control
    ILI9341_CMD_WRITE_CABC_MINIMUM = 0x5E, // Write CABC Minimum Brightness
    ILI9341_CMD_READ_CABC_MINIMUM = 0x5F,  // Read CABC Minimum Brightness
    ILI9341_CMD_FRMCTR1 = 0xB1,            // Frame rate control (In normal mode/full colors)
    ILI9341_CMD_FRMCTR2 = 0xB2,            // Frame rate control (In idle mode/8 colors)
    ILI9341_CMD_FRMCTR3 = 0xB3,            // Frame rate control (In partial mode/full colors)
    ILI9341_CMD_INVCTR = 0xB4,             // Display inversion control
    ILI9341_CMD_DFUNCTR = 0xB6,            // Display function control
    ILI9341_CMD_PWCTR1 = 0xC0,             // Power control 1
    ILI9341_CMD_PWCTR2 = 0xC1,             // Power control 2
    ILI9341_CMD_PWCTRA = 0xCB,             // Power control A
    ILI9341_CMD_PWCTRB = 0xCF,             // Power control B
    ILI9341_CMD_VMCTR1 = 0xC5,             // VCOM control 1
    ILI9341_CMD_VMCTR2 = 0xC7,             // VCOM control 2
    ILI9341_CMD_RDID1 = 0xDA,              // Read ID 1
    ILI9341_CMD_RDID2 = 0xDB,              // Read ID 2
    ILI9341_CMD_RDID3 = 0xDC,              // Read ID 3
    ILI9341_CMD_RDID4 = 0xDD,              // Read ID 4
    ILI9341_CMD_GMCTRP1 = 0xE0,            // Positive gamma correction
    ILI9341_CMD_GMCTRN1 = 0xE1,            // Negative gamma correction
    ILI9341_CMD_DTCA = 0xE8,               // Driver timing control A
    ILI9341_CMD_DTCB = 0xEA,               // Driver timing control B
    ILI9341_CMD_POSC = 0xED,               // Power on sequence control
    ILI9341_CMD_ENABLE3G = 0xF2,           // Enable 3 gamma control
    ILI9341_CMD_PUMPRC = 0xF7,             // Pump ratio control
};

struct ili9341_display_t
{
    // RST
    // Reset
    uint8_t rst;
    // CS/SS
    // Chip select
    uint8_t cs;
    // SCLK/SCK
    // Serial clock
    uint8_t rs;
    // D/CX
    // Data / Command register sel
    uint8_t wr;
    // MOSI/TX
    // (master perspective: )
    // Master output slave input
    // (slave perspective: )
    // Serial data input
    uint8_t sdi;
};

void ili9341_display_initialize(struct ili9341_display_t *);

void ili9341_display_terminate(struct ili9341_display_t *);

#endif //_ILI9341_DISPLAY_H_