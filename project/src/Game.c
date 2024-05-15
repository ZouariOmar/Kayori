// by_kayori_Nova_Grp
// 01/24/24
// kayori :: main.c
                    /* INCLUDE PROTOTYPE DECLARATION PART */

                    /* MAIN() INT FUNCTION DEV PART */

#ifndef GAME
#define GAME

#include "lib.c"

///////////////////////////////////

void SoloPlayer(void) {
    
	initEverything();
    closeEverything();

    SM P1;
    SM P2;
    BGC BG_Camera;
    MAP Mini_Map;

    // Initialisation of the main variables

    Col* C_Tab;

    int Lvl = 3;
    int Quit = 0;
    int N_Collision = 0;

    // Initialisation of the game
    InitGameSP(Lvl, &P1, &P2, &BG_Camera, &Mini_Map, &C_Tab, &N_Collision, &Quit);

    // Game loop

    while(!Quit)
    {
        // Solo mode

        // Update the position of the player
        Mechanics(Lvl, &P1, &Quit, C_Tab, N_Collision);

        // Update the screen
        UpdateScreenSP(&P1, &Mini_Map, &BG_Camera, &Quit);
    
        // Level transition
        if(P1.Lvl_Trans)
            LvlTransition(&Lvl, &P1, &P2, &BG_Camera, &Mini_Map, &C_Tab, &N_Collision, &Quit);
    }

    // Free memory
    FreeGameSP(Lvl, C_Tab, &BG_Camera, &Mini_Map);
}

///////////////////////////////////

void Multiplayer(void) {
    
    initEverything();
    closeEverything();

    SM P1;
    SM P2;
    BGC BG_Camera;
    MAP Mini_Map;

    // Initialisation of the main variables

    Col* C_Tab;

    int Lvl = 1;
    int N_Collision = 0, Quit = 0;

    // Initialisation of the game
    InitGameMP(Lvl, &P1, &P2, &BG_Camera, &Mini_Map, &C_Tab, &N_Collision, &Quit);

    // Game loop

    while(!Quit)
    {
        // Multiplayer

        // Update the position of the players
        MechanicsMulti(Lvl, &P1, &P2, &Quit, C_Tab, N_Collision);

        // Update the screen
        UpdateScreenMP(&P1, &P2, &Mini_Map, &BG_Camera, &Quit);

        // Level transition
        if(P1.Lvl_Trans && P2.Lvl_Trans)
            LvlTransition(&Lvl, &P1, &P2, &BG_Camera, &Mini_Map, &C_Tab, &N_Collision, &Quit);
    }

    // Free memory
    FreeGameMP(Lvl, C_Tab, &BG_Camera, &Mini_Map);
}

///////////////////////////////////

#endif