/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @author: zouari_omar
* @update: 04//24
? @file:   settings.h
----------------------------------------------- */

#ifndef __SETTINGS_H__
#define __SETTINGS_H__

//? --------------------- STRUCT PROTOTYPE DECLARATION PART ----------------------
//? Surface struct
typedef struct Surface {
    SDL_Surface* win;
    SDL_Rect     pos;
} surface;

typedef void (*initFn)(surface *);

typedef void (*lunchFn)(surface *, Mix_Chunk *);

//? ----------------------- FUNCTIONS PROTOTYPE DECLARATION PART -----------------------
/*
? - settings() void func -
* usr can change the following options
    - controls_op (keyboard/controller conf)
    - video____op (fullscreen/windowed mode)
    - audio____op (music/sounds volume)
    - language_op (Eng/Frc language)
    - gamePlay_op (speedRun/MiniMap mode)
*/
void settings();

/*
? - scroll_UD(surface*, int*, int, Mix_Chunk) void func -
* scroll the left menu up and down
*/
void scroll_UD(surface*, int*, int, Mix_Chunk *);

/*
? - rn_settings(surface*) void fn -
* return to the main settings menu proccess
> usr_modification[#](sub)
*/
void rn_settings(surface *, Mix_Chunk *);

/* ----------------------------------
? --- INIT FUNCS DECLARATION PART ---
------------------------------------- */
/*
? - initResources(surface*) void func -
* > settings(int*)
* blit the first viewed res (not all them)
*/
void initResources(surface*);

/*
? - init_rs_ctrl(surface*) void func -
* blit the controls option menu
> initResources(surface*)
*/
void init_rs_ctrl(surface*);

/*
? - init_rs_vid(surface*) void func -
* blit the video option menu
* support the @autosave mode
> initResources(surface*)
*/
void init_rs_vid(surface*);

/*
? - init_rs_aud(surface*) void func -
* blit the audio option menu
* support the @autosave mode
> initResources(surface*)
*/
void init_rs_aud(surface*);

/*
? - init_rs_lang(surface*) void func -
* blit the language option menu
* support the @autosave mode
> initResources(surface*)
*/
void init_rs_lang(surface*);

/*
? - init_rs_gmP(surface*) void func -
* blit the game_paly option menu
* support the @autosave mode
> initResources(surface*)
*/
void init_rs_gmP(surface*);

/*
? - init_kb_ctrl(surface *sub) void func -
* initialize the keyboard conf
> {controls(), kb_ctrls()}
*/
void init_kb_ctrl(surface *);

/*
? - init_cl_ctrl(surface *sub) void func -
* initialize the controller conf
> {controls(), kb_ctrls()}
*/
void init_cl_ctrl(surface *);

/* ----------------------------------------------
? --- USR_MODIFICATION FUNCS DECLARATION PART ---
------------------------------------------------- */

//? -- controls functions declaration part --
/*
? - controls(surface *sub, Mix_Chunk *pip) void func -
* in this section the usr can change:
    * keyboard_configuration
    * controller_configuration
> settings()
*/
void controls(surface*, Mix_Chunk *);

/*
? - ctrl_scroll_UD(surface*, int*, int) void fn -
* scroll the "controls" menu up and down
> settings()
! support only the controls(surface*) function
*/
void ctrl_scroll_UD(surface *, int *, int, Mix_Chunk *);

/*
? - kb_ctrl(surface *sub, int ctrl_usrOpPos) void fn -
* kb_sub_controls_option
* usr can modify the keyboard configuration
> controls()
*/
void kb_ctrl(surface *, int, Mix_Chunk *);

/*
? - kb_ctrl_scroll_UD(surface* sub, int* ctrl_usrOpPos, int direction, Mix_Chunk *pip) void fn -
* scroll the "keyboard conf" menu up and down
> kb_ctrl()
! support only the controls(surface*) function
*/
void kb_ctrl_scroll_UD(surface *, int *, int, Mix_Chunk *);

/*
? - cl_ctrl(surface *sub, int ctrl_usrOpPos) void fn -
* cl_sub_controls_option
* usr can modify the controller configuration
> controls()
*/
void cl_ctrl(surface *, int);

/*
? - rn_ctrl(surface *sub, int ctrl_usrOpPos) void fn -
* return to the controls settings menu proccess
> controls()
*/
void rn_ctrl(surface *sub, int ctrl_usrOpPos);

/*
? - video(surface*) void func -
* in this section the usr can change:
    * fullscreen mode
        * 0:              windowed(1920x1080)
        * SDL_FULLSCREEN: fullscreen
* support the @autosave mode
> settings()
*/
void video(surface*, Mix_Chunk *);

/*
? - audio(surface*) void func -
* in this section the usr can change:
    * audio volume
        * music: usr can change the volume from 0 to 16
        * sound: usr can change the volume from 0 to 16
* support the @autosave mode
> settings()
*/
void audio(surface*, Mix_Chunk *);

/*
? - language(surface*) void func -
* in this section the usr can change:
    * language
        * 0: @English
        * 1: @France
* support the @autosave mode
> settings()
*/
void language(surface*, Mix_Chunk *);

//? -- gamePlay functions declaration part --
/*
? - gamePlay(surface*) void func -
* in this section the usr can change:
    * speedRun mode
        * 0: speedRun in @off_mode
        * 1: speedRun in @on_mode
* support the @autosave mode
> settings()
*/                  
void gamePlay(surface*, Mix_Chunk *);

/*
? - gm_scroll_UD(surface *sub, int *gm_usrOpPos, int direction) void fn -
* scroll up/down the gamePlay menu
> gamePlay(surface*)
*/
void gm_scroll_UD(surface *, int *, int, Mix_Chunk *);

/*
? - gm_scroll_LR(surface *sub, char *op_name, char *format, int line, int conf) void fn -
* scroll left/right the gamePlay menu
> gamePlay(surface*)
*/
void gm_scroll_LR(surface *, char *, char *, int, int, Mix_Chunk *);

/*
? - ctrl_volume(surface *sub, char *type_vol, int line, int conf) void fn -
> audio(surface*)
*/
void ctrl_volume(surface *, char *, int, int, Mix_Chunk *);

#endif