/**
 * ---------------------------------------------------------------------------/
 * Program Name: Fruit Ninja CE
 * Author: Michael2_3B
 * Special Thanks: MateoC for the toolchain and his programming expertise
 *                 Pieman7373 for artistic help and advice
 * License: MIT
 * Description: A fruit ninja remake for the CE. Swipe the calculator keys to
 * slice fruits!
 * ---------------------------------------------------------------------------/
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphx.h>
#include <keypadc.h>
#include <fileioc.h>

#include "gfx/logo_gfx.h"

#define PI 3.1415926

void moveFruits(void);
void animateExplosion(int cx, int cy);
bool isSliced(int x1, int y1, int x2, int y2, int fx, int fy);
void printCentered(char *str, int y, int offset, uint8_t c);
void keyToXY(int *x_val, int *y_val);
void shake(int s);
void swipe(int x, int y);
void debugDisplay();

#define FRUIT_SCALE 1.2

/**
 * Fruit Structure
 * x, y: Coordinates of fruit on screen
 * angle: Angle of throw
 * velocity: Instanteous velocity of fruit
 * rotation: Angle of rotation of fruit
 * rotation_speed: How fast is the fruit rotating
 */
typedef struct {
    int x, y;
    double angle;
    double velocity;
    uint8_t rotation;
    uint8_t rotation_speed;
    gfx_sprite_t *sprite;
} fruit_t;

/**
 * Allocate a fixed number of fruits
 */
#define MAX_FRUITS 20
#define NUM_FRUITS 9
static fruit_t fruit[MAX_FRUITS];

/**
 * Avaiable Fruit sprite structure
 * uncut: Sprite before fruit is cut
 * top: Top of cut fruit
 * bottom: Bottom of cut fruit
 */
typedef struct {
    gfx_sprite_t *uncut;
    gfx_sprite_t *top;
    gfx_sprite_t *bottom;
} fruit_sprite_t;

/**
 * Available fruit sprites, with cut components
 */
static fruit_sprite_t fruit_sprites[NUM_FRUITS] = {
    { watermelon, watermelon_top,  watermelon_bottom },
    { apple,      apple_top,       apple_bottom      },
    { pear,       pear_top,        pear_bottom       },
    { pineapple,  pineapple_top,   pineapple_bottom  },
    { strawberry, strawberry_top,  strawberry_bottom },
    { red_apple,  red_apple_top,   red_apple_bottom  },
    { grapes,     grape_top,       grape_bottom      },
    { kiwi,       kiwi_top,        kiwi_bottom       },
    { banana,     banana_top,      banana_bottom     },
};

typedef struct {
    int xcount;
    uint8_t total_sprites;
    uint8_t whole_sprites;
} game_t;
static game_t game;

fruit_t *getFreeFruit(void);

bool flag = false;
bool pomflag = false;
int i = 0, index = 0;
int mult = 1;
int xList[1000], yList[1000];

/* Sprite buffer for rotating sprites */
gfx_UninitedSprite(sprite_buffer, 64, 64);

struct {
    int highscore;
} file;
char *filename = "FRUITDAT";

void main(void) {

    ti_var_t slot;
    int unsigned score = 0;
    int *temp_ptr;

    char *title = "Fruit Ninja CE";
    char *opt = "Options";
    char *inf = "Info";
    char *high = "High: ";
    int j, c, jc, jy, menuRock = 0, button = 0, gameTime = 0;
    bool clockwise = true, exit = false;

    gfx_Begin();
    gfx_SetDrawBuffer();
    gfx_SetPalette(logo_gfx_pal, sizeof_logo_gfx_pal, 0);

    memset(&file, 0, sizeof(file));
    ti_CloseAll();
    if (slot = ti_Open(filename, "r"))
        ti_Read(&file, sizeof(file), 1, slot);
    ti_CloseAll();

    /* Menu Loop */
    /* I'm redrawing everything each loop */
    do {
        button = 0;
        do {
            int x, y;
            kb_Scan();
            gfx_FillScreen(4);

            gfx_SetColor(1);
            gfx_Rectangle(0, 0, 320, 240);
            gfx_SetColor(2);
            gfx_Rectangle(1, 1, 318, 238);
            gfx_SetColor(3);
            gfx_Rectangle(2, 2, 316, 236);
            gfx_SetColor(0);
            gfx_Rectangle(3, 3, 314, 234);

            gfx_Rectangle(20, 50, 280, 1);
            gfx_FillCircle(80, 160, 55);
            gfx_FillCircle(189, 120, 35);
            gfx_FillCircle(269, 120, 35);
            gfx_FillCircle(230, 195, 35);
            gfx_SetColor(3);
            gfx_Rectangle(19, 49, 280, 1);
            gfx_SetColor(2);
            gfx_Rectangle(18, 48, 280, 1);
            gfx_SetColor(1);
            gfx_Rectangle(17, 47, 280, 1);

            gfx_SetTextScale(3, 3);
            printCentered(title, 17, -3, 1);
            printCentered(title, 18, -2, 2);
            printCentered(title, 19, -1, 3);
            printCentered(title, 20, 0, 0);

            gfx_SetTextScale(2, 2);
            printCentered(high, 75, -100, 0);
            gfx_SetTextXY(95, 75);
            gfx_PrintInt(file.highscore, 1);
            gfx_SetTextScale(1, 1);

            gfx_SetColor(5);
            gfx_FillCircle(80, 160, 49);
            gfx_FillCircle(189, 120, 30);
            gfx_FillCircle(269, 120, 30);
            gfx_FillCircle(230, 195, 30);

            printCentered("Start", 135, -80, 3);
            printCentered(opt, 135, 30, 3);
            printCentered(inf, 135, 110, 3);
            printCentered("Quit", 210, 70, 3);

            gfx_TransparentSprite(gfx_RotateScaleSprite(watermelon,
                                                        sprite_buffer, menuRock,
                                                        1.3 * 64),
                                  60, 150);
            gfx_TransparentSprite(
                gfx_RotateSprite(grapes, sprite_buffer, menuRock - 30), 174,
                100);
            gfx_TransparentSprite(
                gfx_RotateSprite(pineapple, sprite_buffer, menuRock - 30), 255,
                97);
            gfx_TransparentSprite(
                gfx_RotateSprite(bomb, sprite_buffer, menuRock), 214, 170);

            keyToXY(&x, &y);

            if (y > 0) {
                // put screen swipe locations in array
                xList[index] = x;
                yList[index] = y;

                // if there is an active line in the array from swiping
                if (index > 0) {
                    gfx_SetColor(0);
                    gfx_Line_NoClip(xList[index - 1], yList[index - 1], x, y);

                    if (kb_Data[3] == kb_4) // start
                        button = 1;

                    if (kb_Data[5] == kb_9 || kb_Data[4] == kb_8) // options
                        button = 2;

                    if (kb_Data[6] == kb_Mul || kb_Data[6] == kb_Div) // info
                        button = 3;

                    if (kb_Data[5] == kb_3) // exit
                        button = 4;
                }
                index++;
                i = 0;
                if (index == 1000)
                    index = 0;
            } else { // there was not a swipe over the keys
                if (i < 10)
                    i++;
                if (i == 10)
                    index = 0;
            }

            gfx_BlitBuffer();

            /* Controls back and forth rocking of menu sprites */
            if (clockwise == true)
                menuRock += 4;

            if (clockwise == false)
                menuRock -= 4;

            if (menuRock > 30)
                clockwise = false;

            if (menuRock < -30)
                clockwise = true;

        } while (button == 0); // exit the loop once a button is pressed

        if (button == 1) {
            gfx_SetColor(5);
            j = 49;
            jc = 1;
            jy = 150;
            do {
                gfx_FillCircle(80, 160, j);
                if (jy < 240) {
                    gfx_TransparentSprite(
                        gfx_RotateScaleSprite(watermelon_top, sprite_buffer,
                                              menuRock, 1.3 * 64),
                        60, jy);
                    gfx_TransparentSprite(
                        gfx_RotateScaleSprite(watermelon_bottom, sprite_buffer,
                                              menuRock, 1.3 * 64),
                        60, jy + jc);
                }
                gfx_BlitBuffer();

                j += jc;
                jy += jc;
                jc *= 2;

            } while (j <= 320);
        } else if (button == 2) {
            // Options Menu
            gfx_SetColor(5);
            j = 30;
            jc = 1;
            jy = 100;
            do {
                gfx_FillScreen(4);
                if (j > 0)
                    gfx_FillCircle(189, 120, j);
                if (jy < 240) {
                    gfx_TransparentSprite(gfx_RotateSprite(grape_top,
                                                           sprite_buffer,
                                                           menuRock - 30),
                                          174, jy);
                    gfx_TransparentSprite(gfx_RotateSprite(grape_bottom,
                                                           sprite_buffer,
                                                           menuRock - 30),
                                          174, jy + jc);
                }
                gfx_BlitBuffer();

                j -= jc;
                jy += jc;
                jc *= 2;
            } while (j > 0);

            do {
                int x, y;
                kb_Scan();
                gfx_FillScreen(4);

                gfx_SetColor(1);
                gfx_Rectangle(0, 0, 320, 240);
                gfx_SetColor(2);
                gfx_Rectangle(1, 1, 318, 238);
                gfx_SetColor(3);
                gfx_Rectangle(2, 2, 316, 236);
                gfx_SetColor(0);
                gfx_Rectangle(3, 3, 314, 234);

                gfx_SetTextScale(2, 2);
                printCentered(opt, 24, -3, 1);
                printCentered(opt, 25, -2, 2);
                printCentered(opt, 26, -1, 3);
                printCentered(opt, 27, 0, 0);

                // gfx_SetTextScale(1,1);

                gfx_FillCircle(35, 35, 25);
                gfx_SetColor(5);
                gfx_FillCircle(35, 35, 20);
                gfx_SetColor(0);
                gfx_TransparentSprite(
                    gfx_RotateSprite(grapes, sprite_buffer, menuRock - 30), 20,
                    20);

                if (clockwise == true)
                    menuRock += 2;

                if (clockwise == false)
                    menuRock -= 2;

                if (menuRock > 30)
                    clockwise = false;

                if (menuRock < -30)
                    clockwise = true;

                keyToXY(&x, &y);
                swipe(x, y);

                gfx_BlitBuffer();
            } while (kb_Data[2] != kb_Math);

            gfx_SetColor(5);
            j = 20;
            jc = 1;
            jy = 20;
            do {
                gfx_FillScreen(4);
                if (j > 0)
                    gfx_FillCircle(35, 35, j);
                if (jy < 240) {
                    gfx_TransparentSprite(gfx_RotateSprite(grape_top,
                                                           sprite_buffer,
                                                           menuRock - 30),
                                          20, jy);
                    gfx_TransparentSprite(gfx_RotateSprite(grape_bottom,
                                                           sprite_buffer,
                                                           menuRock - 30),
                                          20, jy + jc);
                }
                gfx_BlitBuffer();

                j -= jc;
                jy += jc;
                jc *= 2;

            } while (j > 0);

        } else if (button == 3) {
            // Info Menu
            gfx_SetColor(5);
            j = 30;
            jc = 1;
            jy = 100;
            do {
                gfx_FillScreen(4);
                if (j > 0)
                    gfx_FillCircle(269, 120, j);
                if (jy < 240) {
                    gfx_TransparentSprite(gfx_RotateSprite(pineapple_top,
                                                           sprite_buffer,
                                                           menuRock - 30),
                                          255, jy);
                    gfx_TransparentSprite(gfx_RotateSprite(pineapple_bottom,
                                                           sprite_buffer,
                                                           menuRock - 30),
                                          255, jy + jc);
                }
                gfx_BlitBuffer();

                j -= jc;
                jy += jc;
                jc *= 2;

            } while (j > 0);

            do {
                int x, y;
                kb_Scan();
                gfx_FillScreen(4);

                gfx_SetColor(1);
                gfx_Rectangle(0, 0, 320, 240);
                gfx_SetColor(2);
                gfx_Rectangle(1, 1, 318, 238);
                gfx_SetColor(3);
                gfx_Rectangle(2, 2, 316, 236);
                gfx_SetColor(0);
                gfx_Rectangle(3, 3, 314, 234);

                gfx_SetTextScale(2, 2);
                printCentered(inf, 24, -3, 1);
                printCentered(inf, 25, -2, 2);
                printCentered(inf, 26, -1, 3);
                printCentered(inf, 27, 0, 0);

                gfx_SetTextScale(1, 1);
                printCentered("Created by Michael2_3B", 70, 0, 0);
                printCentered("version x.x.x", 85, 0, 2);
                printCentered("released xx/xx/2019", 100, 0, 0);
                printCentered(
                    "Special thanks to MateoC for his expertise", 115, 0, 0);
                printCentered("and Pieman7373 for artistic help", 130,
                                      0, 0);
                printCentered("based on Halfbrick Studios Fruit Ninja",
                                      220, 0, 0);

                gfx_FillCircle(35, 35, 25);
                gfx_SetColor(5);
                gfx_FillCircle(35, 35, 20);
                gfx_SetColor(0);
                gfx_TransparentSprite(
                    gfx_RotateSprite(pineapple, sprite_buffer, menuRock - 30),
                    20, 20);

                if (clockwise == true)
                    menuRock += 2;

                if (clockwise == false)
                    menuRock -= 2;

                if (menuRock > 30)
                    clockwise = false;

                if (menuRock < -30)
                    clockwise = true;

                keyToXY(&x, &y);
                swipe(x, y);

                gfx_BlitBuffer();
            } while (kb_Data[2] != kb_Math);

            gfx_SetColor(5);
            j = 20;
            jc = 1;
            jy = 20;
            do {
                gfx_FillScreen(4);
                if (j > 0)
                    gfx_FillCircle(35, 35, j);
                if (jy < 240) {
                    gfx_TransparentSprite(gfx_RotateSprite(pineapple_top,
                                                           sprite_buffer,
                                                           menuRock - 30),
                                          20, jy);
                    gfx_TransparentSprite(gfx_RotateSprite(pineapple_bottom,
                                                           sprite_buffer,
                                                           menuRock - 30),
                                          20, jy + jc);
                }
                gfx_BlitBuffer();

                j -= jc;
                jy += jc;
                jc *= 2;

            } while (j > 0);

        } else if (button == 4) {
            gfx_SetColor(0);
            j = 1;
            jc = 1;
            do {
                gfx_FillCircle(80, 160, j);
                gfx_FillCircle(189, 120, j);
                gfx_FillCircle(269, 120, j);
                gfx_FillCircle(230, 195, j);
                gfx_BlitBuffer();
                j += (int)jc;
                jc *= 2;
            } while (j <= 320);
        }
    } while (button == 2 || button == 3);

    if (button == 1) {

        gfx_SetColor(0);
        gfx_SetTextScale(3, 2);
        flag = false;
        score = 0;
        game.total_sprites = 0;
        game.whole_sprites = 0;

        /* ---------------------------------------------------------------------------------------------------------*/
        /* START THE GAME!!! */
        /* SLICE DEM FRUITS */
        /* ---------------------------------------------------------------------------------------------------------*/

        do {
            int x, y;
            kb_Scan();
            gfx_FillScreen(5);
            gfx_SetTextXY(2, 2);
            gfx_SetTextFGColor(4);
            gfx_PrintInt(score, 1);
            gameTime++;

            // for in-game debugging
            // debugDisplay();

            gfx_PrintStringXY("XXX", 248, 2);
            gfx_SetTextFGColor(1);
            switch(game.xcount) {
                case 1:
                    gfx_PrintStringXY("X", 248, 2);
                    break;
                case 2:
                    gfx_PrintStringXY("XX", 248, 2);
                    break;
                case 3:
                    gfx_PrintStringXY("XXX", 248, 2);
                    break;
                case 4:
                    exit = true;
                default:
                    break;
            }

            // move fruit entities on the screen
            moveFruits();

            // interval to throw fruits on the screen
            if (gameTime == 100) {

                fruit_t *n = getFreeFruit();
                n->sprite = fruit_sprites[rand() % NUM_FRUITS].uncut;
                n->x = (int)(25 + (rand() % 250));
                n->y = 240;
                n->angle = PI;
                n->velocity = 9;
                n->rotation = 0;
                n->rotation_speed = rand() % 5;

                game.whole_sprites++;
                game.total_sprites++;

                if (rand() & 1) {
                    for (j = 0; j < (int)(rand() % 3); j++) {

                        fruit_t *n = getFreeFruit();
                        n->sprite = fruit_sprites[rand() % NUM_FRUITS].uncut;
                        n->x = (int)(25 + (rand() % 250));
                        n->y = 240;
                        n->angle = PI;
                        n->velocity = 9;
                        n->rotation = 0;
                        n->rotation_speed = rand() % 5;

                        game.whole_sprites++;
                        game.total_sprites++;
                    }
                }

                gameTime = 0;
            }

            if ((score + 1) % 10 == 0)
                pomflag = false;

            if (score % 10 == 0 && score > 0 && pomflag == false) {

                fruit_t *n = getFreeFruit();
                n->sprite = pomegranate;
                n->x = 320;
                n->y = 220;
                n->angle = 3 * PI / 2;
                n->velocity = 8;
                n->rotation = 0;
                n->rotation_speed = rand() % 5;

                game.whole_sprites++;
                game.total_sprites++;

                pomflag = true;
            }

            // throw a bomb on the screen
            if ((int)(rand() % 200) == 50) {
                fruit_t *n = getFreeFruit();
                n->sprite = bomb;
                n->x = (int)(25 + (rand() % 250));
                n->y = 240;
                n->angle = PI;
                n->velocity = 9;
                n->rotation = 0;
                n->rotation_speed = rand() % 8;

                game.whole_sprites++;
                game.total_sprites++;
            }

            // convert key input to x and y locations on screen
            keyToXY(&x, &y);

            // if there was a swipe over the keys
            if (y > 0) {

                // put screen swipe locations in array
                xList[index] = x;
                yList[index] = y;

                // if there is an active line in the array from swiping
                if (index > 0) {
                    gfx_Line_NoClip(xList[index - 1], yList[index - 1], x, y);

                    if (game.whole_sprites > 0) { // if whole entity count on the screen is
                                  // greater than 0
                                  // (does not include halves)
                        for (j = 0; j < MAX_FRUITS; j++) {

                            // get the pointer to the fruit information
                            fruit_t *f = &fruit[j];

                            if (f->y > 0) {
                                // detect if line touches sprite
                                if (isSliced(xList[index - 1], yList[index - 1],
                                             x, y, f->x, f->y)) {
                                    // something was sliced
                                    if (f->sprite == bomb) {
                                        // YOU HIT A BOMB!!!
                                        animateExplosion(f->x + 20, f->y + 20);
                                        exit = true;

                                        gfx_FillScreen(0);
                                        gfx_SetTextScale(2, 2);
                                        printCentered("Game Over!", 105,
                                                              0, 3);
                                        printCentered("Score:", 130,
                                                              -20, 3);
                                        gfx_SetTextXY(190, 130);
                                        gfx_SetTextFGColor(3);
                                        gfx_PrintInt(score, 1);

                                        gfx_BlitBuffer();
                                        flag = false;
                                        do {
                                            kb_Scan();
                                            if (kb_Data[6] == kb_Clear ||
                                                kb_Data[1] == kb_2nd ||
                                                kb_Data[6] == kb_Enter)
                                                flag = true;
                                        } while (flag == false);

                                    } else if (f->sprite == pomegranate) {
                                        score++;
                                    } else { // fruit was sliced
                                        for (c = 0; c < NUM_FRUITS; c++) {
                                            if (f->sprite == fruit_sprites[c].uncut) {
                                                // throwFruit(fruitname, x, y,
                                                // angle, velocity,
                                                // rotation, rotation speed)
                                                fruit_t *n = getFreeFruit();
                                                n->sprite = fruit_sprites[c].top;
                                                n->x = f->x;
                                                n->y = f->y;
                                                n->angle = f->angle;
                                                n->velocity = 2;
                                                n->rotation = f->rotation;
                                                n->rotation_speed = 0;

                                                n = getFreeFruit();
                                                n->sprite = fruit_sprites[c].bottom;
                                                n->x = f->x;
                                                n->y = f->y;
                                                n->angle = f->angle;
                                                n->velocity = 0;
                                                n->rotation = f->rotation;
                                                n->rotation_speed = 0;

                                                game.whole_sprites--;
                                                game.total_sprites++;
                                                f->y = 0;
                                                score++;

                                                if ((score % 100) == 0 &&
                                                    game.xcount > 0)
                                                    game.xcount--;

                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                index++;
                i = 0;
                if (index == 1000)
                    index = 0;
            } else { // there was not a swipe over the keys

                if (i < 10)
                    i++;
                if (i == 10)
                    index = 0;
            }

            gfx_BlitBuffer();

            if (kb_Data[1] == kb_Mode) {
                gfx_SetColor(4);
                gfx_FillRectangle(50, 50, 220, 140);
                gfx_SetColor(1);
                gfx_Rectangle(46, 46, 228, 148);
                gfx_SetColor(2);
                gfx_Rectangle(47, 47, 226, 146);
                gfx_SetColor(3);
                gfx_Rectangle(48, 48, 224, 144);
                gfx_SetColor(0);
                gfx_Rectangle(49, 49, 222, 142);
                gfx_SetTextScale(3, 3);
                printCentered("Paused", 65, 0, 0);
                gfx_SetTextScale(1, 1);
                printCentered("Quit", 175, -70, 2);
                printCentered("Resume", 175, 70, 2);
                gfx_BlitBuffer();
                gfx_SetColor(0);
                gfx_SetTextScale(3, 2);
                flag = false;
                do {
                    kb_Scan();
                    if (kb_Data[1] == kb_Window) {
                        flag = true;
                        exit = true;
                    }
                    if (kb_Data[1] == kb_Trace) {
                        flag = true;
                    }
                } while (flag == false);
            }

        // wait until bomb is hit or game loop is otherwise exited
        } while (!exit);

        temp_ptr = &file.highscore;
        if (score > *temp_ptr)
            *temp_ptr = score;
    }

    gfx_End();

    if (slot = ti_Open(filename, "w"))
        ti_Write(&file, sizeof(file), 1, slot);
    ti_CloseAll();
}

// gets a pointer to an available fruit slot
fruit_t *getFreeFruit(void) {
    fruit_t *f = &fruit[0];
    while (f->y > 0) {
        f++;
    }
    return f;
}

// move any fruit entities that are on the screen
void moveFruits(void) {
    uint8_t j;
    for (j = 0; j < MAX_FRUITS; j++) {

        // get the pointer to the fruit information
        fruit_t *f = &fruit[j];

        if (f->y > 0) {
            gfx_TransparentSprite(gfx_RotateScaleSprite(f->sprite,
                                                        sprite_buffer,
                                                        f->rotation, FRUIT_SCALE * 64),
                                  f->x, f->y);

            f->y -= f->velocity;
            f->velocity -= 0.2;

            if (f->sprite == pomegranate) {
                mult = 3;
            } else {
                mult = 1;
            }

            f->x += mult * sin(f->angle);
            f->rotation += f->rotation_speed;
            if (f->y >= 240 || f->x >= 320 || f->x <= -32) {
                f->y = 0;
                game.total_sprites--;

                if (f->sprite == bomb) {
                    game.whole_sprites--;
                } else if (f->sprite == pomegranate) {
                    game.whole_sprites--;
                } else {
                    uint8_t c;
                    for (c = 0; c < NUM_FRUITS; c++) {
                        if (f->sprite == fruit_sprites[c].uncut) {
                            game.xcount++;
                            shake(3);
                            game.whole_sprites--;
                            break;
                        }
                    }
                }
            }
        }
    }
}

/* Display the bomb exploding animation */
void animateExplosion(int cx, int cy) {
    int z, j, side, sx, sy, sx2, sy2;
    gfx_SetColor(0);
    for (z = 0; z < 20; z++) {
        side = (int)(rand() % 4);
        if (side == 0) {
            sx = 0;
            sy = (int)(rand() % 240);

            sx2 = 320;
            sy2 = (int)(rand() % 240);

        } else if (side == 1) {
            sx = (int)(rand() % 320);
            sy = 0;

            sx2 = (int)(rand() % 320);
            sy2 = 240;

        } else if (side == 2) {
            sx = 320;
            sy = (int)(rand() % 240);

            sx2 = 0;
            sy2 = (int)(rand() % 240);

        } else {
            sx = (int)(rand() % 320);
            sy = 240;

            sx2 = (int)(rand() % 320);
            sy2 = 0;
        }
        if (z > 12)
            gfx_FillCircle(cx, cy, (z - 12) * (z - 12) * (z - 12));
        gfx_Line_NoClip(cx, cy, sx, sy);
        gfx_Line_NoClip(cx + 1, cy + 1, sx + 1, sy + 1);
        gfx_Line_NoClip(cx, cy, sx2, sy2);
        gfx_Line_NoClip(cx + 1, cy + 1, sx2 + 1, sy2 + 1);
        gfx_SwapDraw();

        shake(5);
    }
}

/**
 * Detect if line goes through sprite
 */
bool isSliced(int x1, int y1, int x2, int y2, int rx1, int ry1) {
    float minX, maxX;
    float minY, maxY;
    float dx;

    int rx2 = rx1 + FRUIT_SCALE * 32;
    int ry2 = ry1 + FRUIT_SCALE * 32;

    if (x1 > x2) {
        minX = x2;
        maxX = x1;
    } else {
        minX = x1;
        maxX = x2;
    }

    // locate X intersection
    if (maxX > rx2) {
        maxX = rx2;
    }

    if (minX < rx1) {
        minX = rx1;
    }

    if (minX > maxX) {
        return false;
    }

    minY = y1;
    maxY = y2;
    dx = x2 - x1;

    // project X onto Y
    if (abs(dx) > 0.000001) {
        float a = (y2 - y1) / dx;
        float b = y1 - a * x1;
        minY = a * minX + b;
        maxY = a * maxX + b;
    }

    if (minY > maxY) {
        float tmp = maxY;
        maxY = minY;
        minY = tmp;
    }

    // locate Y intersection
    if (maxY > ry2) {
        maxY = ry2;
    }

    if (minY < ry1) {
        minY = ry1;
    }

    if (minY > maxY) {
        return false;
    }

    return true;
}

/* Prints a screen centered string, with desired offset and color */
void printCentered(char *str, int y, int offset, uint8_t c) {
    gfx_SetTextFGColor(c);
    gfx_PrintStringXY(str, (LCD_WIDTH - gfx_GetStringWidth(str)) / 2 + offset,
                      y);
}

/* Convert keypress to x/y location for swiping */
void keyToXY(int *x_val, int *y_val) {
    kb_key_t key;
    int x = 0;
    int y = 0;

    if (kb_Data[2]) {
        key = kb_Data[2];
        x = 32;
        if (key == kb_Store)
            y = 188;
        if (key == kb_Ln)
            y = 154;
        if (key == kb_Log)
            y = 120;
        if (key == kb_Square)
            y = 85;
        if (key == kb_Recip)
            y = 51;
        if (key == kb_Math)
            y = 17;
    }
    if (kb_Data[3]) {
        key = kb_Data[3];
        x = 96;
        if (key == kb_0)
            y = 222;
        if (key == kb_1)
            y = 188;
        if (key == kb_4)
            y = 154;
        if (key == kb_7)
            y = 120;
        if (key == kb_Comma)
            y = 85;
        if (key == kb_Sin)
            y = 51;
        if (key == kb_Apps)
            y = 17;
    }
    if (kb_Data[4]) {
        key = kb_Data[4];
        x = 160;
        if (key == kb_DecPnt)
            y = 222;
        if (key == kb_2)
            y = 188;
        if (key == kb_5)
            y = 154;
        if (key == kb_8)
            y = 120;
        if (key == kb_LParen)
            y = 85;
        if (key == kb_Cos)
            y = 51;
        if (key == kb_Prgm)
            y = 17;
    }
    if (kb_Data[5]) {
        key = kb_Data[5];
        x = 224;
        if (key == kb_Chs)
            y = 222;
        if (key == kb_3)
            y = 188;
        if (key == kb_6)
            y = 154;
        if (key == kb_9)
            y = 120;
        if (key == kb_RParen)
            y = 85;
        if (key == kb_Tan)
            y = 51;
        if (key == kb_Vars)
            y = 17;
    }
    if (kb_Data[6]) {
        key = kb_Data[6];
        x = 288;
        if (key == kb_Enter)
            y = 222;
        if (key == kb_Add)
            y = 188;
        if (key == kb_Sub)
            y = 154;
        if (key == kb_Mul)
            y = 120;
        if (key == kb_Div)
            y = 85;
        if (key == kb_Power)
            y = 51;
        if (key == kb_Clear)
            y = 17;
    }

    *x_val = x;
    *y_val = y;
}

/* Shake the screen */
void shake(int s) {
    gfx_ShiftDown(s);
    gfx_SwapDraw();
    gfx_ShiftUp(s);
    gfx_SwapDraw();
    gfx_ShiftUp(s);
    gfx_SwapDraw();
    gfx_ShiftDown(s);
    gfx_SwapDraw();
    gfx_ShiftLeft(s);
    gfx_SwapDraw();
    gfx_ShiftRight(s);
    gfx_SwapDraw();
    gfx_ShiftRight(s);
    gfx_SwapDraw();
    gfx_ShiftLeft(s);
    gfx_SwapDraw();
}

/**
 * Draw slicing lines
 */
void swipe(int x, int y) {

    // there was a swipe over the keys
    if (y > 0) {

        xList[index] = x;
        yList[index] = y;

        gfx_SetColor(0);
        if (index > 0)
            gfx_Line_NoClip(xList[index - 1], yList[index - 1], x, y);

        index++;
        i = 0;
        if (index == 1000) {
            index = 0;
        }

    // there was not a swipe over the keys
    } else {

        if (i < 10)
            i++;
        if (i == 10)
            index = 0;
    }
}

/* Debugging Info */
void debugDisplay() {
    int j;
    gfx_SetTextScale(1, 1);

    // game.whole_sprites is the amount of entities on the screen that aren't fruit halves
    gfx_PrintStringXY("game.whole_sprites: ", 2, 230);
    gfx_SetTextXY(22, 230);
    gfx_PrintInt(game.whole_sprites, 1);

    // game.total_sprites is the total amount of sprites currently onscreen
    gfx_PrintStringXY("game.total_sprites: ", 2, 220);
    gfx_SetTextXY(50, 220);
    gfx_PrintInt(game.total_sprites, 1);

    gfx_SetTextScale(3, 2);
}

