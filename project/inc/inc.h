/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @update: 04/06/24
? @file:   inc.h
----------------------------------------------- */

#ifndef __INC_H__
#define __INC_H__

//? -------------------- DEFINE PROTOTYPE DECLARATION PART --------------------
#define MAX_PATH 260

//? -------------------- INCLUDE PROTOTYPE DECLARATION PART --------------------
//* STANDER LIBS INCLUDE PART
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/time.h>
#include <unistd.h>

//* SDL1.2 INCLUDE PART
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>

//* OUR INC FILES
#include "SDL_Msg.h"
#include "settings.h"
#include "speedRun.h"

//* PUBLIC VARS
SDL_Surface *screen;
SDL_Event    event;

//* SCREEN RESOLUTION
int SCREEN_WIDTH  = 1920;
int SCREEN_HEIGHT = 1080;
int SCREEN_BPP    = 32;

//? --------------------- COLORS PROTOTYPE DECLARATION PART ---------------------
//* SDL_COLOR PUBLIC DEFINTION
SDL_Color WHITE = {255, 255, 255};
SDL_Color BLACK = {0, 0, 0};

//? -------------------- FUNCTIONS PROTOTYPE DECLARATION PART --------------------
//? initEverything() void func
void initEverything();

//? setScreen(int) void func
void setScreen(int);

//? load_img(char*) SDL_Surface*
SDL_Surface *load_img(char*);

//? closeEverything() void func
void closeEverything();

#endif
