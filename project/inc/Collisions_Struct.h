#ifndef COLLISIONS_STRUCT
#define COLLISIONS_STRUCT

///////////////////////////////////

typedef struct Collisions
{
	SDL_Rect Spec_Col;			// Collision specificities
	int Type_Col;				// Collision type ( 0 : Normal || 1 : Deadly )
}Col;

///////////////////////////////////

#endif