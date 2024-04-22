/* -----------------------------------------------
* @author: by_kayori_Nova_Grp
* @date:   03/18/2024
? @file:   __ttt_game__.c
----------------------------------------------- */

/*
! Next Update:
TODO: ameliorate the bot choices (using IA for the 8 direction :: (2 toc in row or 1 toc need it to win) && available postion ==> forcing win)
TODO: make decision about the scrolling part (SDLK_Up && SDLK_Down have 2 bugs)
! 2 bugs code info :: taken_pos(1.2.3.4.6.8 // or reversed(2nd bug)) && usr_current_pos = 0 ** from usr_current_pos to 7 impossible (forcing move to position 5)
TODO: add the front-end toe part
* actual solution for the 2 bugs :: make the scrolling part (SDLK_Up && SDLK_Down) working the same as the scrolling part (SDLK_Left && SDLK_Right) ==> use scroll_UDLR() void func
*/
                    /* INCLUDE PROTOTYPE DECLARATION PART */
#include "../inc/inc.h"
                    /* FUNCTIONS PROTOTYPE DEV PART */
void __ttt_game__() {
    
    // * load_part
    surface sub[16];
    loadResources(sub);
    initResources(sub);

    // * usr_info :: range(0, 8)
    int usr_current_pos = 0;

    /*
    ? ttt_info
    * taken_pos[] take by default the index -1             :: none action
    * taken_pos[] take 0 if the usr choice the current pos :: tic action
    * taken_pos[] take 1 if the bot choice a random pos    :: tac action
    */
    int taken_pos[9];
    for (int i = 0; i < 9; i++) taken_pos[i] = -1;
    int ttt_taken_pos = 0;

    // * update the screen
    SDL_Flip(screen);

    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                    /* KEY DOWN EVENT */
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        
                        // ! the usr will choice the option by pressing SPACE KEY
                        case SDLK_SPACE:
                                /* usr treatment part */
                            if (ttt_taken_pos < 9) {

                                // * add one for the usr
                                ttt_taken_pos++;
                                
                                // * update taken_pos[] var
                                taken_pos[usr_current_pos] = 0;

                                // * del the old usr_postion
                                SDL_BlitSurface(sub[1].win, (sub[1].pos.x = sub[7].pos.x - 603, sub[1].pos.y = sub[7].pos.y - 186, sub[1].pos.w = 150, sub[1].pos.h = 110, &sub[1].pos), screen, &sub[7].pos);
                                
                                // * blit the kayori head (tic action)
                                SDL_BlitSurface(sub[4].win, NULL, screen, &sub[7].pos);

                                // * check if the usr win or not
                                check_ttt(sub, taken_pos, 0, &ttt_taken_pos);
                                if (ttt_taken_pos == 9)
                                    break;
                                
                                // * fill the new usr_position && update the usr_postion
                                usr_current_pos = is_free(taken_pos);
                                
                                // ! check if the usr_current_pos == -1 or not (this is caused by the game_priority ==> the player will have 5 moves)
                                if (usr_current_pos != -1) {
                                    // * fill the new usr_rect_index
                                    have_coordinate(&(sub[7].pos.x), &(sub[7].pos.y), usr_current_pos);
                                    SDL_BlitSurface(sub[7].win, NULL, screen, &sub[7].pos);
                                }
                            }
                            break;

/*
!   when we detect "SDLK_UP(SDLK_DOWN)" event we will reduce(add) the usr position by i = 3
!!  if the new postion is already used :: reduce(add) i by 1 in tell we have a available postion
!!! we verify if the new postion is between 0 and 8
*/

                        // * moving up (exp: from postion 8 to potion 5)
                        case SDLK_UP:
                            if (ttt_taken_pos < 9) {
                                // * update the usr_postion
                                usr_current_pos -= 3;

                                // ! check if the usr_current_pos is out of range
                                if (usr_current_pos <= -1) usr_current_pos += 9;

                                // ! check if the new_usr_pos is available
                                while (taken_pos[usr_current_pos] != -1) {
                                    usr_current_pos--;
                                    if (usr_current_pos <= -1) usr_current_pos = 8;
                                }

                                // * del the old usr_postion
                                SDL_BlitSurface(sub[1].win, (sub[1].pos.x = sub[7].pos.x - 603, sub[1].pos.y = sub[7].pos.y - 186, sub[1].pos.w = 150, sub[1].pos.h = 110, &sub[1].pos), screen, &sub[7].pos);
                                
                                // * fill the new usr_rect_index
                                have_coordinate(&(sub[7].pos.x), &(sub[7].pos.y), usr_current_pos);
                                SDL_BlitSurface(sub[7].win, NULL, screen, &sub[7].pos);
                            }
                            //// scroll_UDLR(int ttt_taken_pos, int &usr_current_pos, int taken_pos, surface *, surface *);

                            break;
                        
                        // * moving down (exp: from postion 4 to potion 1)
                        case SDLK_DOWN:
                            if (ttt_taken_pos < 9) {
                                // * update the usr_postion
                                usr_current_pos += 3;

                                // * check if the usr_current_pos is out of range
                                if (usr_current_pos >= 9) usr_current_pos -= 9;

                                // * check if the new_usr_pos is available
                                // ? can replace it with is_free()
                                while (taken_pos[usr_current_pos] != -1) {
                                    usr_current_pos++;
                                    if (usr_current_pos >= 9) usr_current_pos = 0;
                                }

                                // * del the old usr_postion
                                SDL_BlitSurface(sub[1].win, (sub[1].pos.x = sub[7].pos.x - 603, sub[1].pos.y = sub[7].pos.y - 186, sub[1].pos.w = 150, sub[1].pos.h = 110, &sub[1].pos), screen, &sub[7].pos);
                                
                                // * fill the new usr_rect_index
                                have_coordinate(&(sub[7].pos.x), &(sub[7].pos.y), usr_current_pos);
                                SDL_BlitSurface(sub[7].win, NULL, screen, &sub[7].pos);
                            }
                            break;
                        
                        // * moving right (exp: from postion 0 to potion 1)
                        case SDLK_RIGHT:
                            if (ttt_taken_pos < 9) {
                                // * update the usr_postion
                                usr_current_pos++;
                                
                                // TODO: check if the position is taken
                                // * check if the usr_current_pos is out of range
                                if (usr_current_pos % 3 == 0) usr_current_pos -= 3;

                                // * check if the new_usr_pos is available
                                // ? can replace it with is_free()
                                while (taken_pos[usr_current_pos] != -1) {
                                    usr_current_pos++;
                                    if (usr_current_pos >= 9) usr_current_pos = 0;
                                }

                                // * del the old usr_postion
                                SDL_BlitSurface(sub[1].win, (sub[1].pos.x = sub[7].pos.x - 603, sub[1].pos.y = sub[7].pos.y - 186, sub[1].pos.w = 150, sub[1].pos.h = 110, &sub[1].pos), screen, &sub[7].pos);
                                
                                // * fill the new usr_rect_index
                                have_coordinate(&(sub[7].pos.x), &(sub[7].pos.y), usr_current_pos);
                                SDL_BlitSurface(sub[7].win, NULL, screen, &sub[7].pos);
                            }
                            break;
                        
                        // * moving left (exp: from postion 3 to potion 2)
                        case SDLK_LEFT:
                            if (ttt_taken_pos < 9) {
                                // * update the usr_postion
                                usr_current_pos--;
                                
                                // ! check if the usr_current_pos is out of range [0, 8]
                                if (usr_current_pos % 3 == 2 || usr_current_pos == -1) usr_current_pos += 3;
                                // ! particular cas :: if "usr_current_pos == -1" so "usr_current_pos % 3 = -1"

                                // ! check if the new_usr_pos is available
                                while (taken_pos[usr_current_pos] != -1) {
                                    usr_current_pos--;
                                    if (usr_current_pos <= -1) usr_current_pos = 8;
                                }
                                
                                // * del the old usr_postion
                                SDL_BlitSurface(sub[1].win, (sub[1].pos.x = sub[7].pos.x - 603, sub[1].pos.y = sub[7].pos.y - 186, sub[1].pos.w = 150, sub[1].pos.h = 110, &sub[1].pos), screen, &sub[7].pos);
                                
                                // * fill the new usr_rect_index
                                have_coordinate(&(sub[7].pos.x), &(sub[7].pos.y), usr_current_pos);
                                SDL_BlitSurface(sub[7].win, NULL, screen, &sub[7].pos);
                            }
                            break;

                        case SDLK_ESCAPE:
                            exit(EXIT_SUCCESS);
                            break;

                        default:
                            break;
                    }
                    break; 

                    /* KEY UP EVENT */
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                            /* SPACE UP EVENT */
                        case SDLK_SPACE:
                                /* bot treatment part */
                            if (ttt_taken_pos < 9) {
                                
                                // * add one for the bot
                                ttt_taken_pos++;

                                // * fill the new usr_position
                                while (1) {
                                    srand(time(NULL));
                                    int i = rand() % 9;
                                    if (taken_pos[i] == -1) {
                                        // * update taken_pos[] var
                                        taken_pos[i] = 1;

                                        // * del the old usr_postion
                                        SDL_BlitSurface(sub[1].win, (sub[1].pos.x = sub[7].pos.x - 603, sub[1].pos.y = sub[7].pos.y - 186, sub[1].pos.w = 150, sub[1].pos.h = 110, &sub[1].pos), screen, &sub[7].pos);

                                        // * have the available taken_pos[i] position using the index [0, 8]
                                        have_coordinate(&(sub[7].pos.x), &(sub[7].pos.y), i);

                                        // * blit the enemy (tac action)
                                        SDL_BlitSurface(sub[3].win, NULL, screen, &sub[7].pos);

                                        // * check if the usr lose
                                        check_ttt(sub, taken_pos, 1, &ttt_taken_pos);
                                        if (ttt_taken_pos == 9)
                                            break;

                                        // * have the new usr_position && update the usr_postion
                                        usr_current_pos = is_free(taken_pos);
                                        
                                        // * fill the new usr_rect_index
                                        have_coordinate(&(sub[7].pos.x), &(sub[7].pos.y), usr_current_pos);
                                        SDL_BlitSurface(sub[7].win, NULL, screen, &sub[7].pos);
                                        
                                        break;
                                    }
                                }
                            }
                            break;

                        // * other events
                        default:
                            break;
                    }
                    break;

                    /* QUIT EVENT */
                case SDL_QUIT:
                    exit(EXIT_SUCCESS);
                    break;

                    /* OTHER EVENT */
                default:
                    break;
            }
        }

        // * update the screen
        SDL_Flip(screen);
        SDL_Delay(10);
    }
}

/*
? loadResources() void func guide
* load all res using the "load_img() SDL_Surface func"
*/
void loadResources(surface sub[]) {
    for (int i = 0; i < 16; i++) {
        char tmp_path[MAX_PATH];
        sprintf(tmp_path, "%s%d%s", "res//Tic Tac Toe - Mini_Game//img", i, ".png");
        sub[i].win = load_img(tmp_path);
    }
}

/*
? initResources() void func guide
* blit the first viewed res
*/
void initResources(surface *sub) {
    SDL_BlitSurface(sub[0].win, NULL, screen, (sub[0].pos.x = 0,   sub[0].pos.y = 0,   &sub[0].pos));
    SDL_BlitSurface(sub[1].win, NULL, screen, (sub[1].pos.x = 603, sub[1].pos.y = 186, &sub[1].pos));
    SDL_BlitSurface(sub[2].win, NULL, screen, (sub[2].pos.x = 603, sub[2].pos.y = 186, &sub[2].pos));
    SDL_BlitSurface(sub[7].win, NULL, screen, (sub[7].pos.x = 662, sub[7].pos.y = 282, &sub[7].pos));
}

/*
? have_coordinate() void func guide
* take the old usr_pos_coordinate (x, y) and update them depending on the new "usr_pos (0..8)"
* the "initial_usr_pos = 0" ==> (662, 282)
! we can define x and y as "int*"
*/
void have_coordinate(Sint16* x, Sint16* y, int usr_pos) {
    // * initial usr_postion
    *x = 662, *y = 282;

    // ? fiend the x of the new usr position
    *x += 232 * (usr_pos % 3);

    // ? fiend the y of the new usr postion
    *y += 205 * (usr_pos / 3);
}

/*
? is_free() int func guide
* available pos    :: return "the index of the available pos (0..8)"
* no available pos :: return "-1"
*/
int is_free(int *t) {
    for (int i = 0; i < 9; i++) {
        if (t[i] == -1)
            return i;
    }
    return -1;
}

// ! msg var will removed (line 330) :: use blit instead
void check_ttt(surface* sub, int* t, int x, int *ttttp) {
    if (*ttttp > (4 + x) && check_rcd(sub, t, x)) {
        *ttttp = 9;
        SDL_BlitSurface(sub[14 + x].win, NULL, screen, (sub[14 + x].pos.x = 740, sub[14 + x].pos.y = 473, &sub[14 + x].pos));
    } else if(*ttttp == 9) {
        printf("toe !\n");
    }
}

int check_rcd(surface* sub, int* t, int x) {
    return (check_rows(sub, t, x) || check_columns(sub, t, x) || check_diagonals(sub, t, x));
}

int check_rows(surface* sub, int* t, int x) {
    for (int i = 0; i < 9; i += 3) {
        if(t[i] == x && t[i + 1] == x && t[i + 2] == x) {

            // * blit the line depending on the x value (0 : usr or 1 : bot)
            // * for rows the pos.x = 662 (const)
            // * 340 is the pos.x of the index 0
            sub[5 + x].pos.y = 335;
            SDL_BlitSurface(sub[5 + x].win, NULL, screen, (sub[5 + x].pos.x = 662, sub[5 + x].pos.y += 199 * (i / 3), &sub[5 + x].pos));
            return 1;
        }
    }
    return 0;
}

int check_columns(surface* sub, int* t, int x) {
    for (int i = 0; i < 3; i++) {
        if(t[i] == x && t[i + 3] == x && t[i + 6] == x) {

            // * blit the line depending on the x value (0 : usr or 1 : bot)
            // * for columns the pos.y = 728 (const)
            // * 728 is the pos.x of the index 0
            sub[8 + x].pos.x = 725;
            SDL_BlitSurface(sub[8 + x].win, NULL, screen, (sub[8 + x].pos.x += 232 * (i % 3), sub[8 + x].pos.y = 242, &sub[8 + x].pos));
            return 1;
        }
    }
    return 0;
}

int check_diagonals(surface* sub, int* t, int x) {
    if (t[0] == x && t[4] == x && t[8] == x) {

        // * blit the line depending on the x value (0 : usr or 1 : bot)
        SDL_BlitSurface(sub[12 + x].win, NULL, screen, (sub[12 + x].pos.x = 685, sub[12 + x].pos.y = 257, &sub[12 + x].pos));
        return 1;

    } else if (t[2] == x && t[4] == x && t[6] == x) {

        // * blit the line depending on the x value (0 : usr or 1 : bot)
        SDL_BlitSurface(sub[10 + x].win, NULL, screen, (sub[10 + x].pos.x = 685, sub[10 + x].pos.y = 257, &sub[10 + x].pos));
        return 1;
    }
    return 0;
}

/*
? freeResources() void func guide
* free all res :: sub_surfaces and pip chunk
*/
void freeResources(surface *sub) {
    for(int i = 0; i < 16; i++) SDL_FreeSurface(sub[i].win);
}