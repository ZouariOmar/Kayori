// by_kayori_Nova_Grp
// 01/24/24
// kayori :: settings.c
                    /* INCLUDE PROTOTYPE DECLARATION PART */
#include "../inc/inc.h"
                    /* FUNCTIONS PROTOTYPE DEV PART */
void settings(SDL_Surface* screen) {
    surface img00;
    img00.screen = IMG_Load("pkg//res//test.jpg");
    img00.pos.x = 0; img00.pos.y = 0;
    SDL_BlitSurface(img00.screen, NULL, screen, &img00.pos);
    SDL_Flip(screen);
    SDL_Event event;
    while(1) {
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    exit(0);
                case SDL_KEYDOWN:
                    // rest of code...
                    break;
                case SDL_KEYUP:
                    // rest of code...
                default:
                    // fprintf(stderr, "Key Not Define ! : %s\n", SDL_GetError());        :: for testing part
                    break;
            }
        }
    }
}