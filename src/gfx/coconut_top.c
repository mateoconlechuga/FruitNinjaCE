// convpng v6.8
#include <stdint.h>
#include "logo_gfx.h"

// 8 bpp image
uint8_t coconut_top_data[1026] = {
 32,32,  // width,height
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFD,0xFD,0xFD,0xFD,0x0A,0xFD,0xFD,0xFD,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0xFD,0xFD,0xFD,0xF9,0xF9,0xFB,0x50,0xFB,0xFB,0xF9,0xF9,0xF9,0xFD,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFD,0xFD,0xF9,0xF9,0x20,0xF9,0xF9,0xFB,0xFB,0xFB,0xFB,0xF9,0xF9,0xF9,0xF9,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x50,0xFB,0xF9,0xFD,0xF9,0xF9,0xF9,0xF9,0xF9,0xFB,0xFB,0xFB,0x78,0x78,0xF9,0xF9,0xF9,0xF9,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0xFB,0x50,0x20,0xFD,0xF9,0xF9,0xF9,0xFD,0xFD,0xFD,0xF9,0xF9,0x78,0xF9,0xFB,0xFB,0xFB,0x20,0x20,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0xF9,0xFB,0xFB,0xF9,0xFD,0xF9,0xF9,0x20,0xFD,0x5E,0x20,0xFB,0xF9,0x20,0xF9,0xF9,0xF9,0xFB,0x50,0xF9,0xF9,0x0A,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x0A,0xFD,0xFD,0xFD,0xFD,0xF9,0xF9,0x0A,0x0A,0x0A,0x39,0xF9,0xFB,0xFB,0xFB,0x20,0xF9,0xF9,0xF9,0xF9,0x50,0xF9,0xF9,0x20,0xFD,0x00,0x00,0x00,0x00,
 0x00,0x00,0x0A,0x0A,0xF9,0xF9,0xF9,0xFD,0xF9,0x20,0xB2,0x0A,0x0A,0x0A,0xF9,0xFB,0xFB,0xFB,0xF9,0xF9,0x0A,0x0A,0xFB,0x0A,0x0A,0xF9,0xF9,0xF9,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0xFD,0xF9,0xFB,0x50,0xFB,0xFB,0xFB,0x0A,0xFB,0x7F,0xFD,0xF9,0xFB,0xFB,0xFB,0xF9,0xFB,0x0A,0x78,0x78,0x0A,0xFB,0x0A,0xFB,0xF9,0xF9,0x00,0x00,0x00,
 0x00,0x00,0x00,0xFD,0xF9,0xFB,0xFB,0xF9,0xFD,0xFD,0xFD,0xFD,0x0A,0xFD,0x20,0xF9,0x0A,0x0A,0x0A,0x0C,0x0C,0x0C,0x0C,0x6A,0x5A,0x0C,0x0A,0x0A,0x0A,0x00,0x00,0x00,
 0x00,0x00,0xF9,0xF9,0xF9,0xF9,0xF9,0xFB,0xF9,0xF9,0x0A,0x0A,0x39,0xFD,0x0A,0xF9,0x0A,0x0C,0x5A,0x5A,0x80,0x5A,0x6A,0x0C,0x6A,0x0C,0x0C,0x0A,0xF9,0x00,0x00,0x00,
 0x00,0x00,0xF9,0xF9,0xF9,0xF9,0x7F,0x5E,0x5E,0x40,0xFD,0x0A,0x0A,0x0A,0xF9,0x0C,0x5A,0x5A,0x0C,0x0C,0x0C,0x0C,0x0C,0x5A,0x6A,0x42,0x0C,0x0A,0x0A,0x00,0x00,0x00,
 0x00,0x00,0x20,0xF9,0xF9,0xF9,0x5E,0x5E,0x40,0xF9,0x0A,0xF9,0x78,0x78,0x5A,0x6A,0x0C,0x0C,0x42,0x42,0x0C,0x0C,0x0C,0x42,0x0C,0x6A,0x0C,0x0A,0x0A,0x00,0x00,0x00,
 0x00,0x00,0xFD,0xFD,0xFD,0xF9,0x40,0x0A,0x40,0x0A,0x0A,0x0C,0x5A,0x0C,0x0C,0x0C,0x42,0x42,0x42,0x42,0x42,0x42,0x6A,0xCC,0x0C,0x5A,0x0C,0x0A,0x00,0x00,0x00,0x00,
 0x00,0x00,0xF9,0xF9,0xF9,0xF9,0x40,0x40,0x0A,0x0A,0x0C,0x5A,0x5A,0x0C,0x42,0x42,0x42,0x6A,0x80,0x80,0x80,0xA6,0x0C,0xA6,0xCC,0x0C,0x0C,0x0A,0x00,0x00,0x00,0x00,
 0x00,0x78,0x78,0xF9,0x20,0xF9,0x5E,0xFB,0x0A,0x0C,0x6A,0x0C,0x0C,0x42,0x42,0x6A,0x0C,0x42,0x0C,0x42,0xE8,0x5A,0x80,0x6A,0x0C,0x0C,0xFB,0xF9,0x00,0x00,0x00,0x00,
 0x00,0x00,0xF9,0x20,0x20,0x20,0x0A,0x0A,0x0C,0x0C,0x80,0x0C,0x42,0x80,0x42,0x0C,0x6A,0x6A,0x42,0xE8,0xA6,0x5A,0x0C,0x0C,0x0C,0x0A,0x0A,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0xFD,0xFD,0xFD,0x0A,0x78,0x0C,0x0C,0x0C,0x0C,0x42,0x80,0x80,0x6A,0x6A,0x6A,0xCC,0xA6,0x42,0x5A,0x0C,0x0C,0x0C,0x0A,0xFB,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0xFD,0x0A,0xFB,0x0C,0x0C,0x5A,0x0C,0x0C,0x42,0x42,0x80,0x42,0x42,0xA6,0x42,0x0C,0xA6,0x0C,0x0C,0xF9,0xFB,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0xF9,0x0A,0xFB,0x0C,0x0C,0x80,0x6A,0x5A,0x5A,0x42,0xA6,0x42,0x42,0x42,0x5A,0x80,0x0C,0x0C,0xF9,0x0A,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0xF9,0x0A,0x0A,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x5A,0x0C,0x0C,0x0C,0x0C,0x0C,0xF9,0xFB,0xFB,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0xF9,0xFB,0x0A,0x0C,0x0C,0x0C,0x5A,0x0C,0x6A,0x0C,0x0C,0x0C,0xFB,0x0A,0xF9,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0xFB,0x0A,0x78,0xCC,0xF3,0x00,0x78,0x78,0x0A,0xF9,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFB,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};