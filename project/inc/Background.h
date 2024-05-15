#include "Background_Struct.h"

#ifndef BACKGROUND
#define BACKGROUND

///////////////////////////////////

void InitFramesSP(BGC* BG_Camera, int* Quit);

///////////////////////////////////

void InitFramesMP(BGC* BG_Camera, int* Quit);

///////////////////////////////////

void InitBackgroundSP(BGC* BG_Camera, int* Quit);

///////////////////////////////////

void InitBackgroundMP(BGC* BG_Camera, int* Quit);

///////////////////////////////////

void CheckCameraPosition(SDL_Rect* Camera, SM* P, int WBG, int HBG);

///////////////////////////////////

void CharacterFrame(BGC* BG_Camera, PF* FP, SM* P);

///////////////////////////////////

void UpdateCameraSP(BGC* BG_Camera, SM* P);

///////////////////////////////////

void UpdateCameraMP(BGC* BG_Camera, SM* P1, SM* P2);

///////////////////////////////////

void UpdateBackgroundSP(BGC* BG_Camera, SM* P, int* Quit_Game);

///////////////////////////////////

void UpdateBackgroundMP(BGC* BG_Camera, SM* P1, SM* P2, int* Quit_Game);

///////////////////////////////////

void FreeBackgroundSP(int Lvl, BGC* BG_Camera);

///////////////////////////////////

void FreeBackgroundMP(int Lvl, BGC* BG_Camera);

///////////////////////////////////

#endif