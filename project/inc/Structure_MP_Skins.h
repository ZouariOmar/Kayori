#ifndef STRUCTURES_MPS
#define STRUCTURES_MPS

////////////////////////////////////////

typedef struct Skin_Choice
{
	// Rect arrows
	SDL_Rect Rect_RA,								// Rect right arrow
			 Rect_LA;								// Rect left arrow

	// Rect Skin
	SDL_Rect Rect_Skin;								// Rect skin

	// Skin choice
	int Skin_N;										// Skin number (1, 2 or 3)

	// Position in the menu & Click detection
	int Click_Right,
		Click_Left;
}SC;

////////////////////////////////////////

typedef struct Multiplayer_Skins
{
	//Initialisation music and chunk
	Mix_Music* Music;
	Mix_Chunk* Chunk;
	
	//Initialisation images
	SDL_Surface* Background,						// Multiplayer skin menu background
			   * Img_RA,							// Image Right arrow selected
			   * Img_LA,							// Image Left arrow selected
			   * Img_Play,							// Image Play button selected
			   * Img_Return,						// Image return button selected
			   * Img_Skin1,							// Image skin 1
			   * Img_Skin2,							// Image skin 2
			   * Img_Skin3,							// Image skin 3
			   * Img_Skin4;							// Image skin 4

	// Buttons rect
	SDL_Rect Rect_Play,
			 Rect_Return;

	// Players skin choice
	SC P1,											// Player 1 skin choice
	   P2;											// Player 2 skin chocie

	// Player position && click
	int Actual_Position,							// Actual position in the menu
		Last_Position,								// Last position in the menu
		Clicked_Button;								// 

}MPS;

////////////////////////////////////////

#endif