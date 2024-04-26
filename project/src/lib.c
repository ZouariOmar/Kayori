/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @update: 04/06/24
? @file:   lib.c
----------------------------------------------- */

//? -------------------- INCLUDE PROTOTYPE DECLARATION PART --------------------
#include "../inc/inc.h"
////#include "Main_Menu.c"

//! testing part
#include "settings.c"

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
    setScreen(scanValue("project/doc/settings", 18));

    //* upload the music and chunk volume
    ////Mix_VolumeMusic(scanValue(2));
    ////Mix_VolumeChunk(pop, scanValue(3));

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
    if(loadedImg) {
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

void freeResources(surface *sub, TTF_Font *font, int nb_res) {
    for(int i = 0; i < nb_res; i++) SDL_FreeSurface(sub[i].win);
    TTF_CloseFont(font);
}