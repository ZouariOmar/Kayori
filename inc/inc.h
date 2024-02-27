// by_kayori_Nova_Grp
// 01/24/24
// kayori :: inc.h
#ifndef __INC_H__
#define __INC_H__
                    /* INCLUDE PROTOTYPE DECLARATION PART */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// SDL1.2 INCLUDE PART
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
// OUR INC FILES
#include "SDL_Msg.h"
#include "settings.h"
#include "Main_Menu.h"
#include "Structures_MM.h"
#include "Start_Menu.h"
#include "Structures_SM.h"
#include "Quit_Verification.h"
#include "Structures_QV.h"
// PUBLIC VARS
SDL_Surface *screen;
SDL_Event event;
                    /* PRINCIPAL SCREEN RESOLUTION PROTOTYPE DECLARATION PART */
int SCREEN_WIDTH = 1920;
int SCREEN_HEIGHT = 1080;
int SCREEN_BPP = 32;
                    /* COLORS PROTOTYPE DECLARATION PART */
// TEXT COLORS
// define COLOR "ANSI CODE"...
// BACKGROUND COLORS
// define bgCOLOR "ANSI CODE"...
                    /* MSG PROTOTYPE DECLARATION PART */
// ERROR_MSG
// define errorMsgXX...
// SUCCESS_MSG
// define successMsgXX...
                    /* STRUCT PROTOTYPE DECLARATION PART */
typedef enum Boolean {
    false, true
} bool;
                    /* FUNCTIONS PROTOTYPE DECLARATION PART */
void CreatScreen(int);
#endif
