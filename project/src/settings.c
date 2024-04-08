/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @update: 04/06/24
? @file:   settings.c
----------------------------------------------- */

//? -------------------- INCLUDE PROTOTYPE DECLARATION PART --------------------
#include "../inc/inc.h"

//? ----------------------- FUNCTIONS PROTOTYPE DEV PART -----------------------
/*
? settings(int*) void func
* quit_game can be 0 or 1
*/
void settings(int *quit_game) {
    // * all 100 settings sub-surfaces
    surface sub[12];

    //? ----------------------- initializing part -----------------------
    //* load the settings resources
    loadResources(sub, "project/res/settings_srf/img");

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
                            break;

                        //? --- DOWN CLICK OPTION ---
                        case SDLK_DOWN:
                            scroll_UD(sub, &usrOpPos, 1);
                            break;
                        
                        //? --- LEFT CLICK OPTION ---
                        case SDLK_LEFT:
                            // rest of code...
                            break;

                        //? --- RIGHT CLICK OPTION ---
                        case SDLK_RIGHT:
                            // rest of code
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
        // * update the screen
        SDL_Flip(screen);

        // * wait 100 millisecond befor returning
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
        if (i != usrOpPos)
            SDL_BlitSurface(sub[2 + i].win,  NULL, screen, &sub[2 + i].pos);

    //* update the usrOpPos
    *usrOpPos += direction;

    //* fix usr option postion
    if (*usrOpPos < 0)
        *usrOpPos = 4;
    else if (*usrOpPos > 4)
        *usrOpPos = 0;

    //* blit the @animated_img for the new usr option
    SDL_BlitSurface(sub[7 + *usrOpPos].win,  NULL, screen, &sub[7 + *usrOpPos].pos);
}

//? ----------------------- INIT FUNCTIONS DEV PART -----------------------
/*
? loadResources(surface*, char*) void func
* load all res
*/
void loadResources(surface* sub, char* path) {
    int i = 0;
    while (i < 12) {
        char tmp_path[260];
        sprintf(tmp_path, "%s%d%s", path, i, ".png");
        sub[i].win = load_img(tmp_path);
        i++;
    }
}

/*
? set_pos(surface*) void func
* determinate the positions of all sub_surfaces
*/
void set_pos(surface* sub) {
    //* bkg img position
    sub[0].pos.x = 0; sub[0].pos.y = 0;
    

    //? --- left menu img positions ---
    //* contour img postion
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
}

/*
? initResources(surface*) void func 
* blit the first viewed res (not all them)
*/
void initResources(surface* sub) {
    SDL_BlitSurface(sub[0].win,  NULL, screen, &sub[0].pos);
    SDL_BlitSurface(sub[1].win,  NULL, screen, &sub[1].pos);
    SDL_BlitSurface(sub[7].win,  NULL, screen, &sub[7].pos);
    SDL_BlitSurface(sub[3].win,  NULL, screen, &sub[3].pos);
    SDL_BlitSurface(sub[4].win,  NULL, screen, &sub[4].pos);
    SDL_BlitSurface(sub[5].win,  NULL, screen, &sub[5].pos);
    SDL_BlitSurface(sub[6].win,  NULL, screen, &sub[6].pos);
}

/*
? freeResources(surface*) void func
* free all res :: sub_surfaces, chunk and ttf
*/
void freeResources(surface *sub) {
    for(int i = 0; i < 12; i++) SDL_FreeSurface(sub[i].win);
}