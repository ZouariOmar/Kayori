// by_kayori_Nova_Grp
// 01/24/24
// kayori :: main.c
                    /* INCLUDE PROTOTYPE DECLARATION PART */
#include "../lib/lib.c"
                    /* MAIN() INT FUNCTION DEV PART */
int main() {
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1) {                                                                                           // initializing SDL process
        fprintf(stderr, "Error: couldn't initialize SDL: %s !", SDL_GetError()); exit(1);
    } atexit(SDL_Quit);
    SDL_Surface *screen = SDL_SetVideoMode(width, hight, 32, SDL_HWSURFACE | SDL_SWSURFACE);                                            // initializing screen process
    if(!screen) {
        fprintf(stderr, "Error: couldn't initialize the screen: %s !", SDL_GetError()); exit(1);
    } atexit(SDL_Quit);
    while(1) {                                                                                                                          // creat usr_event loop
        SDL_Event usr_event;
        SDL_WaitEvent(&usr_event);
        switch (usr_event.type) {
            case SDL_QUIT:                                                                                                              // quit option
                exit(0);
            // rest of option...
            default:
                break;
        }
    }
    //rest of code...
    SDL_FreeSurface(screen); SDL_Quit();                                                                                                // free memory process
	return 0;
}