#ifndef STRUCTURES_QV
#define STRUCTURES_QV

////////////////////////////////////////

typedef struct Quit
{
	//Initialisation music and chunk
	Mix_Music* Music;
	Mix_Chunk* Chunk;
	
	//Initialisation background
	SDL_Rect Rect_quit;
	SDL_Surface* Img_bg;
	SDL_Surface* Img_quit_Yes;
	SDL_Surface* Img_quit_No;

	//Initialisation button images
	SDL_Rect Image_Yes,
			 Image_No;

	//Initialisation position button Start menu & clicked button
	int Actual_Position,
		Last_Position,
		Clicked_Button;

}QV;

////////////////////////////////////////

#endif