#ifndef BACKGROUND_STRUCT
#define BACKGROUND_STRUCT

///////////////////////////////////

typedef struct Character_Frames
{
	// Default frame
	SDL_Surface* Standing[2];

	// Wall friction
	SDL_Surface* Wall_Friction[2];

	// Run
	SDL_Surface* Run_Left[8];
	SDL_Surface* Run_Right[8];

	// Jump
	SDL_Surface* Jump_Left;
	SDL_Surface* Jump_Right;

	// Dash
	SDL_Surface* Dash[10];
}CF;

///////////////////////////////////

typedef struct Player_Frames
{
	CF Frames;
	SDL_Rect Frame_Blit;
	int Pos_Frame;
}PF;

///////////////////////////////////

typedef struct Background_Camera
{
	// Width and Height of the background
	int WBG,										// Width background
		HBG;										// Height background

	// Background Images
	SDL_Surface * Normal_bg,						// Normal background
			    * Dynamic_bg,						// Dynamic background
				* Dynamic_2,                      // Dynamic BKG2
				* Dynamic_3;						// Dyn 3

	// Character health images
	SDL_Surface * No_Hit,
				* Hit_1,
				* Hit_2,
				* Hit_3,
				* Hit_4,
				* Hit_5;

	// Chargement image
	SDL_Surface* Chargement;

	// Character frames
	PF P1,
	   P2;
	
	int Number_P;									// Number of players

	// ========== Single player ========== //

	// Single player Camera
	SDL_Rect Camera;								// Camera single player

	// ========== Multiplayer ========== //

	// Multiplayer camera
	SDL_Rect Camera1,								// Camera player 1
			 Camera2,								// Camera player 2
			 Position_BC_P2;			// Position blit camera player 2


}BGC;

///////////////////////////////////

#endif