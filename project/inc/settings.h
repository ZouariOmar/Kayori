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
? - scroll_UD(surface*, int*, int) void func -
* scroll the left menu up and down
*/
void scroll_UD(surface*, int*, int);


//? -- INIT FUNCS DECLARATION PART --
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


//? -- USR_MODIFICATION FUNCS DECLARATION PART --
/*
? - controls(surface*, int) void func -
* in this section the usr can change:
    * keyboard_configuration
    * controller_configuration
> settings()
*/
void controls(surface*);

/*
? - video(surface*) void func -
* in this section the usr can change:
    * fullscreen mode
        * 0:              windowed(1920x1080)
        * SDL_FULLSCREEN: fullscreen
* support the @autosave mode
> settings()
*/
void video(surface*);

/*
? - audio(surface*) void func -
* in this section the usr can change:
    * audio volume
        * music: usr can change the volume from 0 to 16
        * sound: usr can change the volume from 0 to 16
* support the @autosave mode
> settings()
*/
void audio(surface*);

/*
? - language(surface*) void func -
* in this section the usr can change:
    * language
        * 0: @English
        * 1: @France
* support the @autosave mode
> settings()
*/
void language(surface*);

/*
? - gamePlay(surface*) void func -
* in this section the usr can change:
    * speedRun mode
        * 0: speedRun in @off_mode
        * 1: speedRun in @on_mode
* support the @autosave mode
> settings()
*/                  
void gamePlay(surface*);

/*
? - gm_scroll_UD(surface *sub, int *gm_usrOpPos, int direction) void fn -
* scroll up/down the gamePlay menu
> gamePlay(surface*)
*/
void gm_scroll_UD(surface *, int *, int);

/*
? - gm_scroll_LR(surface *sub, char *op_name, char *format, int line, int conf) void fn -
* scroll left/right the gamePlay menu
> gamePlay(surface*)
*/
void gm_scroll_LR(surface *, char *, char *, int, int);

/*
? - scroll_UD(surface*, int*, int) void fn -
* scroll the right menu up and down
> settings()
! support only the controls(surface*) function
*/
void rs_scroll_UD(surface *, int *, int);

/*
? - rn_settings(surface*) void fn -
* return to the main settings menu proccess
> usr_modification[#](sub)
*/
void rn_settings(surface *);

/*
? - ctrl_volume(surface *sub, char *type_vol, int line, int conf) void fn -
> audio(surface*)
*/
void ctrl_volume(surface *, char *, int, int);

#endif