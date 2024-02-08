// by_kayori_Nova_Grp
// 01/24/24
// kayori :: inc.h
#ifndef __INC_H__
#define __INC_H__
                    /* INCLUDE PROTOTYPE DECLARATION PART */
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL_Msg.h"
#include "settings.h"
SDL_Surface *screen;
const int width = 1920, hight = 1080;               // Full HD
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
typedef struct Surface {
    SDL_Surface *screen;
    SDL_Rect pos;
} surface;
typedef enum Bool {                                             // bool values def
    false,
    true
} bool;
typedef enum Moves {                                            // basics moves values def
    up, down, left, right
} moves;
                    /* FUNCTIONS PROTOTYPE DECLARATION PART */
void initEverything();
void closeEverything();
void settings(SDL_Surface*);
#endif