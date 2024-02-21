#include "../inc/Start_Menu.h"

////////////////////////////////////////

void InitialisationSM(SM* Start_Menu,int* Quit_Game)
{
	// Quit Button

	Start_Menu->Image_Quit_Button.pos.h=119;
	Start_Menu->Image_Quit_Button.pos.w=151;

	Start_Menu->Image_Quit_Button.pos.x=69;
	Start_Menu->Image_Quit_Button.pos.y=43;

	Start_Menu->Image_Quit_Button.UC_B = load_img("pkg//res//menu//UCReturn.png");
	Start_Menu->Image_Quit_Button.C_B = load_img("pkg//res//menu//CReturn.png");

	// Bouton save 1

	Start_Menu->Image_Save1.pos.h=206;
	Start_Menu->Image_Save1.pos.w=831;

	Start_Menu->Image_Save1.pos.x=545;
	Start_Menu->Image_Save1.pos.y=168;

	Start_Menu->Image_Save1.UC_B = load_img("pkg//res//menu//NG_USelected.png");
	Start_Menu->Image_Save1.C_B = load_img("pkg//res//menu//NG_Selected.png");

	// Bouton save 2

	Start_Menu->Image_Save2.pos.h=206;
	Start_Menu->Image_Save2.pos.w=831;

	Start_Menu->Image_Save2.pos.x=545;
	Start_Menu->Image_Save2.pos.y=438;

	Start_Menu->Image_Save2.UC_B = load_img("pkg//res//menu//NG_USelected.png");
	Start_Menu->Image_Save2.C_B = load_img("pkg//res//menu//NG_Selected.png");

	// Bouton save 3

	Start_Menu->Image_Save3.pos.h=206;
	Start_Menu->Image_Save3.pos.w=831;

	Start_Menu->Image_Save3.pos.x=545;
	Start_Menu->Image_Save3.pos.y=708;

	Start_Menu->Image_Save3.UC_B = load_img("pkg//res//menu//NG_USelected.png");
	Start_Menu->Image_Save3.C_B = load_img("pkg//res//menu//NG_Selected.png");

	// Background image

	Start_Menu->Image_background_SM = load_img("pkg//res//menu//Start_BG.png");

	// Image pointer verification

	if(!(Start_Menu->Image_Save1.UC_B && Start_Menu->Image_Save1.C_B && Start_Menu->Image_Save2.UC_B &&
	   Start_Menu->Image_Save2.C_B && Start_Menu->Image_Save3.UC_B && Start_Menu->Image_Save3.C_B &&
	   Start_Menu->Image_Quit_Button.UC_B && Start_Menu->Image_Quit_Button.C_B && Start_Menu->Image_background_SM)) 
	{
		printf("Erreur allocation initialisation image\n");
		ClearStartMenu(Start_Menu);
		*Quit_Game=1;
	}

	// Image Save/New Game

	/*
	Start_Menu->Image_NG=IMG_Load(" ");
	Start_Menu->Image_SG=IMG_Load("");
	*/

	// Position & Click

	Start_Menu->Actual_Position=2;
	Start_Menu->Last_Position=0;
	Start_Menu->Compteur_Blit_Fond=0;
	Start_Menu->Clicked_Button=0;

}

////////////////////////////////////////

void KeyboardEventSM(SDL_Event Event,SM* Start_Menu)
{
	// Verification Keyboard movement

	if( Event.key.keysym.sym == SDLK_UP && (Start_Menu->Actual_Position>1) )
		(Start_Menu->Actual_Position)--;

	else if( Event.key.keysym.sym == SDLK_DOWN && (Start_Menu->Actual_Position<4) )	
		(Start_Menu->Actual_Position)++;
}

////////////////////////////////////////

void MouseEventSM(SDL_Event Event,SM* Start_Menu)
{
	if(Event.motion.y>=43 && Event.motion.y<=162 && Event.motion.x>=69 && Event.motion.x<=220)
	{
		// Initialisation bouton position

		Start_Menu->Actual_Position=1;

		// Test position curseur bouton 1

		if(Event.type == SDL_MOUSEBUTTONDOWN && Event.button.button == SDL_BUTTON_LEFT)
			Start_Menu->Clicked_Button=1;
	}

	else if(Event.motion.x>=545 && Event.motion.x<=1376)
	{
		if(Event.motion.y>=168 && Event.motion.y<=374)
		{
			// Initialisation bouton position

			Start_Menu->Actual_Position=2;

			// Test position curseur bouton 2

			if(Event.type == SDL_MOUSEBUTTONDOWN && Event.button.button == SDL_BUTTON_LEFT)
				Start_Menu->Clicked_Button=1;
		}

		else if(Event.motion.y>=438 && Event.motion.y<=644)
		{
			// Initialisation bouton position

			Start_Menu->Actual_Position=3;

			// Test position curseur bouton 3

			if(Event.type == SDL_MOUSEBUTTONDOWN && Event.button.button == SDL_BUTTON_LEFT)
				Start_Menu->Clicked_Button=1;
		}

		else if(Event.motion.y>=708 && Event.motion.y<=914)
		{
			// Initialisation bouton position

			Start_Menu->Actual_Position=4;

			// Test position curseur bouton 4

			if(Event.type == SDL_MOUSEBUTTONDOWN && Event.button.button == SDL_BUTTON_LEFT)
				Start_Menu->Clicked_Button=1;
		}
	}

}

////////////////////////////////////////

void DrawButtonsStartMenu(SDL_Surface* Screen,SM* Start_Menu)
{
	// Visuel des boutons

	switch(Start_Menu->Actual_Position)
	{
		// Return button selected
		case 1:
			if(Start_Menu->Last_Position!=1)
			{
				ButtonBliting(Screen, Start_Menu->Image_Save1.UC_B, &(Start_Menu->Image_Save1.pos), Start_Menu->Image_Save2.UC_B, &(Start_Menu->Image_Save2.pos), Start_Menu->Image_Save3.UC_B, &(Start_Menu->Image_Save3.pos),
							  Start_Menu->Image_Quit_Button.C_B, &(Start_Menu->Image_Quit_Button.pos) );

				Start_Menu->Last_Position=1;
			}
			break;

		// Save 2 selected
		case 3:
			if(Start_Menu->Last_Position!=3)
			{
				ButtonBliting(Screen, Start_Menu->Image_Save1.UC_B, &(Start_Menu->Image_Save1.pos), Start_Menu->Image_Save3.UC_B, &(Start_Menu->Image_Save3.pos), Start_Menu->Image_Quit_Button.UC_B, &(Start_Menu->Image_Quit_Button.pos),
							  Start_Menu->Image_Save2.C_B, &(Start_Menu->Image_Save2.pos) );

				Start_Menu->Last_Position=3;
			}
			break;

		// Save 3 selected
		case 4:
			if(Start_Menu->Last_Position!=4)
			{
				ButtonBliting(Screen, Start_Menu->Image_Save1.UC_B, &(Start_Menu->Image_Save1.pos), Start_Menu->Image_Save2.UC_B, &(Start_Menu->Image_Save2.pos), Start_Menu->Image_Quit_Button.UC_B, &(Start_Menu->Image_Quit_Button.pos),
							  Start_Menu->Image_Save3.C_B, &(Start_Menu->Image_Save3.pos) );

				Start_Menu->Last_Position=4;
			}
			break;

		// Save 1 selected ( default )
		default:
			if(Start_Menu->Last_Position!=2)
			{
				ButtonBliting(Screen, Start_Menu->Image_Save2.UC_B, &(Start_Menu->Image_Save2.pos), Start_Menu->Image_Save3.UC_B, &(Start_Menu->Image_Save3.pos), Start_Menu->Image_Quit_Button.UC_B, &(Start_Menu->Image_Quit_Button.pos),
							  Start_Menu->Image_Save1.C_B, &(Start_Menu->Image_Save1.pos) );

				Start_Menu->Last_Position=2;
			}
			break;
	}
}

////////////////////////////////////////

void StartMenu(int* Quit_Game)
{
	// Quit loop verification

	int Quit=0;

	// Création Start Menu

	SM Start_Menu;

	// Initialisation Start Menu

	InitialisationSM(&Start_Menu, Quit_Game);

	// If no error occured in the initialisation => Enter Start menu loop

	if(!(*Quit_Game))
	{
		// Start menu loop

		while(!Quit)
		{
			while(SDL_PollEvent(&event))
			{
				if(event.type==SDL_QUIT)
				{
					Quit=1;
					*Quit_Game=1;
				}

				else
				{
					// Draw background

					if(Start_Menu.Compteur_Blit_Fond==0)
					{
						SDL_BlitSurface(Start_Menu.Image_background_SM,NULL,screen,NULL);
						Start_Menu.Compteur_Blit_Fond=1;
					}

					// Draw Buttons

					DrawButtonsStartMenu(screen,&Start_Menu);
							
					// Check Main Menu position :: Mettre sous forme de fonction
						
					if(event.type == SDL_KEYDOWN)
						KeyboardEventSM(event,&Start_Menu);

					else if(event.type==SDL_MOUSEMOTION || event.type==SDL_MOUSEBUTTONDOWN)
						MouseEventSM(event,&Start_Menu);

					// Keyboard enter handling

					if( (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) || Start_Menu.Clicked_Button==1)
					{
						switch(Start_Menu.Actual_Position)
						{
							case 1:
								//Return to main menu
								Quit=1;
								break;

							case 2:
								//Save 1
								Start_Menu.Clicked_Button=0;
								break;

							case 3:
								//Save 2
								Start_Menu.Clicked_Button=0;
								break;

							case 4:
								//Save 3
								Start_Menu.Clicked_Button=0;	
								break;

							default:
								break;
						}
					}

					// Flip screen
					SDL_Flip(screen);
				}
			}

			// Frame regulation
			SDL_Delay(6);
		}

		// Clear memory
		ClearStartMenu(&Start_Menu);
	}
}

////////////////////////////////////////

void ClearStartMenu(SM* Start_Menu)
{
	SDL_FreeSurface(Start_Menu->Image_background_SM);
	SDL_FreeSurface(Start_Menu->Image_Save1.UC_B);
	SDL_FreeSurface(Start_Menu->Image_Save1.C_B);
	SDL_FreeSurface(Start_Menu->Image_Save2.UC_B);
	SDL_FreeSurface(Start_Menu->Image_Save2.C_B);
	SDL_FreeSurface(Start_Menu->Image_Save3.UC_B);
	SDL_FreeSurface(Start_Menu->Image_Save3.C_B);
	SDL_FreeSurface(Start_Menu->Image_Quit_Button.UC_B);
	SDL_FreeSurface(Start_Menu->Image_Quit_Button.C_B);
}

////////////////////////////////////////