#include "Structures_SM.h"

#ifndef START_MENU
#define START_MENU

////////////////////////////////////////

void InitialisationSM(SM* Start_Menu,int* Quit_Game);

////////////////////////////////////////

void KeyboardEventSM(SDL_Event Event,SM* Start_Menu);

////////////////////////////////////////

void MouseEventSM(SDL_Event Event,SM* Start_Menu);

////////////////////////////////////////

void DrawButtonsStartMenu(SDL_Surface* Screen,SM* Start_Menu);

////////////////////////////////////////

void StartMenu(SDL_Surface* Screen,SDL_Event Event,int* Quit_Game);

////////////////////////////////////////

void ClearStartMenu(SM* Start_Menu);

////////////////////////////////////////

#endif