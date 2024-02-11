// by_kayori_Nova_Grp
// 01/24/24
// kayori :: settings.c
                    /* INCLUDE PROTOTYPE DECLARATION PART */
#include "../inc/inc.h"
surface img00;

                    /* FUNCTIONS PROTOTYPE DEV PART */
void settings() {
    initResources();
    SDL_Flip(screen);
    SDL_Event event;
    music = Mix_LoadMUS("pkg//music//PS2_ Red Screen of Death.mp3");
    music1 = Mix_LoadWAV("pkg//music//rac_menu_beep.wav");
    Mix_PlayMusic(music, -1);
    int buttonPos = 0, scrollPos1 = 100, scrollPos2 = 100;
    while (1) {
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_MOUSEMOTION:
                    if(event.motion.x >= 683 && event.motion.x <= 683 + 430 && event.motion.y >= 30 && event.motion.y <= 30 + 130) setImg("pkg//res//settings imgs//img18.png", &img00, 682, 30);
                    else if(event.motion.x >= 80 && event.motion.x <= 80 + 60 && event.motion.y >= 58 && event.motion.y <= 58 + 60) setImg("pkg//res//settings imgs//img20.png", &img00, 80, 58);
                    else {
                        setImg("pkg//res//settings imgs//img01.png", &img00, 682, 30);
                        setImg("pkg//res//settings imgs//img08.png", &img00, 80, 58);
                    } break;
                case SDL_MOUSEBUTTONDOWN:
                    // return to the main menu code...
                    break;
                case SDL_KEYDOWN:
                    switch(buttonPos) {
                        case 0:
                            if(event.key.keysym.sym == SDLK_DOWN) {
                                setImg("pkg//res//settings imgs//img02.png", &img00, 311, 206);
                                setImg("pkg//res//settings imgs//img21.png", &img00, 311, 319);
                                Mix_PlayChannel(-1, music1, 0);
                                buttonPos = 1;
                            }
                            if(event.key.keysym.sym == SDLK_UP) {
                                setImg("pkg//res//settings imgs//img02.png", &img00, 311, 206);
                                setImg("pkg//res//settings imgs//img26.png", &img00, 311, 800);
                                Mix_PlayChannel(-1, music1, 0);
                                buttonPos = 6;
                            }
                            if(event.key.keysym.sym == SDLK_RIGHT) {
                                // rest of code...
                            }
                            if(event.key.keysym.sym == SDLK_LEFT) {
                                // rest of code...
                            } break;
                        case 1:
                            if(event.key.keysym.sym == SDLK_DOWN) {
                                setImg("pkg//res//settings imgs//img04.png", &img00, 311, 319);
                                setImg("pkg//res//settings imgs//img22.png", &img00, 311, 390);
                                Mix_PlayChannel(-1, music1, 0);
                                buttonPos = 2;
                            } else if(event.key.keysym.sym == SDLK_UP) {
                                setImg("pkg//res//settings imgs//img04.png", &img00, 311, 319);
                                setImg("pkg//res//settings imgs//img19.png", &img00, 311, 206);
                                Mix_PlayChannel(-1, music1, 0);
                                buttonPos = 0;
                            }
                            if(event.key.keysym.sym == SDLK_KP_ENTER) {
                                // rest of code...
                            } break;
                        case 2:
                            if(event.key.keysym.sym == SDLK_DOWN) {
                                setImg("pkg//res//settings imgs//img05.png", &img00, 311, 390);
                                setImg("pkg//res//settings imgs//img23.png", &img00, 311, 503);
                                Mix_PlayChannel(-1, music1, 0);
                                buttonPos = 3;
                            } else if(event.key.keysym.sym == SDLK_UP) {
                                setImg("pkg//res//settings imgs//img05.png", &img00, 311, 390);
                                setImg("pkg//res//settings imgs//img21.png", &img00, 311, 319);
                                Mix_PlayChannel(-1, music1, 0);
                                buttonPos = 1;
                            }
                            if(event.key.keysym.sym == SDLK_KP_ENTER) {
                                // rest of code...
                            } break;
                        case 3:                                                                                         // option 3 code
                            if(event.key.keysym.sym == SDLK_DOWN) {
                                setImg("pkg//res//settings imgs//img07.png", &img00, 311, 503);
                                setImg("pkg//res//settings imgs//img24.png", &img00, 311, 616);
                                Mix_PlayChannel(-1, music1, 0);
                                buttonPos = 4;
                            } else if(event.key.keysym.sym == SDLK_UP) {
                                setImg("pkg//res//settings imgs//img07.png", &img00, 311, 503);
                                setImg("pkg//res//settings imgs//img22.png", &img00, 311, 390);
                                Mix_PlayChannel(-1, music1, 0);
                                buttonPos = 2;
                            }
                            if(event.key.keysym.sym == SDLK_RIGHT) {
                                setImg("pkg//res//settings imgs//img28.png", &img00, 1570, 503);
                                
                            } else if(event.key.keysym.sym == SDLK_LEFT) {
                                setImg("pkg//res//settings imgs//img27.png", &img00, 1424, 503);
                            } break;
                        case 4:
                            if(event.key.keysym.sym == SDLK_DOWN) {
                                setImg("pkg//res//settings imgs//img10.png", &img00, 311, 616);
                                setImg("pkg//res//settings imgs//img25.png", &img00, 311, 687);
                                Mix_PlayChannel(-1, music1, 0);
                                buttonPos = 5;
                            } else if(event.key.keysym.sym == SDLK_UP) {
                                setImg("pkg//res//settings imgs//img10.png", &img00, 311, 616);
                                setImg("pkg//res//settings imgs//img23.png", &img00, 311, 503);
                                Mix_PlayChannel(-1, music1, 0);
                                buttonPos = 3;
                            } else if(event.key.keysym.sym == SDLK_RIGHT && scrollPos1 < 100) {
                                setImg("pkg//res//settings imgs//img28.png", &img00, 1570, 618);
                                scrollPos1 += 10; scroll("pkg//res//settings imgs//Numbers//", scrollPos1, 615);
                            } else if(event.key.keysym.sym == SDLK_LEFT && 0 < scrollPos1) {
                                setImg("pkg//res//settings imgs//img27.png", &img00, 1424, 618);
                                scrollPos1 -= 10; scroll("pkg//res//settings imgs//Numbers//", scrollPos1, 615);
                            }
                            break;
                        case 5:
                            if(event.key.keysym.sym == SDLK_DOWN) {
                                setImg("pkg//res//settings imgs//img11.png", &img00, 311, 687);
                                setImg("pkg//res//settings imgs//img26.png", &img00, 311, 800);
                                Mix_PlayChannel(-1, music1, 0);
                                buttonPos = 6;
                            } else if(event.key.keysym.sym == SDLK_UP) {
                                setImg("pkg//res//settings imgs//img11.png", &img00, 311, 687);
                                setImg("pkg//res//settings imgs//img24.png", &img00, 311, 616);
                                Mix_PlayChannel(-1, music1, 0);
                                buttonPos = 4;
                            }
                            if(event.key.keysym.sym == SDLK_RIGHT && scrollPos2 < 100) {
                                setImg("pkg//res//settings imgs//img28.png", &img00, 1570,  687);
                                scrollPos2 += 10; scroll("pkg//res//settings imgs//Numbers//", scrollPos2, 683);
                            } else if(event.key.keysym.sym == SDLK_LEFT && 0 < scrollPos2) {
                                setImg("pkg//res//settings imgs//img27.png", &img00, 1424,  687);
                                scrollPos2 -= 10; scroll("pkg//res//settings imgs//Numbers//", scrollPos2, 683);
                            } break;
                        case 6:
                            if(event.key.keysym.sym == SDLK_DOWN) {
                                setImg("pkg//res//settings imgs//img13.png", &img00, 311, 800);
                                setImg("pkg//res//settings imgs//img19.png", &img00, 311, 206);
                                Mix_PlayChannel(-1, music1, 0);
                                buttonPos = 0;
                            } else if(event.key.keysym.sym == SDLK_UP) {
                                setImg("pkg//res//settings imgs//img13.png", &img00, 311, 800);
                                setImg("pkg//res//settings imgs//img25.png", &img00, 311, 687);
                                Mix_PlayChannel(-1, music1, 0);
                                buttonPos = 5;
                            }
                            if(event.key.keysym.sym == SDLK_RIGHT) {
                                setImg("pkg//res//settings imgs//img28.png", &img00, 1570, 800);
                                // on_off_Animation(0, 1485, 800);
                            }
                            if(event.key.keysym.sym == SDLK_LEFT) {
                                setImg("pkg//res//settings imgs//img27.png", &img00, 1424, 800);
                                // on_off_Animation(1, 1485, 800);
                            }
                            break;
                    } break;
                case SDL_KEYUP:
                    if(buttonPos == 3 && event.key.keysym.sym == SDLK_RIGHT) {
                        setImg("pkg//res//settings imgs//img17.png", &img00, 1570, 503);
                        setImg("pkg//res//settings imgs//img30.png", &img00, 1485, 502);
                    }
                    if(buttonPos == 3 && event.key.keysym.sym == SDLK_LEFT)  {
                        setImg("pkg//res//settings imgs//img16.png", &img00, 1424, 503);
                        setImg("pkg//res//settings imgs//img29.png", &img00, 1485, 502);
                    }
                    if(buttonPos == 4 && event.key.keysym.sym == SDLK_RIGHT) setImg("pkg//res//settings imgs//img17.png", &img00, 1570, 618);
                    if(buttonPos == 4 && event.key.keysym.sym == SDLK_LEFT) setImg("pkg//res//settings imgs//img16.png", &img00, 1424, 618);
                    if(buttonPos == 5 && event.key.keysym.sym == SDLK_RIGHT) setImg("pkg//res//settings imgs//img17.png", &img00, 1570, 687);
                    if(buttonPos == 5 && event.key.keysym.sym == SDLK_LEFT) setImg("pkg//res//settings imgs//img16.png", &img00, 1424,  687);
                    if(buttonPos == 6 && event.key.keysym.sym == SDLK_RIGHT) {
                        setImg("pkg//res//settings imgs//img17.png", &img00, 1570, 800);
                        setImg("pkg//res//settings imgs//img30.png", &img00, 1485, 800);
                    }
                    if(buttonPos == 6 && event.key.keysym.sym == SDLK_LEFT) {
                        setImg("pkg//res//settings imgs//img16.png", &img00, 1424, 800);
                        setImg("pkg//res//settings imgs//img29.png", &img00, 1485, 800);
                    }
                    break;
                case SDL_QUIT:          // with event switch
                    exit(0);
            }
        } SDL_Flip(screen); SDL_Delay(10);
    }
}
void setImg(char* path, surface* win, int x, int y) {
    win->screen = IMG_Load(path);
    if(!win->screen) {
        fprintf(stderr, "%s : %s\n", SDL_ERRMSG07, SDL_GetError()); exit(1);
    } win->pos.x = x, win->pos.y = y;
    SDL_BlitSurface(win->screen, NULL, screen, &win->pos);
}
void initResources() {
    setImg("pkg//res//settings imgs//img00.png", &img00, 0, 0);
    setImg("pkg//res//settings imgs//img03.png", &img00, 311, 277);
    setImg("pkg//res//settings imgs//img04.png", &img00, 311, 319);
    setImg("pkg//res//settings imgs//img05.png", &img00, 311, 390);
    setImg("pkg//res//settings imgs//img06.png", &img00, 311, 461);
    setImg("pkg//res//settings imgs//img07.png", &img00, 311, 503);
    setImg("pkg//res//settings imgs//img09.png", &img00, 311, 574);
    setImg("pkg//res//settings imgs//img10.png", &img00, 311, 616);
    setImg("pkg//res//settings imgs//img11.png", &img00, 311, 687);
    setImg("pkg//res//settings imgs//img12.png", &img00, 311, 758);
    setImg("pkg//res//settings imgs//img13.png", &img00, 311, 800);
    setImg("pkg//res//settings imgs//img14.png", &img00, 1457, 213);
    setImg("pkg//res//settings imgs//img15.png", &img00, 1365, 208);
    setImg("pkg//res//settings imgs//img16.png", &img00, 1424, 503);
    setImg("pkg//res//settings imgs//img17.png", &img00, 1570, 503);
    setImg("pkg//res//settings imgs//img16.png", &img00, 1424, 618);
    setImg("pkg//res//settings imgs//img17.png", &img00, 1570, 618);
    setImg("pkg//res//settings imgs//img16.png", &img00, 1424, 685);
    setImg("pkg//res//settings imgs//img17.png", &img00, 1570, 685);
    setImg("pkg//res//settings imgs//img16.png", &img00, 1424, 800);
    setImg("pkg//res//settings imgs//img17.png", &img00, 1570, 800);
    setImg("pkg//res//settings imgs//img19.png", &img00, 311, 206);
    setImg("pkg//res//settings imgs//img29.png", &img00, 1485, 502);
    setImg("pkg//res//settings imgs//img29.png", &img00, 1485, 800);
    setImg("pkg//res//settings imgs//Numbers//100.png", &img00, 1485, 615);
    setImg("pkg//res//settings imgs//Numbers//100.png", &img00, 1485, 683);
}

/*
void on_off_Animation(int z, float x, float y) {
    switch(z) {
        case 0:
            setImg("pkg//res//settings imgs//img32.png", &img00, x, y);
            break;
        case 1:
            setImg("pkg//res//settings imgs//img31.png", &img00, x, y);
            break;
    }
}
*/
void scroll(char* path, int pos, int y) {
    char tempPath[260] = ""; char str_scrollPos1[4];
    sprintf(str_scrollPos1, "%d", pos);
    strcat(tempPath, path);
    strcat(tempPath, str_scrollPos1); strcat(tempPath, ".png");
    setImg(tempPath, &img00, 1485, y); tempPath[0] = '\0';
}