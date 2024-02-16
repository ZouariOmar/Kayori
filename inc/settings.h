// by_kayori_Nova_Grp
// 01/24/24
// kayori :: sittings.h
#ifndef __SETTINGS_H__
#define __SETTINGS_H__
                    /* INCLUDE PROTOTYPE DECLARATION PART */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
                    /* STRUCT PROTOTYPE DECLARATION PART */
typedef struct Surface {                                                                            // Surface struct type
    SDL_Surface *screen;
    SDL_Rect pos;
} surface;
/*typedef struct Music {
    Mix_Music *pop;
};*/
typedef enum Boolean {
    false, true
} bool;
                    /* FUNCTIONS PROTOTYPE DECLARATION PART */
void loadResources(surface*);
void initResources(surface*);
SDL_Surface* load_img(char*);
void fullPath(SDL_Surface **, char*, int, char*);
// void setImg(surface, surface);
void freeResources(surface*);
// bool is_inArea(SDL_Event);
#endif