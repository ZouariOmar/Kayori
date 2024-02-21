#ifndef STRUCTURES_MM
#define STRUCTURES_MM

typedef struct Surface_t {                                                                            // Surface struct type
    SDL_Surface *UC_B;
    SDL_Surface *C_B;
    SDL_Rect pos;
} Surface_test;

// structure Main Menu

typedef struct Main_Menu
{
	//Initialisation button images
	Surface_test	Image_Start,
					Image_Multiplayer,
					Image_Settings,
					Image_Quit;

	//Initialisation background image
	SDL_Surface *Image_background_MM;

	//Initialisation position button Main menu & du bouton clické
	int Actual_Position,
		Last_Position,
		Clicked_Button,
		Compteur_Blit_Fond,
		Quit_game;

}MM;

#endif