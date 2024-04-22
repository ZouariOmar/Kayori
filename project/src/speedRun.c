/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @author: zouari_omar
* @update: 04/21/24
? @file:   speedRun.c
----------------------------------------------- */


//? -------------------- INCLUDE PROTOTYPE DECLARATION PART --------------------
#include "../inc/inc.h"

//? ----------------------- FUNCTIONS PROTOTYPE DEV PART -----------------------
/*
? stopwatch() void fun
* @stopwatch_format: HH:MM:SS:MS
! spRun() fun need 2 flag
    * stop :  1/0 :: stop the @stopwatch fun and reset it in 00:00:00:000
    * pause: -1/0 :: pause the  @stopwatch fun and save the @current_stopwatch_time in tell the usr "resume the game (pause/resume option)"
*/

void startStopwatch(int* pause) {

    struct timeval start_time, current_time;
    gettimeofday(&start_time, NULL);

    int stop = scanValue(22);
    while (stop) {
        if (!*pause) {
            gettimeofday(&current_time, NULL);
            long elapsed_ms = (current_time.tv_sec - start_time.tv_sec) * 1000L +
                              (current_time.tv_usec - start_time.tv_usec) / 1000L;

            displayTime(elapsed_ms);
        }

        //* sleep for a short period to avoid high CPU usage (10 milliseconds)
        usleep(10000);
    }
}

void displayTime(long elapsed_ms) {
    TTF_Font * font = TTF_OpenFont("project/res/font/Code 7x5.ttf", 20);
    surface txt;
    char stopwatch[21];
    int HH = (elapsed_ms / 3600000);
    int MM = (elapsed_ms % 3600000) / 60000;
    int SS = (elapsed_ms % 60000)   / 1000;
    int MS = (elapsed_ms % 1000);
    sprintf(stopwatch, "%02d:%02d:%02d:%03d", HH, MM, SS, MS);
    txt.win = TTF_RenderText_Blended(font, stopwatch, BLACK);

    //* blit the stopwatch
    //! testing part
    txt.pos.x = 100;
    txt.pos.y = 100;
    SDL_BlitSurface(txt.win, NULL, screen, &txt.pos);

    //* close the @code_font
    TTF_CloseFont(font);
}