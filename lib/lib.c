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
    } TTF_Init();                                                                                           // TTF initialisation process
    // coda = TTF_OpenFont("pkg//font//coda//Coda-Regular.ttf", 40);
    if((Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024))) {                            // MIX initialisation process
        fprintf(stderr, "%s: %s",SDL_ERRMSG04, SDL_GetError()); exit(1);
    }
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);                                                                  // IMG initialisation process
	screen =  SDL_SetVideoMode(width, hight, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if(!screen) {
        fprintf(stderr, "%s : %s !", SDL_ERRMSG07, SDL_GetError()); exit(1);
    } SDL_WM_SetCaption("Our Game Name", NULL);
}
void closeEverything() {                                                                                    // free memory process
	atexit(Mix_Quit);
	atexit(IMG_Quit);
	atexit(TTF_Quit);
	atexit(SDL_Quit);
}
void freeEverything() {
    SDL_FreeSurface(screen);
    SDL_FreeSurface(img00.screen);
    Mix_FreeMusic(music);
    Mix_FreeChunk(music1);
    // SDL_FreeSurface(img01.screen);
    // SDL_FreeSurface(img02.screen);
    // TTF_CloseFont(coda);
}
