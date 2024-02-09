// by_kayori_Nova_Grp
// 01/24/24
// kayori :: settings.c
                    /* INCLUDE PROTOTYPE DECLARATION PART */
#include "../inc/inc.h"
                    /* FUNCTIONS PROTOTYPE DEV PART */
surface img00, img01, img02;
void settings(SDL_Surface* screen) {
    initResources();
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
                    break;
                case SDL_MOUSEMOTION:
                    if(event.motion.x >= 683 && event.motion.x <= 683 + 430 && event.motion.y >= 30 && event.motion.y <= 30 + 130) {
                        // setImg("pkg//res//settings imgs//img18.png", &img01, 682, 30);
                    } else {
                        setImg("pkg//res//settings imgs//img01.png", &img01, 682, 30);
                    }
                    // rest of code...
                    break;
                default:
                    //fprintf(stderr, "Key Not Define ! : %s\n", SDL_GetError());       //  :: for testing part
                    break;
            }
        }
    SDL_Flip(screen);
    SDL_Delay(10);
    }
    freeResources();
}

void initResources() {
    //setImg("pkg//res//settings imgs//img00.png", &img00, 0, 0);
    // setImg("pkg//res//settings imgs//img01.png", &img01, 682, 30);
    //setImg("pkg//res//settings imgs//img02.png", &img02, 311, 206);
    setImg("pkg//res//settings imgs//img03.png", &img02, 311, 277);
    setImg("pkg//res//settings imgs//img04.png", &img02, 311, 319);
    setImg("pkg//res//settings imgs//img05.png", &img02, 311, 390);
    setImg("pkg//res//settings imgs//img06.png", &img02, 311, 461);
    setImg("pkg//res//settings imgs//img07.png", &img02, 311, 503);
    setImg("pkg//res//settings imgs//img08.png", &img02, 74, 77);
    setImg("pkg//res//settings imgs//img09.png", &img02, 311, 574);
    setImg("pkg//res//settings imgs//img10.png", &img02, 311, 616);
    setImg("pkg//res//settings imgs//img11.png", &img02, 311, 687);
    setImg("pkg//res//settings imgs//img12.png", &img02, 311, 758);
    setImg("pkg//res//settings imgs//img13.png", &img02, 311, 800);
    setImg("pkg//res//settings imgs//img14.png", &img02, 1457, 213);
    setImg("pkg//res//settings imgs//img15.png", &img02, 1365, 208);
    setImg("pkg//res//settings imgs//img16.png", &img02, 1437, 503);
    setImg("pkg//res//settings imgs//img17.png", &img02, 1549, 503);
    setImg("pkg//res//settings imgs//img16.png", &img02, 1437, 618);
    setImg("pkg//res//settings imgs//img17.png", &img02, 1549, 618);
    setImg("pkg//res//settings imgs//img16.png", &img02, 1437, 685);
    setImg("pkg//res//settings imgs//img17.png", &img02, 1549, 685);
    setImg("pkg//res//settings imgs//img16.png", &img02, 1437, 800);
    setImg("pkg//res//settings imgs//img17.png", &img02, 1549, 800);
}
void setImg(char *path, surface* win, int x, int y) {
    win->screen = IMG_Load(path);
    if(!win->screen) {
        fprintf(stderr, "%s : %s\n", SDL_ERRMSG07, SDL_GetError()); exit(1);
    } win->pos.x = x, win->pos.y = y;
    SDL_BlitSurface(win->screen, NULL, screen, &win->pos);
}

void freeResources() {
    SDL_FreeSurface(img00.screen);
    SDL_FreeSurface(img01.screen);
    SDL_FreeSurface(img02.screen);
    /*
    SDL_FreeSurface(img03.screen);
    SDL_FreeSurface(img04.screen);
    SDL_FreeSurface(img05.screen);
    SDL_FreeSurface(img06.screen);
    SDL_FreeSurface(img07.screen);
    SDL_FreeSurface(img08.screen);
    SDL_FreeSurface(img09.screen);
    SDL_FreeSurface(img10.screen);
    SDL_FreeSurface(img11.screen);
    SDL_FreeSurface(img12.screen);
    SDL_FreeSurface(img13.screen);
    SDL_FreeSurface(img14.screen);
    SDL_FreeSurface(img15.screen);
    SDL_FreeSurface(img16.screen);
    SDL_FreeSurface(img17.screen);
    */
}