/* -----------------------------------------------
* @author: by_kayori_Nova_Grp
* @date:   03/18/2024
? @file:   __ttt_game__.c
----------------------------------------------- */

#ifndef __TTT_GAME_H__
#define __TTT_GAME_H__

                    /* STRUCT PROTOTYPE DECLARATION PART */

                    /* FUNCTIONS PROTOTYPE DECLARATION PART */
// ? __ttt_game__() void func :: main_tic_tac_toe_func_launcher
void __ttt_game__();

void initResources(surface*);
void have_coordinate(Sint16*, Sint16*, int);

int is_free(int*);

// ? check_ttt() void func      > __ttt_game__()
void check_ttt(surface*, int*, int, int*);

// ? check_rcd() int func       > check_ttt()
int check_rcd(surface*, int*, int);

// ? check_rows() int func      > check_rcd()
int check_rows(surface*, int*, int);

// ? check_columns() int func   > check_rcd()
int check_columns(surface*, int*, int);

// ? check_diagonals() int func > check_rcd()
int check_diagonals(surface*, int*, int);

#endif