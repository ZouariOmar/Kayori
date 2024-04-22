/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @update: 04/06/24
? @file:   main.c
----------------------------------------------- */

//? -------------------- INCLUDE PROTOTYPE DECLARATION PART --------------------
#include "lib.c"

//? ----------------------- MAIN() INT FUNCTION DEV PART -----------------------
int main() {
    //* init part
	initEverything();
    closeEverything();

    //* game lunching part
    ////MainMenu();

    //! testing part
    settings();

    //* free the main screen surface
    SDL_FreeSurface(screen);

	return 0;
}