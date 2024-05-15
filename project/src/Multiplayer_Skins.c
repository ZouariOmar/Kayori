#include "../inc/inc.h"
#include "Game.c"

////////////////////////////////////////

void InitialisationMPS(MPS* Skin,int* Quit_Game)
{
	// Music and Chunk
	
	Skin->Chunk = Mix_LoadWAV("project/res/music/rac_menu_beep.wav");

	//* load the @soundVolume
    Mix_VolumeChunk(Skin->Chunk, scanValue("project/doc/settings", 24));

    // Init Images

	// Background
	Skin->Background = load_img("project/res/img_Multiplayer_Skins/Multiplayer skins.png");
	
	// Arrows
	Skin->Img_RA = load_img("project/res/img_Multiplayer_Skins/Right arrow.png");
	Skin->Img_LA = load_img("project/res/img_Multiplayer_Skins/Left arrow.png");

	// Play
	Skin->Img_Play = load_img("project/res/img_Multiplayer_Skins/Play.png");

	// Return
	Skin->Img_Return = load_img("project/res/img_Multiplayer_Skins/Return arrow.png");

	// Skins
	Skin->Img_Skin1 = load_img("project/res/img_Multiplayer_Skins/Skin1.png");
	Skin->Img_Skin2 = load_img("project/res/img_Multiplayer_Skins/Skin2.png");
	Skin->Img_Skin3 = load_img("project/res/img_Multiplayer_Skins/Skin3.png");
	Skin->Img_Skin4 = load_img("project/res/img_Multiplayer_Skins/Skin4.png");

	// Init play rect
	Skin->Rect_Play.w = 170;
	Skin->Rect_Play.h = 105;
	Skin->Rect_Play.x = 877;
	Skin->Rect_Play.y = 948;

	// Init return arrow rect
	Skin->Rect_Return.w = 93;
	Skin->Rect_Return.h = 39;
	Skin->Rect_Return.x = 21;
	Skin->Rect_Return.y = 1031;

	// ====================== Player 1 ======================

	// Init skin choice
	Skin->P1.Skin_N=1;

	// Init Skin rect
	Skin->P1.Rect_Skin.w = 272;
	Skin->P1.Rect_Skin.h = 355;
	Skin->P1.Rect_Skin.x = 435;
	Skin->P1.Rect_Skin.y = 363;

	// Init arrows rect
	Skin->P1.Rect_RA.w = 30;
	Skin->P1.Rect_RA.h = 49;
	Skin->P1.Rect_RA.x = 780;
	Skin->P1.Rect_RA.y = 532;

	Skin->P1.Rect_LA.w = 30;
	Skin->P1.Rect_LA.h = 49;
	Skin->P1.Rect_LA.x = 343;
	Skin->P1.Rect_LA.y = 532;

	// Init position & click
	Skin->P1.Click_Right=0;
	Skin->P1.Click_Left=0;

	// ====================== Player 2 ======================

	// Init skin choice
	Skin->P2.Skin_N=1;

	// Init Skin rect
	Skin->P2.Rect_Skin.w = 272;
	Skin->P2.Rect_Skin.h = 355;
	Skin->P2.Rect_Skin.x = 1219;
	Skin->P2.Rect_Skin.y = 363;

	// Init arrows rect
	Skin->P2.Rect_RA.w = 30;
	Skin->P2.Rect_RA.h = 49;
	Skin->P2.Rect_RA.x = 1560;
	Skin->P2.Rect_RA.y = 532;

	Skin->P2.Rect_LA.w = 30;
	Skin->P2.Rect_LA.h = 49;
	Skin->P2.Rect_LA.x = 1123;
	Skin->P2.Rect_LA.y = 532;

	// Init position & click
	Skin->P2.Click_Right=0;
	Skin->P2.Click_Left=0;

	// Image pointer verification

	
	if( !(Skin->Background && Skin->Img_RA && Skin->Img_LA) )
	{
		printf("Erreur allocation initialisation image\n");
		ClearMPS(Skin);
		*Quit_Game=1;
	}

	// Init Player position && click
	Skin->Actual_Position=1;
	Skin->Last_Position=0;
	Skin->Clicked_Button=0;

	// Init default images
	SDL_BlitSurface(Skin->Background,NULL,screen,NULL);
	SDL_BlitSurface(Skin->Img_Skin1,NULL,screen,&(Skin->P1.Rect_Skin));
	SDL_BlitSurface(Skin->Img_Skin1,NULL,screen,&(Skin->P2.Rect_Skin));
}

////////////////////////////////////////

void UpdateButtonsMPS(MPS* Skin)
{
	// Visuel des boutons

	switch(Skin->Actual_Position)
	{
		case 2:
			if(Skin->Last_Position!=2)
			{
				SDL_BlitSurface(Skin->Img_Play,NULL,screen,&(Skin->Rect_Play));
				SDL_BlitSurface(Skin->Background,&(Skin->Rect_Return),screen,&(Skin->Rect_Return));
				SDL_BlitSurface(Skin->Background,&(Skin->P1.Rect_RA),screen,&(Skin->P1.Rect_RA));
				SDL_BlitSurface(Skin->Background,&(Skin->P1.Rect_LA),screen,&(Skin->P1.Rect_LA));

				Mix_PlayChannel(-1,Skin->Chunk,0);

				Skin->Last_Position=2;
			}
			break;

		case 3:
			if(Skin->Last_Position!=3)
			{
				SDL_BlitSurface(Skin->Img_Return,NULL,screen,&(Skin->Rect_Return));
				SDL_BlitSurface(Skin->Background,&(Skin->Rect_Play),screen,&(Skin->Rect_Play));
				SDL_BlitSurface(Skin->Background,&(Skin->P1.Rect_RA),screen,&(Skin->P1.Rect_RA));
				SDL_BlitSurface(Skin->Background,&(Skin->P1.Rect_LA),screen,&(Skin->P1.Rect_LA));

				Mix_PlayChannel(-1,Skin->Chunk,0);

				Skin->Last_Position=3;
			}
			break;

		default:
			if(Skin->Last_Position!=1)
			{
				SDL_BlitSurface(Skin->Background,&(Skin->Rect_Play),screen,&(Skin->Rect_Play));
				SDL_BlitSurface(Skin->Background,&(Skin->Rect_Return),screen,&(Skin->Rect_Return));

				Skin->Last_Position=1;
			}
			break;
	}
}

////////////////////////////////////////

void UpdateSkinsMPS(MPS* Skin, SC* P)
{
	SDL_BlitSurface(Skin->Background,&(P->Rect_RA),screen,&(P->Rect_RA));
	SDL_BlitSurface(Skin->Background,&(P->Rect_LA),screen,&(P->Rect_LA));

	if(P->Click_Right || P->Click_Left)
	{
		// Arrows

		// Right arrow
		if(P->Click_Right)
		{
			SDL_BlitSurface(Skin->Img_RA,NULL,screen,&(P->Rect_RA));
			P->Click_Right = 0;
		}

		// Left arrow
		if(P->Click_Left)
		{
			SDL_BlitSurface(Skin->Img_LA,NULL,screen,&(P->Rect_LA));
			P->Click_Left = 0;
		}

		// Skin
		switch(P->Skin_N)
		{
			case 1:
				SDL_BlitSurface(Skin->Img_Skin1,NULL,screen,&(P->Rect_Skin));
				break;

			case 2:
				SDL_BlitSurface(Skin->Img_Skin2,NULL,screen,&(P->Rect_Skin));
				break;

			case 3:
				SDL_BlitSurface(Skin->Img_Skin3,NULL,screen,&(P->Rect_Skin));
				break;

			case 4:
				SDL_BlitSurface(Skin->Img_Skin4,NULL,screen,&(P->Rect_Skin));
				break;
		}
	}
}

////////////////////////////////////////

void KeyboardEventMPS(MPS* Skin)
{
	// Verification Keyboard movement

	//
	if( event.key.keysym.sym == SDLK_DOWN && (Skin->Actual_Position<3) )
		 (Skin->Actual_Position)++;

	else if( event.key.keysym.sym == SDLK_UP && (Skin->Actual_Position>1) )
		(Skin->Actual_Position)--;

	else if( event.key.keysym.sym == SDLK_RIGHT )
	{
		if(Skin->Actual_Position == 1)
		{
			Skin->P1.Click_Right = 1;

			if(Skin->P1.Skin_N == 4)
				Skin->P1.Skin_N = 1;
			
			else
				Skin->P1.Skin_N++;
		}
	}

	else if( event.key.keysym.sym == SDLK_LEFT )
	{
		if(Skin->Actual_Position == 1)
		{
			Skin->P1.Click_Left = 1;

			if(Skin->P1.Skin_N == 1)
				Skin->P1.Skin_N = 4;
			
			else
				Skin->P1.Skin_N--;
		}
	}


	//
	else if( event.key.keysym.sym == SDLK_d )
	{
		Skin->P2.Click_Right = 1;

		if(Skin->P2.Skin_N == 4)
			Skin->P2.Skin_N = 1;
			
		else
			Skin->P2.Skin_N++;
	}

	else if( event.key.keysym.sym == SDLK_q )
	{

		Skin->P2.Click_Left = 1;

		if(Skin->P2.Skin_N == 1)
			Skin->P2.Skin_N = 4;
			
		else
			Skin->P2.Skin_N--;
	}

}

////////////////////////////////////////

void MouseEventMPS(MPS* Skin)
{
	if( (event.motion.y >= Skin->P1.Rect_LA.y) && (event.motion.y <= Skin->P1.Rect_LA.y + Skin->P1.Rect_LA.h) )
	{
		// P1 left arrow
		if( (event.motion.x >= Skin->P1.Rect_LA.x) && (event.motion.x <= Skin->P1.Rect_LA.x + Skin->P1.Rect_LA.w) )
		{
			// Initialisation bouton position
			Skin->Actual_Position=1;

			// Test position curseur bouton 1

			if(event.button.button == SDL_BUTTON_LEFT)
			{
				Skin->P1.Click_Left = 1;

				if(Skin->P1.Skin_N == 1)
					Skin->P1.Skin_N = 4;
				
				else
					Skin->P1.Skin_N--;
			}
		}

		// P1 right arrow
		else if( (event.motion.x >= Skin->P1.Rect_RA.x) && (event.motion.x <= Skin->P1.Rect_RA.x + Skin->P1.Rect_RA.w) )
		{
			// Initialisation bouton position
			Skin->Actual_Position=1;

			// Test position curseur bouton 1

			if(event.button.button == SDL_BUTTON_LEFT)
			{
				Skin->P1.Click_Right = 1;

				if(Skin->P1.Skin_N == 4)
					Skin->P1.Skin_N = 1;
				
				else
					Skin->P1.Skin_N++;
			}
		}

		// P2 left arrow
		else if( (event.motion.x >= Skin->P2.Rect_LA.x) && (event.motion.x <= Skin->P2.Rect_LA.x + Skin->P2.Rect_LA.w) )
		{
			// Initialisation bouton position
			Skin->Actual_Position=1;

			// Test position curseur bouton 1

			if(event.button.button == SDL_BUTTON_LEFT)
			{
				Skin->P2.Click_Left = 1;

				if(Skin->P2.Skin_N == 1)
					Skin->P2.Skin_N = 4;
				
				else
					Skin->P2.Skin_N--;
			}
		}

		// P2 right arrow
		else if( (event.motion.x >= Skin->P2.Rect_RA.x) && (event.motion.x <= Skin->P2.Rect_RA.x + Skin->P2.Rect_RA.w) )
		{
			// Initialisation bouton position
			Skin->Actual_Position=1;

			// Test position curseur bouton 1

			if(event.button.button == SDL_BUTTON_LEFT)
			{
				Skin->P2.Click_Right = 1;

				if(Skin->P2.Skin_N == 4)
					Skin->P2.Skin_N = 1;
				
				else
					Skin->P2.Skin_N++;
			}
		}

	}

	else if( (event.motion.y >= Skin->Rect_Play.y) && (event.motion.y <= Skin->Rect_Play.y + Skin->Rect_Play.h) )
	{
		if( (event.motion.x >= Skin->Rect_Play.x) && (event.motion.x <= Skin->Rect_Play.x + Skin->Rect_Play.w) )
		{
			// Initialisation bouton position
			Skin->Actual_Position=2;

			// Test position curseur bouton 2

			if(event.button.button == SDL_BUTTON_LEFT)
				Skin->Clicked_Button=1;
		}
	}

	else if( (event.motion.y >= Skin->Rect_Return.y) && (event.motion.y <= Skin->Rect_Return.y + Skin->Rect_Return.h) )
	{
		if( (event.motion.x >= Skin->Rect_Return.x) && (event.motion.x <= Skin->Rect_Return.x + Skin->Rect_Return.w) )
		{
			// Initialisation bouton position
			Skin->Actual_Position=3;

			// Test position curseur bouton 2

			if(event.button.button == SDL_BUTTON_LEFT)
				Skin->Clicked_Button=1;
		}
	}

}

////////////////////////////////////////

void MovementEventMPS(MPS* Skin)
{
	// Check keyboar
	if(event.type == SDL_KEYDOWN)
		KeyboardEventMPS(Skin);

	else if(event.type==SDL_MOUSEMOTION || event.type==SDL_MOUSEBUTTONDOWN)
		MouseEventMPS(Skin);
}

////////////////////////////////////////

void MenuMPS(int* Quit_Game)
{
	// Quit loop verification

	int Quit=0;

	// Création Quit

	MPS Skin;

	// Initialisation Start Menu

	InitialisationMPS(&Skin,Quit_Game);

	// If no error occured in the initialisation => Enter Quit Verification loop

	while(!Quit && !(*Quit_Game))
	{
		while(SDL_PollEvent(&event))
		{
			// Check Main Menu position

			MovementEventMPS(&Skin);

			// Draw Buttons

			UpdateButtonsMPS(&Skin);

			// Update skins

			UpdateSkinsMPS(&Skin,&(Skin.P1));
			UpdateSkinsMPS(&Skin,&(Skin.P2));

			// If the quit cross is pressed

			if(event.type == SDL_QUIT)
			{
				Quit=1;
				*Quit_Game=1;
			}

			// Return to main menu by pressing "ESCAPE"

			else if(event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN )
			{
				// Return to main menu by pressing "ESCAPE"

				if(event.key.keysym.sym == SDLK_ESCAPE)
					Quit=1;
					
				// Mouse click / Space button pressed

				else if( event.key.keysym.sym == SDLK_SPACE || Skin.Clicked_Button )
				{
					switch(Skin.Actual_Position)
					{
						case 2:
							// Multi function
							Multiplayer();

							// Init default images
							SDL_BlitSurface(Skin.Background,NULL,screen,NULL);
							SDL_BlitSurface(Skin.Img_Skin1,NULL,screen,&(Skin.P1.Rect_Skin));
							SDL_BlitSurface(Skin.Img_Skin1,NULL,screen,&(Skin.P2.Rect_Skin));
							break;

						case 3:
							Quit=1;
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
	ClearMPS(&Skin);
}

////////////////////////////////////////

void ClearMPS(MPS* Skin)
{
	SDL_FreeSurface(Skin->Background);
	SDL_FreeSurface(Skin->Img_RA);
	SDL_FreeSurface(Skin->Img_LA);
	SDL_FreeSurface(Skin->Img_Play);
	SDL_FreeSurface(Skin->Img_Return);
	SDL_FreeSurface(Skin->Img_Skin1);
	SDL_FreeSurface(Skin->Img_Skin2);
	SDL_FreeSurface(Skin->Img_Skin3);
	SDL_FreeSurface(Skin->Img_Skin4);
	Mix_FreeChunk(Skin->Chunk);
}

////////////////////////////////////////