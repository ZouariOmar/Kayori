// by_kayori_Nova_Grp
// 01/24/24
// kayori :: inc.h
#ifndef __INC_H__
#define __INC_H__
                    /* INCLUDE PROTOTYPE DECLARATION PART */
#include "SDL_Msg.h"
#include "settings.h"
                    /* PUBLIC VARIABLES PROTOTYPE DECLARATION PART */
SDL_Surface *screen;
SDL_Event event;
                    /* PRINCIPAL SCREEN RESOLUTION PROTOTYPE DECLARATION PART */
int SCREEN_WIDTH = 1920;
int SCREEN_HEIGHT = 1080;
int SCREEN_BPP = 32;
                    /* COLORS PROTOTYPE DECLARATION PART */

                    /* MSG PROTOTYPE DECLARATION PART */
// define errorMsgXX...
// SUCCESS_MSG
// define successMsgXX...
                    /* STRUCT PROTOTYPE DECLARATION PART */
                    /* FUNCTIONS PROTOTYPE DECLARATION PART */
void initEverything();                                                                              // initEverything() void func > main.c
void closeEverything();                                                                             // closeEverything() void func > main.c
#endif