#include "../inc/Best_Score.h"

////////////////////////////////////////

void InitialisationBS(BS* Best_Score,int* Quit_Game)
{
	// Music and Chunk
	
	//Best_Score->Chunk = Mix_LoadWAV("project/res/music/rac_menu_beep.wav");

	//* load the @soundVolume
    //Mix_VolumeChunk(Best_Score->Chunk, scanValue("project/doc/settings", 20));

	// Background
	Best_Score->Score = load_img("project/res/img_score/best scores menu copie.png");

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