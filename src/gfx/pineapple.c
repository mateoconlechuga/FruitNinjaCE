// convpng v6.8
#include <stdint.h>
#include "logo_gfx.h"

// 8 bpp image
uint8_t pineapple_data[1026] = {
 32,32,  // width,height
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x00,0x00,0xF9,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0xF9,0x0E,0xF9,0xF9,0x0E,0xF9,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x0E,0xF9,0x0E,0xF9,0x0E,0x0E,0xF9,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x00,0xF9,0x0E,0xF9,0x0E,0x0E,0x0E,0xF9,0x00,0xF9,0xF9,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x0E,0xF9,0x16,0x0E,0x0E,0x0E,0x16,0xF9,0x00,0xF9,0x0E,0x0E,0xF9,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x0E,0x0E,0x16,0x16,0x0E,0x0E,0x0E,0x16,0xF9,0x0E,0x0E,0xF9,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0xF9,0x0E,0x16,0x16,0x32,0x16,0x0E,0x0E,0x16,0x0E,0xF9,0xF9,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x16,0xF9,0x0E,0x16,0x0E,0x16,0x16,0x16,0x0E,0x0E,0x0E,0x0E,0x0E,0xF9,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x16,0x16,0x32,0x16,0x0E,0x0E,0x16,0x32,0x0E,0x0E,0xF9,0xF9,0xF9,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x0E,0x16,0x0E,0x16,0x16,0x32,0x0E,0x0E,0x16,0x16,0x0E,0x0E,0x0E,0xF9,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x16,0x0E,0x0E,0x0E,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0xF9,0xF9,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0xF9,0xF9,0xF9,0x16,0x32,0x0E,0x0E,0x32,0x16,0x16,0x32,0x0E,0x0E,0x0E,0xF9,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0xF9,0x13,0x13,0x11,0x32,0x16,0x16,0x0E,0x32,0x0E,0x0E,0x0E,0x16,0xF9,0xF9,0x0E,0x0E,0xF9,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x13,0x11,0x13,0x13,0x11,0x13,0x32,0x16,0x0E,0x0E,0x0E,0x0E,0x16,0x16,0x16,0xF9,0xF9,0xF9,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x11,0x11,0x31,0x11,0x11,0x31,0x11,0x11,0x32,0x16,0x16,0x32,0x0E,0x0E,0xF9,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x32,0x16,0x16,0x16,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x32,0xF9,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0xF9,0x11,0x11,0x31,0x11,0x11,0x31,0x11,0x11,0x31,0x11,0x11,0x31,0x11,0x11,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0xF9,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0xF9,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0xF9,0x11,0x11,0x31,0x11,0x11,0x31,0x11,0x11,0x31,0x11,0x11,0x31,0x11,0x11,0x31,0x11,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0xF9,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0xF9,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0xF9,0x11,0x31,0x11,0x11,0x31,0x11,0x11,0x31,0x11,0x11,0x31,0x11,0x11,0x31,0x11,0x11,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0xF9,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0xF9,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0xF9,0x31,0x11,0x11,0x31,0x11,0x11,0x31,0x11,0x11,0x31,0x11,0x11,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0xF9,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0x13,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0xF9,0x13,0x11,0x13,0x13,0x11,0x13,0x13,0x11,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0xF9,0x31,0x11,0x11,0x31,0x11,0x11,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0xF9,0x13,0x13,0x11,0x13,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0xF9,0xF9,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
