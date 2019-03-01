/*
 *--------------------------------------
 * Program Name:CSWIPE
 * Author:Michael2_3B
 * License:MIT
 * Description: A fruit ninja remake for the CE. Swipe the calculator keys to slice fruits!
 *--------------------------------------
*/

/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Standard headers (recommended) */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <graphx.h>
#include <keypadc.h>

/* Include the sprite data */
#include "gfx/logo_gfx.h"

#define PI 3.1415926
#define color gfx_RGBTo1555(72, 153, 196)

/* Put your function prototypes here */
void throwFruit(gfx_sprite_t *fruitname, int curX, int curY, int angle, int velocity, int rotation);
void moveEnts();
void animateExplosion(int cx, int cy);
bool isSliced(int x1, int y1, int x2, int y2, int j);
bool lineRect(float x1, float y1, float x2, float y2, float rx, float ry, float rw, float rh);
bool lineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
void print_string_centered(const char *str, int y, int offset, uint8_t c);

/* Put all your globals here */
// entX and entY is x and y values of sprites.
// entAng is the angle at which they are thrown
// entVel is the velocity at which they are thrown
// entRot is the sprites' rotation amount on the screen
// when fruits are thrown, entName gets loaded with sprites from sN[], so as to specify which fruit it is at what index
// and of course, these arrays are parallel so that the values at the matching indices give info for the same sprite
double entX[20], entAng[20], entVel[20], entRot[20];
double entY[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
gfx_sprite_t *entName[20];
gfx_sprite_t *sN[7] = {watermelon, apple, pear, pineapple, strawberry, red_apple, bomb};
gfx_sprite_t *sS[12] = {watermelon_top, watermelon_bottom, apple_top, apple_bottom, pear_top, pear_bottom, pineapple_top, pineapple_bottom, strawberry_top, strawberry_bottom, red_apple_top, red_apple_bottom};
gfx_sprite_t *splitTop;
gfx_sprite_t *splitBottom;
const int s=2;
int eC=0, gameTime=0;
gfx_UninitedSprite(sprite_buffer, 32, 32); //sprite buffer for rotating sprites

void main(void) {
    /* Fill in the body of the main function here */

    /* Variable Declarations */
    kb_key_t key;
    const char *title = "Fruit Ninja CE";
    const char *author = "by Michael2_3B";
    const char *start = "Start";
    const char *options = "Options";
    const char *info = "Info";
    const char *quit = "Quit";
    int xList[1000], yList[1000]; //used for swiping calculations
    int i=0, index=0, fat=0, x, y, j, c, randX, menuRock=0, tColor=1;
    bool up=true, flag=false, clockwise=true;
    bool bombHit=false;
    double speed = 1;
    gfx_Begin();
    gfx_SetDrawBuffer();
    gfx_SetPalette(logo_gfx_pal, sizeof_logo_gfx_pal, 0);

    /* Menu Loop */
    /* Technically I'm redrawing everything each loop, I'll look into changing this I think */
    do{
        kb_Scan();
        gfx_FillScreen(0x1234);
        gfx_SetTextScale(3,3);
        print_string_centered(title, 20, 0, tColor);
        tColor++;
        if(tColor==4) tColor = 1;
        gfx_SetTextScale(1,1);
        print_string_centered(author, 60, 0, 0);
        gfx_SetColor(gfx_blue);
        gfx_FillCircle(80,160,49);
        gfx_FillCircle(189, 120, 30);
        gfx_FillCircle(269, 120, 30);
        gfx_FillCircle(230, 195, 30);
        print_string_centered(start, 135, -80, 0);
        print_string_centered(options, 135, 30, 0);
        print_string_centered(info, 135, 110, 0);
        print_string_centered(quit, 210, 70, 0);
        gfx_TransparentSprite(gfx_RotateSprite(watermelon, sprite_buffer, menuRock), 65, 150);
        gfx_TransparentSprite(gfx_RotateSprite(strawberry, sprite_buffer, menuRock), 184, 105);
        gfx_TransparentSprite(gfx_RotateSprite(pineapple, sprite_buffer, menuRock), 264, 100);
        gfx_TransparentSprite(gfx_RotateSprite(bomb, sprite_buffer, menuRock), 214, 170);
        gfx_SetColor(gfx_white);
        gfx_Circle_NoClip(80,160,50);
        gfx_Circle_NoClip(80,160,49);
        gfx_SwapDraw();

        /* Controls back and forth rocking of menu sprites */
        if(clockwise == true)
            menuRock++;

        if(clockwise == false)
            menuRock--;

        if(menuRock > 30)
            clockwise = false;

        if(menuRock < -30)
            clockwise = true;

    } while (kb_Data[3] != kb_4); //exit the loop once the "4" key is pressed - (will be changed to swiping soon)

    /* "slices" watermelon to start game */
    gfx_SetColor(gfx_white);
    gfx_Line(55,175,115,150);
    gfx_SwapDraw();
    for(j=0; j<20000; j++);


    /* START THE GAME!!! */
    do {
    	gameTime++;
    	kb_Scan();
    	gfx_FillScreen(0x1234);

        //if there are entities on the screen, move them
    	if(eC > 0)
    		moveEnts();

        //interval to throw fruits on the screen
    	if(gameTime == 60){
    		randX = (int)(rand() % 320);
    		throwFruit(sN[rand()%6], randX, 240, rand()*PI, 6, 0);
    		gameTime = 0;
    	}

        //throw a bomb on the screen
    	if((int)(rand() % 200)==100){
    		throwFruit(sN[6], (int)(rand()%320), 240, 7.5*PI/12, 6, 0);
    	}

    	//Convert keypress to screen location
    	x=0;
    	y=0;
    	if (kb_Data[2]) {
    		key = kb_Data[2];
    		x=32;
    		if(key == kb_Store) y=188;
    		if(key == kb_Ln) y=154;
    		if(key == kb_Log) y=120;
    		if(key == kb_Square) y=85;
    		if(key == kb_Recip) y=51;
    		if(key == kb_Math) y=17;
    	}
    	if (kb_Data[3]) {
    		key = kb_Data[3];
    		x=96;
    		if(key == kb_0) y=222;
    		if(key == kb_1) y=188;
    		if(key == kb_4) y=154;
    		if(key == kb_7) y=120;
    		if(key == kb_Comma) y=85;
    		if(key == kb_Sin) y=51;
    		if(key == kb_Apps) y=17;
    	}
    	if (kb_Data[4]){
    		key = kb_Data[4];
    		x=160;
    		if(key == kb_DecPnt) y=222;
    		if(key == kb_2) y=188;
    		if(key == kb_5) y=154;
    		if(key == kb_8) y=120;
    		if(key == kb_LParen) y=85;
    		if(key == kb_Cos) y=51;
    		if(key == kb_Prgm) y=17;
    	}
    	if (kb_Data[5]) {
    		key = kb_Data[5];
    		x=224;
    		if(key == kb_Chs) y=222;
    		if(key == kb_3) y=188;
    		if(key == kb_6) y=154;
    		if(key == kb_9) y=120;
    		if(key == kb_RParen) y=85;
    		if(key == kb_Tan) y=51;
    		if(key == kb_Vars) y=17;
    	}
    	if (kb_Data[6]) {
    		key = kb_Data[6];
    		x=288;
    		if(key == kb_Enter) y=222;
    		if(key == kb_Add) y=188;
    		if(key == kb_Sub) y=154;
    		if(key == kb_Mul) y=120;
    		if(key == kb_Div) y=85;
    		if(key == kb_Power) y=51;
    		if(key == kb_Clear) y=17;
    	}

        /* If you are reading this, I would like to apologize if you can't follow along with the calculations */
        /* I can't explain EVERYTHING, but basically I am taking the swiping data and constantly scanning to see */
        /* if and when a fruit is sliced in half, then making sure to slice that specific fruit in half. */
        /* I keep track of the amount of entities on the screen (which increments by 1 when the 2 halves of a fruit are put on) */
        /* I keep track of which sprite is what with arrays, and use those arrays to go off of when referencing entities on the screen */
        /* I keep track of rotations of sprites so hopefully I can maintain continuity when splitting things in half */
        /* and more */
        /* hopefully that clears up a little bit of things */

	//if there was a swipe over the keys
    	if(y>0){
    		if(index>0){
    			//If screen location is same as before
    			if(x==xList[index-1] && y==yList[index-1]){
    				index--; //go back to the same index as before
    				fat++; //increase line thickness
    			}
    		}
		//put screen swipe locations in array
    		xList[index] = x;
    		yList[index] = y;
		
		//if there is an active line in the array from swiping
    		if(index>0){
    			gfx_Line(xList[index-1],yList[index-1],x,y);
    			if(fat > 0) //fatter line
    				gfx_Line(xList[index-1],yList[index-1]-1,x,y-1);
    			if(eC > 0){ //if entity count on the screen is greater than 0
    				for(j=0; j<=20; j++){
    					//Detect if line touches sprite
    					if(isSliced(xList[index-1],yList[index-1],x,y,j)){
						//Something was sliced
    						if(entName[j] == sN[6]){ //bomb was sliced
    							//YOU HIT A BOMB!!!
    							animateExplosion(entX[j]+16, entY[j]+16);
    							bombHit = true;
    						} else { //fruit was sliced
    							flag=false;
    							for(c=0; c<=6; c++){
    								if(entName[j] == sN[c]){
									//split fruit
    									splitTop = sS[2*c];
    									splitBottom = sS[2*c+1];
    									flag = true;
    								}
    							}
    							if(flag==true){
    								//new X/Y for top of fruit and new X/Y for bottom of fruit after split
    								int newX=0, newY=0, newXB=0, newYB=0;

    								//Calculate these values based on current rotation
    								if(entRot[j]<64){
    									newX = entX[j];
    									newY = entY[j];
    									newXB = entX[j];
    									newYB = entY[j]+16;
    								} else if(entRot[j]<128){
    									newX = entX[j]+32;
    									newY = entY[j];
    									newXB = entX[j]+16;
    									newYB = entY[j];
    								} else if(entRot[j]<192){
    									newX = entX[j]+32;
    									newY = entY[j]+32;
    									newXB = entX[j]+32;
    									newYB = entY[j]+16;
    								} else if(entRot[j]<256){
    									newX = entX[j];
    									newY = entY[j]+32;
    									newXB = entX[j]+16;
    									newYB = entY[j]+32;
    								}

    								throwFruit(splitTop, newX, newY, entAng[j], 1, entRot[j]);
    								throwFruit(splitBottom, newXB, newYB, entAng[j], 0, entRot[j]);
    								entY[j] = 0;
    							}
    						}
    					}
    				}
    			}
    		}
    		index++;
    		i=0;
    		if(index==1000)
    			index=0;
    	} else { //there was not a swipe over the keys
    		if(i < 10){
			//increment i up to 10
			//this is the delay between when there is no longer key input and when the lines erase
    			i++;
    		}
    		if(i==10){
			//if a key hasn't been pressed within the time of i being incremented 10 times, reset values
    			index=0;
    			fat=0;
    		}
    	}

    	gfx_SwapDraw();

    } while (kb_Data[1] != kb_2nd && bombHit==false); //wait until 2nd key is hit or bomb is hit

    gfx_End();
}

/* Throw a fruit onto the screen */
void throwFruit(gfx_sprite_t *fruitname, int curX, int curY, int angle, int velocity, int rotation){
	int j=0;
	while(entY[j] > 0){
		j++;
	}
	entName[j] = fruitname;
	entX[j] = curX;
	entY[j] = curY;
	entAng[j] = angle;
	entVel[j] = velocity;
	entRot[j] = rotation;
	eC++;
}

/* Move any entities that are on the screen */
void moveEnts(){
	int j;
	for(j=0; j<20; j++){
		if(entY[j] > 0){
			gfx_TransparentSprite(gfx_RotateSprite(entName[j], sprite_buffer, entRot[j]), entX[j], entY[j]);
			
			entY[j] -= entVel[j];
			entVel[j] -= 0.1;
			entX[j] += 3*cos(entAng[j]);
			entRot[j] += 3;
			if(entRot[j] > 255)
				entRot[j] = 0;
			if(entY[j] >= 240 || entX[j] >= 320 || entX[j] <= -32){
				entY[j] = 0;
				eC--;
			}
		}
	}
}

/* Display the bomb exploding animation */
void animateExplosion(int cx, int cy){
	int i, j, side, sx, sy;
	gfx_SetColor(gfx_white);
	for(i=0; i<200; i++){
		side = (int)(rand()%4);
		if(side==0){
			sx = 0;
			sy = (int)(rand()%240);
		} else if(side==1){
			sx = (int)(rand()%320);
			sy = 0;
		} else if(side==2){
			sx = 320;
			sy = (int)(rand()%240);
		} else {
			sx = (int)(rand()%320);
			sy = 240;
		}
		gfx_Line(cx, cy, sx, sy);
		gfx_SwapDraw();
	}
}


/* Detect if line goes through sprite */
bool isSliced(int x1, int y1, int x2, int y2, int j){
	float sx = entX[j];
	float sy = entY[j];
	float sw = 32;
	float sh = 32;

	bool hit = lineRect(x1, y1, x2, y2, sx, sy, sw, sh);
	
	return hit;
}

/* fancy calculations used in detecting a slice */
/* http://jeffreythompson.org/collision-detection/line-rect.php */
bool lineRect(float x1, float y1, float x2, float y2, float rx, float ry, float rw, float rh){
	bool left = lineLine(x1, y1, x2, y2, rx, ry, rx, ry+rh);
	bool right = lineLine(x1, y1, x2, y2, rx+rw, ry, rx+rw, ry+rh);
	bool top = lineLine(x1, y1, x2, y2, rx, ry, rx+rw, ry);
	bool bottom = lineLine(x1, y1, x2, y2, rx, ry+rh, rx+rw, ry+rh);

	if(left || right || top || bottom){
		return true;
	} else {
		return false;
	}
}

/* fancy calculations used in detecting a slice */
/* http://jeffreythompson.org/collision-detection/line-rect.php */
bool lineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4){
	float uA = ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
	float uB = ((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));

	if(uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1){
		return true;
	} else {
		return false;
	}
}

/* Prints a screen centered string, with desired offset */
void print_string_centered(const char *str, int y, int offset, uint8_t c) {
    gfx_SetTextFGColor(c);
    gfx_PrintStringXY(str, (LCD_WIDTH - gfx_GetStringWidth(str)) / 2 + offset, y);
}
