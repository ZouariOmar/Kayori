/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @update: 04/06/24
? @file:   settings.c
----------------------------------------------- */

#ifndef __SETTINGS_H__
#define __SETTINGS_H__

//? --------------------- STRUCT PROTOTYPE DECLARATION PART ----------------------
//? Surface struct
typedef struct Surface {
    SDL_Surface* win;
    SDL_Rect     pos;
} surface;

//? ----------------------- FUNCTIONS PROTOTYPE DECLARATION PART -----------------------
//? settings(int*) void func
void settings(int*);

//? scroll_UD(surface*, int*, int) void func
void scroll_UD(surface*, int*, int);

//? loadResources(surface*, char*) void func
void loadResources(surface*, char*);

//? set_pos(surface*) void func
void set_pos(surface* sub);

//? initResources(surface*) void func
void initResources(surface*);

//? freeResources(surface*) void func
void freeResources(surface*);

#endif