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

void throwFruit(gfx_sprite_t *fruitname, int curX, int curY, int angle,
                int velocity, int rotation, int rotSpeed);
void moveEnts();
void animateExplosion(int cx, int cy);
bool isSliced(int x1, int y1, int x2, int y2, int j);
bool lineRect(float x1, float y1, float x2, float y2, float rx, float ry,
              float rw, float rh);
bool lineLine(float x1, float y1, float x2, float y2, float x3, float y3,
              float x4, float y4);
void print_string_centered(char *str, int y, int offset, uint8_t c);
void keyToXY(int *x_val, int *y_val);
void shake(int s);
void swipe(int x, int y);
void debugDisplay();

/**
 * Fruit Structure
 * x, y: Coordinates of fruit on screen
 * angle: Angle of throw
 * velocity: Instanteous velocity of fruit
 * rotation: Angle of rotation of fruit
 * rotation_speed: How fast is the fruit rotating
 */
typedef struct {
    double x, y;
    double angle;
    double velocity;
    double rotation;
    int rotation_speed;
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
} game_t;
static game_t game;

bool flag = false;
bool pomflag = false;
int eC = 0, all_eC = 0, i = 0, index = 0;
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
            print_string_centered(title, 17, -3, 1);
            print_string_centered(title, 18, -2, 2);
            print_string_centered(title, 19, -1, 3);
            print_string_centered(title, 20, 0, 0);

            gfx_SetTextScale(2, 2);
            print_string_centered(high, 75, -100, 0);
            gfx_SetTextXY(95, 75);
            gfx_PrintInt(file.highscore, 1);
            gfx_SetTextScale(1, 1);

            gfx_SetColor(5);
            gfx_FillCircle(80, 160, 49);
            gfx_FillCircle(189, 120, 30);
            gfx_FillCircle(269, 120, 30);
            gfx_FillCircle(230, 195, 30);

            print_string_centered("Start", 135, -80, 3);
            print_string_centered(opt, 135, 30, 3);
            print_string_centered(inf, 135, 110, 3);
            print_string_centered("Quit", 210, 70, 3);

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
                    gfx_Line(xList[index - 1], yList[index - 1], x, y);

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
                print_string_centered(opt, 24, -3, 1);
                print_string_centered(opt, 25, -2, 2);
                print_string_centered(opt, 26, -1, 3);
                print_string_centered(opt, 27, 0, 0);

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
                print_string_centered(inf, 24, -3, 1);
                print_string_centered(inf, 25, -2, 2);
                print_string_centered(inf, 26, -1, 3);
                print_string_centered(inf, 27, 0, 0);

                gfx_SetTextScale(1, 1);
                print_string_centered("Created by Michael2_3B", 70, 0, 0);
                print_string_centered("version x.x.x", 85, 0, 2);
                print_string_centered("released xx/xx/2019", 100, 0, 0);
                print_string_centered(
                    "Special thanks to MateoC for his expertise", 115, 0, 0);
                print_string_centered("and Pieman7373 for artistic help", 130,
                                      0, 0);
                print_string_centered("based on Halfbrick Studios Fruit Ninja",
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
        all_eC = 0;

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

            // move entities on the screen
            moveEnts();

            // interval to throw fruits on the screen
            if (gameTime == 100) {

                // throwFruit(fruitname,   x,     y, angle, velocity, rotation,
                // rotation
                // speed)
                throwFruit(fruit_sprites[rand() % NUM_FRUITS].uncut, (int)(25 + (rand() % 250)),
                           240, PI, 9, 0, rand() % 5);
                eC++;
                all_eC++;

                if (rand() & 1) {
                    for (j = 0; j < (int)(rand() % 3); j++) {
                        throwFruit(fruit_sprites[rand() % NUM_FRUITS].uncut,
                                   (int)(25 + (rand() % 250)), 240, PI,
                                   9, 0, rand() % 5);
                        eC++;
                        all_eC++;
                    }
                }

                gameTime = 0;
            }

            if ((score + 1) % 10 == 0)
                pomflag = false;

            if (score % 10 == 0 && score > 0 && pomflag == false) {

                throwFruit(pomegranate, 320, 220, 3 * PI / 2, 8, 0, rand() % 5);
                eC++;
                all_eC++;

                pomflag = true;
            }

            // throw a bomb on the screen
            if ((int)(rand() % 200) == 50) {
                throwFruit(bomb, (int)(25 + (rand() % 250)), 240, PI,
                           9 + (rand() % 1), 0, rand() % 8);
                eC++;
                all_eC++;
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
                    gfx_Line(xList[index - 1], yList[index - 1], x, y);

                    if (eC > 0) { // if whole entity count on the screen is
                                  // greater than 0
                                  // (does not include halves)
                        for (j = 0; j <= 20; j++) {
                            if (fruit[j].y > 0) {
                                // Detect if line touches sprite
                                if (isSliced(xList[index - 1], yList[index - 1],
                                             x, y, j)) {
                                    // Something was sliced
                                    if (fruit[j].sprite == bomb) {
                                        // YOU HIT A BOMB!!!
                                        animateExplosion(fruit[j].x + 20,
                                                         fruit[j].y + 20);
                                        exit = true;

                                        gfx_FillScreen(0);
                                        gfx_SetTextScale(2, 2);
                                        print_string_centered("Game Over!", 105,
                                                              0, 3);
                                        print_string_centered("Score:", 130,
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

                                    } else if (fruit[j].sprite == pomegranate) {
                                        score++;
                                    } else { // fruit was sliced
                                        for (c = 0; c < NUM_FRUITS; c++) {
                                            if (fruit[j].sprite == fruit_sprites[c].uncut) {
                                                // throwFruit(fruitname, x, y,
                                                // angle, velocity,
                                                // rotation, rotation speed)
                                                throwFruit(fruit_sprites[c].top, fruit[j].x,
                                                           fruit[j].y, fruit[j].angle,
                                                           2, fruit[j].rotation, 0);
                                                throwFruit(fruit_sprites[c].bottom,
                                                           fruit[j].x, fruit[j].y,
                                                           fruit[j].angle, 0,
                                                           fruit[j].rotation, 0);
                                                eC--;
                                                all_eC++;
                                                fruit[j].y = 0;
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
                print_string_centered("Paused", 65, 0, 0);
                gfx_SetTextScale(1, 1);
                print_string_centered("Quit", 175, -70, 2);
                print_string_centered("Resume", 175, 70, 2);
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

        } while (
            exit ==
            false); // wait until bomb is hit or game loop is otherwise exited

        temp_ptr = &file.highscore;
        if (score > *temp_ptr)
            *temp_ptr = score;
    }

    gfx_End();

    if (slot = ti_Open(filename, "w"))
        ti_Write(&file, sizeof(file), 1, slot);
    ti_CloseAll();
}

/* Additional Functions! */

/* Throw a fruit onto the screen */
void throwFruit(gfx_sprite_t *fruitname, int curX, int curY, int angle,
                int velocity, int rotation, int rotSpeed) {
    int j = 0;
    while (fruit[j].y > 0) {
        j++;
    }
    fruit[j].sprite = fruitname;
    fruit[j].x = curX;
    fruit[j].y = curY;
    fruit[j].angle = angle;
    fruit[j].velocity = velocity;
    fruit[j].rotation = rotation;
    fruit[j].rotation_speed = rotSpeed;
}

/* Move any entities that are on the screen */
void moveEnts() {
    int j;
    int c;
    for (j = 0; j < 20; j++) {
        if (fruit[j].y > 0) {
            gfx_TransparentSprite(gfx_RotateScaleSprite(fruit[j].sprite,
                                                        sprite_buffer,
                                                        fruit[j].rotation, 1.2 * 64),
                                  fruit[j].x, fruit[j].y);

            fruit[j].y -= fruit[j].velocity;
            fruit[j].velocity -= 0.2;

            if (fruit[j].sprite == pomegranate) {
                mult = 3;
            } else {
                mult = 1;
            }

            fruit[j].x += mult * sin(fruit[j].angle);
            fruit[j].rotation += fruit[j].rotation_speed;
            if (fruit[j].rotation > 255)
                fruit[j].rotation = 0;
            if (fruit[j].y >= 240 || fruit[j].x >= 320 || fruit[j].x <= -32) {
                fruit[j].y = 0;
                all_eC--;

                if (fruit[j].sprite == bomb) {
                    eC--;
                } else if (fruit[j].sprite == pomegranate) {
                    eC--;
                } else {
                    flag = false;
                    for (c = 0; c < NUM_FRUITS; c++) {
                        if (fruit[j].sprite == fruit_sprites[c].uncut) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag == true) {
                        game.xcount++;
                        shake(3);
                        eC--;
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
        gfx_Line(cx, cy, sx, sy);
        gfx_Line(cx + 1, cy + 1, sx + 1, sy + 1);
        gfx_Line(cx, cy, sx2, sy2);
        gfx_Line(cx + 1, cy + 1, sx2 + 1, sy2 + 1);
        gfx_SwapDraw();

        shake(5);
    }
}

/* Detect if line goes through sprite */
bool isSliced(int x1, int y1, int x2, int y2, int j) {
    float sx = fruit[j].x;
    float sy = fruit[j].y;
    float sw = 1.2 * 32;
    float sh = 1.2 * 32;

    bool hit = lineRect(x1, y1, x2, y2, sx, sy, sw, sh);

    return hit;
}

/* fancy calculations used in detecting a slice */
/* http://jeffreythompson.org/collision-detection/line-rect.php */
bool lineRect(float x1, float y1, float x2, float y2, float rx, float ry,
              float rw, float rh) {
    bool left = lineLine(x1, y1, x2, y2, rx, ry, rx, ry + rh);
    bool right = lineLine(x1, y1, x2, y2, rx + rw, ry, rx + rw, ry + rh);
    bool top = lineLine(x1, y1, x2, y2, rx, ry, rx + rw, ry);
    bool bottom = lineLine(x1, y1, x2, y2, rx, ry + rh, rx + rw, ry + rh);

    if (left || right || top || bottom) {
        return true;
    } else {
        return false;
    }
}

/* fancy calculations used in detecting a slice */
/* http://jeffreythompson.org/collision-detection/line-rect.php */
bool lineLine(float x1, float y1, float x2, float y2, float x3, float y3,
              float x4, float y4) {
    float uA = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) /
               ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
    float uB = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) /
               ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

    if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {
        return true;
    } else {
        return false;
    }
}

/* Prints a screen centered string, with desired offset and color */
void print_string_centered(char *str, int y, int offset, uint8_t c) {
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
            gfx_Line(xList[index - 1], yList[index - 1], x, y);

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

    // eC is the amount of entities on the screen that aren't fruit halves
    gfx_PrintStringXY("eC: ", 2, 230);
    gfx_SetTextXY(22, 230);
    gfx_PrintInt(eC, 1);

    // all_eC is the total amount of sprites currently onscreen
    gfx_PrintStringXY("all_eC: ", 2, 220);
    gfx_SetTextXY(50, 220);
    gfx_PrintInt(all_eC, 1);

    gfx_SetTextScale(3, 2);
}

