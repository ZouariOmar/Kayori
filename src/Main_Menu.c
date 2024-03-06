#include <stdio.h>
#include <SDL/SDL_image.h>
#include "..//inc//Main_Menu.h"
#include "..//inc//Structures_MM.h"
#include "Start_Menu.c"
#include "Quit_Verification.c"
#include "settings.c"

////////////////////////////////////////

void InitialisationMM(MM* Main_Menu)
{
	// Music and Chunk

	Main_Menu->Music = Mix_LoadMUS("pkg//music//PS2_ Red Screen of Death.mp3");

	Main_Menu->Chunk = Mix_LoadWAV("pkg//music//rac_menu_beep.wav");

	// Start button

	Main_Menu->Image_Start.pos.h=109;
	Main_Menu->Image_Start.pos.w=551;

	Main_Menu->Image_Start.pos.x=686;
	Main_Menu->Image_Start.pos.y=403;

	Main_Menu->Image_Start.UC_B = load_img("pkg//res//menu//US_Start.png");
	Main_Menu->Image_Start.C_B = load_img("pkg//res//menu//S_Start.png");

	// Multiplayer button

	Main_Menu->Image_Multiplayer.pos.h=109;
	Main_Menu->Image_Multiplayer.pos.w=551;

	Main_Menu->Image_Multiplayer.pos.x=686;
	Main_Menu->Image_Multiplayer.pos.y=550;

	Main_Menu->Image_Multiplayer.UC_B = load_img("pkg//res//menu//US_Multiplayer.png");
	Main_Menu->Image_Multiplayer.C_B = load_img("pkg//res//menu//S_Multiplayer.png");

	// Settings button

	Main_Menu->Image_Settings.pos.h=109;
	Main_Menu->Image_Settings.pos.w=551;

	Main_Menu->Image_Settings.pos.x=686;
	Main_Menu->Image_Settings.pos.y=697;

	Main_Menu->Image_Settings.UC_B = load_img("pkg//res//menu//US_Settings.png");
	Main_Menu->Image_Settings.C_B = load_img("pkg//res//menu//S_Settings.png");

	// Quit button

	Main_Menu->Image_Quit.pos.h=109;
	Main_Menu->Image_Quit.pos.w=551;

	Main_Menu->Image_Quit.pos.x=686;
	Main_Menu->Image_Quit.pos.y=844;

	Main_Menu->Image_Quit.UC_B = load_img("pkg//res//menu//US_Quit.png");
	Main_Menu->Image_Quit.C_B = load_img("pkg//res//menu//S_Quit.png");


	// Initialisation background main menu

	Main_Menu->Image_background_MM = load_img("pkg//res//menu//Background menu.png");

	// Image pointer verification

	if( !(Main_Menu->Image_background_MM && Main_Menu->Image_Start.UC_B && Main_Menu->Image_Start.C_B &&
	   Main_Menu->Image_Multiplayer.UC_B && Main_Menu->Image_Multiplayer.C_B && Main_Menu->Image_Settings.UC_B &&
	   Main_Menu->Image_Settings.C_B && Main_Menu->Image_Quit.UC_B && Main_Menu->Image_Quit.C_B) )
		ClearMainMenu(Main_Menu);

	// Initialisation button position & clicked button

	Main_Menu->Actual_Position=1;
	Main_Menu->Last_Position=0;	
	Main_Menu->Clicked_Button=0;

	// Blitting of the main menu

	// Draw background
	SDL_BlitSurface(Main_Menu->Image_background_MM,NULL,screen,NULL);

	// Draw buttons
	UpdateButtonsMainMenu(Main_Menu);	

}

////////////////////////////////////////

void ButtonUpdate( SDL_Surface* UC_Image1, SDL_Rect* UC_Rect1, SDL_Surface* UC_Image2, SDL_Rect* UC_Rect2, SDL_Surface* UC_Image3, SDL_Rect* UC_Rect3, SDL_Surface* C_Image, SDL_Rect* C_Rect, Mix_Chunk* Chunk)
{
	// Image blitting

	SDL_BlitSurface(UC_Image1,NULL,screen,UC_Rect1);
	SDL_BlitSurface(UC_Image2,NULL,screen,UC_Rect2);
	SDL_BlitSurface(UC_Image3,NULL,screen,UC_Rect3);
	SDL_BlitSurface(C_Image,NULL,screen,C_Rect);

	// Play chunk

	Mix_PlayChannel(-1,Chunk,0);
}

// A changer lors de review code 
// % Taille des boutons et positions

////////////////////////////////////////

void UpdateButtonsMainMenu(MM* Main_Menu)
{
	// Visuel des boutons

	switch(Main_Menu->Actual_Position)
	{
		// Multiplayer selected
		case 2:
			if(Main_Menu->Last_Position!=2)
			{
				ButtonUpdate(Main_Menu->Image_Start.UC_B, &(Main_Menu->Image_Start.pos), Main_Menu->Image_Settings.UC_B, &(Main_Menu->Image_Settings.pos),
							  Main_Menu->Image_Quit.UC_B, &(Main_Menu->Image_Quit.pos), Main_Menu->Image_Multiplayer.C_B, &(Main_Menu->Image_Multiplayer.pos), Main_Menu->Chunk );

				Main_Menu->Last_Position=2;
			}
			break;

		// Settings menu selected
		case 3:

			if(Main_Menu->Last_Position!=3)
			{
				ButtonUpdate(Main_Menu->Image_Start.UC_B, &(Main_Menu->Image_Start.pos), Main_Menu->Image_Multiplayer.UC_B, &(Main_Menu->Image_Multiplayer.pos),
							  Main_Menu->Image_Quit.UC_B, &(Main_Menu->Image_Quit.pos), Main_Menu->Image_Settings.C_B, &(Main_Menu->Image_Settings.pos), Main_Menu->Chunk );

				Main_Menu->Last_Position=3;
			}
			break;

		// Quit menu selected
		case 4:
			if(Main_Menu->Last_Position!=4)
			{
				ButtonUpdate(Main_Menu->Image_Start.UC_B, &(Main_Menu->Image_Start.pos), Main_Menu->Image_Multiplayer.UC_B, &(Main_Menu->Image_Multiplayer.pos),
							  Main_Menu->Image_Settings.UC_B, &(Main_Menu->Image_Settings.pos), Main_Menu->Image_Quit.C_B, &(Main_Menu->Image_Quit.pos), Main_Menu->Chunk );

				Main_Menu->Last_Position=4;
			}
			break;

		// Start menu selected
		default:
			if(Main_Menu->Last_Position!=1)
			{
				ButtonUpdate(Main_Menu->Image_Multiplayer.UC_B, &(Main_Menu->Image_Multiplayer.pos), Main_Menu->Image_Settings.UC_B, &(Main_Menu->Image_Settings.pos),
							  Main_Menu->Image_Quit.UC_B, &(Main_Menu->Image_Quit.pos), Main_Menu->Image_Start.C_B, &(Main_Menu->Image_Start.pos), Main_Menu->Chunk );

				Main_Menu->Last_Position=1;
			}
			break;
	}
}

////////////////////////////////////////

void KeyboardEventMM(MM* Main_Menu)
{
	// Verification Keyboard movement

	// If Key Up is pressed

	if(event.key.keysym.sym == SDLK_UP)
	{	
		if(Main_Menu->Actual_Position>1)
			Main_Menu->Actual_Position--;
		else
			Main_Menu->Actual_Position=4;
	}

	// If Key Down is pressed

	else if(event.key.keysym.sym == SDLK_DOWN)
	{
		if(Main_Menu->Actual_Position<4)
			Main_Menu->Actual_Position++;
		else
			Main_Menu->Actual_Position=1;
	}
}

////////////////////////////////////////

void MouseEventMM(MM* Main_Menu)
{
	if(event.motion.x>=686 && event.motion.x<=1237)
	{
		if(event.motion.y>=403 && event.motion.y<=512)
		{
			// Initialisation bouton position

			Main_Menu->Actual_Position=1;

			// Test position curseur bouton 1

			if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
				Main_Menu->Clicked_Button=1;
		}

		else if(event.motion.y>=550 && event.motion.y<=659)
		{
			// Initialisation bouton position

			Main_Menu->Actual_Position=2;

			// Test position curseur bouton 2

			if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
				Main_Menu->Clicked_Button=1;
		}

		else if(event.motion.y>=697 && event.motion.y<=809)
		{
			// Initialisation bouton position

			Main_Menu->Actual_Position=3;

			// Test position curseur bouton 3

			if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
				Main_Menu->Clicked_Button=1;
		}

		else if(event.motion.y>=844 && event.motion.y<=953)
		{
			// Initialisation bouton position

			Main_Menu->Actual_Position=4;

			// Test position curseur bouton 4

			if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
				Main_Menu->Clicked_Button=1;
		}
	}

}

////////////////////////////////////////

void MovementEventMM(MM* Main_Menu)
{
	if(event.type == SDL_KEYDOWN)
		KeyboardEventMM(Main_Menu);

	else if(event.type==SDL_MOUSEMOTION || event.type==SDL_MOUSEBUTTONDOWN)
		MouseEventMM(Main_Menu);
}

////////////////////////////////////////

void MainMenu(void)
{
	// Quit loop verification

	int Quit_Loop=0;

	//Déclarer Structure Main Menu

	MM Main_Menu;

	// Initialisation Structure Main Menu && Blitting of the background

	InitialisationMM(&Main_Menu);

	// Play music

	Mix_PlayMusic(Main_Menu.Music,-1);

	// Main Menu Loop

	while(!Quit_Loop)
	{
		while(SDL_PollEvent(&event))
		{
			// Checks Main Menu position

			MovementEventMM(&Main_Menu);

			// Updates buttons

			UpdateButtonsMainMenu(&Main_Menu);

			// If the quit cross is pressed

			if(event.type == SDL_QUIT)
				ClearMainMenu(&Main_Menu);

			// If a button is clicked/pressed

			else if( event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN )
			{
				// Press ESCAPE to enter "Quit verification"

				if(event.key.keysym.sym == SDLK_ESCAPE)
				{
					// Free Main menu
					ClearMainMenu(&Main_Menu);

					// Quit
					QuitVerification(&Quit_Loop);
											
					if(!Quit_Loop)
						InitialisationMM(&Main_Menu);
				}

				// Menu event handling

				else if( event.key.keysym.sym == SDLK_SPACE || Main_Menu.Clicked_Button )
				{
					// Free Main menu
					ClearMainMenu(&Main_Menu);

					switch(Main_Menu.Actual_Position)
					{
						// Start menu
						case 1:

							StartMenu(&Quit_Loop);
								
							break;

						// Multiplayer
						case 2:

							Main_Menu.Clicked_Button=0;

							break;

						// Settings
						case 3:
							
							settings(&Quit_Loop);
								
							break;

						// Quit
						case 4:

							QuitVerification(&Quit_Loop);

						default:
							break;
					}

					// Reainitialise Main menu if not quitting
					if(!Quit_Loop)
						InitialisationMM(&Main_Menu);
				}
			}

				// Flip screen
			SDL_Flip(screen);
		}

		//Frame regulation
		SDL_Delay(6);	
	}

	// Free Menu music
	Mix_FreeMusic(Main_Menu.Music);
}

////////////////////////////////////////

void ClearMainMenu(MM* Main_Menu)
{
	SDL_FreeSurface(Main_Menu->Image_background_MM);
	SDL_FreeSurface(Main_Menu->Image_Start.UC_B);
	SDL_FreeSurface(Main_Menu->Image_Start.C_B);
	SDL_FreeSurface(Main_Menu->Image_Multiplayer.UC_B);
	SDL_FreeSurface(Main_Menu->Image_Multiplayer.C_B);
	SDL_FreeSurface(Main_Menu->Image_Settings.UC_B);
	SDL_FreeSurface(Main_Menu->Image_Settings.C_B);
	SDL_FreeSurface(Main_Menu->Image_Quit.UC_B);
	SDL_FreeSurface(Main_Menu->Image_Quit.C_B);
	Mix_FreeChunk(Main_Menu->Chunk);
}

////////////////////////////////////////