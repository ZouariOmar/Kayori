#ifndef MINI_MAP_STRUCT
#define MINI_MAP_STRUCT

///////////////////////////////////

typedef struct Mini_Map
{
	// Mini map images
	SDL_Surface * Normal_MM,					 // Normal mini map image
				* Dynamic_MM,					 // Dynamic mini map image
				* PMMR,							 // Player mini map right side
				* PMML,							 // Player mini map left side
				* IP;							 // Interrogation point mini map

	// Interrogation point variables
	SDL_Rect Rect_IP;							 // Interrogation point rect
	int FR;										 // Frame rate

	// ========== Single player ========== //

	// Mini map Camera
	SDL_Rect Surface,							 // Rect of the surface of the blit
			 Camera;							 // Mini map camera
	
	// Mini map player
	SDL_Rect P,									 // Mini map player
			 MMLP;                               // Last position of the player in the mini map

	// ========== Multiplayer ========== //

	// Mini map Camera
	SDL_Rect Surface1,							 // Rect of the surface of the blit ( Player 1 )
			 Surface2,							 // Rect of the surface of the blit ( Player 2 )
			 Camera1,							 // Mini map camera ( Player 1 )
			 Camera2;							 // Mini map camera ( Player 2 )

	// Mini map multiplayer
	SDL_Rect P1,								 // Mini map Player 1
			 MMLP1,								 // Mini map last position player 1
			 P2,								 // Mini map Player 2
			 MMLP2;								 // Mini map last position player 2
}MAP;

///////////////////////////////////

#endif