#include "../inc/Quit_Verification.h"

////////////////////////////////////////

void InitialisationQV(QV* Quit,int* Quit_Game)
{
	// Background

	Quit->Image_Background.pos.h=244;
	Quit->Image_Background.pos.w=641;

	Quit->Image_Background.pos.x=621;
	Quit->Image_Background.pos.y=467;

	Quit->Image_Background.Image = load_img("pkg//res//menu//Quit_Verification.png");

	// Yes Button

	Quit->Image_Yes.pos.h=63;
	Quit->Image_Yes.pos.w=88;

	Quit->Image_Yes.pos.x=784;
	Quit->Image_Yes.pos.y=585;

	Quit->Image_Yes.UC_B = load_img("pkg//res//menu//Yes_UC.png");
	Quit->Image_Yes.C_B = load_img("pkg//res//menu//Yes_C.png");

	// No Button

	Quit->Image_No.pos.h=63;
	Quit->Image_No.pos.w=88;

	Quit->Image_No.pos.x=1011;
	Quit->Image_No.pos.y=585;

	Quit->Image_No.UC_B = load_img("pkg//res//menu//No_UC.png");
	Quit->Image_No.C_B = load_img("pkg//res//menu//No_C.png");

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
				ButtonBlitingQV(Screen, Quit->Image_Yes.UC_B, &(Quit->Image_Yes.pos), Quit->Image_No.C_B, &(Quit->Image_No.pos) );
				Quit->Last_Position=2;		
			}
			break;

		default:
			if(Quit->Last_Position!=1)
			{
				ButtonBlitingQV(Screen, Quit->Image_No.UC_B, &(Quit->Image_No.pos), Quit->Image_Yes.C_B, &(Quit->Image_Yes.pos) );
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
						SDL_BlitSurface(Quit.Image_Background.Image,NULL,Screen,&(Quit.Image_Background.pos));
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
	SDL_FreeSurface(Quit->Image_Background.Image);
	SDL_FreeSurface(Quit->Image_Yes.UC_B);
	SDL_FreeSurface(Quit->Image_Yes.C_B);
	SDL_FreeSurface(Quit->Image_No.UC_B);
	SDL_FreeSurface(Quit->Image_No.C_B);
}

////////////////////////////////////////