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
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/ioctl.h>

//* SDL1.2 INCLUDE PART
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>

//* OUR INC FILES
#include "SDL_Msg.h"
#include "Main_Menu.h"
#include "start_menu.h"
#include "settings.h"
#include "speedRun.h"
#include "tic_tac_toe.h"
#include "enigma.h"
#include "Multiplayer.h"
#include "serie.h"

//* PUBLIC VARS
SDL_Surface *screen;
SDL_Event    event;

//* SCREEN RESOLUTION
int SCREEN_WIDTH  = 1920;
int SCREEN_HEIGHT = 1080;
int SCREEN_BPP    = 32;

//? --------------------- COLORS PROTOTYPE DECLARATION PART ---------------------
//* SDL_COLOR PUBLIC DEFINTION
SDL_Color WHITE = {255, 255, 255, 0};
SDL_Color BLACK = {0, 0, 0, 0};

//? -------------------- FUNCTIONS PROTOTYPE DECLARATION PART --------------------
/*
? --- initEverything() void func ---
* initialisation SDL1.2 environment
*/
void initEverything();

/*
? setScreen(int) void func
* x : 0               :: the screen will be in Windowed Mode
* x : SDL_FULLSCREEN  :: the screen will be in Fullscreen Mode
*/
void setScreen(int);

/*
? --- load_img(char *) SDL_Surface* ---
* optimizing the img process :: creat a new 32 bit img
*/
SDL_Surface *load_img(char *);

/*
? closeEverything() void func
* close SDL1.2 resources in exit action
*/
void closeEverything();

/* -----------------------------------------------------------
? --- SCANNING && EDITING FILES FUNCTIONS DECLARATION PART ---
-------------------------------------------------------------- */
/*
? - scanValue(char *path, int line) int func -
* scan the next format "%s %d"
*/
int scanValue(char *, int);

/*
? - *scanStr(char *path, char *info, int line) void func -
* scan the next format "%s"
*/
void scanStr(char *, char*, int);

/*
? - editValue(char *, char *, int, int) void func -
* update the changed option info
*/
void editValue(char *, char *, int, int);

/* ---------------------------------------------
? --- LOAD && FREEING FUNCS DECLARATION PART ---
------------------------------------------------*/
/*
? set_pos(surface *, char *, int) void fn
* set all (Sint16 x, Sint16 y) surfaces pos
*/
void set_pos(surface *, char *, int);

/*
? loadResources(surface* sub, char* path, int f_res, int l_res) void fun
* load all resources
*/
void loadResources(surface *, char *, int, int);

//? freeResources(surface*) void fun
void freeResources(surface *, TTF_Font *, Mix_Chunk *, int);

#endif
