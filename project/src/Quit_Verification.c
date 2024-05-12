#include "../inc/Quit_Verification.h"

////////////////////////////////////////

void InitialisationQV(QV* Quit,int* Quit_Game)
{
	// Music and Chunk
	
	Quit->Chunk = Mix_LoadWAV("project/res/music/rac_menu_beep.wav");

	//* load the @soundVolume
	Mix_VolumeChunk(Quit->Chunk, scanValue("project/doc/settings", 24));

	// Background

	Quit->Rect_quit.h=574;
	Quit->Rect_quit.w=1205;

	Quit->Rect_quit.x=358;
	Quit->Rect_quit.y=253;

	Quit->Img_bg = load_img("project/res/img_main_menu/MainMenu.png");
	Quit->Img_quit_Yes = load_img("project/res/img_quit_verification/Quit verification yes S.png");
	Quit->Img_quit_No = load_img("project/res/img_quit_verification/Quit verification no S.png");

	// Yes Button

	Quit->Image_Yes.h=82;
	Quit->Image_Yes.w=81;

	Quit->Image_Yes.x=792;
	Quit->Image_Yes.y=619;

	// No Button

	Quit->Image_No.h=82;
	Quit->Image_No.w=82;

	Quit->Image_No.x=1018;
	Quit->Image_No.y=619;

	// Image pointer verification

	if( !(Quit->Img_quit_Yes && Quit->Img_quit_No && Quit->Img_bg) )
	{
		printf("Erreur allocation initialisation image\n");
		ClearQV(Quit);
		*Quit_Game=1;
	}

	// Initialisation position bouton & bouton cliqué

	Quit->Actual_Position=2;
	Quit->Last_Position=0;
	Quit->Clicked_Button=0;

	SDL_BlitSurface(Quit->Img_bg,NULL,screen,NULL);
}

////////////////////////////////////////

void UpdateButtonsQV(QV* Quit)
{
	// Visuel des boutons

	switch(Quit->Actual_Position)
	{
		case 2:
			if(Quit->Last_Position!=2)
			{
				SDL_BlitSurface(Quit->Img_bg,&(Quit->Rect_quit),screen,&(Quit->Rect_quit));
				SDL_BlitSurface(Quit->Img_quit_No,NULL,screen,&(Quit->Rect_quit));
				Mix_PlayChannel(-1,Quit->Chunk,0);

				Quit->Last_Position=2;		
			}
			break;

		default:
			if(Quit->Last_Position!=1)
			{
				SDL_BlitSurface(Quit->Img_bg,&(Quit->Rect_quit),screen,&(Quit->Rect_quit));
				SDL_BlitSurface(Quit->Img_quit_Yes,NULL,screen,&(Quit->Rect_quit));
				Mix_PlayChannel(-1,Quit->Chunk,0);

				Quit->Last_Position=1;
			}
			break;
	}
}

////////////////////////////////////////

void KeyboardEventQV(QV* Quit)
{
	// Verification Keyboard movement

	if( event.key.keysym.sym == SDLK_LEFT && (Quit->Actual_Position>1) )
		(Quit->Actual_Position)--; 

	else if( event.key.keysym.sym == SDLK_RIGHT && (Quit->Actual_Position<2) )	
		(Quit->Actual_Position)++;

}

////////////////////////////////////////

void MouseEventQV(QV* Quit)
{
	if( (event.motion.y >= Quit->Image_Yes.y) && (event.motion.y <= Quit->Image_Yes.y + Quit->Image_Yes.h) )
	{
		if( (event.motion.x >= Quit->Image_No.x) && (event.motion.x <= Quit->Image_No.x + Quit->Image_No.w) )
		{
			// Initialisation bouton position
			Quit->Actual_Position=2;

			// Test position curseur bouton 1

			if(event.button.button == SDL_BUTTON_LEFT)
				Quit->Clicked_Button=1;
		}

		else if( (event.motion.x >= Quit->Image_Yes.x) && (event.motion.x <= Quit->Image_Yes.x + Quit->Image_Yes.w) )
		{
			// Initialisation bouton position
			Quit->Actual_Position=1;

			// Test position curseur bouton 2

			if(event.button.button == SDL_BUTTON_LEFT)
				Quit->Clicked_Button=1;
		}
	}

}

////////////////////////////////////////

void MovementEventQV(QV* Quit)
{
	if(event.type == SDL_KEYDOWN)
		KeyboardEventQV(Quit);

	else if(event.type==SDL_MOUSEMOTION || event.type==SDL_MOUSEBUTTONDOWN)
		MouseEventQV(Quit);
}

////////////////////////////////////////

void QuitVerification(int* Quit_Game)
{
	// Quit loop verification

	int Quit_QV=0;

	// Création Quit

	QV Quit;

	// Initialisation Start Menu

	InitialisationQV(&Quit,Quit_Game);

	// If no error occured in the initialisation => Enter Quit Verification loop

	while(!Quit_QV && !(*Quit_Game))
	{
		while(SDL_PollEvent(&event))
		{
			// Check Main Menu position

			MovementEventQV(&Quit);

			// Draw Buttons

			UpdateButtonsQV(&Quit);

			// If the quit cross is pressed

			if(event.type == SDL_QUIT)
			{
				Quit_QV=1;
				*Quit_Game=1;
			}

			// Return to main menu by pressing "ESCAPE"

			else if(event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN )
			{
				// Return to main menu by pressing "ESCAPE"

				if(event.key.keysym.sym == SDLK_ESCAPE)
					Quit_QV=1;
					
				// Mouse click / Space button pressed

				else if( event.key.keysym.sym == SDLK_SPACE || Quit.Clicked_Button )
				{
					switch(Quit.Actual_Position)
					{
						case 1:
							//Quit game
							*Quit_Game=1;
							Quit_QV=1;
							break;

						case 2:
							//Return to main menu
							Quit_QV=1;
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
	ClearQV(&Quit);
}



////////////////////////////////////////

void ClearQV(QV* Quit)
{
	SDL_FreeSurface(Quit->Img_quit_Yes);
	SDL_FreeSurface(Quit->Img_quit_No);
	Mix_FreeChunk(Quit->Chunk);
}

////////////////////////////////////////