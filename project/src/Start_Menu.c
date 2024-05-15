/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @author: @ZouariOmar @Fraddosse1
* @IDE:    @vsc @sublime
* @update: 05/15/24
? @file:   start_menu.c
----------------------------------------------- */

//? ----------------------- NOTE SECTION DECLARATION PART -----------------------
/*
* NONE...
*/

//? -------------------- INCLUDE PROTOTYPE DECLARATION PART --------------------
#include "../inc/inc.h"


//? ----------------------- FUNCTIONS PROTOTYPE DEV PART -----------------------

void start_menu() {
    //* the curent user option position
    int usrOpPos = 0;

    // * all 10 start_menu sub-surfaces
    surface sub[11];

    //* load all 3 saves info
    load_info info[3];
    scanLvlInfo("project/doc/load_lvl", info);

    //* init the chunk 
    Mix_Chunk *pip = Mix_LoadWAV("project/res/music/rac_menu_beep.wav");

    //* load the @soundVolume
    Mix_VolumeChunk(pip, scanValue("project/doc/settings", 24));

    //? ----------------------- initializing part -----------------------
    //* load the start_menu resources
    loadResources(sub, "project/res/img_start_menu/img", 0, 11);

    //* set potions for the other res
    set_pos(sub, "project/doc/start_menu_ref", 11);

    //* initializing the start_menu resources
    SDL_BlitSurface(sub[0].win, NULL, screen, &sub[0].pos);
    SDL_BlitSurface(sub[1].win, NULL, screen, &sub[1].pos);
    sm_initResources(sub, info[0], 0, 1);
    sm_initResources(sub, info[1], 1, 0);
    sm_initResources(sub, info[2], 2, 0);

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
                        }
                    break;

                //? ------------------ MOUSE BUTTON DOWN CLICK EVENT ------------------
                case SDL_MOUSEBUTTONDOWN:
                    //* deselect the usr curent position
                    scroll_UD(sub, &usrOpPos, 0, pip);

                    //* activate the sub_menu mode (depending on the usr option position var)

                    break;
                //? ------------------- KB BUTTON DOWN CLICK EVENT -------------------
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        //? --- UP CLICK OPTION ---
                        case SDLK_UP:
                            sm_scroll_UD(sub, info, &usrOpPos, -1, pip);
                            break;

                        //? --- DOWN CLICK OPTION ---
                        case SDLK_DOWN:
                            sm_scroll_UD(sub, info, &usrOpPos, 1, pip);
                            break;

                        //? --- ENTER CLICK OPTION ---
                        case SDLK_SPACE:
                            if (usrOpPos == 3)
                                return;
                            else
                                //* load/new game part...
                            break;

                        //? --- ESCAPE CLICK OPTION ---
                        case SDLK_ESCAPE:
                            //* free all settings res
                            freeResources(sub, NULL, pip, 11);
                            return;

                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? --------------------- QUIT CLICK EVENT ---------------------
                case SDL_QUIT:
                    //* free all settings res
                    freeResources(sub, NULL, pip, 11);

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

void sm_scroll_UD(surface *sub, load_info *info, int *usrOpPos, int direction, Mix_Chunk *pip) {
    //* play the pip chunk
    Mix_PlayChannel(-1, pip, 0);

    //* del the old surface
    SDL_BlitSurface(sub[0].win, NULL, screen, &sub[0].pos);

    //* update the @usrOpPos var
    (*usrOpPos) += direction;
    if (*usrOpPos == -1)
        *usrOpPos = 3;
    else if (*usrOpPos == 4)
        *usrOpPos = 0;

    switch (*usrOpPos) {
        //* display the button number 1
        case 0:
            SDL_BlitSurface(sub[1].win, NULL, screen, &sub[1].pos);
            sm_initResources(sub, info[0], 0, 1);
            sm_initResources(sub, info[1], 1, 0);
            sm_initResources(sub, info[2], 2, 0);
            break;

        //* display the button number 2
        case 1:
            SDL_BlitSurface(sub[1].win, NULL, screen, &sub[1].pos);
            sm_initResources(sub, info[0], 0, 0);
            sm_initResources(sub, info[1], 1, 1);
            sm_initResources(sub, info[2], 2, 0);
            break;

        //* display the button number 2
        case 2:
            SDL_BlitSurface(sub[1].win, NULL, screen, &sub[1].pos);
            sm_initResources(sub, info[0], 0, 0);
            sm_initResources(sub, info[1], 1, 0);
            sm_initResources(sub, info[2], 2, 1);
            break;

        //* display the quit button
        case 3:
            SDL_BlitSurface(sub[2].win, NULL, screen, &sub[2].pos);
            sm_initResources(sub, info[0], 0, 0);
            sm_initResources(sub, info[1], 1, 0);
            sm_initResources(sub, info[2], 2, 0);
            break;

        //* none
        default:
            break;
    }
}

void sm_initResources(surface *sub, load_info info, int save_nbr, int usrOpPos) {
    if (save_nbr == 0)
        set_pos(sub, "project/doc/start_menu_ref", 11);

    else if (save_nbr == 1) {
        sub[3 + usrOpPos].pos.y  = 430;
        sub[5 + usrOpPos].pos.y  = 400;
        sub[7].pos.y  = 446;
        sub[8].pos.y  = 493;
        sub[9].pos.y  = 546;
        sub[10].pos.y = 590;

    } else {
        sub[3 + usrOpPos].pos.y  = 735;
        sub[5 + usrOpPos].pos.y  = 705;
        sub[7].pos.y  = 750;
        sub[8].pos.y  = 797;
        sub[9].pos.y  = 850;
        sub[10].pos.y = 894;
    }

    if (info.estimated_time_ms) {
        SDL_BlitSurface(sub[5 + usrOpPos].win, NULL, screen, &sub[5 + usrOpPos].pos);
        for (int i = 0; i < 4; i++) {
            //* init the "Groundation Foundation.ttf"
            TTF_Font *font = TTF_OpenFont("project/res/font/Groundation Foundation.ttf", 30);

            //* cast the info to txt char
            char txt[4][11];
            sprintf(txt[0], "%d",   info.current_lvl);
            sprintf(txt[1], "%d%s", info.estimated_time_ms, "ms");
            sprintf(txt[2], "%d",   info.death_time);
            sprintf(txt[3], "%d",   info.collected_items);

            surface inf[4];
            for (int i = 0; i < 4; i++)
                inf[i].win = TTF_RenderText_Blended(font, txt[i], BLACK);

            SDL_BlitSurface(inf[i].win, NULL, screen, (inf[i].pos.x = sub[7 + i].pos.x + 50, inf[i].pos.y = sub[7 + i].pos.y + 10, &inf[i].pos));
            SDL_BlitSurface(sub[7 + i].win, NULL, screen, &sub[7 + i].pos);
        }

    } else
        SDL_BlitSurface(sub[3 + usrOpPos].win, NULL, screen, &sub[3 + usrOpPos].pos);
}

void scanLvlInfo(char *path, load_info *info) {
	//* open the settings file
    FILE* file = fopen(path, "r");
    if (!file) {
        perror("Error: can't open load_lvl file !"); exit(EXIT_FAILURE);
    }

    /*
    ? holder     :: to detect the newLine char ('\n')
    ? ln         :: to detect the file line number
    */
    char holder[MAX_PATH];
    int ln = 0;

	//* scan info from file and put into @holder
    while (ln < 3 && fgets(holder, sizeof(holder), file))
		//* scan info from @holder and put it into @info_struct
        if (sscanf(holder, "%d%d%d%d", &info[ln].current_lvl, &info[ln].estimated_time_ms, &info[ln].death_time, &info[ln].collected_items) == 4)
            ln++;

    //* close the settings file
    fclose(file);
}
