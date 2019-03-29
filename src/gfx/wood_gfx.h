// convpng v7.0
// this file contains all the graphics sources for easy inclusion in a project
#ifndef __wood_gfx__
#define __wood_gfx__
#include <stdint.h>

#include <stdbool.h>

#define wood_gfx_num 1

extern uint8_t *wood_gfx[1];
#define wood_width 320
#define wood_height 240
#define wood_compressed ((gfx_sprite_t*)wood_gfx[0])
#define wood_tiles_num 12
extern uint8_t *wood_tiles_compressed[12];
#define wood_tile_0_compressed ((gfx_sprite_t*)wood_tiles_compressed[0])
#define wood_tile_1_compressed ((gfx_sprite_t*)wood_tiles_compressed[1])
#define wood_tile_2_compressed ((gfx_sprite_t*)wood_tiles_compressed[2])
#define wood_tile_3_compressed ((gfx_sprite_t*)wood_tiles_compressed[3])
#define wood_tile_4_compressed ((gfx_sprite_t*)wood_tiles_compressed[4])
#define wood_tile_5_compressed ((gfx_sprite_t*)wood_tiles_compressed[5])
#define wood_tile_6_compressed ((gfx_sprite_t*)wood_tiles_compressed[6])
#define wood_tile_7_compressed ((gfx_sprite_t*)wood_tiles_compressed[7])
#define wood_tile_8_compressed ((gfx_sprite_t*)wood_tiles_compressed[8])
#define wood_tile_9_compressed ((gfx_sprite_t*)wood_tiles_compressed[9])
#define wood_tile_10_compressed ((gfx_sprite_t*)wood_tiles_compressed[10])
#define wood_tile_11_compressed ((gfx_sprite_t*)wood_tiles_compressed[11])
bool wood_gfx_init(void);

#endif
