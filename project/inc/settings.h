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

//? scroll_UD(surface*, int*, int) void func > settings(int*)
void scroll_UD(surface*, int*, int);

//? loadResources(surface*, char*) void func > settings(int*)
void loadResources(surface*, char*, int, int);

//? set_pos(surface*) void func              > initResources(surface*)
void set_pos(surface*);

//? initResources(surface*) void func        > settings(int*)
void initResources(surface*);

//? init_rs_ctrl(surface*) void func         > initResources(surface*)
void init_rs_ctrl(surface*);

//? init_rs_vid(surface*) void func          > initResources(surface*)
void init_rs_vid(surface*);

//? freeResources(surface*) void func        > settings(int*)
void freeResources(surface*);

#endif