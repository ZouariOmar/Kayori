/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @update: 04/11/24
? @file:   settings.c
----------------------------------------------- */

//? ----------------------- TODO SECTION DECLARATION PART -----------------------
//TODO_01: working on the 5 usr_modification functions             :: @ZouariOmar
//TODO_03: move the 5 usr_modification functions to a new c files  :: @ZouariOmar
//TODO_02: support the mouse events (motion and button down click) :: @ZouariOmar

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
    video
};

/*
? settings(int*) void func
* quit_game can be 0 or 1
*/
void settings(int *quit_game) {
    // * all 100 settings sub-surfaces
    surface sub[52];

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
    init_rs_ctrl(sub);

    //* ctrl button selected by default
    SDL_BlitSurface(sub[7].win,  NULL, screen, &sub[7].pos);
    
    

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

                        //? --- ENTER CLICK OPTION ---
                        case SDLK_SPACE:
                            //* deselect the usr curent position
                            scroll_UD(sub, &usrOpPos, 0);

                            //* activate the sub_menu mode (depending on the usr option position var)
                            usr_modification[usrOpPos](sub);
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
    if (direction)
        SDL_BlitSurface(sub[7 + *usrOpPos].win,  NULL, screen, &sub[7 + *usrOpPos].pos);
}

/*
? set_pos(surface*) void func
* determinate the positions of all sub_surfaces
! we need to rm set_pos(surface*) void func :: all instruction will be included in the blit instruction
*/
void set_pos(surface* sub) {
    //* open the settings file
    FILE* file = fopen("project/doc/settings_ref", "r");
    if (!file) {
        perror("Error: can't open settings_ref file !"); exit(EXIT_FAILURE);
    }

    //* fill all surface positions
    int i = 0;
    while (i < 52 && fscanf(file, "%hd%hd", &(sub[i].pos.x), &(sub[i].pos.y)) == 2)
        i++;

    //* close the settings file
    fclose(file);
}

//? ----------------------- INIT FUNCTIONS DEV PART -----------------------
/*
? --- initResources(surface*) void func ---
* blit the first viewed res (not all them)
*/
void initResources(surface* sub) {
    sub[0].pos.x = 0; sub[0].pos.y = 0;
    //* LS sub_surfaces blit part
    for (int i = 0; i < 7; i++)
        SDL_BlitSurface(sub[i].win,  NULL, screen, &sub[i].pos);
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
    //* blit the video std imgs (2 img) && blit the left and right video buttons
    for (int i = 28; i < 32; i++)
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

    //* rest to the original values
    sub[30].pos.y = 300;
    sub[31].pos.y = 300;

    // X42 = X43 = X44 :: we choose X42
    sub[42].pos.x = 1341;
    sub[42].pos.y = 284;

    //TODO: optimize the music and sound bars blit proccess in 1 fn
    //* --- blit the music volume bars ---
    for (int i = 1; i <= (int)(scanValue(2) / 8); i++) {
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
        sub[42].pos.x += 15;
    }
    // reset the X42;
    sub[42].pos.x = 1341;

    //* --- blit the sound volume bars ---
    // Y42 = Y43 = Y44 :: we choose to change Y42
    sub[42].pos.y = 365;
    for (int i = 1; i <= (int)(scanValue(3) / 8); i++) {
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
        sub[42].pos.x += 15;
    }
    // reset the X42 and Y42
    sub[42].pos.x = 1341;
    sub[42].pos.y = 284;
}

/*
? --- init_rs_lang(surface*) void func ---
* blit the language option menu :: support the @autosave mode
*/
void init_rs_lang(surface* sub) {
    //* blit the contour_03 and the shape
    SDL_BlitSurface(sub[28].win, NULL, screen, &sub[28].pos);
    SDL_BlitSurface(sub[49].win, NULL, screen, (sub[49].pos.x = 1319, sub[49].pos.y = 274, &sub[49].pos));

    //* blit the Eng and Frc normal imgs
    if (!scanValue(4)) {
        //* Eng option selected
        SDL_BlitSurface(sub[47].win, NULL, screen, (sub[47].pos.x = 952,  sub[47].pos.y = 275, &sub[47].pos));
        SDL_BlitSurface(sub[46].win, NULL, screen, (sub[46].pos.x = 1451, sub[46].pos.y = 292, &sub[46].pos));
    } else {
        //* Frc option selected
        SDL_BlitSurface(sub[48].win, NULL, screen, (sub[48].pos.x = 1320, sub[48].pos.y = 275, &sub[48].pos));
        SDL_BlitSurface(sub[45].win, NULL, screen, (sub[45].pos.x = 1062, sub[45].pos.y = 292, &sub[45].pos));
    }
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

//? ----------------------- USR_MODIFICATION FUNCTIONS DEV PART -----------------------
/*
? controls(surface*, int) void func
* in this section the usr can change:
    * keyboard_configuration
    * controller_configuration
*/
void controls(surface* sub) {
    //* the curent user option position
    int ctrl_usrOpPos = 0;

    //* init part
    SDL_BlitSurface(sub[15].win, NULL, screen, &sub[15].pos);
    for (int i = 17; i < 23; i++)
        SDL_BlitSurface(sub[i].win, NULL, screen, &sub[i].pos);

    //* update the screen
    SDL_Flip(screen);

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
* scroll the right menu up and down
*/
void rs_scroll_UD(surface* sub, int* ctrl_usrOpPos, int direction) {
    //* del the old rs_interface
    SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 274, &sub[0].pos), screen, &sub[0].pos);

    //* blit the contour img
    SDL_BlitSurface(sub[12].win,  NULL, screen, &sub[12].pos);

    //* blit the @normal_img for the curent usr option
    SDL_BlitSurface(sub[13 + *ctrl_usrOpPos].win,  NULL, screen, &sub[13 + *ctrl_usrOpPos].pos);

    //* update the usrOpPos
    *ctrl_usrOpPos += direction;

    //* blit the sub left menu
    //! support the kb_menu only (we don't have the controller resources)
    for (int i = 17; i < 23 && !(*ctrl_usrOpPos); i++)
        SDL_BlitSurface(sub[i].win, NULL, screen, &sub[i].pos);

    //* fix usr option postion
    if (*ctrl_usrOpPos == -1)
        *ctrl_usrOpPos = 1;
    else if (*ctrl_usrOpPos == 2)
        *ctrl_usrOpPos = 0;

    //* blit the @animated_img for the new usr option
    SDL_BlitSurface(sub[15 + *ctrl_usrOpPos].win,  NULL, screen, &sub[15 + *ctrl_usrOpPos].pos);
}

/*
? video(surface*) void func
* in this section the usr can change:
    * fullscreen mode
        * 0:              windowed(1920x1080)
        * SDL_FULLSCREEN: fullscreen
* support the @autosave mode
*/
void video(surface* sub) {
    //* init part
    SDL_BlitSurface(sub[32].win, NULL, screen, &sub[32].pos);

    //* update the screen
    SDL_Flip(screen);

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
                            editValue("fullscreen", 0, 1);

                            //* reset the screen
                            initResources(sub);

                            //* reset the video menu surface
                            init_rs_vid(sub);
                            SDL_BlitSurface(sub[32].win, NULL, screen, &sub[32].pos);

                            //* blit left normal button
                            SDL_BlitSurface(sub[30].win, NULL, screen, &sub[30].pos);
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            //* fullscreen mode set
                            setScreen(SDL_FULLSCREEN);
                            
                            //* change to fullscreen mode
                            editValue("fullscreen", SDL_FULLSCREEN, 1);

                            //* reset the screen
                            initResources(sub);

                            //* reset the video menu surface
                            init_rs_vid(sub);
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
? rn_settings(surface*) void func
* return to the main settings menu proccess
*/
void rn_settings(surface* sub) {
    //* del the old rs_surface
    SDL_BlitSurface(sub[0].win, (sub[0].pos.x = 952, sub[0].pos.y = 274, &sub[0].pos), screen, &sub[0].pos);

    //* reset the sub menu surface
    init[usrOpPos](sub);

    //* reset the settings menu selection
    SDL_BlitSurface(sub[7 + usrOpPos].win,  NULL, screen, &sub[7 + usrOpPos].pos);
}

/*
? editValue(int) void func
* update the changed option info
*/
void editValue(char* option, int value, int line) {
    //* open the settings file
    FILE* file = fopen("project/doc/settings", "r+");
    if (!file) {
        perror("Error: can't open settings file !");
        exit(EXIT_FAILURE);
    }

    //* creat a tmp file
    FILE* tmp_file = fopen("project/doc/tmp", "w+");
    if (!tmp_file) {
        perror("Error: can't open the file !");
        exit(EXIT_FAILURE);
    }

    /*
    ? holder     :: to detect the newLine char ('\n')
    ? ln         :: to detect the file line number
    */
    char holder;
    int ln = 0;

    //* process each character in the settings file
    while ((holder = fgetc(file)) != EOF) {
        if (ln == line) {
            //* add the update info line
            fprintf(tmp_file, "%s  %d\n", option, value);
            ln++;

            //* skip the rest of the original value line
            while ((holder = fgetc(file)) != EOF && holder != '\n');
        } else {
            //* add the other info
            fputc(holder, tmp_file);
            if (holder == '\n') ln++;
        }
    }

    //* close both files
    fclose(file);
    fclose(tmp_file);

    //* replace the original file with the tmp file
    remove("project/doc/settings");
    rename("project/doc/tmp", "project/doc/settings");
}






//? ----------------------- LOAD && FREEING FUNCTIONS DEV PART -----------------------
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
    for(int i = 0; i < 52; i++) SDL_FreeSurface(sub[i].win);
}