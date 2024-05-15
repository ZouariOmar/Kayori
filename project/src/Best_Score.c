#include "../inc/inc.h"

////////////////////////////////////////

void InitialisationBS(BS* Best_Score,int* Quit_Game)
{
	// Music and Chunk
	
	//Best_Score->Chunk = Mix_LoadWAV("project/res/music/rac_menu_beep.wav");

	//* load the @soundVolume
    //Mix_VolumeChunk(Best_Score->Chunk, scanValue("project/doc/settings", 20));

	// Background
	Best_Score->Score = load_img("project/res/img_score/best scores menu copie.png");

	// TTF rect
	Best_Score->Rect_S1.x = 730;
	Best_Score->Rect_S1.y = 456;

	Best_Score->Rect_S2.x = 725;
	Best_Score->Rect_S2.y = 553;

	Best_Score->Rect_S3.x = 715;
	Best_Score->Rect_S3.y = 667;

	// Return button

	Best_Score->Rect_Arrow.h=39;
	Best_Score->Rect_Arrow.w=90;

	Best_Score->Rect_Arrow.x=22;
	Best_Score->Rect_Arrow.y=1030;

	// Image pointer verification

	if( !(Best_Score->Score) )
	{
		printf("Erreur allocation initialisation image\n");
		ClearBS(Best_Score);
		*Quit_Game=1;
	}

	// Initialisation position bouton & bouton cliqué
	Best_Score->Clicked_Button=0;

	SDL_BlitSurface(Best_Score->Score,NULL,screen,NULL);
	BestScore(Best_Score,Quit_Game);
}

////////////////////////////////////////

void BlitBS(BS* Best_Score, int S1, int S2, int S3)
{
	char Txt1[20], Txt2[20], Txt3[20];

	// TTF font
	TTF_Font* Font = TTF_OpenFont("project/res/font/Groundation Foundation.ttf", 79);

	// Color text
	SDL_Color Text_Color = {0, 0, 0, 0};

	//
	sprintf(Txt1, "%s%d", "1. ", S1);
	sprintf(Txt2, "%s%d", "2. ", S2);
	sprintf(Txt3, "%s%d", "3. ", S3);

	//
	Best_Score->Txt_S1 = TTF_RenderText_Blended(Font,Txt1,Text_Color);
	Best_Score->Txt_S2 = TTF_RenderText_Blended(Font,Txt2,Text_Color);
	Best_Score->Txt_S3 = TTF_RenderText_Blended(Font,Txt3,Text_Color);

	SDL_BlitSurface(Best_Score->Txt_S1,NULL,screen,&(Best_Score->Rect_S1));
	SDL_BlitSurface(Best_Score->Txt_S2,NULL,screen,&(Best_Score->Rect_S2));
	SDL_BlitSurface(Best_Score->Txt_S3,NULL,screen,&(Best_Score->Rect_S3));
}

////////////////////////////////////////

void BestScore(BS* Best_Score, int* Quit)
{
// Open the collision file and initialisation of the variables

	FILE* file = fopen("project/doc/Scores","r");
	int* S_Tab;
	int Score, T=0, i=0, j=0, c=0;

	if(file==NULL)
	{
		printf("ERREUR : Echec de l'ouverture fichier Score\n");
		*Quit = 1;
		return;
	}

	// Get the number of rect to allocate

	while(!feof(file))
	{
		fscanf(file,"%d",&Score);
		T++;
	}

	// Reinitialisation of the position of the cursor

	rewind(file);

	// Allocation of the rects

	S_Tab = malloc(sizeof(int)*(T));

	if(S_Tab == NULL)
	{
		printf("ERREUR : Echec de l'allocation dynamique des scores\n");
		*Quit = 1;
		return;
	}

	// Fill the rects

	while(!feof(file))
	{
		fscanf(file,"%d",&Score);
		S_Tab[j]=Score;
		j++;
	}

	// Tri tab

	for(i=0;i<T-1;i++)
	{
	    for(j=i+1;j<T;j++)
	        if ( S_Tab[i] < S_Tab[j] ) {
	            c = S_Tab[i];
	            S_Tab[i] = S_Tab[j];
	            S_Tab[j] = c;
	        }
	}

	//
	BlitBS(Best_Score,S_Tab[0],S_Tab[1],S_Tab[2]);

	free(S_Tab);
}

////////////////////////////////////////

void MouseEventBS(BS* Best_Score)
{
	if( (event.motion.y >= Best_Score->Rect_Arrow.y) && (event.motion.y <= Best_Score->Rect_Arrow.y + Best_Score->Rect_Arrow.h) )
	{
		if( (event.motion.x >= Best_Score->Rect_Arrow.x) && (event.motion.x <= Best_Score->Rect_Arrow.x + Best_Score->Rect_Arrow.w) )
		{
			// Test position curseur bouton 2

			if(event.button.button == SDL_BUTTON_LEFT)
				Best_Score->Clicked_Button=1;
		}
	}

}

////////////////////////////////////////

void MenuBS(int* Quit_Game)
{
	// Quit loop verification

	int Quit=0;

	// Création Quit

	BS Best_Score;

	// Initialisation Start Menu

	InitialisationBS(&Best_Score,Quit_Game);

	// If no error occured in the initialisation => Enter Quit Verification loop

	while(!Quit && !(*Quit_Game))
	{
		while(SDL_PollEvent(&event))
		{
			// Check Main Menu position

			MouseEventBS(&Best_Score);

			// If the quit cross is pressed

			if(event.type == SDL_QUIT)
			{
				Quit=1;
				*Quit_Game=1;
			}

			// Return to main menu by pressing "ESCAPE"

			else if(event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN )
			{
				// Return to main menu by pressing "ESCAPE"

				if(event.key.keysym.sym == SDLK_ESCAPE || Best_Score.Clicked_Button || event.key.keysym.sym == SDLK_SPACE)
					Quit=1;				
			}

			// Flip screen
			SDL_Flip(screen);
		}

		//Frame regulation
		SDL_Delay(6);
	}

	// CLear Quit verification
	ClearBS(&Best_Score);
}



////////////////////////////////////////

void ClearBS(BS* Best_Score)
{
	SDL_FreeSurface(Best_Score->Score);
}

////////////////////////////////////////