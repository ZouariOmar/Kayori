// by_kayori_Nova_Grp
// 01/24/24
// kayori :: sittings.h
#ifndef __SETTINGS_H__
#define __SETTINGS_H__
                    /* INCLUDE PROTOTYPE DECLARATION PART */

                    /* STRUCT PROTOTYPE DECLARATION PART */
typedef struct Surface {                                                                            // Surface struct type
    SDL_Surface *screen;
    SDL_Rect pos;
} surface;
                    /* FUNCTIONS PROTOTYPE DECLARATION PART */
void settings(int*);                                // settings() void func
void loadResources(surface*);                       // loadResources() void func
void initResources(surface*);                       // loadResources() void func
SDL_Surface* load_img(char*);                       // load_img() SDL_Surface* func
void freeResources(surface*);                       // freeResources() void func
#endif