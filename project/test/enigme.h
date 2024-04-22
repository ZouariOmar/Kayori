#ifndef ENIGME_H
#define ENIGME_H

typedef struct{
    SDL_Rect position;
    TTF_Font *font;
    SDL_Surface *Stexte;
    SDL_Color textColor;
    char text [100];
}Text;

typedef struct image{
    SDL_Rect pos0;
    SDL_Rect pos1;
    SDL_Rect pos2;
    SDL_Rect pos3;
    SDL_Rect pos4;
    SDL_Rect pos5;
    SDL_Surface *img;
    SDL_Surface *img1;
    SDL_Surface *img2;
    SDL_Surface *img3;
    SDL_Surface *img4;
    SDL_Surface *img5;
}image;

void init_enigme(image *E, Text *T);
void init_back(image *backg);
void liberer_img(image E,Text T);
void afficher(image, SDL_Event, Text);
void generer(image*);
#endif

