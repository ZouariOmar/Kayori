/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @update: 04/11/24
? @file:   settings.c
----------------------------------------------- */

//? ----------------------- TODO SECTION DECLARATION PART -----------------------
/*
TODO_01: working on the 5 usr_modification functions             :: @ZouariOmar :: 90%
    * fix the "volume bars view" in video(surface*) fn
    * load and test with test.mp3, test0.wav, test1.wav
TODO_02: support the mouse events (motion and button down click) :: @ZouariOmar
TODO_03: code the keyboard_conf() void func                      :: @ZouariOmar
*/

//? -------------------- INCLUDE PROTOTYPE DECLARATION PART --------------------
#include "../inc/inc.h"

//? ----------------------- FUNCTIONS PROTOTYPE DEV PART -----------------------
//* the curent user option position
int usrOpPos = 0;

//? init InitFunc public array var
InitFunc init[] = {
    init_rs_ctrl,
    init_rs_vid,
    init_rs_aud,
    init_rs_lang,
    init_rs_gmP
};

//? usr_modification InitFunc public array var
InitFunc usr_modification[] = {
    controls,
    video,
    audio,
    language,
    gamePlay
};

void settings() {
    // * all 100 settings sub-surfaces
    surface sub[54];

    //? ----------------------- initializing part -----------------------
    //* load the settings resources
    loadResources(sub, "project/res/settings/LS/img",               0,  12);
    loadResources(sub, "project/res/settings/RS/controls_menu/img", 12, 27);
    loadResources(sub, "project/res/settings/RS/video_menu/img",    27, 37);
    loadResources(sub, "project/res/settings/RS/audio_menu/img",    37, 45);
    loadResources(sub, "project/res/settings/RS/language_menu/img", 45, 50);
    loadResources(sub, "project/res/settings/RS/gamePlay_menu/img", 50, 54);

    //* set potions for the other res
    set_pos(sub, "project/doc/settings_ref", 54);

    //* initializing the settings resources
    initResources(sub);
    init_rs_ctrl(sub);

    //* ctrl button selected by default
    SDL_BlitSurface(sub[7].win,  NULL, screen, &sub[7].pos);

    // * update the screen
    SDL_Flip(screen);
    
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                //? ----------------------- MOUSE MOTION EVENT -----------------------
                case SDL_MOUSEMOTION:
                    // rest of code...
                    break;

                //? ------------------ MOUSE BUTTON DOWN CLICK EVENT ------------------
                case SDL_MOUSEBUTTONDOWN:
                    // rest of code...
                    break;
                
                //? ------------------- KB BUTTON DOWN CLICK EVENT -------------------
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        //? --- UP CLICK OPTION ---
                        case SDLK_UP:
                            scroll_UD(sub, &usrOpPos, -1);
                            SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 274, &sub[0].pos), screen, &sub[0].pos);
                            init[usrOpPos](sub);
                            break;

                        //? --- DOWN CLICK OPTION ---
                        case SDLK_DOWN:
                            scroll_UD(sub, &usrOpPos, 1);
                            SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 274, &sub[0].pos), screen, &sub[0].pos);
                            init[usrOpPos](sub);
                            break;

                        //? --- ENTER CLICK OPTION ---
                        case SDLK_SPACE:
                            //* deselect the usr curent position
                            scroll_UD(sub, &usrOpPos, 0);

                            //* activate the sub_menu mode (depending on the usr option position var)
                            usr_modification[usrOpPos](sub);
                            break;

                        //? --- ESCAPE CLICK OPTION ---
                        case SDLK_ESCAPE:
                            freeResources(sub, NULL, 52);
                            return;

                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? --------------------- QUIT CLICK EVENT ---------------------
                case SDL_QUIT:
                    freeResources(sub, NULL, 52);
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

void scroll_UD(surface* sub, int* usrOpPos, int direction) {
    //* del the left menu
    SDL_BlitSurface(sub[0].win,  &sub[1].pos, screen, &sub[1].pos);

    //* blit the contour img
    SDL_BlitSurface(sub[1].win,  NULL, screen, &sub[1].pos);

    //* blit the @normal_img for the curent usr option
    SDL_BlitSurface(sub[2 + *usrOpPos].win,  NULL, screen, &sub[2 + *usrOpPos].pos);

    //* blit the left menu
    for (int i = 0; i < 5; i++)
        if (i != *usrOpPos)
            SDL_BlitSurface(sub[2 + i].win,  NULL, screen, &sub[2 + i].pos);

    //* update the usrOpPos
    *usrOpPos += direction;

    //* fix usr option postion
    if (*usrOpPos == -1)
        *usrOpPos = 4;
    else if (*usrOpPos == 5)
        *usrOpPos = 0;

    //* blit the @animated_img for the new usr option
    if (direction)
        SDL_BlitSurface(sub[7 + *usrOpPos].win,  NULL, screen, &sub[7 + *usrOpPos].pos);
}

//? ----------------------- INIT FUNCTIONS DEV PART -----------------------
void initResources(surface* sub) {
    sub[0].pos.x = 0; sub[0].pos.y = 0;
    //* LS sub_surfaces blit part
    for (int i = 0; i < 7; i++)
        SDL_BlitSurface(sub[i].win,  NULL, screen, &sub[i].pos);
}

void init_rs_ctrl(surface* sub) {
    for (int i = 12; i < 15; i++)
        SDL_BlitSurface(sub[i].win, NULL, screen, &sub[i].pos);
}

void init_rs_vid(surface* sub) {
    //* blit the video std imgs (2 img) && blit the L/R video buttons
    for (int i = 28; i < 32; i++)
        SDL_BlitSurface(sub[i].win, NULL, screen, &sub[i].pos);
    
    //* blit off/on fullscreen mode state
    (!scanValue("project/doc/settings", 18)) ? SDL_BlitSurface(sub[36].win, NULL, screen, &sub[36].pos) : SDL_BlitSurface(sub[35].win, NULL, screen, &sub[35].pos);
}

void init_rs_aud(surface* sub) {
    //* blit the contour_04
    SDL_BlitSurface(sub[12].win, NULL, screen, &sub[12].pos);
    
    //* blit the 2 rounded bar
    sub[37].pos.x = 1341;
    SDL_BlitSurface(sub[37].win, NULL, screen, (sub[37].pos.y = 283, &sub[37].pos));
    SDL_BlitSurface(sub[37].win, NULL, screen, (sub[37].pos.y = 364, &sub[37].pos));

    //* blit the music and sound txt imgs
    SDL_BlitSurface(sub[38].win, NULL, screen, &sub[38].pos);
    SDL_BlitSurface(sub[39].win, NULL, screen, &sub[39].pos);

    //* blit the L/R "sound" buttons
    SDL_BlitSurface(sub[30].win, NULL, screen, (sub[30].pos.y = 381, &sub[30].pos));
    SDL_BlitSurface(sub[31].win, NULL, screen, (sub[31].pos.y = 381, &sub[31].pos));

    //* blit the L/R "music" buttons
    SDL_BlitSurface(sub[30].win, NULL, screen, (sub[30].pos.y = 300, &sub[30].pos));
    SDL_BlitSurface(sub[31].win, NULL, screen, (sub[31].pos.y = 300, &sub[31].pos));

    //! X42 = X43 = X44 :: we choose X42

    //TODO: optimize the music and sound bars blit proccess in 1 fn
    //* --- blit the music volume bars ---
    for (int i = 1; i <= (scanValue("project/doc/settings", 19) / 8); i++) {
        switch (i) {
            case 1:
                SDL_BlitSurface(sub[42].win, NULL, screen, &sub[42].pos);
                break;
            case 16:
                SDL_BlitSurface(sub[43].win, NULL, screen, &sub[42].pos);
                break;
            default:
                SDL_BlitSurface(sub[44].win, NULL, screen, &sub[42].pos);
                break;
        }
        sub[42].pos.x += 16;
    }
    //* reset the X42;
    sub[42].pos.x = 1341;

    //* --- blit the sound volume bars ---
    // Y42 = Y43 = Y44 :: we choose to change Y42
    sub[42].pos.y = 365;
    for (int i = 1; i <= (scanValue("project/doc/settings", 20) / 8); i++) {
        switch (i) {
            case 1:
                SDL_BlitSurface(sub[42].win, NULL, screen, &sub[42].pos);
                break;
            case 16:
                SDL_BlitSurface(sub[43].win, NULL, screen, &sub[42].pos);
                break;
            default:
                SDL_BlitSurface(sub[44].win, NULL, screen, &sub[42].pos);
                break;
        }
        sub[42].pos.x += 16;
    }
    //* reset the X42 and Y42
    sub[42].pos.x = 1341;
    sub[42].pos.y = 284;
}

void init_rs_lang(surface* sub) {
    //* blit the contour_03 and the shape
    SDL_BlitSurface(sub[28].win, NULL, screen, &sub[28].pos);
    SDL_BlitSurface(sub[49].win, NULL, screen, (sub[49].pos.x = 1319, sub[49].pos.y = 274, &sub[49].pos));

    //* blit the Eng and Frc normal imgs
    if (!scanValue("project/doc/settings", 21)) {
        //* Eng option selected
        SDL_BlitSurface(sub[47].win, NULL, screen, (sub[47].pos.x = 952,  sub[47].pos.y = 275, &sub[47].pos));
        SDL_BlitSurface(sub[46].win, NULL, screen, (sub[46].pos.x = 1451, sub[46].pos.y = 292, &sub[46].pos));
    } else {
        //* Frc option selected
        SDL_BlitSurface(sub[48].win, NULL, screen, (sub[48].pos.x = 1320, sub[48].pos.y = 275, &sub[48].pos));
        SDL_BlitSurface(sub[45].win, NULL, screen, (sub[45].pos.x = 1062, sub[45].pos.y = 292, &sub[45].pos));
    }
    // reset the X42 and Y42
    sub[42].pos.x = 1341;
    sub[42].pos.y = 284;
}

void init_rs_gmP(surface* sub) {
    //* blit the contour_04
    SDL_BlitSurface(sub[12].win, NULL, screen, &sub[12].pos);

    //* blit the speedRun/miniMap normal imgs
    SDL_BlitSurface(sub[50].win, NULL, screen, &sub[50].pos);
    SDL_BlitSurface(sub[52].win, NULL, screen, &sub[52].pos);

    //* blit the L/R normal buttons for miniMap op
    SDL_BlitSurface(sub[30].win, NULL, screen, (sub[30].pos.y = 381, &sub[30].pos));
    SDL_BlitSurface(sub[31].win, NULL, screen, (sub[31].pos.y = 381, &sub[31].pos));

    //* blit the L/R normal buttons for speedRun op
    SDL_BlitSurface(sub[30].win, NULL, screen, (sub[30].pos.y = 300, &sub[30].pos));
    SDL_BlitSurface(sub[31].win, NULL, screen, (sub[31].pos.y = 300, &sub[31].pos));

    //* blit off/on miniMap mode state
    SDL_BlitSurface(sub[35 + !scanValue("project/doc/settings", 23)].win, NULL, screen, (sub[36].pos.y = 372, &sub[36].pos));

    //* blit off/on speedRun mode state
    SDL_BlitSurface(sub[35 + !scanValue("project/doc/settings", 22)].win, NULL, screen, (sub[36].pos.y = 292, &sub[36].pos));
}

//? ----------------------- USR_MODIFICATION FUNCTIONS DEV PART -----------------------
void controls(surface* sub) {
    //* the curent user option position
    int ctrl_usrOpPos = 0;

    //* init part
    SDL_BlitSurface(sub[15].win, NULL, screen, &sub[15].pos);
    for (int i = 17; i < 23; i++)
        SDL_BlitSurface(sub[i].win, NULL, screen, &sub[i].pos);

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
                            //* blit the new ctrl ls_interface
                            rs_scroll_UD(sub, &ctrl_usrOpPos, -1);
                            break;

                        //? --- DOWN CLICK OPTION ---
                        case SDLK_DOWN:
                            //* blit the new ctrl ls_interface
                            rs_scroll_UD(sub, &ctrl_usrOpPos, 1);
                            break;

                        //? --- ENTER CLICK OPTION ---
                        case SDLK_KP_ENTER:
                            // rest of code...
                            break;

                        //? --- ESCAPE CLICK OPTION ---
                        case SDLK_ESCAPE:
                            rn_settings(sub);
                            return;

                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? --------------------- QUIT CLICK EVENT ---------------------
                case SDL_QUIT:
                    freeResources(sub, NULL, 52);
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

void rs_scroll_UD(surface* sub, int* ctrl_usrOpPos, int direction) {
    //* del the old rs_interface
    SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 274, &sub[0].pos), screen, &sub[0].pos);

    //* blit the contour img
    SDL_BlitSurface(sub[12].win,  NULL, screen, &sub[12].pos);

    //* blit the @normal_img for the curent usr option
    SDL_BlitSurface(sub[13 + *ctrl_usrOpPos].win,  NULL, screen, &sub[13 + *ctrl_usrOpPos].pos);

    //* update the usrOpPos
    *ctrl_usrOpPos += direction;

    //* fix usr option postion
    if (*ctrl_usrOpPos == -1)
        *ctrl_usrOpPos = 1;
    else if (*ctrl_usrOpPos == 2)
        *ctrl_usrOpPos = 0;

    //* blit the sub left menu
    //! support the kb_menu only (we don't have the controller resources)
    for (int i = 17; i < 23 && !(*ctrl_usrOpPos); i++)
        SDL_BlitSurface(sub[i].win, NULL, screen, &sub[i].pos);
    
    //* blit the @animated_img for the new usr option
    SDL_BlitSurface(sub[15 + *ctrl_usrOpPos].win,  NULL, screen, &sub[15 + *ctrl_usrOpPos].pos);
}

void video(surface* sub) {
    //* init part
    SDL_BlitSurface(sub[32].win, NULL, screen, &sub[32].pos);

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
                            //* blit left animated button
                            SDL_BlitSurface(sub[33].win, NULL, screen, &sub[33].pos);
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            //* blit right animated button
                            SDL_BlitSurface(sub[34].win, NULL, screen, &sub[34].pos);
                            break;

                        //? --- ESCAPE CLICK OPTION ---
                        case SDLK_ESCAPE:
                            rn_settings(sub);
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
                            editValue("%s  %d\n", "fullscreen", 0, 18);

                            //* reset the screen
                            initResources(sub);

                            //* reset the video menu surface
                            init[usrOpPos](sub);
                            SDL_BlitSurface(sub[32].win, NULL, screen, &sub[32].pos);

                            //* blit left normal button
                            SDL_BlitSurface(sub[30].win, NULL, screen, &sub[30].pos);
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            //* fullscreen mode set
                            setScreen(SDL_FULLSCREEN);
                            
                            //* change to fullscreen mode
                            editValue("%s  %d\n", "fullscreen", SDL_FULLSCREEN, 18);

                            //* reset the screen
                            initResources(sub);

                            //* reset the video menu surface
                            init[usrOpPos](sub);
                            SDL_BlitSurface(sub[32].win, NULL, screen, &sub[32].pos);

                            //* blit right normal button
                            SDL_BlitSurface(sub[31].win, NULL, screen, &sub[31].pos);
                            break;
                        
                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? --------------------- QUIT CLICK EVENT ---------------------
                case SDL_QUIT:
                    freeResources(sub, NULL, 52);
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

void rn_settings(surface* sub) {
    //* del the old rs_surface
    SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 274, &sub[0].pos), screen, &sub[0].pos);

    //* reset the sub menu surface
    init[usrOpPos](sub);

    //* reset the settings menu selection
    SDL_BlitSurface(sub[7 + usrOpPos].win,  NULL, screen, &sub[7 + usrOpPos].pos);
}

void audio(surface* sub) {
    //* the curent @audio_user_option_position
    int audio_usrOpPos = 0;

    //* init part
    SDL_BlitSurface(sub[40].win, NULL, screen, &sub[40].pos);

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
                            //* update the @audio_usrOpPos
                            audio_usrOpPos--;

                            //* correct the @audio_usrOpPos
                            if (audio_usrOpPos == -1)
                                audio_usrOpPos = 1;
                            else if (audio_usrOpPos == 2)
                                audio_usrOpPos = 0;
                            
                            //* del the old rs_interface
                            SDL_BlitSurface(sub[0].win, &sub[12].pos, screen, &sub[12].pos);

                            //* reset the current @sub_menu_surface
                            init[usrOpPos](sub);
                            
                            //* blit the selected @sub_option
                            SDL_BlitSurface(sub[40 + audio_usrOpPos].win, NULL, screen, &sub[40 + audio_usrOpPos].pos);
                            break;

                        //? --- DOWN CLICK OPTION ---
                        case SDLK_DOWN:
                            //* update the @audio_usrOpPos
                            audio_usrOpPos++;

                            //* correct the @audio_usrOpPos
                            if (audio_usrOpPos == -1)
                                audio_usrOpPos = 1;
                            else if (audio_usrOpPos == 2)
                                audio_usrOpPos = 0;
                            
                            //* del the old rs_interface
                            SDL_BlitSurface(sub[0].win, &sub[12].pos, screen, &sub[12].pos);

                            //* reset the current @sub_menu_surface
                            init[usrOpPos](sub);
                            
                            //* blit the selected @sub_option
                            SDL_BlitSurface(sub[40 + audio_usrOpPos].win, NULL, screen, &sub[40 + audio_usrOpPos].pos);
                            break;

                        //? --- LEFT CLICK OPTION ---
                        case SDLK_LEFT:
                            //* reduce volume
                            (!audio_usrOpPos) ? ctrl_volume(sub, "musicVolume", 19, -8) : ctrl_volume(sub, "soundVolume", 20, -8);
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            //* add volume
                            (!audio_usrOpPos) ? ctrl_volume(sub, "musicVolume", 19, 8) : ctrl_volume(sub, "soundVolume", 20, 8);
                            break;

                        //? --- ESCAPE CLICK OPTION ---
                        case SDLK_ESCAPE:
                            rn_settings(sub);
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
                            SDL_BlitSurface(sub[30].win, NULL, screen, (sub[30].pos.y += (sub[30].pos.h + 49) * audio_usrOpPos, &sub[30].pos));

                            //* reset the Y31
                            sub[30].pos.y = 300;
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            //* blit right normal button
                            SDL_BlitSurface(sub[31].win, NULL, screen, (sub[31].pos.y += (sub[31].pos.h + 49) * audio_usrOpPos, &sub[31].pos));

                            //* reset the Y31
                            sub[31].pos.y = 300;
                            break;
                        
                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? --------------------- QUIT CLICK EVENT ---------------------
                case SDL_QUIT:
                    freeResources(sub, NULL, 52);
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

void ctrl_volume(surface* sub, char* type_vol, int line, int config) {
    //* del the old rs_interface
    SDL_BlitSurface(sub[0].win, &sub[12].pos, screen, &sub[12].pos);

    //* scan the music/chunk volume
    int volume = scanValue("project/doc/settings", line);

    //* add/reduce the volume process
    if (volume >= 0 && volume <= 128) {
        volume += config;

        //* correct the volume in mute or max volume situation
        if (volume == -8)
            volume = 0;
        else if(volume == 136)
            volume = 128;

        //* update the new volume
        editValue("%s %d\n", type_vol, volume, line);

        //* set the new music/chunk volume
        ////(line == 2) ? Mix_VolumeMusic(scanValue("project/doc/settings", 2)) : Mix_VolumeChunk(pop, scanValue("project/doc/settings", 3));
    }
    
    //* reset the current @sub_menu_surface
    init[usrOpPos](sub);

    //* blit the selected @audio_sub_option
    SDL_BlitSurface(sub[41 - (line % 2)].win, NULL, screen, &sub[41 - (line % 2)].pos);

    //* blit L/R animated button
    if (config == -8)
        SDL_BlitSurface(sub[33].win, NULL, screen, (sub[33].pos.y += (sub[33].pos.h + 49) * (line - 2), &sub[33].pos));
    else
        SDL_BlitSurface(sub[34].win, NULL, screen, (sub[34].pos.y += (sub[34].pos.h + 49) * (line - 2), &sub[34].pos));

    //* reset the Y33/Y34
    sub[33].pos.y = 300;
    sub[34].pos.y = 300;
}

void language(surface* sub) {
    //* enter the @event_loop part
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                //? ------------------- KB BUTTON DOWN CLICK EVENT -------------------
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        //? --- LEFT CLICK OPTION ---
                        case SDLK_LEFT:
                            //* del the old rs_interface
                            SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 274, &sub[0].pos), screen, &sub[0].pos);

                            //* change the language to @Eng
                            editValue("%s    %d\n", "language", 0, 21);

                            //* reset the current @sub_menu_surface
                            init[usrOpPos](sub);
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            //* del the old rs_interface
                            SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 274, &sub[0].pos), screen, &sub[0].pos);

                            //* change the language to @Frc
                            editValue("%s    %d\n", "language", 1, 21);

                            //* reset the current @sub_menu_surface
                            init[usrOpPos](sub);
                            break;

                        //? --- SPACE CLICK OPTION ---
                        case SDLK_SPACE:
                            rn_settings(sub);
                            return;

                        //? --- ESCAPE CLICK OPTION ---
                        case SDLK_ESCAPE:
                            rn_settings(sub);
                            return;

                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? --------------------- QUIT CLICK EVENT ---------------------
                case SDL_QUIT:
                    freeResources(sub, NULL, 52);
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

void gamePlay(surface* sub) {
    //* init the curent @gamePlay_user_option_position in speedRun op by default
    int gm_usrOpPos = 0;

    //* select the speedRun op by default
    SDL_BlitSurface(sub[51].win, NULL, screen, &sub[51].pos);

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
                            gm_scroll_UD(sub, &gm_usrOpPos, -1);
                            break;

                        //? --- DOWN CLICK OPTION ---
                        case SDLK_DOWN:
                            gm_scroll_UD(sub, &gm_usrOpPos, 1);
                            break;

                        //? --- LEFT CLICK OPTION ---
                        case SDLK_LEFT:
                            if (gm_usrOpPos)
                                gm_scroll_LR(sub, "miniMap", "%s     %d\n", 23, 0);
                            else
                                gm_scroll_LR(sub, "speedRun", "%s    %d\n", 22, 0);
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            if (gm_usrOpPos)
                                gm_scroll_LR(sub, "miniMap", "%s     %d\n", 23, 1);
                            else
                                gm_scroll_LR(sub, "speedRun", "%s    %d\n", 22, 1);
                            break;

                        //? --- ESCAPE CLICK OPTION ---
                        case SDLK_ESCAPE:
                            rn_settings(sub);
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
                            (gm_usrOpPos) ? (sub[30].pos.y = 378) : (sub[30].pos.y = 300);
                            SDL_BlitSurface(sub[30].win, NULL, screen, &sub[30].pos);
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            //* blit right normal button
                            (gm_usrOpPos) ? (sub[31].pos.y = 378) : (sub[31].pos.y = 300);
                            SDL_BlitSurface(sub[31].win, NULL, screen, &sub[31].pos);
                            break;
                        
                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? --------------------- QUIT CLICK EVENT ---------------------
                case SDL_QUIT:
                    freeResources(sub, NULL, 52);
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

void gm_scroll_UD(surface *sub, int *gm_usrOpPos, int direction) {
    //* del the old rs_interface
    SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 274, &sub[0].pos), screen, &sub[0].pos);

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
    SDL_BlitSurface(sub[51 + *gm_usrOpPos * 2].win, NULL, screen, &sub[51 + *gm_usrOpPos * 2].pos);
}

void gm_scroll_LR(surface *sub, char *op_name, char *format, int line, int conf) {
    //* del the old rs_interface
    SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 274, &sub[0].pos), screen, &sub[0].pos);

    //* change the gamePlay to @On_mode
    editValue(format, op_name, conf, line);

    //* reset the current @sub_menu_surface
    init[usrOpPos](sub);

    //* blit/reset the current selected img
    SDL_BlitSurface(sub[51 + 2 * (line == 23)].win, NULL, screen, &sub[51 + 2 * (line == 23)].pos);

    //* blit R or L animated button
    (line == 23) ? (sub[33 + conf].pos.y = 378) : (sub[33 + conf].pos.y = 300);
    SDL_BlitSurface(sub[33 + conf].win, NULL, screen, &sub[33 + conf].pos);
}