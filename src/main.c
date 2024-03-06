// by_kayori_Nova_Grp
// 01/24/24
// kayori :: main.c
                    /* INCLUDE PROTOTYPE DECLARATION PART */
#include "lib.c"
                    /* MAIN() INT FUNCTION DEV PART */
int main() {
    Mix_Chunk *pip = Mix_LoadWAV("pkg//music//rac_menu_beep.wav");
	initEverything();
    closeEverything();
    MainMenu();
    SDL_FreeSurface(screen);
	return 0;
}