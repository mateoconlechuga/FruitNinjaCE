// convpng v6.8
#include <stdint.h>
#include "logo_gfx.h"

// 8 bpp image
uint8_t grapes_data[1026] = {
 32,32,  // width,height
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0xF9,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x16,0x16,0xF9,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0xF9,0xF9,0xF9,0x00,0x00,0x00,0x00,0x00,0xF9,0x16,0xF9,0xF9,0x16,0xF9,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x19,0x19,0x19,0x19,0xF9,0xF9,0x00,0x00,0x00,0x00,0xF9,0x16,0xF9,0xF9,0x16,0xF9,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x19,0x0B,0x0B,0x19,0x19,0x19,0x19,0xF9,0xF9,0xF9,0xF9,0xF9,0xF9,0xF9,0x16,0x16,0xF9,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x19,0x0B,0x0B,0x19,0x0B,0x0B,0x0B,0x0B,0x19,0x16,0x16,0x16,0x16,0x16,0x16,0xF9,0xF9,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x19,0x0B,0x19,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x19,0x16,0xF9,0xF9,0xF9,0xF9,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x19,0x0B,0x19,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x19,0x19,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x19,0x19,0x19,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x19,0x0B,0x19,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x19,0x0B,0x0B,0x19,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x19,0x0B,0x0B,0x19,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x19,0x0B,0x0B,0x19,0x0B,0x19,0x0B,0x0B,0x0B,0x0B,0x19,0x0B,0x0B,0x0B,0x19,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x19,0x0B,0x19,0x0B,0x0B,0x0B,0x19,0x19,0x19,0x19,0x0B,0x0B,0x0B,0x0B,0x19,0x19,0xF9,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x19,0x0B,0x19,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x19,0x0B,0x0B,0x0B,0x0B,0x19,0x19,0xF9,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x19,0x19,0x19,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x19,0x0B,0x0B,0x0B,0x19,0x0B,0x19,0xF9,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x19,0x0B,0x0B,0x19,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x19,0x19,0x19,0x19,0x0B,0x0B,0x19,0xF9,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x19,0x0B,0x0B,0x0B,0x0B,0x19,0x0B,0x0B,0x0B,0x0B,0x19,0x0B,0x19,0x0B,0x0B,0x0B,0x19,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x19,0x0B,0x0B,0x0B,0x0B,0x0B,0x19,0x19,0x19,0x19,0x0B,0x0B,0x19,0x19,0x19,0x19,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x19,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x19,0x0B,0x0B,0x0B,0x19,0xF9,0xF9,0xF9,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x19,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x19,0x19,0x19,0x19,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x19,0x0B,0x0B,0x0B,0x0B,0x19,0xF9,0xF9,0xF9,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x19,0x19,0x19,0x19,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0xF9,0xF9,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
