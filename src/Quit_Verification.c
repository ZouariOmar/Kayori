#include "../inc/Quit_Verification.h"

////////////////////////////////////////

void InitialisationQV(QV* Quit,int* Quit_Game)
{
	// Music and Chunk
	
	Quit->Chunk = Mix_LoadWAV("pkg//music//rac_menu_beep.wav");

	// Background

	Quit->Image_Background.pos.h=244;
	Quit->Image_Background.pos.w=641;

	Quit->Image_Background.pos.x=621;
	Quit->Image_Background.pos.y=467;

	Quit->Image_Background.Image = load_img("pkg//res//menu//Quit_verification copie.png");

	// Yes Button

	Quit->Image_Yes.pos.h=63;
	Quit->Image_Yes.pos.w=88;

	Quit->Image_Yes.pos.x=784;
	Quit->Image_Yes.pos.y=585;

	Quit->Image_Yes.UC_B = load_img("pkg//res//menu//US_Yes.png");
	Quit->Image_Yes.C_B = load_img("pkg//res//menu//S_Yes.png");

	// No Button

	Quit->Image_No.pos.h=63;
	Quit->Image_No.pos.w=88;

	Quit->Image_No.pos.x=1011;
	Quit->Image_No.pos.y=585;

	Quit->Image_No.UC_B = load_img("pkg//res//menu//US_No.png");
	Quit->Image_No.C_B = load_img("pkg//res//menu//S_No.png");

	// Image pointer verification

	if( !(Quit->Image_Background.Image && Quit->Image_Yes.UC_B && Quit->Image_Yes.C_B && Quit->Image_No.UC_B && Quit->Image_No.C_B) )
	{
		printf("Erreur allocation initialisation image\n");
		ClearQV(Quit);
		*Quit_Game=1;
	}

	// Initialisation position bouton & bouton cliqué

	Quit->Actual_Position=2;
	Quit->Last_Position=0;	
	Quit->Clicked_Button=0;

	// Blitting of the quit verification

	// Draw background
	SDL_BlitSurface(Quit->Image_Background.Image,NULL,screen,&(Quit->Image_Background.pos));
}

////////////////////////////////////////

void ButtonUpdateQV(SDL_Surface* UC_Image1, SDL_Rect* UC_Rect1, SDL_Surface* C_Image, SDL_Rect* C_Rect, Mix_Chunk* Chunk)
{
	// Image blitting

	SDL_BlitSurface(UC_Image1,NULL,screen,UC_Rect1);
	SDL_BlitSurface(C_Image,NULL,screen,C_Rect);

	// Play chunk

	Mix_PlayChannel(-1,Chunk,0);
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
				ButtonUpdateQV(Quit->Image_Yes.UC_B, &(Quit->Image_Yes.pos), Quit->Image_No.C_B, &(Quit->Image_No.pos), Quit->Chunk );

				Quit->Last_Position=2;		
			}
			break;

		default:
			if(Quit->Last_Position!=1)
			{
				ButtonUpdateQV(Quit->Image_No.UC_B, &(Quit->Image_No.pos), Quit->Image_Yes.C_B, &(Quit->Image_Yes.pos), Quit->Chunk );

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
	if(event.motion.y>=585 && event.motion.y<=648)
	{
		if(event.motion.x>=784 && event.motion.x<=872)
		{
			// Initialisation bouton position
			Quit->Actual_Position=1;

			// Test position curseur bouton 1

			if(event.button.button == SDL_BUTTON_LEFT)
				Quit->Clicked_Button=1;
		}

		else if(event.motion.x>=1011 && event.motion.x<=1099)
		{
			// Initialisation bouton position
			Quit->Actual_Position=2;

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
	SDL_FreeSurface(Quit->Image_Background.Image);
	SDL_FreeSurface(Quit->Image_Yes.UC_B);
	SDL_FreeSurface(Quit->Image_Yes.C_B);
	SDL_FreeSurface(Quit->Image_No.UC_B);
	SDL_FreeSurface(Quit->Image_No.C_B);
	Mix_FreeChunk(Quit->Chunk);
}

////////////////////////////////////////