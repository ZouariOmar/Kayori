/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @author: @ZouariOmar @Fraddosse1
* @IDE:    @vsc @sublime
* @update: 04/27/24
? @file:   start_menu.h
----------------------------------------------- */
#include "settings.h"

#ifndef __START_MENU__H
#define __START_MENU__H

//? --------------------- STRUCT PROTOTYPE DECLARATION PART ----------------------
//? load_lvl struct (size = 16bit)
typedef struct load_lvl {
	int current_lvl,
		estimated_time_ms,
		death_time,
		collected_items;
} load_info;

//? -------------------- FUNCTIONS PROTOTYPE DECLARATION PART --------------------


void sm_initResources(surface *, load_info, int, int);

void scanLvlInfo(char *, load_info *);

void sm_scroll_UD(surface *, load_info *, int *, int, Mix_Chunk *);

#endif