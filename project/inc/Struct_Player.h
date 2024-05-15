#ifndef STRUCT_PLAYER
#define STRUCT_PLAYER

///////////////////////////////////

#define Gravity 6

#define DEFAULT_SPEED 8

#define Y_VELOCITY -18

#define X_VELOCITY 15

///////////////////////////////////

typedef struct Player_Keys
{
	SDLKey Right,
		   Left,
		   Up,
		   Down,
		   Jump,
		   Dash,
		   Inter;

	int Pause;
	int Interact;
}PK;

///////////////////////////////////

typedef struct Structure_Mechanics
{
	// === Player Keys ===

	// Keys of the player
	PK Keys;

	// === Player Rect === 

	// Actual player position
	SDL_Rect A_Pos; 						// Actual position

	// Last player position
	SDL_Rect L_Pos; 						// Last position

	// Default position
	int Default_X,
		Default_Y;

	// Death check

	int Death,
		N_Death;

	// === Player mechanics === 

	// Basic movements
	int Move_Up,
		Move_Down,
		Move_Right,
		Move_Left;

	float Move_Speed,
		  Move_Acc; 						// Move acceleration
		
	// Dash mechanic
	int Dash_Direction,
		Dash_Distance,
		Default_DD; 						// Default Dash direction

	// Jump mechanic

	int Y_Velocity,
		X_Velocity,
		Wall_Jump;

	// Collision related mechanics
	int	Wall_Friction,
		Grounded;

	// Level transition
	int Lvl_Trans;

}SM;

///////////////////////////////////

#endif