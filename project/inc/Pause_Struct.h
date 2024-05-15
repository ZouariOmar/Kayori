#ifndef STRUCTURE_PAUSE
#define STRUCTURE_PAUSE

////////////////////////////////////////

typedef struct Pause_Game
{
	//Initialisation music and chunk
	Mix_Music* Music;
	Mix_Chunk* Chunk;
	
	//Initialisation background
	SDL_Surface* Img_PG_Resume;
	SDL_Surface* Img_PG_Return;

	//Initialisation button images
	SDL_Rect Image_Resume,
			 Image_Return;

	//Initialisation position button Start menu & clicked button
	int Actual_Position,
		Last_Position,
		Clicked_Button;

}PG;

////////////////////////////////////////

#endif