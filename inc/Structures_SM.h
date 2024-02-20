#ifndef STRUCTURES_SM
#define STRUCTURES_SM

////////////////////////////////////////

typedef struct Start_Menu
{
	//Initialisation Start menu buttons
	SDL_Rect Quit_Button,
			 Save1,
			 Save2,
			 Save3;

	//Initialisation Images
	SDL_Surface *Image_background_SM,
				*Image_UC_Quit_Button,
				*Image_C_Quit_Button,
				*Image_UC_Button_SM,
				*Image_C_Button_SM,
				*Image_NG,
				*Image_LG;

	//Initialisation position button Start menu & clicked button
	int Actual_Position,
		Last_Position,
		Clicked_Button,
		Compteur_Blit_Fond;

}SM;

////////////////////////////////////////

#endif