#ifndef STRUCTURES_MM
#define STRUCTURES_MM

// structure Main Menu

typedef struct Main_Menu
{
	//Initialisation Main menu buttons
	SDL_Rect Button1MM,
			 Button2MM,
			 Button3MM,
			 Button4MM;

	//Initialisation Images
	SDL_Surface *Image_background_MM,
				*Image_Start_UC,
				*Image_Start_C,
				*Image_Multiplayer_UC,
				*Image_Multiplayer_C,
				*Image_Settings_UC,
				*Image_Settings_C,
				*Image_Quit_UC,
				*Image_Quit_C;

	//Initialisation position button Main menu & du bouton clické
	int Actual_Position,
		Last_Position,
		Clicked_Button,
		Compteur_Blit_Fond,
		Quit_game;

}MM;

#endif