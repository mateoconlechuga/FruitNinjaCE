// convpng v6.8
#include <stdint.h>
#include "logo_gfx.h"

// 8 bpp image
uint8_t bomb_data[1026] = {
 32,32,  // width,height
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x17,0x1A,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x17,0x1A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1A,0x17,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x1E,0x1E,0x17,0x1E,0x1E,0x1E,0x1E,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x1E,0x08,0x08,0x08,0x1A,0x08,0x08,0x08,0x08,0x1E,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x1E,0x08,0x08,0x08,0x08,0x17,0x17,0x17,0x08,0x08,0x08,0x08,0x08,0x1E,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x08,0x1E,0x1E,0x08,0x08,0x08,0x08,0x17,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x08,0x08,0x08,0x1E,0x08,0x08,0x08,0x1E,0x1E,0x1E,0x1E,0x1E,0x08,0x08,0x08,0x1E,0x1E,0x08,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x1E,0x08,0x08,0x08,0x08,0x08,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x11,0x08,0x08,0x1E,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x1E,0x08,0x08,0x08,0x11,0x08,0x1E,0x1E,0x1E,0x08,0x08,0x08,0x08,0x08,0x1E,0x1E,0x1E,0x11,0x08,0x08,0x08,0x1E,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x1E,0x08,0x08,0x08,0x08,0x08,0x11,0x1E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x11,0x1E,0x08,0x08,0x08,0x08,0x1E,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x1E,0x08,0x08,0x08,0x08,0x1E,0x1E,0x11,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x11,0x08,0x1E,0x1E,0x08,0x08,0x08,0x1E,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x1E,0x08,0x08,0x08,0x08,0x08,0x1E,0x1E,0x08,0x11,0x08,0x08,0x08,0x08,0x08,0x08,0x11,0x08,0x08,0x1E,0x1E,0x08,0x08,0x08,0x08,0x1E,0x00,0x00,0x00,
 0x00,0x00,0x00,0x1E,0x08,0x08,0x08,0x08,0x1E,0x1E,0x08,0x08,0x08,0x11,0x08,0x08,0x08,0x08,0x11,0x08,0x08,0x08,0x08,0x1E,0x1E,0x08,0x08,0x08,0x1E,0x00,0x00,0x00,
 0x00,0x00,0x00,0x1E,0x08,0x08,0x08,0x08,0x1E,0x1E,0x08,0x08,0x08,0x11,0x08,0x08,0x08,0x11,0x08,0x08,0x08,0x08,0x08,0x1E,0x1E,0x08,0x08,0x08,0x1E,0x00,0x00,0x00,
 0x00,0x00,0x00,0x1E,0x08,0x08,0x08,0x08,0x1E,0x1E,0x08,0x08,0x08,0x08,0x11,0x08,0x11,0x08,0x08,0x08,0x08,0x08,0x08,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x00,0x00,0x00,
 0x00,0x00,0x00,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x08,0x08,0x08,0x08,0x08,0x11,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x1E,0x1E,0x08,0x08,0x08,0x1E,0x00,0x00,0x00,
 0x00,0x00,0x00,0x1E,0x1E,0x08,0x08,0x08,0x1E,0x1E,0x08,0x08,0x08,0x08,0x11,0x08,0x11,0x08,0x08,0x08,0x08,0x08,0x08,0x1E,0x1E,0x08,0x08,0x08,0x1E,0x00,0x00,0x00,
 0x00,0x00,0x00,0x1E,0x08,0x08,0x08,0x08,0x08,0x1E,0x1E,0x08,0x08,0x11,0x08,0x08,0x08,0x11,0x08,0x08,0x08,0x08,0x1E,0x1E,0x08,0x08,0x08,0x08,0x1E,0x00,0x00,0x00,
 0x00,0x00,0x00,0x1E,0x08,0x08,0x08,0x08,0x08,0x1E,0x1E,0x08,0x11,0x08,0x08,0x08,0x08,0x08,0x11,0x08,0x08,0x08,0x1E,0x1E,0x08,0x08,0x08,0x08,0x1E,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x1E,0x08,0x08,0x08,0x08,0x08,0x1E,0x11,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x11,0x08,0x1E,0x1E,0x08,0x08,0x08,0x08,0x1E,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x1E,0x08,0x08,0x08,0x08,0x08,0x11,0x1E,0x1E,0x1E,0x08,0x08,0x08,0x08,0x08,0x11,0x1E,0x1E,0x1E,0x1E,0x1E,0x08,0x08,0x1E,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x1E,0x08,0x08,0x08,0x11,0x08,0x08,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x11,0x08,0x08,0x08,0x1E,0x1E,0x1E,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x1E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x1E,0x1E,0x1E,0x1E,0x1E,0x08,0x08,0x11,0x08,0x08,0x08,0x08,0x1E,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x08,0x08,0x08,0x08,0x08,0x1E,0x1E,0x1E,0x08,0x08,0x08,0x1E,0x08,0x08,0x08,0x11,0x08,0x08,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x08,0x08,0x1E,0x1E,0x1E,0x08,0x08,0x08,0x08,0x08,0x1E,0x1E,0x08,0x08,0x08,0x08,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x1E,0x1E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x1E,0x08,0x08,0x1E,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x1E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x1E,0x1E,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
