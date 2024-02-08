// by_kayori_Nova_Grp
// 01/24/24
// kayori :: lib.c
                    /* INCLUDE PROTOTYPE DECLARATION PART */
#include "../inc/inc.h"
#include "settings.c"
                    /* FUNCTIONS PROTOTYPE DEV PART */
void initEverything() {
    if(SDL_Init(SDL_INIT_EVERYTHING)) {                                                                     // SDL initialisation process
        fprintf(stderr, "%s: %s",SDL_ERRMSG00, SDL_GetError()); exit(1);
    } atexit(SDL_Quit);
    TTF_Init();
    // Mix_Init(MIX_INIT_MP3);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	screen =  SDL_SetVideoMode(width, hight, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Our Game Name", NULL);
}
void closeEverything() {                                                                                    // free memory process
	// atexit(Mix_Quit);
	atexit(IMG_Quit);
	atexit(TTF_Quit);
	atexit(SDL_Quit);
}
