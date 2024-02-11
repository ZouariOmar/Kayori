// by_kayori_Nova_Grp
// 01/24/24
// kayori :: inc.h
#ifndef __INC_H__
#define __INC_H__
                    /* INCLUDE PROTOTYPE DECLARATION PART */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL_Msg.h"
#include "settings.h"

SDL_Surface *screen;
Mix_Music *music;
Mix_Chunk *music1;
const int width = 1920, hight = 1080;               // Full HD
                    /* COLORS PROTOTYPE DECLARATION PART */

                    /* MSG PROTOTYPE DECLARATION PART */
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
void freeEverything();
void closeEverything();
void setImg(char*, surface*, int, int);
#endif