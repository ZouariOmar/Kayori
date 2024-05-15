#include "Collisions_Struct.h"
#include "Struct_Player.h"

#ifndef COLLISIONS
#define COLLISIONS

///////////////////////////////////

void InitCollisions(Col** C_Tab, int* N_Collision, int Lvl ,int* Quit);

///////////////////////////////////

void CollisionCheck(int Lvl, SM* P, Col* C_Tab, int i);

///////////////////////////////////

void FreeCollisions(Col* Tab);

///////////////////////////////////

#endif