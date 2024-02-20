// by_kayori_Nova_Grp
// 01/24/24
// kayori :: main.c
                    /* INCLUDE PROTOTYPE DECLARATION PART */
#include "lib.c"
                    /* MAIN() INT FUNCTION DEV PART */
int main() {
	initEverything();
    closeEverything();
    MainMenu(screen, event);            // ! memory leak here
    SDL_FreeSurface(screen);
	return 0;
}