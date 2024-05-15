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

	// TTF font
	TTF_Font* Font;

	// Color text
	SDL_Color Text_Color;

	// TTF text
	SDL_Surface * Txt_S1,
				* Txt_S2,
				* Txt_S3;

	// TTF rect
	SDL_Rect Rect_S1,
			 Rect_S2,
			 Rect_S3;

	//Initialisation position button Start menu & clicked button
	int Clicked_Button;

} BS;

////////////////////////////////////////

#endif