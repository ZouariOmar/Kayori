/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @author: zouari_omar
* @update: 04/21/24
? @file:   speedRun.c
----------------------------------------------- */

//? ----------------------- TODO SECTION DECLARATION PART -----------------------
/*
TODO_01: fix the timer
    * make the HH, MM, SS, MS in the timer struct
    * fix the divergent time between all @time_info
*/

//? -------------------- INCLUDE PROTOTYPE DECLARATION PART --------------------
#include "../inc/inc.h"

//? ----------------------- FUNCTIONS PROTOTYPE DEV PART -----------------------
void startStopwatch(int *pause, int *elapsed_ss, surface remover) {
    int stop = scanValue("project/doc/settings", 22);
    if (stop) {
        if (!*pause) {
            //* init the @start_time and @current_time vars
            struct timeval current_time;
            gettimeofday(&current_time, NULL);
            if (time(NULL))
                displayTime(remover, ++(*elapsed_ss));
        }
    }
}

void displayTime(surface remover, long elapsed_ss) {
    //* init the Code 7x5.ttf font
    TTF_Font * font = TTF_OpenFont("project/res/font/Code 7x5.ttf", 20);
    
    //* init the elapsed_ss surface
    surface txt;

    char stopwatch[260];

    //* split the elapsed_ss long var to timer info
    //! can put it in timer struct in the next update
    int HH = (elapsed_ss / 36000) % 60;
    int MM = (elapsed_ss / 3600)  % 60;
    int SS = (elapsed_ss / 60)    % 60;
    int MS = (elapsed_ss % 100);

    //* convert the time info to a string var (stopwatch)
    sprintf(stopwatch, "%02d:%02d:%02d:%02d", HH, MM, SS, MS);
    txt.win = TTF_RenderText_Blended(font, stopwatch, WHITE);

    //* stopwatch pos
    txt.pos.x = 100; txt.pos.y = 100;
    txt.pos.w = 200; txt.pos.h = 100;

    //* del the old stopwatch time
    SDL_BlitSurface(remover.win, &txt.pos, screen, &txt.pos);

    //* blit the stopwatch
    SDL_BlitSurface(txt.win, NULL, screen, &txt.pos);

    //* close the @code_font
    TTF_CloseFont(font);

    //* close the txt surface
    SDL_FreeSurface(txt.win);

    SDL_Flip(screen);
}