#include "Structures_MM.h"

#ifndef MAIN_MENU
#define MAIN_MENU

////////////////////////////////////////

void InitialisationSDL(SDL_Surface** Screen);

////////////////////////////////////////

void InitialisationMM(SDL_Surface* Screen,MM* Main_Menu);

////////////////////////////////////////

void ButtonBliting(SDL_Surface* Screen, SDL_Surface* UC_Image1, SDL_Rect* UC_Rect1, SDL_Surface* UC_Image2, SDL_Rect* UC_Rect2, SDL_Surface* UC_Image3, SDL_Rect* UC_Rect3, SDL_Surface* C_Image, SDL_Rect* C_Rect);

////////////////////////////////////////

void DrawButtonsMainMenu(SDL_Surface* Screen,MM* MainMenu);

////////////////////////////////////////

void KeyboardEventMM(SDL_Event Event,MM* MainMenu);

////////////////////////////////////////

void MouseEventMM(SDL_Event Event,MM* MainMenu);

////////////////////////////////////////

void MainMenu(SDL_Surface* Screen,SDL_Event Event);

////////////////////////////////////////

void ClearMainMenu(SDL_Surface* Screen,MM* MainMenu);

////////////////////////////////////////

#endif