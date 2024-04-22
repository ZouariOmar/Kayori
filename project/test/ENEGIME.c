#include "../inc/inc.h"

void enegime() {
    image enigme;
    Text texte;
    image background;
    
    init_enigme(&enigme, &texte);
    init_back(&background);

    SDL_Event event;
    int running = 1;

    SDL_Flip(screen);
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = 0;
                }
            else if(event.type==SDLK)
            }
        }
        SDL_BlitSurface(background.img, NULL, screen, &background.pos0);
        afficher(enigme, event, texte);
        SDL_Flip(screen);
    }
    liberer_img(enigme,texte);
}

void init_enigme(image *E , Text *T){
   E->img1=load_img("project/test/enigma res/img1.png");
   if(E->img1==NULL){
    return ;
   }
   E->pos1.x=500;
   E->pos1.y=163;

   E->img2=load_img("project/test/enigma res/img2.png");
   if(E->img2==NULL){
    return ;
   }
   E->pos2.x=635;
   E->pos2.y=672;

   E->img3=load_img("project/test/enigma res/img3.png");
   if(E->img3==NULL){
    return ;
   }
   E->pos3.x=1030;
   E->pos3.y=672;

   E->img4=load_img("project/test/enigma res/img4.png");
   if(E->img4==NULL){
    return ;
   }
   E->pos4.x=635;
   E->pos4.y=672;
  
  E->img5=load_img("project/test/enigma res/img5.png");
   if(E->img5==NULL){
    return ;
   }
   E->pos5.x=1030;
   E->pos5.y=672;

   T->font=TTF_OpenFont("project/res/font/Code 7x5.ttf",70);
   if (T->font == NULL) {
      printf("Erreur : impossible de charger la police !\n");
      return;
   }
    T->position.x=290;
    T->position.y=454;

}
void init_back(image *backg){
    backg->img=load_img("project/test/enigma res/img0.png");
    if(backg->img==NULL){
        printf("eureur:can't load the background %s\n ",SDL_GetError());
        return ;
    }
    backg->pos0.x=0;
    backg->pos0.y=0;
}

void liberer_img(image E,Text T){
        SDL_FreeSurface(E.img1);
        SDL_FreeSurface(E.img2);
        SDL_FreeSurface(E.img3);
        SDL_FreeSurface(E.img4);
        SDL_FreeSurface(E.img5);
        SDL_FreeSurface(T.Stexte);
        
}

void afficher(image p,SDL_Event event,Text T){
    SDL_BlitSurface(p.img1,NULL,screen,(p.pos1.x=500, p.pos1.y=163, &p.pos1));
    SDL_BlitSurface(p.img2,NULL,screen,&p.pos2);
    SDL_BlitSurface(p.img3,NULL,screen,&p.pos3);
    if ( event.type == SDL_MOUSEMOTION) {
        if  (event.button.x >= bouton.pos.x && event.button.x <= bouton.pos.x + bouton.width &&
                    event.button.y >= bouton.pos.y && event.button.y <= bouton.pos.y + bouton.height) {
            SDL_FreeSurface(p.img2); 
            SDL_BlitSurface(p.img4, NULL, screen, &p.pos4); 
        }
        else  if (event.button.x >= bouton.pos.x && event.button.x <= bouton.pos.x + bouton.width &&
                    event.button.y >= bouton.pos.y && event.button.y <= bouton.pos.y + bouton.height) {
            SDL_FreeSurface(p.img3); 
            SDL_BlitSurface(p.img5, NULL, screen, &p.pos5); 
        }
    }
    else if (event.key.keysym.sym == SDLK_RIGHT){
         if  (event.button.x >= bouton.pos.x && event.button.x <= bouton.pos.x + bouton.width &&
                    event.button.y >= bouton.pos.y && event.button.y <= bouton.pos.y + bouton.height) {
            SDL_FreeSurface(p.img2); 
            SDL_BlitSurface(p.img4, NULL, screen, &p.pos4); 
        }  
    }
    T.Stexte=TTF_RenderText_Solid(T.font,"asba 3la termetek ya omar ya sfaxi ya 7awi", WHITE);
    SDL_BlitSurface(T.Stexte, NULL, screen,&T.position );

}
void generer(image *r){
  //  int random_nbr;
    //int nb=random(&random_nbr);
   // FILE *f;
   // f=fopen("enigme.txt","r");
  void generer(image *r) {
    FILE *f;
    f = fopen("enigme.txt", "r");

    if (f == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier enigme.txt\n");
        return;
    }

    // Compter le nombre total d'énigmes
    int totalEnigmes = 0;
    char line[20];
    while (fgets(line, sizeof(line), f) != NULL) {
        totalEnigmes++;
    }

    // Générer un nombre aléatoire pour choisir une énigme
    srand(time(NULL));
    int randomEnigme = rand() % totalEnigmes;

    // Revenir au début du fichier
    rewind(f);

    // Parcourir le fichier jusqu'à la ligne de l'énigme choisie
    int currentEnigme = 0;
    while (fgets(line, sizeof(line), f) != NULL) {
        if (currentEnigme == randomEnigme) {
            // Stocker l'énigme dans une variable ou l'afficher directement
            printf("Enigme choisie : %s", line);
            break;
        }
        currentEnigme++;
    }

    fclose(f);
}



}

int random(int* random_nbr){
    srand(NULL);
    * random_nbr = rand() % 20;
}
