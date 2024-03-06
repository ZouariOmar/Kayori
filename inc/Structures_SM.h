#ifndef STRUCTURES_SM
#define STRUCTURES_SM

////////////////////////////////////////

typedef struct Start_Menu
{
	//Initialisation music and chunk
	Mix_Chunk* Chunk;
	
	//Initialisation button images
	Surface_test Image_Quit_Button,
				 Image_Save1,
				 Image_Save2,
				 Image_Save3;

	//Initialisation background image
	SDL_Surface *Image_background_SM;

	//Initialisation position button Start menu & clicked button
	int Actual_Position,
		Last_Position,
		Clicked_Button;

}SM;

////////////////////////////////////////

#endif