// by_kayori_Nova_Grp
// 01/24/24
// kayori :: sittings.h
#ifndef __SETTINGS_H__
#define __SETTINGS_H__
                    /* INCLUDE PROTOTYPE DECLARATION PART */
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
                    /* STRUCT PROTOTYPE DECLARATION PART */
typedef struct Surface {                                                                            // Surface struct type
    SDL_Surface *screen;
    SDL_Rect pos;
} surface;
                    /* FUNCTIONS PROTOTYPE DECLARATION PART */
void settings(int*);
void loadResources(surface*);
void initResources(surface*);
SDL_Surface* load_img(char*);
void fullPath(SDL_Surface **, char*, int, char*);
void freeResources(surface*);
#endif