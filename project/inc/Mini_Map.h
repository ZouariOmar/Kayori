#include "Mini_Map_Struct.h"

///////////////////////////////////

#ifndef MINI_MAP
#define MINI_MAP

///////////////////////////////////

void InitMiniMapSP(MAP* Mini_Map, int* Quit);

///////////////////////////////////

void InitMiniMapMP(MAP* Mini_Map, int* Quit);

///////////////////////////////////

void AnimationMM(MAP* Mini_Map);

///////////////////////////////////

void UpdateVariables(SDL_Rect* MM_P, SDL_Rect* MMLP , SDL_Rect* MM_Camera, SDL_Rect Camera, SM* P);

///////////////////////////////////

void UpdateCameraMM(MAP* Mini_Map, SDL_Rect Surface, SDL_Rect P, SDL_Rect MMLP, SDL_Rect MM_Camera, int Side);

///////////////////////////////////

void UpdateMMSolo(MAP* Mini_Map, BGC* BG_Camera, SM* P);

///////////////////////////////////

void UpdateMMMulti(MAP* Mini_Map, BGC* BG_Camera, SM* P1, SM* P2);

///////////////////////////////////

void FreeMM(MAP* Mini_Map);

///////////////////////////////////

#endif