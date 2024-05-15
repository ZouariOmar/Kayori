/* -----------------------------------------------
* @author: by_kayori_Nova_Grp
* @author: zouari_omar
* @date:   03/18/2024
? @file:   tic_tac_toe.h
----------------------------------------------- */

#ifndef __TIC_TAC_TOE_H__
#define __TIC_TAC_TOE_H__

//? ----------------------- STRUCT PROTOTYPE DECLARATION PART ------------------------

//? ----------------------- FUNCTIONS PROTOTYPE DECLARATION PART -----------------------
/*
? __ttt_game__() void fn
* main_tic_tac_toe_func_launcher
*/
void __ttt_game__();

/*
? scroll_UD() void fn
* scroll up and down the contour usr_current_position indicator
> __ttt_game__()
*/
void ttt_scroll_UD(surface *, int *, int *, int);

/*
? initResources(surface *sub) void fn
* blit the first viewed interface of thr program
*/
void ttt_initResources(surface *);

/*
? have_coordinate(Sint16 *x, Sint16 *y, int pos) void fn
* change the (x, y) values depending on the curent usr_pos
* the "initial_usr_pos = 0" ==> (662, 282)
! we can define x and y as "int*"
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