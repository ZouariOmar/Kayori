/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @update: 04/06/24
? @file:   settings.c
----------------------------------------------- */

//? -------------------- INCLUDE PROTOTYPE DECLARATION PART --------------------
#include "../inc/inc.h"

//? ----------------------- FUNCTIONS PROTOTYPE DEV PART -----------------------
//? init InitFunc public array var
InitFunc init[] = {
    init_rs_ctrl,
    init_rs_vid,
    init_rs_aud,
    init_rs_lang,
    init_rs_gmP
},

//? usr_modification InitFunc public array var
usr_modification[] = {
    controls,
    video,
    audio,
    language,
    gamePlay
};

/*
? settings(int*) void func
* quit_game can be 0 or 1
*/
void settings(int *quit_game) {
    // * all 100 settings sub-surfaces
    surface sub[51];

    //? ----------------------- initializing part -----------------------
    //* load the settings resources
    loadResources(sub, "project/res/settings_srf/LS/img",               0,  12);
    loadResources(sub, "project/res/settings_srf/RS/controls_menu/img", 12, 27);
    loadResources(sub, "project/res/settings_srf/RS/video_menu/img",    27, 37);
    loadResources(sub, "project/res/settings_srf/RS/audio_menu/img",    37, 45);
    loadResources(sub, "project/res/settings_srf/RS/language_menu/img", 45, 50);
    loadResources(sub, "project/res/settings_srf/RS/gamePlay_menu/img", 50, 52);

    //* set potions for the other res
    set_pos(sub);

    //* initializing the settings resources
    initResources(sub);

    //* the curent user option position
    int usrOpPos = 0;

    // * update the screen
    SDL_Flip(screen);

    while (!*quit_game) {
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
                        
                        //? --- LEFT CLICK OPTION ---
                        case SDLK_LEFT:
                            // rest of code...
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            // rest of code...
                            break;

                        //? --- SPACE CLICK OPTION ---
                        case SDLK_SPACE:
                            // rest of code...
                            break;

                        //? --- ESCAPE CLICK OPTION ---
                        case SDLK_ESCAPE:
                            freeResources(sub);
                            return;

                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;
                //? ------------------- KB BUTTON UP CLICK EVENT -------------------
                case SDL_KEYUP:
                    switch(event.key.keysym.sym) {
                        //? --- UP CLICK OPTION ---
                        case SDLK_UP:
                            // rest of code...
                            break;

                        //? --- DOWN CLICK OPTION ---
                        case SDLK_DOWN:
                            // rest of code...
                            break;
                        
                        //? --- LEFT CLICK OPTION ---
                        case SDLK_LEFT:
                            // rest of code...
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            // rest of code
                            break;

                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? --------------------- QUIT CLICK EVENT ---------------------
                case SDL_QUIT:
                    freeResources(sub);
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

/*
? scroll_UD(surface*, int*, int) void func
* scroll the left menu up and down
*/
void scroll_UD(surface* sub, int* usrOpPos, int direction) {
    //* del the left menu
    SDL_BlitSurface(sub[0].win,  &sub[1].pos, screen, &sub[1].pos);

    //* blit the contour img
    SDL_BlitSurface(sub[1].win,  NULL, screen, &sub[1].pos);

    //* blit the @normal_img for the curent usr option
    SDL_BlitSurface(sub[2 + *usrOpPos].win,  NULL, screen, &sub[2 + *usrOpPos].pos);

    //* blit the rest of the left menu
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
    SDL_BlitSurface(sub[7 + *usrOpPos].win,  NULL, screen, &sub[7 + *usrOpPos].pos);
}

/*
? set_pos(surface*) void func
* determinate the positions of all sub_surfaces
! we need to rm set_pos(surface*) void func :: all instruction will be included in the blit instruction
*/
void set_pos(surface* sub) {
    //* bkg img position
    sub[0].pos.x = 0; sub[0].pos.y = 0;
    
    //? --- left menu img positions ---
    //* contour_00 img postion
    sub[1].pos.x = 270;  sub[1].pos.y = 274;

    //* normal img position
    sub[2].pos.x = 277;  sub[2].pos.y = 293;
    sub[3].pos.x = 277;  sub[3].pos.y = 355;
    sub[4].pos.x = 277;  sub[4].pos.y = 426;
    sub[5].pos.x = 277;  sub[5].pos.y = 496;
    sub[6].pos.x = 277;  sub[6].pos.y = 565;

    //* animated img position
    sub[7].pos.x  = 271;  sub[7].pos.y  = 274;
    sub[8].pos.x  = 271;  sub[8].pos.y  = 355;
    sub[9].pos.x  = 271;  sub[9].pos.y  = 426;
    sub[10].pos.x = 271;  sub[10].pos.y = 496;
    sub[11].pos.x = 271;  sub[11].pos.y = 565;

    //? --- right menu img position (controls) ---
    //* contour_01 img position
    sub[12].pos.x = 952;  sub[12].pos.y = 274;

    //* contour_02 img position
    sub[17].pos.x = 952;  sub[17].pos.y = 475;

    //* normal img position
    sub[13].pos.x = 960;   sub[13].pos.y = 291;
    sub[14].pos.x = 960;   sub[14].pos.y = 355;
    sub[18].pos.x = 1014;  sub[18].pos.y = 494;
    sub[19].pos.x = 1014;  sub[19].pos.y = 561;
    sub[20].pos.x = 1014;  sub[20].pos.y = 634;
    sub[21].pos.x = 1014;  sub[21].pos.y = 707;
    sub[22].pos.x = 1014;  sub[22].pos.y = 778;

    //* animated img position
    // rest of the code...

    //? --- right menu img position (video) ---
    //* contour_03 img position
    sub[28].pos = sub[12].pos;

    //* normal img position
    sub[29].pos.x = 1043;  sub[29].pos.y = 300;

    //* left and right button img postion
    sub[30].pos.x = 1298;
    sub[31].pos.x = 1629; 

    //* On and Off img position
    sub[35].pos.x = 1449;  sub[35].pos.y = 292;
    sub[36].pos = sub[35].pos;

    //* animated img position
    // rest of the code...

    //? --- right menu img position (audio) ---
    //* normal img position
    sub[38].pos.x = 960;  sub[38].pos.y = 296;
    sub[39].pos.x = 960;  sub[39].pos.y = 353;

    //* animated img position
}

//? ----------------------- INIT FUNCTIONS DEV PART -----------------------
/*
? --- initResources(surface*) void func ---
* blit the first viewed res (not all them)
*/
void initResources(surface* sub) {
    //* LS sub_surfaces blit part
    for (int i = 0; i < 8; i++)
        if (i != 2)
            SDL_BlitSurface(sub[i].win,  NULL, screen, &sub[i].pos);

    //* RS sub_surfaces blit part (controls)
    init_rs_ctrl(sub);
}

/*
? --- init_rs_ctrl(surface*) void func ---
* blit the controls option menu
*/
void init_rs_ctrl(surface* sub) {
    for (int i = 12; i < 15; i++)
        SDL_BlitSurface(sub[i].win, NULL, screen, &sub[i].pos);
}

/*
? --- init_rs_vid(surface*) void func ---
* blit the video option menu :: support the @autosave mode
*/
void init_rs_vid(surface* sub) {
    //* blit the left and right video buttons
    SDL_BlitSurface(sub[30].win, NULL, screen, (sub[30].pos.y = 300, &sub[30].pos));
    SDL_BlitSurface(sub[31].win, NULL, screen, (sub[31].pos.y = 300, &sub[31].pos));

    //* blit the video std imgs (2 img)
    for (int i = 28; i < 30; i++)
        SDL_BlitSurface(sub[i].win, NULL, screen, &sub[i].pos);
    
    //* blit off/on fullscreen mode state
    if (!scanValue(1))
        SDL_BlitSurface(sub[36].win, NULL, screen, &sub[36].pos);
    else
        SDL_BlitSurface(sub[35].win, NULL, screen, &sub[36].pos);
}

/*
? --- init_rs_aud(surface*) void func ---
* blit the audio option menu :: support the @autosave mode
*/
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

    //* blit the left and right "music" buttons
    SDL_BlitSurface(sub[30].win, NULL, screen, &sub[30].pos);
    SDL_BlitSurface(sub[31].win, NULL, screen, &sub[31].pos);

    //* blit the left and right "sound" buttons
    SDL_BlitSurface(sub[30].win, NULL, screen, (sub[30].pos.y = 381, &sub[30].pos));
    SDL_BlitSurface(sub[31].win, NULL, screen, (sub[31].pos.y = 381, &sub[31].pos));

    // X42 = X43 = X44 :: we choose X42
    sub[42].pos.x = 1341;
    sub[42].pos.y = 284;

    //* --- blit the music volume bars ---
    for (int i = 0; i < (scanValue(2) / 8) + 1; i++) {
        if (i == 0)
            SDL_BlitSurface(sub[42].win, NULL, screen, &sub[42].pos);
        else if (i == 16)
            SDL_BlitSurface(sub[43].win, NULL, screen, &sub[42].pos);
        else
            SDL_BlitSurface(sub[44].win, NULL, screen, &sub[42].pos);
        sub[42].pos.x += 15;
    }
    // reset the X42;
    sub[42].pos.x = 1341;

    //* --- blit the sound volume bars ---
    // Y42 = Y43 = Y44 :: we choose to change Y42
    sub[42].pos.y = 365;
    for (int i = 0; i < (scanValue(3) / 8) + 1; i++) {
        if (i == 0)
            SDL_BlitSurface(sub[42].win, NULL, screen, &sub[42].pos);
        else if (i == 16)
            SDL_BlitSurface(sub[43].win, NULL, screen, &sub[42].pos);
        else
            SDL_BlitSurface(sub[44].win, NULL, screen, &sub[42].pos);
        sub[42].pos.x += 15;
    }
}

/*
? --- init_rs_lang(surface*) void func ---
* blit the language option menu
*/
void init_rs_lang(surface* sub) {
    //* blit the contour_03 and the shape
    SDL_BlitSurface(sub[28].win, NULL, screen, &sub[28].pos);
    SDL_BlitSurface(sub[49].win, NULL, screen, (sub[49].pos.x = 1319, sub[49].pos.y = 274, &sub[49].pos));

    //* blit the Eng and Frc normal imgs
    SDL_BlitSurface(sub[45].win, NULL, screen, (sub[45].pos.x = 1062, sub[45].pos.y = 292, &sub[45].pos));
    SDL_BlitSurface(sub[46].win, NULL, screen, (sub[46].pos.x = 1451, sub[46].pos.y = 292, &sub[46].pos));
}

/*
? --- init_rs_gmP(surface*) void func ---
* blit the game_paly option menu :: support the @autosave mode
*/
void init_rs_gmP(surface* sub) {
    //* blit the contour_03
    SDL_BlitSurface(sub[28].win, NULL, screen, &sub[28].pos);

    //* blit the speedRun normal img
    SDL_BlitSurface(sub[50].win, NULL, screen, (sub[50].pos.x = 971, sub[50].pos.y = 294, &sub[50].pos));

    //* blit the left and right video buttons
    SDL_BlitSurface(sub[30].win, NULL, screen, (sub[30].pos.y = 300, &sub[30].pos));
    SDL_BlitSurface(sub[31].win, NULL, screen, (sub[31].pos.y = 300, &sub[31].pos));

    //* blit off/on fullscreen mode state
    if (!scanValue(5))
        SDL_BlitSurface(sub[36].win, NULL, screen, &sub[36].pos);
    else
        SDL_BlitSurface(sub[35].win, NULL, screen, &sub[36].pos);
}

/*
? --- scanValue(int) int func ---
* return 0 or (1 or SDL_code_number)
*/
int scanValue(int line) {
    //* open the settings file
    FILE* file = fopen("project/doc/settings", "r");
    if (!file) {
        perror("Error: can't open settings file !"); exit(EXIT_FAILURE);
    }

    /*
    ? holder     :: to detect the newLine char ('\n')
    ? consumer   :: to store the unused info
    ? ln         :: to detect the file line number
    ? value      :: to store the needed info (0 or 1 or SDL_code_number)
    */
    char holder,
        consumer[100];
    int value,
        ln = 0;

    while ((holder = fgetc(file)) != EOF) {
        if (ln == line) {
            fscanf(file, "%s%d", consumer, &value);
            break;
        }
        if (holder == '\n') ln++;
    }

    //* close the settings file
    fclose(file);

    return value;
}

/*
? --- loadResources(surface*, char*) void func ---
* load all res
*/
void loadResources(surface* sub, char* path, int begin_res, int nbr_res) {
    while (begin_res < nbr_res) {
        char tmp_path[260];
        sprintf(tmp_path, "%s%d%s", path, begin_res, ".png");
        sub[begin_res].win = load_img(tmp_path);
        begin_res++;
    }
}

/*
? --- freeResources(surface*) void func ---
* free all res :: sub_surfaces, chunk and ttf
*/
void freeResources(surface *sub) {
    for(int i = 0; i < 51; i++) SDL_FreeSurface(sub[i].win);
}