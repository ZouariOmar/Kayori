#ifndef STRUCTURES_MM
#define STRUCTURES_MM

typedef struct Surface_t {
    SDL_Surface *UC_B;
    SDL_Surface *C_B;
    SDL_Rect pos;
} Surface_test;

// structure Main Menu

typedef struct Main_Menu
{
	//Initialisation music and chunk

	Mix_Music* Music;
	Mix_Chunk* Chunk;

	//Initialisation button images

	SDL_Rect Blit_Buttons;

	SDL_Surface *	Image_Start,
				*	Image_Multiplayer,
				*	Image_Settings,
				*	Image_Quit;

	//Initialisation background image

	SDL_Surface *Image_background_MM;

	//Initialisation animation

	SDL_Rect Blit_animation;

	SDL_Surface *	Animation1,
				*	Animation2;

	//Initialisation position button Main menu & du bouton clické

	int Actual_Position,
		Last_Position,
		Clicked_Button;

}MM;

#endif