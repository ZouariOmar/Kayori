// by_kayori_Nova_Grp
// 01/24/24
// kayori :: main.c
                    /* INCLUDE PROTOTYPE DECLARATION PART */
#include "../lib/lib.c"
                    /* MAIN() INT FUNCTION DEV PART */
int main() {
	initEverything();
    settings(screen);
	closeEverything();
    SDL_FreeSurface(screen);
    // freeEverything();
	return 0;
}