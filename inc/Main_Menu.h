#include "Structures_MM.h"

#ifndef MAIN_MENU
#define MAIN_MENU

////////////////////////////////////////

void InitialisationMM(MM* Main_Menu);

////////////////////////////////////////

void ButtonUpdate( SDL_Surface* UC_Image1, SDL_Rect* UC_Rect1, SDL_Surface* UC_Image2, SDL_Rect* UC_Rect2, SDL_Surface* UC_Image3, SDL_Rect* UC_Rect3, SDL_Surface* C_Image, SDL_Rect* C_Rect, Mix_Chunk* Chunk);

////////////////////////////////////////

void UpdateButtonsMainMenu(MM* Main_Menu);

////////////////////////////////////////

void KeyboardEventMM(MM* MainMenu);

////////////////////////////////////////

void MouseEventMM(MM* MainMenu);

////////////////////////////////////////

void MovementEventMM(MM* Main_Menu);

////////////////////////////////////////

void MainMenu(void);

////////////////////////////////////////

void ClearMainMenu(MM* MainMenu);

////////////////////////////////////////

#endif