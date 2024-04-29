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
	// => Music and Chunk

	Main_Menu->Music = Mix_LoadMUS("project/res/music/PS2_ Red Screen of Death.mp3");

	Main_Menu->Chunk = Mix_LoadWAV("project/res/music/rac_menu_beep.wav");

	// => Buttons

	// Surface of the image

	Main_Menu->Blit_Buttons.x = 1081;
	Main_Menu->Blit_Buttons.y = 252;
	Main_Menu->Blit_Buttons.w = 549;
	Main_Menu->Blit_Buttons.h = 521;

	// Start button

	Main_Menu->Image_Start = load_img("project/res/img_main_menu/MainMenuStart.png");

	// Multiplayer button

	Main_Menu->Image_Multiplayer = load_img("project/res/img_main_menu/MainMenuMulti.png");

	// Settings button

	Main_Menu->Image_Settings = load_img("project/res/img_main_menu/MainMenuSettings.png");

	// Quit button

	Main_Menu->Image_Quit = load_img("project/res/img_main_menu/MainMenuQuit.png");

	// Initialisation background main menu

	Main_Menu->Image_background_MM = load_img("project/res/img_main_menu/MainMenu.png");


	// => Animation

	//  Surface of the animation

	Main_Menu->Blit_animation.x = 736;
	Main_Menu->Blit_animation.y = 1;
	Main_Menu->Blit_animation.w = 509;
	Main_Menu->Blit_animation.h = 330;

	// Images of the animation

	// Image 1

	Main_Menu->Animation1 = load_img("project/res/img_main_menu/Animation1.png");

	// Image 2

	Main_Menu->Animation2 = load_img("project/res/img_main_menu/Animation2.png");

	// Image pointer verification

	if( !(Main_Menu->Image_background_MM && Main_Menu->Image_Start && Main_Menu->Image_Multiplayer && Main_Menu->Image_Settings && Main_Menu->Image_Quit) )
		ClearMainMenu(Main_Menu);

	// => Initialisation button position & clicked button

	Main_Menu->Actual_Position=1;
	Main_Menu->Last_Position=0;	
	Main_Menu->Clicked_Button=0;

	// => Blitting of the main menu

	// Draw background
	SDL_BlitSurface(Main_Menu->Image_background_MM,NULL,screen,NULL);

	// Draw buttons
	UpdateButtonsMainMenu(Main_Menu);	

}

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
				SDL_BlitSurface(Main_Menu->Image_Multiplayer, NULL, screen, &(Main_Menu->Blit_Buttons));

				Main_Menu->Last_Position=2;
				
				// Play chunk
				Mix_PlayChannel(-1,Main_Menu->Chunk,0);
			}
			break;

		// Settings menu selected
		case 3:

			if(Main_Menu->Last_Position!=3)
			{
				SDL_BlitSurface(Main_Menu->Image_Settings, NULL, screen, &(Main_Menu->Blit_Buttons));

				Main_Menu->Last_Position=3;

				// Play chunk
				Mix_PlayChannel(-1,Main_Menu->Chunk,0);
			}
			break;

		// Quit menu selected
		case 4:
			if(Main_Menu->Last_Position!=4)
			{
				SDL_BlitSurface(Main_Menu->Image_Quit, NULL, screen, &(Main_Menu->Blit_Buttons));

				Main_Menu->Last_Position=4;

				// Play chunk
				Mix_PlayChannel(-1,Main_Menu->Chunk,0);
			}
			break;

		// Start menu selected
		default:
			if(Main_Menu->Last_Position!=1)
			{
				SDL_BlitSurface(Main_Menu->Image_Start, NULL, screen, &(Main_Menu->Blit_Buttons));

				Main_Menu->Last_Position=1;

				// Play chunk
				Mix_PlayChannel(-1,Main_Menu->Chunk,0);
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
	if(event.motion.x>=1081 && event.motion.x<=1630)
	{
		if(event.motion.y>=252 && event.motion.y<=341)
		{
			// Initialisation bouton position

			Main_Menu->Actual_Position=1;

			// Test position curseur bouton 1

			if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
				Main_Menu->Clicked_Button=1;
		}

		else if(event.motion.y>=365 && event.motion.y<=497)
		{
			// Initialisation bouton position

			Main_Menu->Actual_Position=2;

			// Test position curseur bouton 2

			if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
				Main_Menu->Clicked_Button=1;
		}

		else if(event.motion.y>=533 && event.motion.y<=642)
		{
			// Initialisation bouton position

			Main_Menu->Actual_Position=3;

			// Test position curseur bouton 3

			if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
				Main_Menu->Clicked_Button=1;
		}

		else if(event.motion.y>=692 && event.motion.y<=773)
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

void Animation(MM* Main_Menu, int* A)
{
	(*A)++;

	if(*A==1 || *A==55 || *A==70)
		SDL_BlitSurface(Main_Menu->Animation1,NULL,screen,&(Main_Menu->Blit_animation));

	else if(*A==45 || *A==65 || *A==80)
		SDL_BlitSurface(Main_Menu->Animation2,NULL,screen,&(Main_Menu->Blit_animation));

	else if(*A==110)
		*A=0;
}

////////////////////////////////////////

void MainMenu(void)
{
	// Quit loop verification

	int Quit_Loop=0, A=0;

	//Déclarer Structure Main Menu

	MM Main_Menu;

	// Initialisation Structure Main Menu && Blitting of the background

	InitialisationMM(&Main_Menu);

	// Play music

	Mix_PlayMusic(Main_Menu.Music,-1);

	// Main Menu Loop

	while(!Quit_Loop)
	{
		// Update animation

		Animation(&Main_Menu, &A);

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
							
							settings();
								
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
		}

		// Flip screen
		SDL_Flip(screen);

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
	SDL_FreeSurface(Main_Menu->Image_Start);
	SDL_FreeSurface(Main_Menu->Image_Multiplayer);
	SDL_FreeSurface(Main_Menu->Image_Settings);
	SDL_FreeSurface(Main_Menu->Image_Quit);
	SDL_FreeSurface(Main_Menu->Animation1);
	SDL_FreeSurface(Main_Menu->Animation2);
	Mix_FreeChunk(Main_Menu->Chunk);
}

////////////////////////////////////////