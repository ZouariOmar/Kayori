#ifndef STRUCTURES_QV
#define STRUCTURES_QV

////////////////////////////////////////

typedef struct Image_Background
{
	SDL_Surface* Image;
	SDL_Rect pos;
}IBG;

////////////////////////////////////////

typedef struct Quit
{
	//Initialisation music and chunk
	Mix_Music* Music;
	Mix_Chunk* Chunk;
	
	//Initialisation background
	IBG Image_Background;

	//Initialisation button images
	Surface_test Image_Yes,
				 Image_No;

	//Initialisation position button Start menu & clicked button
	int Actual_Position,
		Last_Position,
		Clicked_Button;

}QV;

////////////////////////////////////////

#endif