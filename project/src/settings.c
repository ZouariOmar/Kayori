/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @author: zouari_omar
* @IDE:    vsc
* @update: 04/27/24
? @file:   settings.c
----------------------------------------------- */

//? ----------------------- TODO SECTION DECLARATION PART -----------------------
/*
TODO_01: support the mouse events (motion and button down click) :: @ZouariOmar
TODO_02: fix the "volume bars view" in video(surface*) fn        :: @ZouariOmar
*/

//? ----------------------- NOTE SECTION DECLARATION PART -----------------------
/*
* @init_kb_ctrl: if you want to make all the txt in the center ==> strlen(txt) * LEN_OF_ONE_CHARACTER_BY_PIXEL
* @init_kb_ctrl: animate the key box (white / brown) to indicate the key changing process
* X42 = X43 = X44 / Y42 = Y43 = Y44
*/

//? -------------------- INCLUDE PROTOTYPE DECLARATION PART --------------------
#include "../inc/inc.h"
#include "serie.c"

//? ----------------------- FUNCTIONS PROTOTYPE DEV PART -----------------------
//* the curent user option position
int usrOpPos = 0;

//* init InitFunc public array var
initFn init[] = {
    init_rs_ctrl,
    init_rs_vid,
    init_rs_aud,
    init_rs_lang,
    init_rs_gmP,
    quit_settings
};

//* usr_modification InitFunc public array var
lunchFn usr_modification[] = {
    controls,
    video,
    audio,
    language,
    gamePlay,
    quit
};

void settings() {
    // * all 100 settings sub-surfaces
    surface sub[63];

    //* init the chunk 
    Mix_Chunk *pip = Mix_LoadWAV("project/res/music/rac_menu_beep.wav");

    //* load the @soundVolume
    Mix_VolumeChunk(pip, scanValue("project/doc/settings", 24));

    //? ----------------------- initializing part -----------------------
    //* load the settings resources
    loadResources(sub, "project/res/img_settings/LS/img",                              0,  12);
    loadResources(sub, "project/res/img_settings/RS/controls_menu/img_keyboard/img",   12, 34);
    loadResources(sub, "project/res/img_settings/RS/video_menu/img",                   34, 43);
    loadResources(sub, "project/res/img_settings/RS/audio_menu/img",                   43, 51);
    loadResources(sub, "project/res/img_settings/RS/language_menu/img",                51, 56);
    loadResources(sub, "project/res/img_settings/RS/gamePlay_menu/img",                56, 60);
    loadResources(sub, "project/res/img_settings/RS/controls_menu/img_controller/img", 60, 61);
    loadResources(sub, "project/res/img_settings/img",                                 61, 63);

    //* set potions for the other res
    set_pos(sub, "project/doc/settings_ref", 63);

    //* initializing the settings resources
    initResources(sub);
    init_rs_ctrl(sub);

    //* ctrl button selected by default
    SDL_BlitSurface(sub[7].win, NULL, screen, &sub[7].pos);

    // * update the screen
    SDL_Flip(screen);

    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                //? ----------------------- MOUSE MOTION EVENT -----------------------
                case SDL_MOUSEMOTION:
                    for (int i = 2; i < 7; i++)
                        if (event.motion.x >= sub[i].pos.x && event.motion.x <= sub[i].pos.x + sub[i].pos.w && event.motion.y >= sub[i].pos.y && event.motion.y <= sub[i].pos.y + sub[i].pos.h && (i - 2) != usrOpPos) {
                            scroll_UD(sub, &usrOpPos, i - 2 - usrOpPos, pip);
                            SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 230, &sub[0].pos), screen, &sub[0].pos);
                            init[usrOpPos](sub);
                        }
                    break;

                //? ------------------ MOUSE BUTTON DOWN CLICK EVENT ------------------
                case SDL_MOUSEBUTTONDOWN:
                    //* deselect the usr curent position
                    scroll_UD(sub, &usrOpPos, 0, pip);

                    //* activate the sub_menu mode (depending on the usr option position var)
                    usr_modification[usrOpPos](sub, pip);

                    break;
                //? ------------------- KB BUTTON DOWN CLICK EVENT -------------------
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        //? --- UP CLICK OPTION ---
                        case SDLK_UP:
                            scroll_UD(sub, &usrOpPos, -1, pip);
                            SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 230, &sub[0].pos), screen, &sub[0].pos);
                            init[usrOpPos](sub);
                            break;

                        //? --- DOWN CLICK OPTION ---
                        case SDLK_DOWN:
                            scroll_UD(sub, &usrOpPos, 1, pip);
                            SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 230, &sub[0].pos), screen, &sub[0].pos);
                            init[usrOpPos](sub);
                            break;

                        //? --- ENTER CLICK OPTION ---
                        case SDLK_SPACE:
                            //* deselect the usr curent position
                            scroll_UD(sub, &usrOpPos, 0, pip);
                            
                            //* activate the sub_menu mode (depending on the usr option position var)
                            usr_modification[usrOpPos](sub, pip);

                            if (usrOpPos == 5) {
                                //* reset the user option postion in default postion (0 by default)
                                usrOpPos = 0;
                                return;
                            }
                            break;

                        //? --- ESCAPE CLICK OPTION ---
                        case SDLK_ESCAPE:
                            //* reset the user option postion in default postion (0 by default)
                            usrOpPos = 0;

                            //* free all settings res
                            freeResources(sub, NULL, pip, 63);

                            return;

                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? --------------------- QUIT CLICK EVENT ---------------------
                case SDL_QUIT:
                    //* reset the user option postion in default postion (0 by default)
                    usrOpPos = 0;

                    //* free all settings res
                    freeResources(sub, NULL, pip, 63);

                    //* exit from the game
                    exit(EXIT_SUCCESS);
                    break;

                //? --------------------- OTHER CLICK EVENT ---------------------
                default:
                    break;
            }
        }
        //* update the screen
        SDL_Flip(screen);

        //* wait 100 millisecond befor returning
        SDL_Delay(100);
    }
}

void scroll_UD(surface* sub, int* usrOpPos, int direction, Mix_Chunk *pip) {
    //* play the pip chunk
    Mix_PlayChannel(-1, pip, 0);

    //* del the left menu
    SDL_BlitSurface(sub[0].win,  &sub[1].pos, screen, &sub[1].pos);
    SDL_BlitSurface(sub[0].win,  &sub[62].pos, screen, &sub[62].pos);

    //* blit the contour img
    SDL_BlitSurface(sub[1].win,  NULL, screen, &sub[1].pos);

    //* blit the @normal_img for the curent usr option
    if (*usrOpPos != 5)
        SDL_BlitSurface(sub[2 + *usrOpPos].win,  NULL, screen, &sub[2 + *usrOpPos].pos);

    //* blit the left menu
    for (int i = 0; i < 5; i++)
        if (i != *usrOpPos)
            SDL_BlitSurface(sub[2 + i].win,  NULL, screen, &sub[2 + i].pos);
    SDL_BlitSurface(sub[61].win,  NULL, screen, &sub[61].pos);

    //* update the usrOpPos
    *usrOpPos += direction;

    //* fix usr option postion
    if (*usrOpPos < 0)
        *usrOpPos = 5;
    else if (*usrOpPos > 5)
        *usrOpPos = 0;

    //* blit the @animated_img for the new usr option
    if (direction)
        SDL_BlitSurface(sub[7 + *usrOpPos].win,  NULL, screen, &sub[7 + *usrOpPos].pos);
}

void rn_settings(surface* sub, Mix_Chunk *pip) {
    //* play the pip chunk
    Mix_PlayChannel(-1, pip, 0);

    //* del the old rs_surface
    SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 230, &sub[0].pos), screen, &sub[0].pos);

    //* reset the sub menu surface
    init[usrOpPos](sub);

    //* reset the settings menu selection
    SDL_BlitSurface(sub[7 + usrOpPos].win,  NULL, screen, &sub[7 + usrOpPos].pos);
}

//? ----------------------- INIT FUNCTIONS DEV PART -----------------------
void initResources(surface* sub) {
    sub[0].pos.x = 0; sub[0].pos.y = 0;
    //* LS sub_surfaces blit part
    for (int i = 0; i < 7; i++)
        SDL_BlitSurface(sub[i].win,  NULL, screen, &sub[i].pos);
    SDL_BlitSurface(sub[61].win,  NULL, screen, &sub[61].pos);
}

void init_rs_ctrl(surface* sub) {
    //* blit the contour_04
    SDL_BlitSurface(sub[12].win, NULL, screen, (sub[12].pos.x = 953, sub[12].pos.y = 240, &sub[12].pos));

    for (int i = 13; i < 15; i++)
        SDL_BlitSurface(sub[i].win, NULL, screen, &sub[i].pos);
}

void init_kb_ctrl(surface *sub, int player) {
    //* del the old rs_surface
    SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 230, &sub[0].pos), screen, &sub[0].pos);

    //* blit the normal select keyboard res
    for (int i = 12; i < 15; i++)
        SDL_BlitSurface(sub[i].win, NULL, screen, &sub[i].pos);

    //* blit the @player_number :: ! need player int var
    SDL_BlitSurface(sub[17 + player].win, NULL, screen, &sub[17 + player].pos);

    //* blit the L/R player button
    SDL_BlitSurface(sub[36].win, NULL, screen, (sub[36].pos.x = 1253, sub[36].pos.y = 412, &sub[36].pos));
    SDL_BlitSurface(sub[37].win, NULL, screen, (sub[36].pos.x = 1373, sub[36].pos.y = 412, &sub[36].pos));

    //* reset the L/R initial values
    sub[36].pos.x = 1298; sub[36].pos.y = 300;

    //* blit the @player_keys
    for (int i = 19; i < 27; i++)
        SDL_BlitSurface(sub[i].win, NULL, screen, &sub[i].pos);

    /*
    ? -- blit the current used keys :: support the @autoSave mode --
    */
    //* init the "Groundation Foundation.ttf"
    TTF_Font *font = TTF_OpenFont("project/res/font/Groundation Foundation.ttf", 30);

    //* init key var
    surface key;

    //* set the @key_pos
    key.pos.x = 1430;
    key.pos.y = 477;

    //* init the key txt holder
    char info[100];

    //* i from 0 to 5 :: 5 indicate the @kb_moves
    for (int i = 0; i < 7; i++) {
        //* update info to take the current mvs
        scanStr("project/doc/ref_SDLkey", info, scanValue("project/doc/settings", 2 + (player * 10) + i));

        //* render the @key_info
        key.win = TTF_RenderText_Blended(font, info, BLACK);

        //* blit the @key_surface
        SDL_BlitSurface(key.win, NULL, screen, &key.pos);

        //* update the Y for the next keys pos
        key.pos.y += 72;
    }

    //* free the current used font
    SDL_FreeSurface(key.win);
    TTF_CloseFont(font);
}

void init_cl_ctrl(surface *sub) {
    SDL_BlitSurface(sub[60].win, NULL, screen, &sub[60].pos);
}

void init_rs_vid(surface* sub) {
    //* blit the video std imgs (2 img) && blit the L/R video buttons
    for (int i = 34; i < 38; i++)
        SDL_BlitSurface(sub[i].win, NULL, screen, &sub[i].pos);
    
    //* blit off/on fullscreen mode state
    (!scanValue("project/doc/settings", 22)) ? SDL_BlitSurface(sub[42].win, NULL, screen, &sub[42].pos) : SDL_BlitSurface(sub[41].win, NULL, screen, &sub[41].pos);
}

void init_rs_aud(surface* sub) {
    //* blit the contour_04
    SDL_BlitSurface(sub[12].win, NULL, screen, (sub[12].pos.x = 952, sub[12].pos.y = 274, &sub[12].pos));

    //* blit the 2 rounded bar
    sub[43].pos.x = 1341;
    SDL_BlitSurface(sub[43].win, NULL, screen, (sub[43].pos.y = 283, &sub[43].pos));
    SDL_BlitSurface(sub[43].win, NULL, screen, (sub[43].pos.y = 364, &sub[43].pos));

    //* blit the music and sound txt imgs
    SDL_BlitSurface(sub[44].win, NULL, screen, &sub[44].pos);
    SDL_BlitSurface(sub[45].win, NULL, screen, &sub[45].pos);

    //* blit the L/R "sound" buttons
    SDL_BlitSurface(sub[36].win, NULL, screen, (sub[36].pos.y = 381, &sub[36].pos));
    SDL_BlitSurface(sub[37].win, NULL, screen, (sub[37].pos.y = 381, &sub[37].pos));

    //* blit the L/R "music" buttons
    SDL_BlitSurface(sub[36].win, NULL, screen, (sub[36].pos.y = 300, &sub[36].pos));
    SDL_BlitSurface(sub[37].win, NULL, screen, (sub[37].pos.y = 300, &sub[37].pos));

    //* blit the music volume bars
    bar_volume(sub, scanValue("project/doc/settings", 23) / 8);

    //* Y42 = Y43 = Y44 :: we choose to change Y42
    sub[48].pos.y = 365;

    //* blit the sound volume bars
    bar_volume(sub, scanValue("project/doc/settings", 24) / 8);
}

void bar_volume(surface *sub, int volume) {
    //* blit the music/sound volume bars
    for (int i = 1; i <= volume; i++) {
        switch (i) {
            case 1:
                SDL_BlitSurface(sub[48].win, NULL, screen, &sub[48].pos);
                break;
            case 16:
                SDL_BlitSurface(sub[49].win, NULL, screen, &sub[48].pos);
                break;
            default:
                SDL_BlitSurface(sub[50].win, NULL, screen, &sub[48].pos);
                break;
        }
        sub[48].pos.x += 16;
    }

    //* reset the X42 and Y42
    sub[48].pos.x = 1341;
    sub[48].pos.y = 284;
}

void init_rs_lang(surface* sub) {
    //* blit the contour_03 and the shape
    SDL_BlitSurface(sub[34].win, NULL, screen, &sub[34].pos);
    SDL_BlitSurface(sub[55].win, NULL, screen, (sub[55].pos.x = 1319, sub[55].pos.y = 274, &sub[55].pos));

    //* blit the Eng and Frc normal imgs
    if (!scanValue("project/doc/settings", 25)) {
        //* Eng option selected
        SDL_BlitSurface(sub[53].win, NULL, screen, &sub[53].pos);
        SDL_BlitSurface(sub[52].win, NULL, screen, &sub[52].pos);
    } else {
        //* Frc option selected
        SDL_BlitSurface(sub[54].win, NULL, screen, &sub[54].pos);
        SDL_BlitSurface(sub[51].win, NULL, screen, &sub[51].pos);
    }
    // reset the X42 and Y42
    sub[48].pos.x = 1341;
    sub[48].pos.y = 284;
}

void init_rs_gmP(surface* sub) {
    //* blit the contour_04
    SDL_BlitSurface(sub[12].win, NULL, screen, (sub[12].pos.x = 952, sub[12].pos.y = 274, &sub[12].pos));

    //* blit the speedRun/miniMap normal imgs
    SDL_BlitSurface(sub[56].win, NULL, screen, &sub[56].pos);
    SDL_BlitSurface(sub[58].win, NULL, screen, &sub[58].pos);

    //* blit the L/R normal buttons for miniMap op
    SDL_BlitSurface(sub[36].win, NULL, screen, (sub[36].pos.y = 381, &sub[36].pos));
    SDL_BlitSurface(sub[37].win, NULL, screen, (sub[37].pos.y = 381, &sub[37].pos));

    //* blit the L/R normal buttons for speedRun op
    SDL_BlitSurface(sub[36].win, NULL, screen, (sub[36].pos.y = 300, &sub[36].pos));
    SDL_BlitSurface(sub[37].win, NULL, screen, (sub[37].pos.y = 300, &sub[37].pos));

    //* blit off/on miniMap mode state
    SDL_BlitSurface(sub[41 + !scanValue("project/doc/settings", 27)].win, NULL, screen, (sub[41].pos.y = 372, &sub[41].pos));

    //* blit off/on speedRun mode state
    SDL_BlitSurface(sub[41 + !scanValue("project/doc/settings", 26)].win, NULL, screen, (sub[41].pos.y = 292, &sub[41].pos));
}

void quit_settings(surface *sub) {
    SDL_BlitSurface(sub[62].win, NULL, screen, &sub[62].pos);
}

//? ----------------------- USR_MODIFICATION FUNCTIONS DEV PART -----------------------
void controls(surface* sub, Mix_Chunk *pip) {
    //* the curent user option position
    int ctrl_usrOpPos = 0;

    //* init @player_flag (P1 by default)
    int player = 0;

    //* init the kb_ctrl menu
    init_kb_ctrl(sub, player);

    //* blit the selected img (blit the animated "keyboard config" img by default)
    SDL_BlitSurface(sub[15].win, NULL, screen, &sub[15].pos);

    //* update the screen
    SDL_Flip(screen);

    //* enter the @event_loop part
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                //? ----------------------- MOUSE MOTION EVENT -----------------------
                case SDL_MOUSEMOTION:
                    for (int i = 13; i < 15; i++)
                        if (event.motion.x >= sub[i].pos.x && event.motion.x <= sub[i].pos.x + sub[i].pos.w && event.motion.y >= sub[i].pos.y && event.motion.y <= sub[i].pos.y + sub[i].pos.h && (i - 13) != ctrl_usrOpPos)
                            ctrl_scroll_UD(sub, &ctrl_usrOpPos, i - 13 - ctrl_usrOpPos, player, pip);
                    break;

                //? ------------------ MOUSE BUTTON DOWN CLICK EVENT ------------------
                case SDL_MOUSEBUTTONDOWN:
                    (ctrl_usrOpPos) ? init_cl_ctrl(sub)           : init_kb_ctrl(sub, player);
                    (ctrl_usrOpPos) ? 0 : kb_ctrl(sub, ctrl_usrOpPos, player, pip);
                    break;

                //? ------------------- KB BUTTON DOWN CLICK EVENT -------------------
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        //? --- UP CLICK OPTION ---
                        case SDLK_UP:
                            //* blit the new ctrl ls_interface
                            ctrl_scroll_UD(sub, &ctrl_usrOpPos, -1, player, pip);
                            break;

                        //? --- DOWN CLICK OPTION ---
                        case SDLK_DOWN:
                            //* blit the new ctrl ls_interface
                            ctrl_scroll_UD(sub, &ctrl_usrOpPos, 1, player, pip);
                            break;

                        //? --- LEFT CLICK OPTION ---
                        case SDLK_LEFT:
                            if (!ctrl_usrOpPos) {
                                //* blit the @left_animated_player_scroll_button
                                SDL_BlitSurface(sub[39].win, NULL, screen, (sub[39].pos.x = 1253, sub[39].pos.y = 412, &sub[39].pos));
                                
                                //* reset the sub_39 values
                                sub[39].pos.x = 1298; sub[39].pos.y = 300;

                                //* update the player value
                                player = 0;
                            }
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            if (!ctrl_usrOpPos) {
                                //* blit the @right_animated_player_scroll_button
                                SDL_BlitSurface(sub[40].win, NULL, screen, (sub[40].pos.x = 1373, sub[40].pos.y = 412, &sub[40].pos));

                                //* reset the sub_40 values
                                sub[40].pos.x = 1629; sub[40].pos.y = 300;

                                //* update the player value
                                player = 1;
                            }
                            break;

                        //? --- ENTER CLICK OPTION ---
                        case SDLK_SPACE:
                            if (!ctrl_usrOpPos)
                                kb_ctrl(sub, ctrl_usrOpPos, player, pip);
                            break;

                        //? --- ESCAPE CLICK OPTION ---
                        case SDLK_ESCAPE:
                            rn_settings(sub, pip);
                            return;

                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? ------------------- KB BUTTON UP CLICK EVENT -------------------
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        //? --- LEFT CLICK OPTION ---
                        case SDLK_LEFT:
                            if (!ctrl_usrOpPos) {
                                //* blit the @left_animated_player_scroll_button
                                SDL_BlitSurface(sub[36].win, NULL, screen, (sub[36].pos.x = 1253, sub[36].pos.y = 412, &sub[36].pos));

                                //* reset the sub_36 values
                                sub[36].pos.x = 1298; sub[36].pos.y = 300;

                                //* display the @P1_keys_info
                                ctrl_scroll_UD(sub, &ctrl_usrOpPos, 0, 0, pip);
                            }
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            if (!ctrl_usrOpPos) {
                                //* blit the @right_animated_player_scroll_button
                                SDL_BlitSurface(sub[37].win, NULL, screen, (sub[37].pos.x = 1373, sub[37].pos.y = 412, &sub[37].pos));

                                //* reset the sub_37 values
                                sub[37].pos.x = 1629; sub[37].pos.y = 300;

                                //* display the @P2_keys_info
                                ctrl_scroll_UD(sub, &ctrl_usrOpPos, 0, 1, pip);
                            }
                            break;

                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? --------------------- QUIT CLICK EVENT ---------------------
                case SDL_QUIT:
                    freeResources(sub, NULL, pip, 63);
                    exit(EXIT_SUCCESS);
                    break;

                //? --------------------- OTHER CLICK EVENT ---------------------
                default:
                    break;
            }
        }
        //* update the screen
        SDL_Flip(screen);

        //* wait 100 millisecond befor returning
        SDL_Delay(100);
    }
}

void ctrl_scroll_UD(surface* sub, int* ctrl_usrOpPos, int direction, int player, Mix_Chunk *pip) {
    //* play the pip chunk
    Mix_PlayChannel(-1, pip, 0);

    //* del the old rs_interface
    SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 230, &sub[0].pos), screen, &sub[0].pos);

    //* blit the contour img
    SDL_BlitSurface(sub[12].win,  NULL, screen, &sub[12].pos);

    //* blit the @normal_img for the curent usr option
    SDL_BlitSurface(sub[13 + *ctrl_usrOpPos].win,  NULL, screen, &sub[13 + *ctrl_usrOpPos].pos);

    //* update the usrOpPos
    *ctrl_usrOpPos += direction;

    //* correct usr option postion
    if (*ctrl_usrOpPos == -1)
        *ctrl_usrOpPos = 1;
    else if (*ctrl_usrOpPos == 2)
        *ctrl_usrOpPos = 0;

    //* blit the sub right menu
    (*ctrl_usrOpPos) ? init_cl_ctrl(sub) : init_kb_ctrl(sub, player);
    
    //* blit the @animated_img for the new usr option
    SDL_BlitSurface(sub[15 + *ctrl_usrOpPos].win,  NULL, screen, &sub[15 + *ctrl_usrOpPos].pos);
}

void kb_ctrl(surface *sub, int ctrl_usrOpPos, int player, Mix_Chunk *pip) {
    //* the curent keyboard controls user option position
    int kb_ctrl_usrOpPos = 0;

    //* display the @player_keys_info
    init_kb_ctrl(sub, player); 

    //* blit the selected img (blit the animated "Right" img by default)
    SDL_BlitSurface(sub[27].win, NULL, screen, &sub[27].pos);

    //* update the screen
    SDL_Flip(screen);

    //* enter the @event_loop part
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                //? ----------------------- MOUSE MOTION EVENT -----------------------
                case SDL_MOUSEMOTION:
                    for (int i = 25; i < 32; i++)
                        if (event.motion.x >= sub[i].pos.x && event.motion.x <= sub[i].pos.x + sub[i].pos.w && event.motion.y >= sub[i].pos.y && event.motion.y <= sub[i].pos.y + sub[i].pos.h && (i - 25) != kb_ctrl_usrOpPos)
                            kb_ctrl_scroll_UD(sub, &kb_ctrl_usrOpPos, i - 25 - kb_ctrl_usrOpPos, player, pip);
                    break;

                //? ------------------ MOUSE BUTTON DOWN CLICK EVENT ------------------
                case SDL_MOUSEBUTTONDOWN:
                    // rest of code ...
                    break;

                //? ------------------- KB BUTTON DOWN CLICK EVENT -------------------
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        //? --- UP CLICK OPTION ---
                        case SDLK_UP:
                            kb_ctrl_scroll_UD(sub, &kb_ctrl_usrOpPos, -1, player, pip);
                            break;

                        //? --- DOWN CLICK OPTION ---
                        case SDLK_DOWN:
                            kb_ctrl_scroll_UD(sub, &kb_ctrl_usrOpPos, 1, player, pip);
                            break;

                        //? --- ENTER CLICK OPTION ---
                        case SDLK_SPACE:
                            edit_kb(sub, pip, kb_ctrl_usrOpPos, player);
                            break;

                        //? --- ESCAPE CLICK OPTION ---
                        case SDLK_ESCAPE:
                            rn_ctrl(sub, ctrl_usrOpPos, player);
                            return;

                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? --------------------- QUIT CLICK EVENT ---------------------
                case SDL_QUIT:
                    freeResources(sub, NULL, pip, 63);
                    exit(EXIT_SUCCESS);
                    break;

                //? --------------------- OTHER CLICK EVENT ---------------------
                default:
                    break;
            }
        }
        //* update the screen
        SDL_Flip(screen);

        //* wait 100 millisecond befor returning
        SDL_Delay(100);
    }
}

void kb_ctrl_scroll_UD(surface* sub, int* kb_ctrl_usrOpPos, int direction, int player, Mix_Chunk *pip) {
    //* play the pip chunk
    Mix_PlayChannel(-1, pip, 0);

    //* del the old rs_interface
    init_kb_ctrl(sub, player);

    //* update the usrOpPos
    *kb_ctrl_usrOpPos += direction;

    //* correct usr option postion
    if (*kb_ctrl_usrOpPos == -1)
        *kb_ctrl_usrOpPos = 6;
    else if (*kb_ctrl_usrOpPos == 7)
        *kb_ctrl_usrOpPos = 0;
    
    //* blit the @animated_img for the new usr option
    SDL_BlitSurface(sub[27 + *kb_ctrl_usrOpPos].win,  NULL, screen, &sub[27 + *kb_ctrl_usrOpPos].pos);
}

void edit_kb(surface *sub, Mix_Chunk *pip, int kb_ctrl_usrOpPos, int player) {
    surface key;

    //* set the @key_pos
    key.pos.x = 1430;
    key.pos.y = 472 + 73 * kb_ctrl_usrOpPos;
    key.pos.w = 115;
    key.pos.h = 40;

    //* cover the key surface
    SDL_BlitSurface(sub[0].win, &key.pos, screen, &key.pos);

    //* enter the @event_loop part
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                //? ------------------- KB BUTTON DOWN CLICK EVENT -------------------
                case SDL_KEYDOWN:
                    //* hold the key input
                    int key_value = event.key.keysym.sym;

                    //* escape the @key_change_event
                    if (key_value == SDLK_ESCAPE) {
                        //* update the keyboard menu
                        init_kb_ctrl(sub, player);

                        //* blit the @current_selected_key img
                        SDL_BlitSurface(sub[27 + kb_ctrl_usrOpPos].win,  NULL, screen, &sub[27 + kb_ctrl_usrOpPos].pos);
                        return;

                    } else {
                        //* get the key name
                        char key_name[21];
                        scanStr("project/doc/settings", key_name, kb_ctrl_usrOpPos + 3);

                        //* the @new_key_value is not used by another move in the @keyboard_controller_keys
                        if (!is_exist(key_value)) {
                            //* update the settings file
                            editValue("%s %d\n", key_name, key_value, kb_ctrl_usrOpPos + (player * 10) + 2);

                        //* the @new_key_value is currently used by another move in the @keyboard_controller_keys (max 2 keys)
                        } else {
                            //* get the used key name
                            char used_key_name[21];
                            scanStr("project/doc/settings", used_key_name, is_exist(key_value) + 1);

                            //* update the settings file with @keys_switching_mode
                            editValue("%s %d\n", used_key_name, scanValue("project/doc/settings", kb_ctrl_usrOpPos + (player * 10) + 2), is_exist(key_value));
                            editValue("%s %d\n", key_name, key_value, kb_ctrl_usrOpPos + (player * 10) + 2);
                        }

                        //* update the keyboard menu
                        init_kb_ctrl(sub, player);

                        //* blit the @current_selected_key img
                        SDL_BlitSurface(sub[27 + kb_ctrl_usrOpPos].win,  NULL, screen, &sub[27 + kb_ctrl_usrOpPos].pos);
                        return;
                    }
                    break;
                //? --------------------- QUIT CLICK EVENT ---------------------
                case SDL_QUIT:
                    freeResources(sub, NULL, pip, 63);
                    exit(EXIT_SUCCESS);
                    break;

                //? --------------------- OTHER CLICK EVENT ---------------------
                default:
                    break;
            }
        }
        //* update the screen
        SDL_Flip(screen);

        //* wait 100 millisecond befor returning
        SDL_Delay(100);
    }
}

int is_exist(int key) {
    for (int i = 2; i < 9; i++)
        if (scanValue("project/doc/settings", i) == key || scanValue("project/doc/settings", i + 10) == key)
            return i;
    return 0;
}

void rn_ctrl(surface *sub, int ctrl_usrOpPos, int player) {
    //* reset the kb/controller ctrl option menu
    ctrl_usrOpPos ? init_cl_ctrl(sub) : init_kb_ctrl(sub, player);

    //* reset the last selected button for the kb/controller ctrl option menu
    SDL_BlitSurface(sub[15 + ctrl_usrOpPos].win,  NULL, screen, &sub[15 + ctrl_usrOpPos].pos);
}

void video(surface* sub, Mix_Chunk *pip) {
    //* init part
    SDL_BlitSurface(sub[38].win, NULL, screen, &sub[38].pos);

    //* update the screen
    SDL_Flip(screen);

    //* enter the @event_loop part
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                //? ------------------- KB BUTTON DOWN CLICK EVENT -------------------
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        //? --- LEFT CLICK OPTION ---
                        case SDLK_LEFT:
                            //* play the pip chunk
                            Mix_PlayChannel(-1, pip, 0);

                            //* blit left animated button
                            SDL_BlitSurface(sub[39].win, NULL, screen, (sub[39].pos.y = 300, &sub[39].pos));
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            //* play the pip chunk
                            Mix_PlayChannel(-1, pip, 0);

                            //* blit right animated button
                            SDL_BlitSurface(sub[40].win, NULL, screen, (sub[40].pos.y = 300, &sub[40].pos));
                            break;

                        //? --- ESCAPE CLICK OPTION ---
                        case SDLK_ESCAPE:
                            rn_settings(sub, pip);
                            return;

                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? ------------------- KB BUTTON DOWN CLICK EVENT -------------------
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        //? --- LEFT CLICK OPTION ---
                        case SDLK_LEFT:
                            //* windowed mode set
                            setScreen(0);

                            //* change to windowed mode
                            editValue("%s  %d\n", "fullscreen", 0, 22);

                            //* reset the screen
                            initResources(sub);

                            //* reset the video menu surface
                            init[usrOpPos](sub);
                            SDL_BlitSurface(sub[38].win, NULL, screen, &sub[38].pos);

                            //* blit left normal button
                            SDL_BlitSurface(sub[36].win, NULL, screen, &sub[36].pos);
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            //* fullscreen mode set
                            setScreen(SDL_FULLSCREEN);
                            
                            //* change to fullscreen mode
                            editValue("%s  %d\n", "fullscreen", SDL_FULLSCREEN, 22);

                            //* reset the screen
                            initResources(sub);

                            //* reset the video menu surface
                            init[usrOpPos](sub);
                            SDL_BlitSurface(sub[38].win, NULL, screen, &sub[38].pos);

                            //* blit right normal button
                            SDL_BlitSurface(sub[37].win, NULL, screen, &sub[37].pos);
                            break;
                        
                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? --------------------- QUIT CLICK EVENT ---------------------
                case SDL_QUIT:
                    freeResources(sub, NULL, pip, 63);
                    exit(EXIT_SUCCESS);
                    break;

                //? --------------------- OTHER CLICK EVENT ---------------------
                default:
                    break;
            }
        }
        //* update the screen
        SDL_Flip(screen);

        //* wait 100 millisecond befor returning
        SDL_Delay(100);
    }
}

void audio(surface* sub, Mix_Chunk *pip) {
    //* the curent @audio_user_option_position
    int audio_usrOpPos = 0;

    //* init part
    SDL_BlitSurface(sub[46].win, NULL, screen, &sub[46].pos);

    //* update the screen
    SDL_Flip(screen);

    //* enter the @event_loop part
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                //? ------------------- KB BUTTON DOWN CLICK EVENT -------------------
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        //? --- UP CLICK OPTION ---
                        case SDLK_UP:
                            //* play the pip chunk
                            Mix_PlayChannel(-1, pip, 0);

                            //* update the @audio_usrOpPos
                            audio_usrOpPos--;

                            //* correct the @audio_usrOpPos
                            if (audio_usrOpPos == -1)
                                audio_usrOpPos = 1;
                            else if (audio_usrOpPos == 2)
                                audio_usrOpPos = 0;
                            
                            //* del the old rs_interface
                            SDL_BlitSurface(sub[0].win, (sub[12].pos.x = 952, sub[12].pos.y = 274, &sub[12].pos), screen, &sub[12].pos);

                            //* reset the current @sub_menu_surface
                            init[usrOpPos](sub);
                            
                            //* blit the selected @sub_option
                            SDL_BlitSurface(sub[46 + audio_usrOpPos].win, NULL, screen, &sub[46 + audio_usrOpPos].pos);
                            break;

                        //? --- DOWN CLICK OPTION ---
                        case SDLK_DOWN:
                            //* play the pip chunk
                            Mix_PlayChannel(-1, pip, 0);

                            //* update the @audio_usrOpPos
                            audio_usrOpPos++;

                            //* correct the @audio_usrOpPos
                            if (audio_usrOpPos == -1)
                                audio_usrOpPos = 1;
                            else if (audio_usrOpPos == 2)
                                audio_usrOpPos = 0;

                            //* del the old rs_interface
                            SDL_BlitSurface(sub[0].win, (sub[12].pos.x = 952, sub[12].pos.y = 274, &sub[12].pos), screen, &sub[12].pos);

                            //* reset the current @sub_menu_surface
                            init[usrOpPos](sub);

                            //* blit the selected @sub_option
                            SDL_BlitSurface(sub[46 + audio_usrOpPos].win, NULL, screen, &sub[46 + audio_usrOpPos].pos);
                            break;

                        //? --- LEFT CLICK OPTION ---
                        case SDLK_LEFT:
                            //* reduce volume
                            (!audio_usrOpPos) ? ctrl_volume(sub, "musicVolume", 23, -8, pip) : ctrl_volume(sub, "soundVolume", 24, -8, pip);
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            //* add volume
                            (!audio_usrOpPos) ? ctrl_volume(sub, "musicVolume", 23, 8, pip) : ctrl_volume(sub, "soundVolume", 24, 8, pip);
                            break;

                        //? --- ESCAPE CLICK OPTION ---
                        case SDLK_ESCAPE:
                            rn_settings(sub, pip);
                            return;

                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;
                //? ------------------- KB BUTTON DOWN CLICK EVENT -------------------
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        //? --- LEFT CLICK OPTION ---
                        case SDLK_LEFT:
                            //* blit left normal button
                            SDL_BlitSurface(sub[36].win, NULL, screen, (sub[36].pos.y += (sub[36].pos.h + 49) * audio_usrOpPos, &sub[36].pos));

                            //* reset the Y31
                            sub[36].pos.y = 300;
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            //* blit right normal button
                            SDL_BlitSurface(sub[37].win, NULL, screen, (sub[37].pos.y += (sub[37].pos.h + 49) * audio_usrOpPos, &sub[37].pos));

                            //* reset the Y31
                            sub[37].pos.y = 300;
                            break;

                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? --------------------- QUIT CLICK EVENT ---------------------
                case SDL_QUIT:
                    freeResources(sub, NULL, pip, 63);
                    exit(EXIT_SUCCESS);
                    break;

                //? --------------------- OTHER CLICK EVENT ---------------------
                default:
                    break;
            }
        }
        //* update the screen
        SDL_Flip(screen);

        //* wait 100 millisecond befor returning
        SDL_Delay(100);
    }
}

void ctrl_volume(surface* sub, char* type_vol, int line, int config, Mix_Chunk *pip) {
    //* del the old rs_interface
    SDL_BlitSurface(sub[0].win, (sub[12].pos.x = 952, sub[12].pos.y = 274, &sub[12].pos), screen, &sub[12].pos);

    //* scan the music/chunk volume
    int volume = scanValue("project/doc/settings", line);

    //* add/reduce the volume process
    volume += config;

    //* correct the volume in mute or max volume situation
    if (volume == -8)
        volume = 0;
    else if(volume == 136)
        volume = 128;

    //* update the new volume
    editValue("%s %d\n", type_vol, volume, line);

    //* set the new music/chunk volume
    (line == 23) ? Mix_VolumeMusic(scanValue("project/doc/settings", 23)) : Mix_VolumeChunk(pip, scanValue("project/doc/settings", 24));

    //* play the pip chunk
    Mix_PlayChannel(-1, pip, 0);

    //* reset the current @sub_menu_surface
    init[usrOpPos](sub);

    //* blit the selected @audio_sub_option
    SDL_BlitSurface(sub[47 - (line % 2)].win, NULL, screen, &sub[47 - (line % 2)].pos);

    //* blit L/R animated button
    if (config == -8)
        SDL_BlitSurface(sub[39].win, NULL, screen, (sub[39].pos.y += (sub[39].pos.h + 49) * (line - 2), &sub[39].pos));
    else
        SDL_BlitSurface(sub[40].win, NULL, screen, (sub[40].pos.y += (sub[40].pos.h + 49) * (line - 2), &sub[40].pos));

    //* reset the Y33/Y34
    sub[39].pos.y = 300;
    sub[40].pos.y = 300;
}

void language(surface* sub, Mix_Chunk *pip) {
    //* enter the @event_loop part
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                //? ------------------- KB BUTTON DOWN CLICK EVENT -------------------
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        //? --- LEFT CLICK OPTION ---
                        case SDLK_LEFT:
                            //* play the pip chunk
                            Mix_PlayChannel(-1, pip, 0);

                            //* del the old rs_interface
                            SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 230, &sub[0].pos), screen, &sub[0].pos);

                            //* change the language to @Eng
                            editValue("%s    %d\n", "language", 0, 25);

                            //* reset the current @sub_menu_surface
                            init[usrOpPos](sub);
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            //* play the pip chunk
                            Mix_PlayChannel(-1, pip, 0);

                            //* del the old rs_interface
                            SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 230, &sub[0].pos), screen, &sub[0].pos);

                            //* change the language to @Frc
                            editValue("%s    %d\n", "language", 1, 25);

                            //* reset the current @sub_menu_surface
                            init[usrOpPos](sub);
                            break;

                        //? --- SPACE CLICK OPTION ---
                        case SDLK_SPACE:
                            rn_settings(sub, pip);
                            return;

                        //? --- ESCAPE CLICK OPTION ---
                        case SDLK_ESCAPE:
                            rn_settings(sub, pip);
                            return;

                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? --------------------- QUIT CLICK EVENT ---------------------
                case SDL_QUIT:
                    freeResources(sub, NULL, pip, 63);
                    exit(EXIT_SUCCESS);
                    break;

                //? --------------------- OTHER CLICK EVENT ---------------------
                default:
                    break;
            }
        }
        //* update the screen
        SDL_Flip(screen);

        //* wait 100 millisecond befor returning
        SDL_Delay(100);
    }
}

void gamePlay(surface* sub, Mix_Chunk *pip) {
    //* init the curent @gamePlay_user_option_position in speedRun op by default
    int gm_usrOpPos = 0;

    //* select the speedRun op by default
    SDL_BlitSurface(sub[57].win, NULL, screen, &sub[57].pos);

    //* update the screen
    SDL_Flip(screen);

    //* enter the @event_loop part
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                //? ------------------- KB BUTTON DOWN CLICK EVENT -------------------
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        //? --- UP CLICK OPTION ---
                        case SDLK_UP:
                            gm_scroll_UD(sub, &gm_usrOpPos, -1, pip);
                            break;

                        //? --- DOWN CLICK OPTION ---
                        case SDLK_DOWN:
                            gm_scroll_UD(sub, &gm_usrOpPos, 1, pip);
                            break;

                        //? --- LEFT CLICK OPTION ---
                        case SDLK_LEFT:
                            if (gm_usrOpPos)
                                gm_scroll_LR(sub, "miniMap",  "%s     %d\n", 27, 0, pip);
                            else
                                gm_scroll_LR(sub, "speedRun", "%s    %d\n",  26, 0, pip);
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            if (gm_usrOpPos)
                                gm_scroll_LR(sub, "miniMap",  "%s     %d\n", 27, 1, pip);
                            else
                                gm_scroll_LR(sub, "speedRun", "%s    %d\n",  26, 1, pip);
                            break;

                        //? --- ESCAPE CLICK OPTION ---
                        case SDLK_ESCAPE:
                            rn_settings(sub, pip);
                            return;

                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? ------------------- KB BUTTON DOWN CLICK EVENT -------------------
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        //? --- LEFT CLICK OPTION ---
                        case SDLK_LEFT:
                            //* blit left normal button
                            (gm_usrOpPos) ? (sub[36].pos.y = 378) : (sub[36].pos.y = 300);
                            SDL_BlitSurface(sub[36].win, NULL, screen, &sub[36].pos);
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            //* blit right normal button
                            (gm_usrOpPos) ? (sub[37].pos.y = 378) : (sub[37].pos.y = 300);
                            SDL_BlitSurface(sub[37].win, NULL, screen, &sub[37].pos);
                            break;

                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? --------------------- QUIT CLICK EVENT ---------------------
                case SDL_QUIT:
                    freeResources(sub, NULL, pip, 63);
                    exit(EXIT_SUCCESS);
                    break;

                //? --------------------- OTHER CLICK EVENT ---------------------
                default:
                    break;
            }
        }
        //* update the screen
        SDL_Flip(screen);

        //* wait 100 millisecond befor returning
        SDL_Delay(100);
    }
}

void gm_scroll_UD(surface *sub, int *gm_usrOpPos, int direction, Mix_Chunk *pip) {
    //* play the pip chunk
    Mix_PlayChannel(-1, pip, 0);

    //* del the old rs_interface
    SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 230, &sub[0].pos), screen, &sub[0].pos);

    //* update the gm_usrOpPos value
    *gm_usrOpPos += direction;

    //* correct the gm_usrOpPos value
    if (*gm_usrOpPos == 2)
        *gm_usrOpPos = 0;
    else if (*gm_usrOpPos == -1)
        *gm_usrOpPos = 1;

    //* reset the current @sub_menu_surface
    init[usrOpPos](sub);

    //* select the new option
    SDL_BlitSurface(sub[57 + *gm_usrOpPos * 2].win, NULL, screen, &sub[57 + *gm_usrOpPos * 2].pos);
}

void gm_scroll_LR(surface *sub, char *op_name, char *format, int line, int conf, Mix_Chunk *pip) {
    //* play the pip chunk
    Mix_PlayChannel(-1, pip, 0);

    //* del the old rs_interface
    SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 230, &sub[0].pos), screen, &sub[0].pos);

    //* change the gamePlay to @On_mode
    editValue(format, op_name, conf, line);

    //* reset the current @sub_menu_surface
    init[usrOpPos](sub);

    //* blit/reset the current selected img
    SDL_BlitSurface(sub[57 + 2 * (line == 27)].win, NULL, screen, &sub[57 + 2 * (line == 27)].pos);

    //* blit R or L animated button
    (line == 27) ? (sub[39 + conf].pos.y = 378) : (sub[39 + conf].pos.y = 300);
    SDL_BlitSurface(sub[39 + conf].win, NULL, screen, &sub[39 + conf].pos);
}

void quit(surface *sub, Mix_Chunk *pip) {
    //* play the pip chunk
    Mix_PlayChannel(-1, pip, 0);

    //* free resources
    freeResources(sub, NULL, pip, 63);
}