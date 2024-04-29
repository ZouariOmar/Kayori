#include "../inc/Start_Menu.h"

////////////////////////////////////////

void InitialisationSM(SM* Start_Menu,int* Quit_Game)
{
	// Music and Chunk

	Start_Menu->Chunk = Mix_LoadWAV("project/res/music/rac_menu_beep.wav");

	// Quit Button

	Start_Menu->Image_Quit_Button.pos.h=119;
	Start_Menu->Image_Quit_Button.pos.w=151;

	Start_Menu->Image_Quit_Button.pos.x=69;
	Start_Menu->Image_Quit_Button.pos.y=43;

	Start_Menu->Image_Quit_Button.UC_B = load_img("project/res/img_menu/UCReturn.png");
	Start_Menu->Image_Quit_Button.C_B = load_img("project/res/img_menu/CReturn.png");

	// Bouton save 1

	Start_Menu->Image_Save1.pos.h=204;
	Start_Menu->Image_Save1.pos.w=860;

	Start_Menu->Image_Save1.pos.x=510;
	Start_Menu->Image_Save1.pos.y=130;

	Start_Menu->Image_Save1.UC_B = load_img("project/res/img_start_menu/StartMenuNewGame.png");
	Start_Menu->Image_Save1.C_B = load_img("project/res/img_start_menu/StartMenuNewGame2.png");

	// Bouton save 2

	Start_Menu->Image_Save2.pos.h=204;
	Start_Menu->Image_Save2.pos.w=860;

	Start_Menu->Image_Save2.pos.x=510;
	Start_Menu->Image_Save2.pos.y=428;

	Start_Menu->Image_Save2.UC_B = load_img("project/res/img_start_menu/StartMenuNewGame.png");
	Start_Menu->Image_Save2.C_B = load_img("project/res/img_start_menu/StartMenuNewGame2.png");

	// Bouton save 3

	Start_Menu->Image_Save3.pos.h=204;
	Start_Menu->Image_Save3.pos.w=860;

	Start_Menu->Image_Save3.pos.x=510;
	Start_Menu->Image_Save3.pos.y=733;

	Start_Menu->Image_Save3.UC_B = load_img("project/res/img_start_menu/StartMenuNewGame.png");
	Start_Menu->Image_Save3.C_B = load_img("project/res/img_start_menu/StartMenuNewGame2.png");

	// Background image

	Start_Menu->Image_background_SM = load_img("project/res/img_start_menu/Start Menu.png");

	// Image pointer verification

	if(!(Start_Menu->Image_Save1.UC_B && Start_Menu->Image_Save1.C_B && Start_Menu->Image_Save2.UC_B &&
	   Start_Menu->Image_Save2.C_B && Start_Menu->Image_Save3.UC_B && Start_Menu->Image_Save3.C_B &&
	   Start_Menu->Image_Quit_Button.UC_B && Start_Menu->Image_Quit_Button.C_B && Start_Menu->Image_background_SM)) 
	{
		printf("Erreur allocation initialisation image\n");
		ClearStartMenu(Start_Menu);
		*Quit_Game=1;
	}

	// Position & Click

	Start_Menu->Actual_Position=2;
	Start_Menu->Last_Position=0;
	Start_Menu->Clicked_Button=0;

	// Blitting of the start menu

	// Draw background

	SDL_BlitSurface(Start_Menu->Image_background_SM,NULL,screen,NULL);
}

////////////////////////////////////////

void KeyboardEventSM(SM* Start_Menu)
{
	// Verification Keyboard movement

	if( event.key.keysym.sym == SDLK_UP && (Start_Menu->Actual_Position>1) )
		(Start_Menu->Actual_Position)--;

	else if( event.key.keysym.sym == SDLK_DOWN )
	{
		if(Start_Menu->Actual_Position<4)
			(Start_Menu->Actual_Position)++;
		else
			Start_Menu->Actual_Position=2;
	}	
}

////////////////////////////////////////

void MouseEventSM(SM* Start_Menu)
{
	if(event.motion.y>=43 && event.motion.y<=162 && event.motion.x>=69 && event.motion.x<=220)
	{
		// Initialisation bouton position

		Start_Menu->Actual_Position=1;

		// Test position curseur bouton 1

		if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
			Start_Menu->Clicked_Button=1;
	}

	else if(event.motion.x>=510 && event.motion.x<=1370)
	{
		if(event.motion.y>=130 && event.motion.y<=334)
		{
			// Initialisation bouton position

			Start_Menu->Actual_Position=2;

			// Test position curseur bouton 2

			if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
				Start_Menu->Clicked_Button=1;
		}

		else if(event.motion.y>=428 && event.motion.y<=632)
		{
			// Initialisation bouton position

			Start_Menu->Actual_Position=3;

			// Test position curseur bouton 3

			if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
				Start_Menu->Clicked_Button=1;
		}

		else if(event.motion.y>=733 && event.motion.y<=937)
		{
			// Initialisation bouton position

			Start_Menu->Actual_Position=4;

			// Test position curseur bouton 4

			if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
				Start_Menu->Clicked_Button=1;
		}
	}

}

////////////////////////////////////////

void MovementEventSM(SM* Start_Menu)
{
	if(event.type == SDL_KEYDOWN)
		KeyboardEventSM(Start_Menu);

	else if(event.type==SDL_MOUSEMOTION || event.type==SDL_MOUSEBUTTONDOWN)
		MouseEventSM(Start_Menu);
}

////////////////////////////////////////

void ButtonUpdate( SM* Start_Menu, SDL_Surface* UC_Image1, SDL_Rect* UC_Rect1, SDL_Surface* UC_Image2, SDL_Rect* UC_Rect2, SDL_Surface* UC_Image3, SDL_Rect* UC_Rect3, SDL_Surface* C_Image, SDL_Rect* C_Rect, Mix_Chunk* Chunk)
{
	// Reset the blitted surface
	SDL_BlitSurface(Start_Menu->Image_background_SM,&(Start_Menu->Image_Save1.pos),screen,&(Start_Menu->Image_Save1.pos));
	SDL_BlitSurface(Start_Menu->Image_background_SM,&(Start_Menu->Image_Save2.pos),screen,&(Start_Menu->Image_Save2.pos));
	SDL_BlitSurface(Start_Menu->Image_background_SM,&(Start_Menu->Image_Save3.pos),screen,&(Start_Menu->Image_Save3.pos));
	SDL_BlitSurface(Start_Menu->Image_background_SM,&(Start_Menu->Image_Quit_Button.pos),screen,&(Start_Menu->Image_Quit_Button.pos));

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

void UpdateButtonsStartMenu(SM* Start_Menu)
{
	// Visuel des boutons

	switch(Start_Menu->Actual_Position)
	{
		// Return button selected
		case 1:
			if(Start_Menu->Last_Position!=1)
			{
				ButtonUpdate(Start_Menu, Start_Menu->Image_Save1.UC_B, &(Start_Menu->Image_Save1.pos), Start_Menu->Image_Save2.UC_B, &(Start_Menu->Image_Save2.pos),
							  Start_Menu->Image_Save3.UC_B, &(Start_Menu->Image_Save3.pos), Start_Menu->Image_Quit_Button.C_B, &(Start_Menu->Image_Quit_Button.pos), Start_Menu->Chunk );

				Start_Menu->Last_Position=1;
			}
			break;

		// Save 2 selected
		case 3:
			if(Start_Menu->Last_Position!=3)
			{
				ButtonUpdate(Start_Menu, Start_Menu->Image_Save1.UC_B, &(Start_Menu->Image_Save1.pos), Start_Menu->Image_Save3.UC_B, &(Start_Menu->Image_Save3.pos),
							  Start_Menu->Image_Quit_Button.UC_B, &(Start_Menu->Image_Quit_Button.pos), Start_Menu->Image_Save2.C_B, &(Start_Menu->Image_Save2.pos), Start_Menu->Chunk );

				Start_Menu->Last_Position=3;
			}
			break;

		// Save 3 selected
		case 4:
			if(Start_Menu->Last_Position!=4)
			{
				ButtonUpdate(Start_Menu, Start_Menu->Image_Save1.UC_B, &(Start_Menu->Image_Save1.pos), Start_Menu->Image_Save2.UC_B, &(Start_Menu->Image_Save2.pos),
							  Start_Menu->Image_Quit_Button.UC_B, &(Start_Menu->Image_Quit_Button.pos), Start_Menu->Image_Save3.C_B, &(Start_Menu->Image_Save3.pos), Start_Menu->Chunk );

				Start_Menu->Last_Position=4;
			}
			break;

		// Save 1 selected ( default )
		default:
			if(Start_Menu->Last_Position!=2)
			{
				ButtonUpdate(Start_Menu, Start_Menu->Image_Save2.UC_B, &(Start_Menu->Image_Save2.pos), Start_Menu->Image_Save3.UC_B, &(Start_Menu->Image_Save3.pos),
							  Start_Menu->Image_Quit_Button.UC_B, &(Start_Menu->Image_Quit_Button.pos), Start_Menu->Image_Save1.C_B, &(Start_Menu->Image_Save1.pos), Start_Menu->Chunk );

				Start_Menu->Last_Position=2;
			}
			break;
	}
}

////////////////////////////////////////

void StartMenu(int* Quit_Game)
{
	// Quit loop verification

	int Quit_SM=0;

	// Création Start Menu

	SM Start_Menu;

	// Initialisation Start Menu && Blitting of the background

	InitialisationSM(&Start_Menu, Quit_Game);

	// If no error occured in the initialisation => Enter Start menu loop

	while(!Quit_SM && !(*Quit_Game))
	{
		while(SDL_PollEvent(&event))
		{
			// Check Main Menu position
						
			MovementEventSM(&Start_Menu);

			// Draw Buttons

			UpdateButtonsStartMenu(&Start_Menu);

			// If the quit cross is pressed
			
			if(event.type==SDL_QUIT)
			{
				Quit_SM=1;
				*Quit_Game=1;
			}
		
			// If a button is clicked/pressed

			else if(event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN)
			{
				// Return to main menu by pressing "ESCAPE"

				if(event.key.keysym.sym == SDLK_ESCAPE)
					Quit_SM=1;

				// Mouse click / Space button pressed
						
				else if( event.key.keysym.sym == SDLK_SPACE || Start_Menu.Clicked_Button )
				{
					switch(Start_Menu.Actual_Position)
					{
						case 1:
							//Return to main menu
							Quit_SM=1;
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
			}

			// Flip screen
			SDL_Flip(screen);
		}

		// Frame regulation
		SDL_Delay(6);
	}

	// Clear memory
	ClearStartMenu(&Start_Menu);
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
	Mix_FreeChunk(Start_Menu->Chunk);
}

////////////////////////////////////////