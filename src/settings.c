// by_kayori_Nova_Grp
// 01/24/24
// kayori :: settings.c
                    /* INCLUDE PROTOTYPE DECLARATION PART */
#include "../inc/inc.h"
                    /* FUNCTIONS PROTOTYPE DEV PART */
void settings() {
    surface sub[41];
    int optionsAreaPos[7][3] = {            // x: 311    // need to make it dynamic !
        {2, 19, 206},                       // optionAreaPos[][0] :: the normal img pos in sub[]
        {4, 21, 319},                       // optionAreaPos[][1] :: the animated img pos in sub[]
        {5, 22, 390},                       // optionAreaPos[][2] :: the hight of th img (y) --> open figma for more details
        {7, 23, 503},
        {10, 24, 616},
        {11, 25, 687},
        {13, 26, 800},
    },
    opCtrlPos[4][3] = {             // all right & left buttons ctrls height
        {503, 30},                  // option 3 :: 30 mean that the option is in "Off" mode (30 is the loaded img pos in sub[])
        {618, 41},                  // option 4 :: 41 mean that the volume is equal 100 (41 is the loaded img pos in sub[])
        {685, 41},                  // option 5 :: 41 mean that the volume is equal 100 (41 is the loaded img pos in sub[])
        {800, 29}},                 // option 6 :: 29 mean that the option is in "On" mode (29 is the loaded img pos in sub[])
    optionPos = 0;
    loadResources(sub);
    initResources(sub);
    SDL_Flip(screen);
    while(1) {
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_MOUSEMOTION:
                    if(event.motion.x >= 683 && event.motion.x <= 683 + 430 && event.motion.y >= 30 && event.motion.y <= 30 + 130)
                        SDL_BlitSurface(sub[18].screen, NULL, screen, (sub[18].pos.x = 682, sub[18].pos.y = 30, &sub[18].pos));
                    else if(event.motion.x >= 80 && event.motion.x <= 80 + 60 && event.motion.y >= 58 && event.motion.y <= 58 + 60)
                        SDL_BlitSurface(sub[20].screen, NULL, screen, (sub[20].pos.x = 80, sub[20].pos.y = 58, &sub[20].pos)); 
                    else {
                        SDL_BlitSurface(sub[8].screen, NULL, screen, (sub[8].pos.x = 80, sub[8].pos.y = 58, &sub[8].pos));
                        SDL_BlitSurface(sub[1].screen, NULL, screen, (sub[1].pos.x = 682, sub[1].pos.y = 30, &sub[1].pos));
                    }
                    // rest of code... :: support the mouse motion for option and their buttons
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(event.motion.x >= 80 && event.motion.x <= 80 + 60 && event.motion.y >= 58 && event.motion.y <= 58 + 60 && event.button.button == SDL_BUTTON_LEFT) {
                        freeResources(sub);
                        return;
                    }
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        case SDLK_DOWN:
                            // normal img
                            SDL_BlitSurface(sub[optionsAreaPos[optionPos][0]].screen, NULL, screen, (sub[optionsAreaPos[optionPos][0]].pos.x = 311, sub[optionsAreaPos[optionPos][0]].pos.y = optionsAreaPos[optionPos][2], &sub[optionsAreaPos[optionPos][0]].pos));
                            optionPos++;
                            if(optionPos == 7) optionPos = 0;
                            // animated img
                            SDL_BlitSurface(sub[optionsAreaPos[optionPos][1]].screen, NULL, screen, (sub[optionsAreaPos[optionPos][1]].pos.x = 311, sub[optionsAreaPos[optionPos][1]].pos.y = optionsAreaPos[optionPos][2], &sub[optionsAreaPos[optionPos][1]].pos));
                            break;
                        case SDLK_UP:
                            // normal img
                            SDL_BlitSurface(sub[optionsAreaPos[optionPos][0]].screen, NULL, screen, (sub[optionsAreaPos[optionPos][0]].pos.x = 311, sub[optionsAreaPos[optionPos][0]].pos.y = optionsAreaPos[optionPos][2], &sub[optionsAreaPos[optionPos][0]].pos));
                            optionPos--;
                            if(optionPos == -1) optionPos = 6;
                            // animated img
                            SDL_BlitSurface(sub[optionsAreaPos[optionPos][1]].screen, NULL, screen, (sub[optionsAreaPos[optionPos][1]].pos.x = 311, sub[optionsAreaPos[optionPos][1]].pos.y = optionsAreaPos[optionPos][2], &sub[optionsAreaPos[optionPos][1]].pos));
                            break;
                        case SDLK_LEFT:                             /* LEFT CLICK OPTION */
                            if(3 <= optionPos && optionPos <= 6) {                              // ctrl buttons && scroll animation in option 4 and 5
                                SDL_BlitSurface(sub[27].screen, NULL, screen, (sub[27].pos.x = 1424, sub[27].pos.y = opCtrlPos[optionPos-3][0], &sub[27].pos));
                            }
                            if(optionPos == 3) {                                                // On button in option 3 :: need optimization with option 6
                                SDL_BlitSurface(sub[29].screen, NULL, screen, (sub[29].pos.x = 1485, sub[29].pos.y = 503, &sub[29].pos));
                            } else if((optionPos == 4 || optionPos == 5) && opCtrlPos[optionPos - 3][1] > 31) {                 // option 4 scroll in left part
                                opCtrlPos[optionPos - 3][1]--;
                                SDL_BlitSurface(sub[opCtrlPos[optionPos - 3][1]].screen, NULL, screen, (sub[opCtrlPos[optionPos - 3][1]].pos.x = 1485, sub[opCtrlPos[optionPos - 3][1]].pos.y = opCtrlPos[optionPos - 3][0], &sub[opCtrlPos[optionPos - 3][1]].pos));
                            }else if(optionPos == 6) {                                          // on button in option 6 :: need optimization with option 3
                                SDL_BlitSurface(sub[29].screen, NULL, screen, (sub[29].pos.x = 1485, sub[29].pos.y = 800, &sub[29].pos));
                            }
                            break;
                        case SDLK_RIGHT:                        /* RIGHT CLICK OPTION */
                            if(3 <= optionPos && optionPos <= 6) {                              // ctrl buttons && scroll animation in option 4 and 5
                                SDL_BlitSurface(sub[28].screen, NULL, screen, (sub[28].pos.x = 1570, sub[28].pos.y = opCtrlPos[optionPos-3][0], &sub[28].pos));
                            }
                            if(optionPos == 3) {                                                // Off button in option 3 :: need optimization with option 6
                                SDL_BlitSurface(sub[30].screen, NULL, screen, (sub[30].pos.x = 1485, sub[30].pos.y = 503, &sub[30].pos));
                            } else if((optionPos == 4 || optionPos == 5) && opCtrlPos[optionPos - 3][1] < 41) {                 // option 4 scroll in right part
                                opCtrlPos[optionPos - 3][1]++;
                                SDL_BlitSurface(sub[opCtrlPos[optionPos - 3][1]].screen, NULL, screen, (sub[opCtrlPos[optionPos - 3][1]].pos.x = 1485, sub[opCtrlPos[optionPos - 3][1]].pos.y = opCtrlPos[optionPos - 3][0], &sub[opCtrlPos[optionPos - 3][1]].pos));
                            } else if(optionPos == 6) {                                         // off button in option 6 :: need optimization with option 3
                                SDL_BlitSurface(sub[30].screen, NULL, screen, (sub[30].pos.x = 1485, sub[30].pos.y = 800, &sub[30].pos));
                            }
                            break;
                        default:
                            break;
                        }
                    break;
                case SDL_KEYUP:
                    switch(event.key.keysym.sym) {
                    case SDLK_LEFT:
                        if(3 <= optionPos && optionPos <= 6) {
                            SDL_BlitSurface(sub[15].screen, NULL, screen, (sub[15].pos.x = 1424, sub[15].pos.y = opCtrlPos[optionPos-3][0], &sub[15].pos));
                        }
                        break;
                    case SDLK_RIGHT:
                        if(3 <= optionPos && optionPos <= 6) {
                            SDL_BlitSurface(sub[16].screen, NULL, screen, (sub[16].pos.x = 1570, sub[16].pos.y = opCtrlPos[optionPos-3][0], &sub[16].pos));
                        }
                        break;
                    default:
                        break;
                    }
                    break;
                case SDL_QUIT:          // with event switch
                    exit(0);
            }
        } SDL_Flip(screen); SDL_Delay(100);
    }
}
void loadResources(surface sub[]) {
    int i = 0, j = 0;
    while(i < 42) {
        char path[260];
        if(i < 31)
            strcpy(path, "pkg//res//settings imgs//img");
        else
            strcpy(path, "pkg//res//Numbers//");
        fullPath(&sub[i].screen, path, (i < 31) ? i : j, ".png");
        if(i >= 31)
            j += 10;
        i++;
    }
}
void fullPath(SDL_Surface **win, char *newPath, int count, char *fileType) {
    char str_count[4];
    sprintf(str_count, "%d", count);
    strcat(newPath, str_count);
    strcat(newPath, fileType);
    *win = load_img(newPath);
}
void initResources(surface sub[]) {
    SDL_BlitSurface(sub[0].screen, NULL, screen, (sub[0].pos.x = 0, sub[0].pos.y = 0, &sub[0].pos));
    SDL_BlitSurface(sub[3].screen, NULL, screen, (sub[3].pos.x = 311, sub[3].pos.y = 277, &sub[3].pos));
    SDL_BlitSurface(sub[4].screen, NULL, screen, (sub[4].pos.x = 311, sub[4].pos.y = 319, &sub[4].pos));
    SDL_BlitSurface(sub[5].screen, NULL, screen, (sub[5].pos.x = 311, sub[5].pos.y = 390, &sub[5].pos));
    SDL_BlitSurface(sub[6].screen, NULL, screen, (sub[6].pos.x = 311, sub[6].pos.y = 461, &sub[6].pos));
    SDL_BlitSurface(sub[7].screen, NULL, screen, (sub[7].pos.x = 311, sub[7].pos.y = 503, &sub[7].pos));
    SDL_BlitSurface(sub[9].screen, NULL, screen, (sub[9].pos.x = 311, sub[9].pos.y = 574, &sub[9].pos));
    SDL_BlitSurface(sub[10].screen, NULL, screen, (sub[10].pos.x = 311, sub[10].pos.y = 616, &sub[10].pos));
    SDL_BlitSurface(sub[11].screen, NULL, screen, (sub[11].pos.x = 311, sub[11].pos.y = 687, &sub[11].pos));
    SDL_BlitSurface(sub[12].screen, NULL, screen, (sub[12].pos.x = 311, sub[12].pos.y = 758, &sub[12].pos));
    SDL_BlitSurface(sub[13].screen, NULL, screen, (sub[13].pos.x = 311, sub[13].pos.y = 800, &sub[13].pos));
    SDL_BlitSurface(sub[14].screen, NULL, screen, (sub[14].pos.x = 1457, sub[14].pos.y =  213, &sub[14].pos));
    SDL_BlitSurface(sub[17].screen, NULL, screen, (sub[17].pos.x = 1365, sub[17].pos.y =  208, &sub[17].pos));
    SDL_BlitSurface(sub[15].screen, NULL, screen, (sub[16].pos.x = 1424, sub[16].pos.y =  503, &sub[16].pos));
    SDL_BlitSurface(sub[16].screen, NULL, screen, (sub[15].pos.x = 1570, sub[15].pos.y =  503, &sub[15].pos));
    SDL_BlitSurface(sub[15].screen, NULL, screen, (sub[16].pos.x = 1424, sub[16].pos.y =  618, &sub[16].pos));
    SDL_BlitSurface(sub[16].screen, NULL, screen, (sub[15].pos.x = 1570, sub[15].pos.y =  618, &sub[15].pos));
    SDL_BlitSurface(sub[15].screen, NULL, screen, (sub[16].pos.x = 1424, sub[16].pos.y =  685, &sub[16].pos));
    SDL_BlitSurface(sub[16].screen, NULL, screen, (sub[15].pos.x = 1570, sub[15].pos.y =  685, &sub[15].pos));
    SDL_BlitSurface(sub[15].screen, NULL, screen, (sub[16].pos.x = 1424, sub[16].pos.y =  800, &sub[16].pos));
    SDL_BlitSurface(sub[16].screen, NULL, screen, (sub[16].pos.x = 1570, sub[16].pos.y =  800, &sub[16].pos));
    SDL_BlitSurface(sub[19].screen, NULL, screen, (sub[19].pos.x = 311, sub[19].pos.y = 206, &sub[19].pos));
    SDL_BlitSurface(sub[29].screen, NULL, screen, (sub[29].pos.x = 1485,sub[29].pos.y =  502, &sub[29].pos));
    SDL_BlitSurface(sub[29].screen, NULL, screen, (sub[29].pos.x = 1485,sub[29].pos.y =  800, &sub[29].pos));
    SDL_BlitSurface(sub[41].screen, NULL, screen, (sub[41].pos.x = 1485,sub[41].pos.y =  615, &sub[41].pos));
    SDL_BlitSurface(sub[41].screen, NULL, screen, (sub[41].pos.x = 1485,sub[41].pos.y =  683, &sub[41].pos));
}
void freeResources(surface sub[]) {
    for(int i = 0; i < 42; i++) SDL_FreeSurface(sub[i].screen);
}