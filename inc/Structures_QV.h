#ifndef STRUCTURES_QV
#define STRUCTURES_QV

typedef struct Quit
{
	SDL_Rect Background,
			 Yes_Button,
			 No_Button;

	SDL_Surface *Background_Image_Quit,
				*Yes_UC_Image,
				*Yes_C_Image,
				*No_UC_Image,
				*No_C_Image;

	int Actual_Position,
		Last_Position,
		Clicked_Button,
		Compteur_Blit_Fond;

}QV;

#endif