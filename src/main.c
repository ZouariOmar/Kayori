// by_kayori_Nova_Grp
// 01/24/24
// kayori :: main.c
                    /* INCLUDE PROTOTYPE DECLARATION PART */
#include "../lib/lib.c"
#include "../lib/menu/menu.c"
                    /* MAIN() INT FUNCTION DEV PART */
int main() {
	CreatSurface();
    SDL_Event usr_event;
    while(1) {                                                                                                                          // creat usr_event loop
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
    SDL_Quit();                                                                                                // free memory process
	return 0;
}