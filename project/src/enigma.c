/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @author: @ZouariOmar @kouka12345
* @update: 04/24/24
? @file:   enigma.c
----------------------------------------------- */

//? ----------------------- TODO SECTION DECLARATION PART -----------------------
/*
TODO_01: fix the timer
TODO_02: fix the @enigma_load_file :: taille, pos and displaying mode (del the "_")
*/

//? -------------------- INCLUDE PROTOTYPE DECLARATION PART --------------------
#include "../inc/inc.h"

//? ----------------------- FUNCTIONS PROTOTYPE DEV PART -----------------------

void enigma() {
    //* init the 9 enigma sub-surfaces
    surface sub[30];

    //* init the @usrOpPos var (get 0 by default)
    int usrOpPos = 0;

    //* init the @enigma_info holder
    eg e;

    //* init the elapsed time var
    int elapsed_time = 0;

    //* load the enigma resources
    loadResources(sub, "project/res/img_enigma/img", 0, 6);
    loadResources(sub, "project/res/img_enigma/timer_bar/img", 6, 26);

    //* set the enigma pos surfaces
    set_pos(sub, "project/doc/enigma_ref", 30);

    //* set the @timer_seed
    srand(time(NULL));

    /*
    * generate random number that will indicate the enigma info
    * get the enigma info using the @scanEnigma fn
    */
    scanEnigma("project/doc/enigma", &e, rand() % 21);

    //* initializing the enigma first viewed resources
    initEnigma(sub, e);

    //* update the screen
    SDL_Flip(screen);

    while (1) {
        qcm(sub, &elapsed_time);
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
                        //? --- LEFT CLICK OPTION ---
                        case SDLK_LEFT:
                            if (elapsed_time < 20)
                                scroll_LR(sub, &usrOpPos, -1);
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            if (elapsed_time < 20)
                                scroll_LR(sub, &usrOpPos, 1);
                            break;

                        //? --- ENTER CLICK OPTION ---
                        case SDLK_SPACE:
                                //* blit the red/green_box
                                for (int i = 0; i < 3 && elapsed_time != 21; i++)
                                    SDL_BlitSurface(sub[2 + (i == e.answer)].win, NULL, screen, &sub[1 + i].pos);

                                //* change the @elapsed_time value to avoid infinite img blit
                                elapsed_time = 22;
                            break;

                        //? --- ESCAPE CLICK OPTION ---
                        case SDLK_ESCAPE:
                            freeResources(sub, NULL, NULL, 30);
                            return;

                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? ------------------- KB BUTTON UP CLICK EVENT -------------------
                case SDL_KEYUP:
                    switch(event.key.keysym.sym) {
                        //? --- ENTER CLICK OPTION ---
                        case SDLK_SPACE:
                            if (elapsed_time == 22) {
                                //* blit/reset the bkg img
                                SDL_BlitSurface(sub[0].win, NULL, screen, &sub[0].pos);

                                //* blit "You Win" or "You lose" img
                                SDL_BlitSurface(sub[4 + (usrOpPos == e.answer)].win, NULL, screen, &sub[4].pos);

                                //* change the @elapsed_time value to avoid infinite img blit
                                elapsed_time = 21;
                            }
                            break;

                        //? --- OTHER CLICK OPTION ---
                        default:
                            break;
                    }
                    break;

                //? --------------------- QUIT CLICK EVENT ---------------------
                case SDL_QUIT:
                    freeResources(sub, NULL, NULL, 30);
                    exit(EXIT_SUCCESS);
                    break;

                //? --------------------- OTHER CLICK EVENT ---------------------
                default:
                    break;
            }
        }
        qcm(sub, &elapsed_time);
        //* update the screen
        SDL_Flip(screen);

        //* wait 100 millisecond befor returning
        SDL_Delay(100);
    }
}

void initEnigma(surface *sub, eg e) {
    //* open the @Groundation_Foundation ttf file in @size01 and @size02
    TTF_Font *font_size01 = TTF_OpenFont("project/res/font/Groundation Foundation.ttf", 35);
    TTF_Font *font_size02 = TTF_OpenFont("project/res/font/Groundation Foundation.ttf", 25);

    //* Render the @enigma_info
    sub[26].win  = TTF_RenderText_Blended(font_size02, e.op1, WHITE);
    sub[27].win  = TTF_RenderText_Blended(font_size02, e.op2, WHITE);
    sub[28].win  = TTF_RenderText_Blended(font_size02, e.op3, WHITE);
    sub[29].win  = TTF_RenderText_Blended(font_size01, e.qcm, WHITE);

    //* blit the @enigma_info
    for (int i = 0; i < 30; i++) {
        if (i == 2)
            i = 6;
        SDL_BlitSurface(sub[i].win, NULL, screen, &sub[i].pos);
    }

    //* free fonts res
    TTF_CloseFont(font_size01);
    TTF_CloseFont(font_size02);
}

void scroll_LR(surface *sub, int *usrOpPos, int direction) {
    //* del the old selected img and reset it to normal img
    SDL_BlitSurface(sub[0].win, &sub[1 + *usrOpPos].pos, screen, &sub[1 + *usrOpPos].pos);
    SDL_BlitSurface(sub[26 + *usrOpPos].win, NULL, screen, &sub[26 + *usrOpPos].pos);

    //* update the @usrOpPos
    *usrOpPos += direction;

    //* correct the @usrOpPos to be in range(0, 1)
    if (*usrOpPos == -1)
        *usrOpPos = 2;
    else if (*usrOpPos == 3)
        *usrOpPos = 0;

    //* blit the new select bar
    SDL_BlitSurface(sub[1].win, NULL, screen, &sub[1 + *usrOpPos].pos);
}

void scanEnigma(char *path, eg *e, int line) {
    //* open the settings file
    FILE* file = fopen(path, "r");
    if (!file) {
        perror("Error: can't open settings file !"); exit(EXIT_FAILURE);
    }

    /*
    ? holder     :: to detect the newLine char ('\n')
    ? ln         :: to detect the file line number
    */
    char holder;
    int ln = 0;

    while ((holder = fgetc(file)) != EOF) {
        if (holder == '\n') ln++;
        if (ln == line) {
            fscanf(file, "%s%s%s%s%d", e->qcm, e->op1, e->op2, e->op3, &e->answer);
            break;
        }
    }

    //* close the settings file
    fclose(file);
}

void qcm(surface *sub, int *elapsed_time) {
    //* init the @time_counter
    struct timeval current_time;
    gettimeofday(&current_time, NULL);

    //* del 1 single @nano_bar every 20msec
    if (!(current_time.tv_usec % 20) && *elapsed_time < 20) {
        SDL_BlitSurface(sub[0].win, &sub[6 + *elapsed_time].pos, screen, &sub[6 + *elapsed_time].pos);
        (*elapsed_time)++;
    }

    //* if the usr lose by time
    if (*elapsed_time == 20) {
        //* blit/reset the bkg img
        SDL_BlitSurface(sub[0].win, NULL, screen, &sub[0].pos);

        //* blit "You Lose" img
        SDL_BlitSurface(sub[4].win, NULL, screen, &sub[4].pos);

        //* change the @elapsed_time value to avoid infinite "You Lose" img blit
        *elapsed_time = 21;
    }
}