/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @author: zouari_omar
* @update: 04/21/24
? @file:   speedRun.h
----------------------------------------------- */

#ifndef __SPRUN_H__
#define __SPRUN_H__

//? -------------------- INCLUDE PROTOTYPE DECLARATION PART --------------------

//? --------------------- STRUCT PROTOTYPE DECLARATION PART ----------------------
typedef struct Timer {
    int HH,
        MM,
        SS,
        MS;
} timer;

//? -------------------- FUNCTIONS PROTOTYPE DECLARATION PART --------------------

/*
? -- stopwatch(int *pause, int* elapsed_ss, surface remover) void fun --
* @stopwatch_format: HH:MM:SS:MS
* pause: 1/0 :: pause the @stopwatch func and save the @current_stopwatch_time in tell the usr "resume the game (pause/resume option)"
! need to set @startStopwatch fn in while() loop :: the while() loop work as @startStopwatch_stop_flag
*/
void startStopwatch(int *, int *, surface);

/*
? -- void displayTime(surface remover, long elapsed_ss) void fun --
* this fn display the current time using @stopwatch_format
*/
void displayTime(surface, long);

#endif
