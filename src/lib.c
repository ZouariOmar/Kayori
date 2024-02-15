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
    }
    TTF_Init();                                                                                             // TTF initialisation process
    if((Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024))) {                            // MIX initialisation process
        fprintf(stderr, "%s: %s",SDL_ERRMSG04, SDL_GetError()); exit(1);
    }
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);                                                                  // IMG initialisation process
	const SDL_VideoInfo* Video_Info = SDL_GetVideoInfo();
    if(Video_Info)
        screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
    else
        screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,SDL_SWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
    if(!screen) {
        fprintf(stderr, "%s : %s !", SDL_ERRMSG07, SDL_GetError()); exit(1);
    }
    SDL_WM_SetCaption("Our Game Name", NULL);
}
void closeEverything() {                                                                                    // free memory process
	atexit(Mix_Quit);
	atexit(IMG_Quit);
	atexit(TTF_Quit);
	atexit(SDL_Quit);
}
SDL_Surface *load_img(char* path) {
    SDL_Surface *loadedImg = IMG_Load(path),
                *optimizedImg = NULL;
    if(loadedImg) {
        optimizedImg = SDL_DisplayFormatAlpha(loadedImg);
        SDL_FreeSurface(loadedImg);
    }
    return optimizedImg;
}