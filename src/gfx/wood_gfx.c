// convpng v7.0
#include <stdint.h>
#include "wood_gfx.h"

#include <fileioc.h>
uint8_t *wood_gfx[1] = {
 (uint8_t*)0,
};

bool wood_gfx_init(void) {
    unsigned int data, i;
    ti_var_t appvar;

    ti_CloseAll();

    appvar = ti_Open("wood_gfx", "r");
    data = (unsigned int)ti_GetDataPtr(appvar) - (unsigned int)wood_gfx[0];
    for (i = 0; i < wood_gfx_num; i++) {
        wood_gfx[i] += data;
    }

    ti_CloseAll();

    data = (unsigned int)wood_gfx[0] - (unsigned int)wood_tiles_compressed[0];
    for (i = 0; i < wood_tiles_num; i++) {
        wood_tiles_compressed[i] += data;
    }

    return (bool)appvar;
}
