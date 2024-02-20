#include "../inc/Quit_Verification.h"

////////////////////////////////////////

void InitialisationQV(QV* Quit,int* Quit_Game)
{
	// Background

	Quit->Background.h=244;
	Quit->Background.w=641;

	Quit->Background.x=621;
	Quit->Background.y=467;

	// Yes Button

	Quit->Yes_Button.h=63;
	Quit->Yes_Button.w=88;

	Quit->Yes_Button.x=784;
	Quit->Yes_Button.y=585;

	// No Button

	Quit->No_Button.h=63;
	Quit->No_Button.w=88;

	Quit->No_Button.x=1011;
	Quit->No_Button.y=585;


	// Initialisation Image

	Quit->Background_Image_Quit = SDL_DisplayFormatAlpha(IMG_Load("pkg//res//menu//Quit_Verification.png"));
	
	Quit->Yes_UC_Image = SDL_DisplayFormatAlpha(IMG_Load("pkg//res//menu//Yes_UC.png"));
	Quit->Yes_C_Image = SDL_DisplayFormatAlpha(IMG_Load("pkg//res//menu//Yes_C.png"));
	
	Quit->No_UC_Image = SDL_DisplayFormatAlpha(IMG_Load("pkg//res//menu//No_UC.png"));
	Quit->No_C_Image = SDL_DisplayFormatAlpha(IMG_Load("pkg//res//menu//No_C.png"));


	if( !(Quit->Background_Image_Quit && Quit->Yes_UC_Image && Quit->Yes_C_Image && Quit->No_UC_Image && Quit->No_C_Image) )
	{
		printf("Erreur allocation initialisation image\n");
		ClearQV(Quit);
		*Quit_Game=1;
	}
	// Initialisation position bouton & bouton cliqué

	Quit->Actual_Position=2;
	Quit->Last_Position=0;	
	Quit->Clicked_Button=0;
	Quit->Compteur_Blit_Fond=0;
}

////////////////////////////////////////

void ButtonBlitingQV(SDL_Surface* Screen, SDL_Surface* UC_Image1, SDL_Rect* UC_Rect1, SDL_Surface* C_Image, SDL_Rect* C_Rect)
{
	SDL_BlitSurface(UC_Image1,NULL,Screen,UC_Rect1);
	SDL_BlitSurface(C_Image,NULL,Screen,C_Rect);
}

////////////////////////////////////////

void DrawButtonsQV(SDL_Surface* Screen,QV* Quit)
{
	// Visuel des boutons

	switch(Quit->Actual_Position)
	{
		case 2:
			if(Quit->Last_Position!=2)
			{
				ButtonBlitingQV(Screen, Quit->Yes_UC_Image, &(Quit->Yes_Button), Quit->No_C_Image, &(Quit->No_Button) );
				Quit->Last_Position=2;		
			}
			break;

		default:
			if(Quit->Last_Position!=1)
			{
				ButtonBlitingQV(Screen, Quit->No_UC_Image, &(Quit->No_Button), Quit->Yes_C_Image, &(Quit->Yes_Button) );
				Quit->Last_Position=1;
			}
			break;
	}
}

////////////////////////////////////////

void KeyboardEventQV(SDL_Event Event,QV* Quit)
{
	// Verification Keyboard movement

	if( Event.key.keysym.sym == SDLK_LEFT && (Quit->Actual_Position>1) )
		(Quit->Actual_Position)--;

	else if( Event.key.keysym.sym == SDLK_RIGHT && (Quit->Actual_Position<2) )	
		(Quit->Actual_Position)++;

}

////////////////////////////////////////

void MouseEventQV(SDL_Event Event,QV* Quit)
{
	if(Event.motion.y>=585 && Event.motion.y<=648)
	{
		if(Event.motion.x>=784 && Event.motion.x<=872)
		{
			// Initialisation bouton position
			Quit->Actual_Position=1;

			// Test position curseur bouton 1

			if(Event.button.button == SDL_BUTTON_LEFT)
				Quit->Clicked_Button=1;
		}

		else if(Event.motion.x>=1011 && Event.motion.x<=1099)
		{
			// Initialisation bouton position
			Quit->Actual_Position=2;

			// Test position curseur bouton 2

			if(Event.button.button == SDL_BUTTON_LEFT)
				Quit->Clicked_Button=1;
		}
	}

}

////////////////////////////////////////

void QuitVerification(SDL_Surface* Screen,SDL_Event Event,int* Quit_Game)
{
	// Quit loop verification

	int Quit_Loop=0;

	// Création Quit

	QV Quit;

	// Initialisation Start Menu

	InitialisationQV(&Quit,Quit_Game);

	// If no error occured in the initialisation => Enter Quit Verification loop

	if(!(*Quit_Game))
	{
		// Quit verification loop
		while(!Quit_Loop)
		{
			while(SDL_PollEvent(&Event))
			{
				//Switch type of event

				if(Event.type == SDL_QUIT)
				{
					*Quit_Game=1;
					Quit_Loop=1;
				}

				else
				{
					// Draw background once

					if(Quit.Compteur_Blit_Fond==0)
					{
						SDL_BlitSurface(Quit.Background_Image_Quit,NULL,Screen,&(Quit.Background));
						Quit.Compteur_Blit_Fond=1;
					}

					// Check Main Menu position :: à mettre sous forme d'une seule fonction

					if(Event.type == SDL_KEYDOWN)
						KeyboardEventQV(Event,&Quit);

					else if(Event.type==SDL_MOUSEMOTION || Event.type==SDL_MOUSEBUTTONDOWN)
						MouseEventQV(Event,&Quit);


					// Draw Buttons

					DrawButtonsQV(Screen,&Quit);

					// Main event handling

					if( (Event.type == SDL_KEYDOWN && Event.key.keysym.sym == SDLK_SPACE) || Quit.Clicked_Button==1)
					{
						switch(Quit.Actual_Position)
						{
							case 1:
								//Quit game
								*Quit_Game=1;
								Quit_Loop=1;
								break;

							case 2:
								//Return to main menu
								Quit_Loop=1;
								break;

							default:
								break;
						}
					}

					// Flip screen
					SDL_Flip(Screen);
				}
			}

			//Frame regulation
			SDL_Delay(6);
		}

		// CLear Quit verification
		ClearQV(&Quit);
	}
}

////////////////////////////////////////

void ClearQV(QV* Quit)
{
	SDL_FreeSurface(Quit->Background_Image_Quit);
	SDL_FreeSurface(Quit->Yes_UC_Image);
	SDL_FreeSurface(Quit->Yes_C_Image);
	SDL_FreeSurface(Quit->No_UC_Image);
	SDL_FreeSurface(Quit->No_C_Image);
}

////////////////////////////////////////