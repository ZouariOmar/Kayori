/* -----------------------------------------------
* @author: by_kayori_Nova_Grp
* @date:   03/18/2024
? @file:   __ttt_game__.h
----------------------------------------------- */

#ifndef __TTT_GAME_H__
#define __TTT_GAME_H__

//? ----------------------- STRUCT PROTOTYPE DECLARATION PART ------------------------

//? ----------------------- FUNCTIONS PROTOTYPE DECLARATION PART -----------------------
/*
? __ttt_game__() void fn
* main_tic_tac_toe_func_launcher
*/
void __ttt_game__();

/*
? initResources(surface *sub) void fn
* blit the first viewed interface of thr program
*/
void initResources(surface *);

/*
? have_coordinate(Sint16 *x, Sint16 *y, int pos) void fn
* change the (x, y) values depending on the curent usr_pos
*/
void have_coordinate(Sint16 *, Sint16 *, int);

/*
? - is_free() int fn -
* available pos    :: return "the index of the available pos (0..8)"
* no available pos :: return "-1"
*/
int is_free(int *);

/*
? check_ttt(surface* sub, int *tab, int value, int *ttttp) void fn
* check if there is a winner or there is toe
> __ttt_game__()
*/
void check_ttt(surface *, int *, int, int *);

/*
? check_rcd(surface* sub, int *tab, int value) void fn
* collect {check_rows, check_columns, check_diagonals} in check_rcd fn
> check_ttt()
*/
int check_rcd(surface *, int *, int);

/*
? check_rows(surface* sub, int *tab, int value) void fn
* check the 3 rows of ttt game
> check_rcd()
*/
int check_rows(surface *, int *, int);

/*
? check_columns(surface* sub, int *tab, int value) void fn
* check the 3 columns of ttt game
> check_rcd()
*/
int check_columns(surface*, int*, int);

/*
? check_diagonals(surface* sub, int *tab, int value) void fn
* check the 2 diagonals of ttt game
> check_rcd()
*/
int check_diagonals(surface*, int*, int);

#endif