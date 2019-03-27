// convpng v6.8
#include <stdint.h>
#include "logo_gfx.h"

// 8 bpp image
uint8_t pomegranate_data[1026] = {
 32,32,  // width,height
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x65,0x00,0x28,0x00,0x28,0x00,0x65,0x00,0x65,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x65,0x28,0x7A,0x28,0xE9,0xE8,0x65,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE5,0x7A,0x28,0x28,0xEA,0xEB,0x7A,0x28,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x75,0x15,0x28,0x28,0x28,0x77,0x4D,0x4D,0x28,0x28,0x28,0x95,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x48,0x48,0x15,0x28,0x4D,0x4D,0x78,0x4D,0xA5,0x39,0x1E,0x15,0x2E,0xE2,0x93,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x2E,0x39,0x78,0x2E,0xE3,0xE6,0xA5,0x39,0x15,0x4C,0x53,0xE7,0x1E,0x15,0x27,0x2D,0x4C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x40,0x2D,0x53,0x38,0x39,0x4C,0x38,0x2D,0x39,0x2E,0x28,0x39,0x2D,0x15,0x1E,0x1E,0x27,0x53,0x6F,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x15,0x76,0x2E,0x40,0x76,0x39,0x39,0xDE,0xA1,0x27,0xE1,0x2D,0x1E,0x2E,0x39,0x40,0x15,0x1E,0x1E,0x27,0x4D,0xA3,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0xCB,0x2E,0x2E,0x1E,0x38,0x6F,0x2E,0xA2,0x2E,0xDF,0x63,0x2D,0x1E,0x15,0x48,0x38,0x40,0x15,0x1E,0x27,0xA2,0x6F,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x15,0x28,0x2E,0x2E,0x28,0xCD,0x39,0xDD,0x2E,0x2D,0x3D,0x2E,0x3D,0x40,0x15,0x15,0x48,0x38,0x48,0x15,0x1E,0xD8,0x98,0x9C,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x1E,0x2E,0x3D,0x40,0x76,0x39,0x38,0x15,0x2D,0x38,0x3D,0x1E,0x3D,0x2D,0x15,0x15,0x15,0x48,0x2D,0x38,0x15,0x1E,0x3D,0x98,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0xCE,0x1E,0x2D,0x2D,0x15,0x4C,0x99,0x15,0x15,0x39,0x2D,0x3D,0x48,0x3D,0x2D,0x1E,0x15,0x28,0x15,0x39,0x39,0x15,0x1E,0x40,0x3D,0xC2,0x00,0x00,0x00,
 0x00,0x00,0x00,0x6C,0xD2,0x2E,0x2E,0x15,0x4C,0x39,0x15,0x15,0x38,0x3F,0x3F,0x38,0x40,0x3F,0x40,0x15,0x15,0x15,0x38,0x38,0x15,0x15,0xA0,0x3D,0x79,0x00,0x00,0x00,
 0x00,0x00,0x00,0x1E,0x9F,0x3F,0x2E,0x15,0x4D,0x38,0x15,0x1E,0x2D,0x3D,0xD5,0x2E,0x9D,0x3F,0x2E,0x15,0x15,0x28,0x48,0x39,0xC8,0x15,0x15,0x3D,0xC1,0x00,0x00,0x00,
 0x00,0x00,0x00,0x6C,0x1E,0x3F,0x2E,0x15,0x4C,0x39,0x15,0x9D,0x2D,0x39,0x9B,0x40,0xA1,0x9B,0x3F,0x40,0x15,0x28,0x15,0x38,0xC7,0x48,0x1E,0x40,0x8B,0x00,0x00,0x00,
 0x00,0x00,0x00,0x1E,0x1E,0x3D,0x2D,0x15,0x4C,0x99,0x15,0x1E,0x2D,0x2D,0x27,0x1E,0x53,0x1E,0x3D,0x3D,0x15,0x15,0x2E,0x15,0x4D,0x38,0xC3,0x1E,0x95,0x00,0x00,0x00,
 0x00,0x00,0x00,0x15,0x27,0x3F,0x63,0x40,0x4D,0x38,0x15,0x15,0x2D,0x2D,0x27,0x27,0x15,0x15,0x3D,0x2D,0x15,0x15,0x15,0x15,0x48,0x4D,0x40,0x1E,0x93,0x00,0x00,0x00,
 0x00,0x00,0x00,0x15,0x1E,0x27,0x70,0xA4,0xD3,0xD4,0x15,0x15,0x3D,0x2D,0x27,0x27,0x1E,0x1E,0x3F,0x2E,0x15,0x15,0x28,0x15,0x15,0x4C,0x2D,0x6C,0x78,0x00,0x00,0x00,
 0x00,0x00,0x00,0x75,0x1E,0x15,0x27,0x63,0x53,0x38,0x48,0x15,0x2D,0x2D,0x27,0x1E,0x1E,0x1E,0x3F,0x2E,0x15,0x15,0x28,0x15,0x15,0x4C,0x39,0x75,0x6C,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x15,0x15,0x1E,0x63,0x63,0x3F,0x38,0x1E,0x40,0x2E,0x40,0x15,0x15,0x1E,0x3F,0x2E,0x15,0x15,0x28,0x15,0x15,0x48,0xCA,0x77,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0xD1,0x15,0x15,0x40,0x70,0xA7,0xA7,0x1E,0x1E,0x3F,0x3F,0x1E,0x28,0x28,0x38,0x38,0x1E,0x15,0x28,0x15,0x15,0x1E,0x9C,0x77,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x1E,0xA6,0x27,0x27,0x70,0x3F,0x48,0x15,0x53,0x53,0xED,0x28,0xDA,0xA3,0x6F,0x15,0x28,0x28,0x15,0x15,0x1E,0xDB,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x15,0x27,0xA6,0xF7,0xF1,0xF6,0x3F,0x1E,0x53,0x53,0x79,0x28,0x28,0x4C,0x39,0x15,0x28,0x27,0x27,0x15,0x6E,0xCF,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x1E,0x27,0xF4,0x70,0xF3,0x27,0x63,0xEC,0xD7,0x15,0x15,0x15,0x1E,0x27,0x1E,0xEF,0x27,0xA0,0x6E,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x9F,0x1E,0x27,0x27,0xF2,0xEE,0xA4,0x3F,0x27,0x1E,0x1E,0x27,0x27,0x7B,0x27,0x27,0x28,0x28,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x1E,0x79,0x3D,0x7B,0x7B,0x27,0x15,0x3F,0x1E,0x27,0x27,0x27,0x1E,0x1E,0x15,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0xE0,0x2D,0x27,0x27,0x27,0x28,0x15,0x28,0x15,0x1E,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6E,0x1E,0x27,0x27,0x15,0x15,0x8B,0x6E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};