#ifndef STRUCTURES_MP
#define STRUCTURES_MP

////////////////////////////////////////

typedef struct Multiplayer
{
	//Initialisation music and chunk
	Mix_Music* Music;
	Mix_Chunk* Chunk;
	
	//Initialisation background
	SDL_Rect Rect_MP;
	SDL_Rect Rect_Arrow;

	SDL_Surface* Img_Start;
	SDL_Surface* Img_Score;
	SDL_Surface* Img_Arrow;
	
	//Initialisation button images
	SDL_Rect Rect_Start,
			 Rect_Score;

	//Initialisation position button Start menu & clicked button
	int Actual_Position,
		Last_Position,
		Clicked_Button;

}MP;

////////////////////////////////////////

#endif