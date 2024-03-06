// by_kayori_Nova_Grp
// 01/24/24
// kayori :: lib.c
                    /* INCLUDE PROTOTYPE DECLARATION PART */
#include "../inc/inc.h"
#include "Main_Menu.c"
                    /* FUNCTIONS PROTOTYPE DEV PART */
void initEverything() {
    // * SDL initialisation process
    if(SDL_Init(SDL_INIT_EVERYTHING)) {
        fprintf(stderr, "%s: %s",SDL_ERRMSG00, SDL_GetError()); exit(1);
    }

    // * TTF initialisation process
    TTF_Init();

    // * Mix initialisation process
    if((Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024))) {
        fprintf(stderr, "%s: %s",SDL_ERRMSG04, SDL_GetError()); exit(1);
    }

    // * IMG initialisation process
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	//////////////
    setScreen(0);
    //////////////
    SDL_WM_SetCaption("Our Game Name", NULL);
}

// * free memory process
void closeEverything() {
	atexit(Mix_Quit);
	atexit(IMG_Quit);
	atexit(TTF_Quit);
	atexit(SDL_Quit);
}

// * optimizing the img process :: creat a new 32 bit img
SDL_Surface *load_img(char* path) {
    SDL_Surface *loadedImg = IMG_Load(path),
                *optimizedImg = NULL;
    if(loadedImg) {
        optimizedImg = SDL_DisplayFormatAlpha(loadedImg);
        SDL_FreeSurface(loadedImg);
    }
    return optimizedImg;
}

/*
* x : 0               :: the screen will be in Windowed Mode
* x : SDL_FULLSCREEN  :: the screen will be in Fullscreen Mode
*/
void setScreen(int x) {
    const SDL_VideoInfo* Video_Info = SDL_GetVideoInfo();
    if(Video_Info)
        screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF|x);
    else
        screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF|x);
    if(!screen) {
        fprintf(stderr, "%s : %s !", SDL_ERRMSG07, SDL_GetError()); exit(1);
    }
}