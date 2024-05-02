#include "Structures_SM.h"

#ifndef START_MENU
#define START_MENU

////////////////////////////////////////

void InitialisationSM(SM* Start_Menu,int* Quit_Game);

////////////////////////////////////////

void KeyboardEventSM(SM* Start_Menu);

////////////////////////////////////////

void MouseEventSM(SM* Start_Menu);

////////////////////////////////////////

void MovementEventSM(SM* Main_Menu);

////////////////////////////////////////

void ButtonUpdate( SM* Start_Menu, SDL_Surface* UC_Image1, SDL_Rect* UC_Rect1, SDL_Surface* UC_Image2, SDL_Rect* UC_Rect2, SDL_Surface* UC_Image3, SDL_Rect* UC_Rect3, SDL_Surface* C_Image, SDL_Rect* C_Rect, Mix_Chunk* Chunk);

////////////////////////////////////////

void UpdateButtonsStartMenu(SM* Start_Menu);

////////////////////////////////////////

void StartMenu(int* Quit_Game);

////////////////////////////////////////

void ClearStartMenu(SM* Start_Menu);

////////////////////////////////////////

#endif