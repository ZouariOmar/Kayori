#include "Structures_QV.h"

#ifndef QUIT_VERIFICATION
#define QUIT_VERIFICATION

////////////////////////////////////////

void InitialisationQV(QV* Quit,int* Quit_Game);

////////////////////////////////////////

void ButtonBlitingQV(SDL_Surface* Screen, SDL_Surface* UC_Image1, SDL_Rect* UC_Rect1, SDL_Surface* C_Image, SDL_Rect* C_Rect);

////////////////////////////////////////

void DrawButtonsQV(SDL_Surface* Screen,QV* Quit);

////////////////////////////////////////

void KeyboardEventQV(SDL_Event Event,QV* Quit);

////////////////////////////////////////

void MouseEventQV(SDL_Event Event,QV* Quit);

////////////////////////////////////////

void QuitVerification(SDL_Surface* Screen,SDL_Event Event,int* Quit_Game);

////////////////////////////////////////

void ClearQV(QV* Quit);

////////////////////////////////////////

#endif