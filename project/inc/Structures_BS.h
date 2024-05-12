#ifndef STRUCTURES_BS
#define STRUCTURES_BS

////////////////////////////////////////

typedef struct Best_Score
{
	//Initialisation music and chunk
	Mix_Music* Music;
	
	//Return button
	SDL_Rect Rect_Arrow;

	//Initialisation background
	SDL_Surface* Score;

	//Initialisation position button Start menu & clicked button
	int Clicked_Button;

} BS;

////////////////////////////////////////

#endif