// by_kayori_Nova_Grp
// 01/24/24
// kayori :: settings.h
#ifndef __SETTINGS_H__
#define __SETTINGS_H__
                    /* INCLUDE PROTOTYPE DECLARATION PART */

                    /* STRUCT PROTOTYPE DECLARATION PART */
// * Surface struct type
typedef struct Surface {
    SDL_Surface *screen;
    SDL_Rect pos;
} surface;
                    /* FUNCTIONS PROTOTYPE DECLARATION PART */
// * settings() void func
void settings(int*);

// * loadResources() void func
void loadResources(surface*);

// * loadResources() void func
void initResources(surface*);

// * load_img() SDL_Surface* func
SDL_Surface* load_img(char*);

// * freeResources() void func
void freeResources(surface*);

#endif