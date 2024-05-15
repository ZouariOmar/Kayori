#include "../inc/Pause.h"

////////////////////////////////////////

void InitialisationPG(PG* Pause,int* Quit_Game)
{
	// Music and Chunk
	
	//Pause->Chunk = Mix_LoadWAV("project/res/music/rac_menu_beep.wav");

	//* load the @soundVolume
    //Mix_VolumeChunk(Pause->Chunk, scanValue("project/doc/settings", 20));

	// Background
	Pause->Img_PG_Resume = load_img("project//res//Pause game//Pause Resume.png");
	Pause->Img_PG_Return = load_img("project//res//Pause game///Pause MainMenu.png");

	// Resume game Button

	Pause->Image_Resume.h=82;
	Pause->Image_Resume.w=204;

	Pause->Image_Resume.x=857;
	Pause->Image_Resume.y=423;

	// Return to main menu Button

	Pause->Image_Return.h=82;
	Pause->Image_Return.w=408;

	Pause->Image_Return.x=755;
	Pause->Image_Return.y=583;

	// Image pointer verification

	if( !(Pause->Img_PG_Resume && Pause->Img_PG_Return) )
	{
		printf("Erreur allocation initialisation image\n");
		ClearPG(Pause);
		*Quit_Game=1;
	}

	// Initialisation position bouton & bouton cliqué

	Pause->Actual_Position=1;
	Pause->Last_Position=0;
	Pause->Clicked_Button=0;

	//SDL_BlitSurface(Pause->Img_bg,NULL,screen,NULL);
}

////////////////////////////////////////

void UpdateButtonsPG(PG* Pause, BGC* BG_Camera)
{
	// Visuel des boutons

	switch(Pause->Actual_Position)
	{
		case 2:
			if(Pause->Last_Position!=2)
			{
				if(BG_Camera->Number_P==1)
					SDL_BlitSurface(BG_Camera->Dynamic_bg, &(BG_Camera->Camera), screen, NULL);
				else
				{
					SDL_BlitSurface(BG_Camera->Dynamic_bg, &(BG_Camera->Camera1), screen, NULL);
					SDL_BlitSurface(BG_Camera->Dynamic_bg, &(BG_Camera->Camera2), screen, &(BG_Camera->Position_BC_P2));
				}

				SDL_BlitSurface(Pause->Img_PG_Return,NULL,screen,NULL);
				//Mix_PlayChannel(-1,Pause->Chunk,0);

				Pause->Last_Position=2;		
			}
			break;

		default:
			if(Pause->Last_Position!=1)
			{
				if(BG_Camera->Number_P==1)
					SDL_BlitSurface(BG_Camera->Dynamic_bg, &(BG_Camera->Camera), screen, NULL);
				else
				{
					SDL_BlitSurface(BG_Camera->Dynamic_bg, &(BG_Camera->Camera1), screen, NULL);
					SDL_BlitSurface(BG_Camera->Dynamic_bg, &(BG_Camera->Camera2), screen, &(BG_Camera->Position_BC_P2));
				}
				
				SDL_BlitSurface(Pause->Img_PG_Resume,NULL,screen,NULL);
				//Mix_PlayChannel(-1,Pause->Chunk,0);

				Pause->Last_Position=1;
			}
			break;
	}
}

////////////////////////////////////////

void KeyboardEventPG(PG* Pause)
{
	// Verification Keyboard movement

	if( event.key.keysym.sym == SDLK_UP && (Pause->Actual_Position>1) )
		(Pause->Actual_Position)--; 

	else if( event.key.keysym.sym == SDLK_DOWN && (Pause->Actual_Position<2) )	
		(Pause->Actual_Position)++;

}

////////////////////////////////////////

void MouseEventPG(PG* Pause)
{
	if( (event.motion.x >= Pause->Image_Resume.x) && (event.motion.x <= Pause->Image_Resume.x + Pause->Image_Resume.w) )
	{
		if((event.motion.y >= Pause->Image_Resume.y) && (event.motion.y <= Pause->Image_Resume.y + Pause->Image_Resume.h) )
		{
			// Initialisation bouton position
			Pause->Actual_Position=1;

			// Test position curseur bouton 1

			if(event.button.button == SDL_BUTTON_LEFT)
				Pause->Clicked_Button=1;
		}
	}

	else if((event.motion.x >= Pause->Image_Return.x) && (event.motion.x <= Pause->Image_Return.x + Pause->Image_Return.w))
	{
		if((event.motion.y >= Pause->Image_Return.y) && (event.motion.y <= Pause->Image_Return.y + Pause->Image_Return.h) )
		{
			// Initialisation bouton position
			Pause->Actual_Position=2;

			// Test position curseur bouton 2

			if(event.button.button == SDL_BUTTON_LEFT)
				Pause->Clicked_Button=1;
		}
	}
}

////////////////////////////////////////

void MovementEventPG(PG* Pause)
{
	if(event.type == SDL_KEYDOWN)
		KeyboardEventPG(Pause);

	else if(event.type==SDL_MOUSEMOTION || event.type==SDL_MOUSEBUTTONDOWN)
		MouseEventPG(Pause);
}

////////////////////////////////////////

void PauseGame(int* Quit_Game, BGC* BG_Camera)
{
	// Quit loop verification

	int Quit_PG=0;

	// Création Quit

	PG Pause;

	// Initialisation Start Menu

	InitialisationPG(&Pause,Quit_Game);

	// If no error occured in the initialisation => Enter Quit Verification loop

	while(!Quit_PG && !(*Quit_Game))
	{
		while(SDL_PollEvent(&event))
		{
			// Check Main Menu position

			MovementEventPG(&Pause);

			// Draw Buttons

			UpdateButtonsPG(&Pause, BG_Camera);

			// If the quit cross is pressed

			if(event.type == SDL_QUIT)
			{
				Quit_PG=1;
				*Quit_Game=1;
			}

			// Return to main menu by pressing "ESCAPE"

			else if(event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN )
			{
				// Return to main menu by pressing "ESCAPE"

				if(event.key.keysym.sym == SDLK_ESCAPE)
					Quit_PG=1;
					
				// Mouse click / Space button pressed

				else if( event.key.keysym.sym == SDLK_SPACE || Pause.Clicked_Button )
				{
					switch(Pause.Actual_Position)
					{
						case 1:
							//Resume game
							Quit_PG=1;
							break;

						case 2:
							//Return to main menu
							Quit_PG=1;
							*Quit_Game=1;
							break;

						default:
							break;
					}
				}					
			}

			// Flip screen
			SDL_Flip(screen);
		}

		//Frame regulation
		SDL_Delay(6);
	}

	// CLear Quit verification
	ClearPG(&Pause);
}

////////////////////////////////////////

void ClearPG(PG* Pause)
{
	SDL_FreeSurface(Pause->Img_PG_Resume);
	SDL_FreeSurface(Pause->Img_PG_Return);
	//Mix_FreeChunk(Pause->Chunk);
}

////////////////////////////////////////