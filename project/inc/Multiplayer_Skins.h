
#ifndef MULTIPLAYER_MENU_SKINS
#define MULTIPLAYER_MENU_SKINS

#include "Structure_MP_Skins.h"

////////////////////////////////////////

void InitialisationMPS(MPS* Skin,int* Quit_Game);

////////////////////////////////////////

void UpdateButtonsMPS(MPS* Skin);

////////////////////////////////////////

void UpdateSkinsMPS(MPS* Skin ,SC* P);

////////////////////////////////////////

void KeyboardEventMPS(MPS* Skin);

////////////////////////////////////////

void MouseEventMPS(MPS* Skin);

////////////////////////////////////////

void MovementEventMPS(MPS* Skin);

////////////////////////////////////////

void MenuMPS(int* Quit_Game);

////////////////////////////////////////

void ClearMPS(MPS* Skin);

////////////////////////////////////////

#endif