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

typedef void (*InitFunc)(surface*);

//? ----------------------- FUNCTIONS PROTOTYPE DECLARATION PART -----------------------
//? settings(int*) void func
void settings(int*);

//? scroll_UD(surface*, int*, int) void func > settings(int*)
void scroll_UD(surface*, int*, int);

/*
? --- INIT FUNCS DECLARATION PART ---
*/
//? initResources(surface*) void func > settings(int*)
void initResources(surface*);

//? set_pos(surface*) void func      > initResources(surface*)
void set_pos(surface*);

//? init_rs_ctrl(surface*) void func > initResources(surface*)
void init_rs_ctrl(surface*);

//? init_rs_vid(surface*) void func  > initResources(surface*)
void init_rs_vid(surface*);

//? init_rs_aud(surface*) void func  > initResources(surface*)
void init_rs_aud(surface*);

//? init_rs_lang(surface*) void func > initResources(surface*)
void init_rs_lang(surface*);

//? init_rs_gmP(surface*) void func  > initResources(surface*)
void init_rs_gmP(surface*);

//? scanValue(int) int func          > init_rs_#(surface*)
int scanValue(int);

/*
? --- USR_MODIFICATION FUNCS DECLARATION PART ---
*/
//? controls(surface*, int) void func           > settings(int*)
void controls(surface*);

//? video(surface*) void func                   > settings(int*)
void video(surface*);

//? audio(surface*) void func                   > settings(int*)
void audio(surface*);

//? language(surface*) void func                > settings(int*)
void language(surface*);

//? gamePlay(surface*) void func                > settings(int*)
void gamePlay(surface*);

//? rs_scroll_UD(surface*, int*, int) void func > settings(int*)
void rs_scroll_UD(surface*, int*, int);

//? rn_settings(surface*) void func             > usr_modification[#](sub)
void rn_settings(surface*);

//? editValue(int) void func                    > usr_modification[#](sub)
void editValue(char*, char*, int, int);

/*
? --- LOAD && FREEING FUNCS DECLARATION PART ---
*/
//? loadResources(surface*, char*) void func   > settings(int*)
void loadResources(surface*, char*, int, int);

//? freeResources(surface*) void func          > settings(int*)
void freeResources(surface*);

#endif