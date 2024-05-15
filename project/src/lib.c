/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @author: @ZouariOmar
* @IDE:    @vsc
* @update: 05/15/24
? @file:   lib.c
----------------------------------------------- */

//? ----------------------- NOTE SECTION DECLARATION PART -----------------------
/*
* NONE...
*/
#ifndef LIB
#define LIB
//? -------------------- INCLUDE PROTOTYPE DECLARATION PART --------------------
#include "../inc/inc.h"
#include "Mechanics.c"
#include "MiniMap.c"
#include "Background.c"
#include "Main_Menu.c"

//? ----------------------- FUNCTIONS PROTOTYPE DEV PART -----------------------
void initEverything() {
    //* SDL initialisation process
    if(SDL_Init(SDL_INIT_EVERYTHING)) {
        fprintf(stderr, "%s: %s",SDL_ERRMSG00, SDL_GetError()); exit(1);
    }

    //* TTF initialisation process
    TTF_Init();

    //* Mix initialisation process
    if((Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024))) {
        fprintf(stderr, "%s: %s",SDL_ERRMSG04, SDL_GetError()); exit(1);
    }

    //* IMG initialisation process
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

    //* upload the screen mode
    setScreen(scanValue("project/doc/settings", 22));

    //* set the game caption
    SDL_WM_SetCaption("Hollow Vessels", NULL);
}

void closeEverything() {
	atexit(Mix_Quit);
	atexit(IMG_Quit);
	atexit(TTF_Quit);
	atexit(SDL_Quit);
}

SDL_Surface *load_img(char* path) {
    SDL_Surface *loadedImg = IMG_Load(path),
                *optimizedImg = NULL;
    if (loadedImg) {
        optimizedImg = SDL_DisplayFormatAlpha(loadedImg);
        SDL_FreeSurface(loadedImg);
    }
    return optimizedImg;
}

void setScreen(int x) {
    const SDL_VideoInfo* Video_Info = SDL_GetVideoInfo();
    if(Video_Info)
        screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF | x);
    else
        screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF | x);
    if(!screen) {
        fprintf(stderr, "%s: %s !", SDL_ERRMSG07, SDL_GetError()); exit(1);
    }
}

void loadGameResources(SDL_Surface* sub[], char* path, int begin_res, int nbr_res) {
    while (begin_res <= nbr_res) {
        char tmp_path[260];
        sprintf(tmp_path, "%s%d%s", path, begin_res, ".png");
        sub[begin_res-1] = load_img(tmp_path);
        begin_res++;
    }
}
// ================== Single player ================== //

///////////////////////////////////

void InitSave(int Lvl, SM* P1, SM* P2, BGC* BG_Camera, MAP* Mini_Map, Col** C_Tab, int* N_Collision, int* Quit)
{
    switch(Lvl)
    {
        case 1:
            // ================= PLAYER =================

            // ----- P1 -----

            // Default position
            P1->Default_X = 963;
            P1->Default_Y = 2981;

            // Players actual position
            P1->A_Pos.x=P1->Default_X;
            P1->A_Pos.y=P1->Default_Y;

            // Players last position
            P1->L_Pos.x=P1->Default_X;
            P1->L_Pos.y=P1->Default_Y;

            // ----- P2 -----

            // Default position
            P2->Default_X = 963;
            P2->Default_Y = 2981;

            // Players actual position
            P2->A_Pos.x=P2->Default_X;
            P2->A_Pos.y=P2->Default_Y;

            // Players last position
            P2->L_Pos.x=P2->Default_X;
            P2->L_Pos.y=P1->Default_Y;

            // ================= BACKGROUND =================

            // Initialisation background size
            BG_Camera->WBG = 7781;
            BG_Camera->HBG = 3263;

            // Initialisation background image
            BG_Camera->Normal_bg = load_img("pkg//Testlevel//Tuto.png");
            BG_Camera->Dynamic_bg = load_img("pkg//Testlevel//Tuto.png");
            BG_Camera->Dynamic_2 = BG_Camera->Dynamic_bg;
            BG_Camera->Dynamic_3 = BG_Camera->Dynamic_bg;

            // ================= MINI MAP =================

            // Init mini map image
            Mini_Map->Normal_MM = load_img("pkg//Testlevel//Mini map tuto.png");
            Mini_Map->Dynamic_MM = load_img("pkg//Testlevel//Mini map tuto.png");
            
            // Init mini map position
            Mini_Map->Rect_IP.x = 0;
            Mini_Map->Rect_IP.y = 0;

            // ================= COLLISIONS =================

            InitCollisions(C_Tab, N_Collision, 1, Quit);

            break;

        case 2:
            // ================= PLAYER =================

            // ----- P1 -----

            // Default position
            P1->Default_X = 1032;
            P1->Default_Y = 1699;

            // Players actual position
            P1->A_Pos.x=P1->Default_X;
            P1->A_Pos.y=P1->Default_Y;

            // Players last position
            P1->L_Pos.x=P1->Default_X;
            P1->L_Pos.y=P1->Default_Y;

            // ----- P2 -----

            // Default position
            P2->Default_X = 1032;
            P2->Default_Y = 1699;

            // Players actual position
            P2->A_Pos.x=P2->Default_X;
            P2->A_Pos.y=P2->Default_Y;

            // Players last position
            P2->L_Pos.x=P2->Default_X;
            P2->L_Pos.y=P2->Default_Y;

            // ================= BACKGROUND =================

            // Initialisation background size
            BG_Camera->WBG = 7205;
            BG_Camera->HBG = 3787;

            // Initialisation background image
            BG_Camera->Normal_bg = load_img("pkg//Testlevel//LEVEL1.png");
            BG_Camera->Dynamic_bg = load_img("pkg//Testlevel//LEVEL1.png");
            BG_Camera->Dynamic_2 = BG_Camera->Dynamic_bg;
            BG_Camera->Dynamic_3 = BG_Camera->Dynamic_bg;

            // ================= MINI MAP =================

            // Init mini map image
            Mini_Map->Normal_MM = load_img("pkg//Testlevel//Mini map level1.png");
            Mini_Map->Dynamic_MM = load_img("pkg//Testlevel//Mini map level1.png");
            
            // Init mini map position
            Mini_Map->Rect_IP.x = 1067;
            Mini_Map->Rect_IP.y = 616;

            // ================= COLLISIONS =================

            InitCollisions(C_Tab, N_Collision, 2, Quit);
            break;

        case 3:
            // ================= PLAYER =================

            // ----- P1 -----

            // Default position
            P1->Default_X = 199;
            P1->Default_Y = 2582;

            // Players actual position
            P1->A_Pos.x=P1->Default_X;
            P1->A_Pos.y=P1->Default_Y;

            // Players last position
            P1->L_Pos.x=P1->Default_X;
            P1->L_Pos.y=P1->Default_Y;

            // ----- P2 -----

            // Default position
            P2->Default_X = 199;
            P2->Default_Y = 2582;

            // Players actual position
            P2->A_Pos.x=P2->Default_X;
            P2->A_Pos.y=P2->Default_Y;

            // Players last position
            P2->L_Pos.x=P2->Default_X;
            P2->L_Pos.y=P2->Default_Y;

            // ================= BACKGROUND =================

            // Initialisation background size
            BG_Camera->WBG = 13467;
            BG_Camera->HBG = 5191;

            // Initialisation background image
            BG_Camera->Normal_bg   = load_img("pkg//Testlevel//Level 2 no shoot.png");
            BG_Camera->Dynamic_bg  = load_img("pkg//Testlevel//Level 2 no shoot.png");
            BG_Camera->Dynamic_2 = load_img("pkg//Testlevel//Level 2 shoot1.png");
            BG_Camera->Dynamic_3 = load_img("pkg//Testlevel//Level 2 shoot2.png");

            // ================= MINI MAP =================

            // Init mini map image
            Mini_Map->Normal_MM = load_img("pkg//Testlevel//Mini map level2.png");
            Mini_Map->Dynamic_MM = load_img("pkg//Testlevel//Mini map level2.png"); 
            
            // Init mini map position
            Mini_Map->Rect_IP.x = 1646;
            Mini_Map->Rect_IP.y = 789;

            // ================= COLLISIONS =================

            InitCollisions(C_Tab, N_Collision, 3, Quit);
            break;

        default:
            break;
    }
}

///////////////////////////////////

void LvlTransition(int* Lvl, SM* P1, SM* P2, BGC* BG_Camera, MAP* Mini_Map, Col** C_Tab, int* N_Collision, int* Quit)
{
    (*Lvl)++;

    if(*Lvl < 4)
    {
        SDL_FreeSurface(BG_Camera->Normal_bg);
        SDL_FreeSurface(BG_Camera->Dynamic_bg);
        
        if(*Lvl == 4)
        {
            SDL_FreeSurface(BG_Camera->Dynamic_2);
            SDL_FreeSurface(BG_Camera->Dynamic_3);
        }
        
        SDL_FreeSurface(Mini_Map->Normal_MM);
        SDL_FreeSurface(Mini_Map->Dynamic_MM);
        FreeCollisions(*C_Tab);

        InitSave(*Lvl, P1, P2, BG_Camera, Mini_Map, C_Tab, N_Collision, Quit);
    }

    P1->Lvl_Trans = 0;
    P2->Lvl_Trans = 0;
}

///////////////////////////////////

void InitGameSP(int Lvl, SM* P1, SM* P2, BGC* BG_Camera, MAP* Mini_Map, Col** C_Tab, int* N_Collision, int* Quit)
{
    // Initialiser save

    InitSave(Lvl, P1, P2, BG_Camera, Mini_Map, C_Tab, N_Collision, Quit);

    // Initialisation of the player

    InitPlayer(P1, P2);

    // Initialiser background camera

    InitBackgroundSP(BG_Camera, Quit);

    // Initialiser Mini Map

    InitMiniMapSP(Mini_Map, Quit);
}

///////////////////////////////////

void UpdateScreenSP(SM* P, MAP* Mini_Map, BGC* BG_Camera, int* Quit_Game)
{
    // Enter in the background update function
    UpdateBackgroundSP(BG_Camera, P, Quit_Game);

    if(!(P->Lvl_Trans))
    {
        // Mini Map
        UpdateMMSolo(Mini_Map, BG_Camera, P);
    }

    // Refresh the screen
    SDL_Flip(screen);
    SDL_Delay(7);
}

///////////////////////////////////

// ================== Multiplayer ================== //

///////////////////////////////////

void InitGameMP(int Lvl, SM* P1, SM* P2, BGC* BG_Camera, MAP* Mini_Map, Col** C_Tab, int* N_Collision, int* Quit)
{
    // Initialiser save

    InitSave(Lvl, P1, P2, BG_Camera, Mini_Map, C_Tab, N_Collision, Quit);

    // Initialisation of the player

    InitPlayer(P1, P2);

    // Initialiser background camera

    InitBackgroundMP(BG_Camera, Quit);

    // Initialiser Mini Map
 
    InitMiniMapMP(Mini_Map, Quit);
}

///////////////////////////////////

void UpdateScreenMP(SM* P1, SM* P2, MAP* Mini_Map, BGC* BG_Camera, int* Quit_Game)
{
    // Enter in the background update function
    UpdateBackgroundMP(BG_Camera, P1, P2, Quit_Game);

    if(!(P1->Lvl_Trans && P2->Lvl_Trans))
    {
        // Mini Map
        UpdateMMMulti(Mini_Map, BG_Camera, P1, P2);
    }

    // Refresh the screen
    SDL_Flip(screen);
    SDL_Delay(7);
}

// =============================================== //

///////////////////////////////////

void FreeGameSP(int Lvl, Col* Tab, BGC* BG_Camera, MAP* Mini_Map)
{
    FreeCollisions(Tab);
    FreeBackgroundSP(Lvl, BG_Camera);
    FreeMM(Mini_Map);
    SDL_FreeSurface(screen);
}

///////////////////////////////////

void FreeGameMP(int Lvl, Col* Tab, BGC* BG_Camera, MAP* Mini_Map)
{
    FreeCollisions(Tab);
    FreeBackgroundMP(Lvl, BG_Camera);
    FreeMM(Mini_Map);
    SDL_FreeSurface(screen);
}

///////////////////////////////////

//? ------------------ SCANNING && EDITING FILES FUNCTIONS DEV PART ------------------
int scanValue(char *path, int line) {
    //* open the settings file
    FILE* file = fopen(path, "r");
    if (!file) {
        perror("Error: can't open settings file !"); exit(EXIT_FAILURE);
    }

    /*
    ? holder     :: to detect the newLine char ('\n')
    ? consumer   :: to store the unused info
    ? ln         :: to detect the file line number
    ? value      :: to store the needed info (0 or 1 or SDL_code_number)
    */
    char holder,
        consumer[100];
    int value,
        ln = 0;

    while ((holder = fgetc(file)) != EOF) {
        if (ln == line) {
            fscanf(file, "%s%d", consumer, &value);
            break;
        }
        if (holder == '\n') ln++;
    }

    //* close the settings file
    fclose(file);

    return value;
}

void scanStr(char *path, char *info, int line) {
    //* open the file
    FILE* file = fopen(path, "r");
    if (!file) {
        perror("Error: can't open settings file !"); exit(EXIT_FAILURE);
    }

    /*
    ? holder     :: to detect the newLine char ('\n')
    ? info       :: to store the info
    ? ln         :: to detect the file line number
    */
    char holder;
    int ln = 1;

    while ((holder = fgetc(file)) != EOF) {
        if (holder == '\n') ln++;
        if (ln == line) {
            fscanf(file, "%s", info);
            break;
        }
    }

    //* close the settings file
    fclose(file);
}

void editValue(char *format, char *option, int value, int line) {
    //* open the settings file
    FILE* file = fopen("project/doc/settings", "r+");
    if (!file) {
        perror("Error: can't open settings file !");
        exit(EXIT_FAILURE);
    }

    //* creat a tmp file
    FILE* tmp_file = fopen("project/doc/tmp", "w+");
    if (!tmp_file) {
        perror("Error: can't open the file !");
        exit(EXIT_FAILURE);
    }

    /*
    ? holder     :: to detect the newLine char ('\n')
    ? ln         :: to detect the file line number
    */
    char holder;
    int ln = 0;

    //* process each character in the settings file
    while ((holder = fgetc(file)) != EOF) {
        if (ln == line) {
            //* add the update info line
            fprintf(tmp_file, format, option, value);
            ln++;

            //* skip the rest of the original value line
            while ((holder = fgetc(file)) != EOF && holder != '\n');
        } else {
            //* add the other info
            fputc(holder, tmp_file);
            if (holder == '\n') ln++;
        }
    }

    //* close both files
    fclose(file);
    fclose(tmp_file);

    //* replace the original file with the tmp file
    remove("project/doc/settings");
    rename("project/doc/tmp", "project/doc/settings");
}

//? ----------------------- LOAD && FREEING FUNCTIONS DEV PART -----------------------
void set_pos(surface *sub, char *path, int nb_res) {
    //* open the settings file
    FILE *file = fopen(path, "r");
    if (!file) {
        perror("Error: can't open settings_ref file !"); exit(EXIT_FAILURE);
    }

    //* fill all surface positions
    int i = 0;
    while (i < nb_res && fscanf(file, "%hd%hd", &(sub[i].pos.x), &(sub[i].pos.y)) == 2)
        i++;

    //* close the settings file
    fclose(file);
}

void loadResources(surface *sub, char *path, int begin_res, int nbr_res) {
    while (begin_res < nbr_res) {
        char tmp_path[260];
        sprintf(tmp_path, "%s%d%s", path, begin_res, ".png");
        sub[begin_res].win = load_img(tmp_path);
        begin_res++;
    }
}

void freeResources(surface *sub, TTF_Font *font, Mix_Chunk *pip, int nb_res) {
    for(int i = 0; i < nb_res; i++) SDL_FreeSurface(sub[i].win);
    TTF_CloseFont(font);
    Mix_FreeChunk(pip);
}

#endif