#include "../inc/inc.h"
#include "Best_Score.c"
#include "Multiplayer_Skins.c"

////////////////////////////////////////

void InitialisationMP(MP* Multi,int* Quit_Game)
{
	// Music and Chunk
	
	Multi->Chunk = Mix_LoadWAV("project/res/music/rac_menu_beep.wav");

	//* load the @soundVolume
    Mix_VolumeChunk(Multi->Chunk, scanValue("project/doc/settings", 24));

	// Background

	Multi->Rect_MP.h=389;
	Multi->Rect_MP.w=633;

	Multi->Rect_MP.x=636;
	Multi->Rect_MP.y=321;

	Multi->Img_Start = load_img("project/res/img_multiplayer/multiplayer start.png");
	Multi->Img_Score = load_img("project/res/img_multiplayer/multiplayer best score.png");
	Multi->Img_Arrow = load_img("project/res/img_multiplayer/multiplayer return.png");

	// Start Button

	Multi->Rect_Start.h=95;
	Multi->Rect_Start.w=273;

	Multi->Rect_Start.x=823;
	Multi->Rect_Start.y=373;

	// Score Button

	Multi->Rect_Score.h=96;
	Multi->Rect_Score.w=517;

	Multi->Rect_Score.x=688;
	Multi->Rect_Score.y=531;

	// Return button

	Multi->Rect_Arrow.h=39;
	Multi->Rect_Arrow.w=90;

	Multi->Rect_Arrow.x=22;
	Multi->Rect_Arrow.y=1030;

	// Image pointer verification

	if( !(Multi->Img_Start && Multi->Img_Score && Multi->Img_Arrow) )
	{
		printf("Erreur allocation initialisation image\n");
		ClearMP(Multi);
		*Quit_Game=1;
	}

	// Initialisation position bouton & bouton cliqué

	Multi->Actual_Position=1;
	Multi->Last_Position=0;
	Multi->Clicked_Button=0;

	SDL_BlitSurface(Multi->Img_Start,NULL,screen,NULL);
}

////////////////////////////////////////

void UpdateButtonsMP(MP* Multi)
{
	// Visuel des boutons

	switch(Multi->Actual_Position)
	{
		case 2:
			if(Multi->Last_Position!=2)
			{
				SDL_BlitSurface(Multi->Img_Score,&(Multi->Rect_MP),screen,&(Multi->Rect_MP));
				SDL_BlitSurface(Multi->Img_Score,&(Multi->Rect_Arrow),screen,&(Multi->Rect_Arrow));
				Mix_PlayChannel(-1,Multi->Chunk,0);

				Multi->Last_Position=2;
			}
			break;

		case 3:
			if(Multi->Last_Position!=3)
			{
				SDL_BlitSurface(Multi->Img_Arrow,NULL,screen,NULL);
				Mix_PlayChannel(-1,Multi->Chunk,0);

				Multi->Last_Position=3;
			}
			break;

		default:
			if(Multi->Last_Position!=1)
			{
				SDL_BlitSurface(Multi->Img_Start,&(Multi->Rect_MP),screen,&(Multi->Rect_MP));
				SDL_BlitSurface(Multi->Img_Score,&(Multi->Rect_Arrow),screen,&(Multi->Rect_Arrow));
				Mix_PlayChannel(-1,Multi->Chunk,0);

				Multi->Last_Position=1;
			}
			break;
	}
}

////////////////////////////////////////

void KeyboardEventMP(MP* Multi)
{
	// Verification Keyboard movement

	if( event.key.keysym.sym == SDLK_DOWN && (Multi->Actual_Position<3) )
		 (Multi->Actual_Position)++;

	else if( event.key.keysym.sym == SDLK_UP )
	{
		if(Multi->Actual_Position == 1)
			Multi->Actual_Position = 2;
		else
		 (Multi->Actual_Position)--; 
	}

}

////////////////////////////////////////

void MouseEventMP(MP* Multi)
{
	if( (event.motion.y >= Multi->Rect_Start.y) && (event.motion.y <= Multi->Rect_Start.y + Multi->Rect_Start.h) )
	{
		if( (event.motion.x >= Multi->Rect_Start.x) && (event.motion.x <= Multi->Rect_Start.x + Multi->Rect_Start.w) )
		{
			// Initialisation bouton position
			Multi->Actual_Position=1;

			// Test position curseur bouton 1

			if(event.button.button == SDL_BUTTON_LEFT)
				Multi->Clicked_Button=1;
		}
	}

	else if( (event.motion.y >= Multi->Rect_Score.y) && (event.motion.y <= Multi->Rect_Score.y + Multi->Rect_Score.h) )
	{
		if( (event.motion.x >= Multi->Rect_Score.x) && (event.motion.x <= Multi->Rect_Score.x + Multi->Rect_Score.w) )
		{
			// Initialisation bouton position
			Multi->Actual_Position=2;

			// Test position curseur bouton 2

			if(event.button.button == SDL_BUTTON_LEFT)
				Multi->Clicked_Button=1;
		}
	}

	else if( (event.motion.y >= Multi->Rect_Arrow.y) && (event.motion.y <= Multi->Rect_Arrow.y + Multi->Rect_Arrow.h) )
	{
		if( (event.motion.x >= Multi->Rect_Arrow.x) && (event.motion.x <= Multi->Rect_Arrow.x + Multi->Rect_Arrow.w) )
		{
			// Initialisation bouton position
			Multi->Actual_Position=3;

			// Test position curseur bouton 2

			if(event.button.button == SDL_BUTTON_LEFT)
				Multi->Clicked_Button=1;
		}
	}

}

////////////////////////////////////////

void MovementEventMP(MP* Multi)
{
	if(event.type == SDL_KEYDOWN)
		KeyboardEventMP(Multi);

	else if(event.type==SDL_MOUSEMOTION || event.type==SDL_MOUSEBUTTONDOWN)
		MouseEventMP(Multi);
}

////////////////////////////////////////

void MenuMP(int* Quit_Game)
{
	// Quit loop verification

	int Quit=0;

	// Création Quit

	MP Multi;

	// Initialisation Start Menu

	InitialisationMP(&Multi,Quit_Game);

	// If no error occured in the initialisation => Enter Quit Verification loop

	while(!Quit && !(*Quit_Game))
	{
		while(SDL_PollEvent(&event))
		{
			// Check Main Menu position

			MovementEventMP(&Multi);

			// Draw Buttons

			UpdateButtonsMP(&Multi);

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

				if(event.key.keysym.sym == SDLK_ESCAPE)
					Quit=1;
					
				// Mouse click / Space button pressed

				else if( event.key.keysym.sym == SDLK_SPACE || Multi.Clicked_Button )
				{
					ClearMP(&Multi);

					switch(Multi.Actual_Position)
					{
						case 1:
							// Multiplayer skins
							MenuMPS(Quit_Game);

							break;

						case 2:

							//Best score
							MenuBS(Quit_Game);

							break;

						case 3:
							Quit=1;
							break;

						default:
							break;
					}

					if(!(*Quit_Game))
						InitialisationMP(&Multi,Quit_Game);
				}					
			}

			// Flip screen
			SDL_Flip(screen);
		}

		//Frame regulation
		SDL_Delay(6);
	}

	// CLear Quit verification
	ClearMP(&Multi);
}



////////////////////////////////////////

void ClearMP(MP* Multi)
{
	SDL_FreeSurface(Multi->Img_Start);
	SDL_FreeSurface(Multi->Img_Score);
	SDL_FreeSurface(Multi->Img_Arrow);
	Mix_FreeChunk(Multi->Chunk);
}

////////////////////////////////////////