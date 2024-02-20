#include "../inc/inc.h"
#include "Start_Menu.c"
#include "Quit_Verification.c"
#include "settings.c"
////////////////////////////////////////

void InitialisationMM(SDL_Surface* Screen,MM* Main_Menu)
{
	// Bouton 1

	Main_Menu->Button1MM.h=109;
	Main_Menu->Button1MM.w=551;

	Main_Menu->Button1MM.x=686;
	Main_Menu->Button1MM.y=403;

	// Bouton 2

	Main_Menu->Button2MM.h=109;
	Main_Menu->Button2MM.w=551;

	Main_Menu->Button2MM.x=686;
	Main_Menu->Button2MM.y=550;

	// Bouton 3

	Main_Menu->Button3MM.h=109;
	Main_Menu->Button3MM.w=551;

	Main_Menu->Button3MM.x=686;
	Main_Menu->Button3MM.y=697;

	// Bouton 4

	Main_Menu->Button4MM.h=109;
	Main_Menu->Button4MM.w=551;

	Main_Menu->Button4MM.x=686;
	Main_Menu->Button4MM.y=844;

	// Initialisation Image

	Main_Menu->Image_background_MM = (IMG_Load("pkg/res/menu/Hollow_Vessels2.png"));					// ! memory leak in here
	
	Main_Menu->Image_Start_UC = (IMG_Load("pkg/res/menu/Start_Button_UC.png"));
	Main_Menu->Image_Start_C = (IMG_Load("pkg/res/menu/Start_Button_C.png"));
	
	Main_Menu->Image_Multiplayer_UC = (IMG_Load("pkg/res/menu/Multiplayer_Button_UC.png"));
	Main_Menu->Image_Multiplayer_C = (IMG_Load("pkg/res/menu/Multiplayer_Button_C.png"));
	
	Main_Menu->Image_Settings_UC = (IMG_Load("pkg/res/menu/Settings_Button_UC.png"));
	Main_Menu->Image_Settings_C = (IMG_Load("pkg/res/menu/Settings_Button_C.png"));
	
	Main_Menu->Image_Quit_UC = (IMG_Load("pkg/res/menu/Quit_Button_UC.png"));
	Main_Menu->Image_Quit_C = (IMG_Load("pkg/res/menu/Quit_Button_C.png"));

	// Image pointer verification

	if( !(Main_Menu->Image_background_MM && Main_Menu->Image_Start_UC && Main_Menu->Image_Start_C &&
	   Main_Menu->Image_Multiplayer_UC && Main_Menu->Image_Multiplayer_C && Main_Menu->Image_Settings_UC &&
	   Main_Menu->Image_Settings_C && Main_Menu->Image_Quit_UC && Main_Menu->Image_Quit_C) )
		ClearMainMenu(Screen,Main_Menu);

	// Initialisation position bouton & bouton cliqué

	Main_Menu->Actual_Position=1;
	Main_Menu->Last_Position=0;	
	Main_Menu->Clicked_Button=0;
	Main_Menu->Compteur_Blit_Fond=0;
	Main_Menu->Quit_game=0;

}

////////////////////////////////////////

void ButtonBliting(SDL_Surface* Screen, SDL_Surface* UC_Image1, SDL_Rect* UC_Rect1, SDL_Surface* UC_Image2, SDL_Rect* UC_Rect2, SDL_Surface* UC_Image3, SDL_Rect* UC_Rect3, SDL_Surface* C_Image, SDL_Rect* C_Rect)
{
	SDL_BlitSurface(UC_Image1,NULL,Screen,UC_Rect1);
	SDL_BlitSurface(UC_Image2,NULL,Screen,UC_Rect2);
	SDL_BlitSurface(UC_Image3,NULL,Screen,UC_Rect3);
	SDL_BlitSurface(C_Image,NULL,Screen,C_Rect);
}

// A changer lors de review code 
// % Taille des boutons et positions

////////////////////////////////////////

void DrawButtonsMainMenu(SDL_Surface* Screen,MM* Main_Menu)
{
	// Visuel des boutons

	switch(Main_Menu->Actual_Position)
	{
		// Multiplayer selected
		case 2:
			if(Main_Menu->Last_Position!=2)
			{
				ButtonBliting(Screen, Main_Menu->Image_Start_UC, &(Main_Menu->Button1MM), Main_Menu->Image_Settings_UC, &(Main_Menu->Button3MM),Main_Menu->Image_Quit_UC, &(Main_Menu->Button4MM),
							  Main_Menu->Image_Multiplayer_C, &(Main_Menu->Button2MM) );

				Main_Menu->Last_Position=2;
			}
			break;

		// Settings menu selected
		case 3:

			if(Main_Menu->Last_Position!=3)
			{
				ButtonBliting(Screen, Main_Menu->Image_Start_UC, &(Main_Menu->Button1MM), Main_Menu->Image_Multiplayer_UC, &(Main_Menu->Button2MM), Main_Menu->Image_Quit_UC, &(Main_Menu->Button4MM),
							  Main_Menu->Image_Settings_C, &(Main_Menu->Button3MM) );

				Main_Menu->Last_Position=3;
			}
			break;

		// Quit menu selected
		case 4:
			if(Main_Menu->Last_Position!=4)
			{
				ButtonBliting(Screen, Main_Menu->Image_Start_UC, &(Main_Menu->Button1MM), Main_Menu->Image_Multiplayer_UC, &(Main_Menu->Button2MM), Main_Menu->Image_Settings_UC, &(Main_Menu->Button3MM),
							  Main_Menu->Image_Quit_C, &(Main_Menu->Button4MM) );

				Main_Menu->Last_Position=4;
			}
			break;

		// Start menu selected
		default:
			if(Main_Menu->Last_Position!=1)
			{
				ButtonBliting(Screen, Main_Menu->Image_Multiplayer_UC, &(Main_Menu->Button2MM), Main_Menu->Image_Settings_UC, &(Main_Menu->Button3MM), Main_Menu->Image_Quit_UC, &(Main_Menu->Button4MM),
							  Main_Menu->Image_Start_C, &(Main_Menu->Button1MM) );

				Main_Menu->Last_Position=1;
			}
			break;
	}
}

////////////////////////////////////////

void KeyboardEventMM(SDL_Event Event,MM* Main_Menu)
{
	// Verification Keyboard movement

	if( Event.key.keysym.sym == SDLK_UP && (Main_Menu->Actual_Position>1) )
		(Main_Menu->Actual_Position)--;

	else if( Event.key.keysym.sym == SDLK_DOWN && (Main_Menu->Actual_Position<4) )	
		(Main_Menu->Actual_Position)++;
}

////////////////////////////////////////

void MouseEventMM(SDL_Event Event,MM* Main_Menu)
{
	if(Event.motion.x>=686 && Event.motion.x<=1237)
	{
		if(Event.motion.y>=403 && Event.motion.y<=512)
		{
			// Initialisation bouton position

			Main_Menu->Actual_Position=1;

			// Test position curseur bouton 1

			if(Event.type == SDL_MOUSEBUTTONDOWN && Event.button.button == SDL_BUTTON_LEFT)
				Main_Menu->Clicked_Button=1;
		}

		else if(Event.motion.y>=550 && Event.motion.y<=659)
		{
			// Initialisation bouton position

			Main_Menu->Actual_Position=2;

			// Test position curseur bouton 2

			if(Event.type == SDL_MOUSEBUTTONDOWN && Event.button.button == SDL_BUTTON_LEFT)
				Main_Menu->Clicked_Button=1;
		}

		else if(Event.motion.y>=697 && Event.motion.y<=809)
		{
			// Initialisation bouton position

			Main_Menu->Actual_Position=3;

			// Test position curseur bouton 3

			if(Event.type == SDL_MOUSEBUTTONDOWN && Event.button.button == SDL_BUTTON_LEFT)
				Main_Menu->Clicked_Button=1;
		}

		else if(Event.motion.y>=844 && Event.motion.y<=953)
		{
			// Initialisation bouton position

			Main_Menu->Actual_Position=4;

			// Test position curseur bouton 4

			if(Event.type == SDL_MOUSEBUTTONDOWN && Event.button.button == SDL_BUTTON_LEFT)
				Main_Menu->Clicked_Button=1;
		}
	}

}

////////////////////////////////////////

void MainMenu(SDL_Surface* Screen,SDL_Event Event)
{
	// Quit loop verification

	int Quit_Loop=0;

	//Déclarer Structure Main Menu

	MM Main_Menu;

	// Initialisation Structure Main Menu

	InitialisationMM(Screen,&Main_Menu);

	// Main Menu Loop

	while(!Quit_Loop)
	{
		while(SDL_PollEvent(&Event))
		{
			if(Event.type==SDL_QUIT)
				ClearMainMenu(Screen,&Main_Menu);

			else
			{
				// Draw background

				if(Main_Menu.Compteur_Blit_Fond==0)
				{
					SDL_BlitSurface(Main_Menu.Image_background_MM,NULL,Screen,NULL);
					Main_Menu.Compteur_Blit_Fond=1;
				}
					
				// Check Main Menu position :: à mettre sous forme d'une seule fonction

				if(Event.type == SDL_KEYDOWN)
					KeyboardEventMM(Event,&Main_Menu);

				else if(Event.type==SDL_MOUSEMOTION || Event.type==SDL_MOUSEBUTTONDOWN)
					MouseEventMM(Event,&Main_Menu);

				// Draw Buttons

				DrawButtonsMainMenu(Screen,&Main_Menu);

				// Keyboard enter handling

				if( (Event.type == SDL_KEYDOWN && Event.key.keysym.sym == SDLK_SPACE) || Main_Menu.Clicked_Button==1)
				{
					switch(Main_Menu.Actual_Position)
					{
						case 1:
							StartMenu(Screen,Event,&(Main_Menu.Quit_game));				// ! memory leak

							if(Main_Menu.Quit_game)
								Quit_Loop=1;
							else
							{
								// Réinitialisation des paramètres
								Main_Menu.Clicked_Button=0;
								Main_Menu.Compteur_Blit_Fond=0;
								Main_Menu.Last_Position=0;
							}
							break;

						case 2:
							Main_Menu.Clicked_Button=0;
							//Multiplayer
							break;

						case 3:
							//Settings
							settings(&(Main_Menu.Quit_game));
							if(Main_Menu.Quit_game)
								Quit_Loop=1;
							else
							{
								// Réinitialisation des paramètres
								Main_Menu.Clicked_Button=0;
								Main_Menu.Compteur_Blit_Fond=0;
								Main_Menu.Last_Position=0;
							}
							break;

						case 4:
							QuitVerification(Screen,Event,&(Main_Menu.Quit_game));

							if(Main_Menu.Quit_game)
								Quit_Loop=1;
							else
							{
								// Réinitialisation des paramètres
								Main_Menu.Clicked_Button=0;
								Main_Menu.Compteur_Blit_Fond=0;
								Main_Menu.Last_Position=0;
							}
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

	// Clear Menu & Game
	ClearMainMenu(Screen,&Main_Menu);
}

////////////////////////////////////////

void ClearMainMenu(SDL_Surface* Screen,MM* Main_Menu)
{
	SDL_FreeSurface(Screen);
	SDL_FreeSurface(Main_Menu->Image_background_MM);
	SDL_FreeSurface(Main_Menu->Image_Start_UC);
	SDL_FreeSurface(Main_Menu->Image_Start_C);
	SDL_FreeSurface(Main_Menu->Image_Multiplayer_UC);
	SDL_FreeSurface(Main_Menu->Image_Multiplayer_C);
	SDL_FreeSurface(Main_Menu->Image_Settings_UC);
	SDL_FreeSurface(Main_Menu->Image_Settings_C);
	SDL_FreeSurface(Main_Menu->Image_Quit_UC);
	SDL_FreeSurface(Main_Menu->Image_Quit_C);
	IMG_Quit();
	SDL_Quit();
	exit(1);
}

////////////////////////////////////////