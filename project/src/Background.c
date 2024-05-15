#include "../inc/inc.h"
#include "Pause.c"
#include "tic_tac_toe.c"
#include "enigma.c"

///////////////////////////////////

void InitFramesSP(BGC* BG_Camera, int* Quit)
{
	int i=0;

	// Rect frame

	BG_Camera->P1.Frame_Blit.w = 180;
	BG_Camera->P1.Frame_Blit.h = 249;
	BG_Camera->P1.Frame_Blit.x = 0;
	BG_Camera->P1.Frame_Blit.y = 0;

	BG_Camera->P1.Pos_Frame = 0;

	// Standing frames
	loadGameResources(BG_Camera->P1.Frames.Standing,"project//res//PNG frames//Default Skin//Default frames//",1,2);

	// Run frames

	// Left
	loadGameResources(BG_Camera->P1.Frames.Run_Left,"project//res//PNG frames//Default Skin//Run frames//Left run//",1,8);

	// Right
	loadGameResources(BG_Camera->P1.Frames.Run_Right,"project//res//PNG frames//Default Skin//Run frames//Right run//",1,8);

	// Jump frames

	// Left jump
	BG_Camera->P1.Frames.Jump_Left = load_img("project//res//PNG frames//Default Skin//Jump//Left frames//3.png");

	// Left
	BG_Camera->P1.Frames.Jump_Right = load_img("project//res//PNG frames//Default Skin//Jump//Right frames//3.png");

	// Dash frames
	loadGameResources(BG_Camera->P1.Frames.Dash,"project//res//PNG frames//Default Skin//Dash//",1,10);
	
	// Wall friction
	loadGameResources(BG_Camera->P1.Frames.Wall_Friction,"project//res//PNG frames//Default Skin//Wall friction//",1,2);


	// Check frame ressources

	// Standing
	while(i<2 && !(*Quit))
	{
		if(!(BG_Camera->P1.Frames.Standing[i]))
			*Quit = 1;
		i++;
	}

	// Wall friction
	i=0;
	while(i<2 && !(*Quit))
	{
		if(!(BG_Camera->P1.Frames.Wall_Friction[i]))
			*Quit = 1;
		i++;
	}


	// Run
	i=0;
	while(i<8 && !(*Quit))
	{
		if(!(BG_Camera->P1.Frames.Run_Left[i]))
			*Quit = 1;
		i++;
	}

	i=0;
	while(i<8 && !(*Quit))
	{
		if(!(BG_Camera->P1.Frames.Run_Right[i]))
			*Quit = 1;
		i++;
	}

	// Jump
	if(!(BG_Camera->P1.Frames.Jump_Left && BG_Camera->P1.Frames.Jump_Right))
		*Quit = 1;

	// Dash
	i=0;
	while(i<10 && !(*Quit))
	{
		if(!(BG_Camera->P1.Frames.Dash[i]))
			*Quit = 1;
		i++;
	}
}

///////////////////////////////////

void InitFramesMP(BGC* BG_Camera, int* Quit)
{
	int i=0;

	// ================================= Player 1 ======================================

	// Rect frame

	BG_Camera->P1.Frame_Blit.w = 180;
	BG_Camera->P1.Frame_Blit.h = 249;
	BG_Camera->P1.Frame_Blit.x = 0;
	BG_Camera->P1.Frame_Blit.y = 0;

	BG_Camera->P1.Pos_Frame = 0;

	// Standing frames
	loadGameResources(BG_Camera->P1.Frames.Standing,"project//res//PNG frames//Default Skin//Default frames//",1,2);

	// Run frames

	// Left
	loadGameResources(BG_Camera->P1.Frames.Run_Left,"project//res//PNG frames//Default Skin//Run frames//Left run//",1,8);

	// Right
	loadGameResources(BG_Camera->P1.Frames.Run_Right,"project//res//PNG frames//Default Skin//Run frames//Right run//",1,8);

	// Jump frames

	// Left jump
	BG_Camera->P1.Frames.Jump_Left = load_img("project//res//PNG frames//Default Skin//Jump//Left frames//3.png");

	// Left
	BG_Camera->P1.Frames.Jump_Right = load_img("project//res//PNG frames//Default Skin//Jump//Right frames//3.png");

	// Dash frames
	loadGameResources(BG_Camera->P1.Frames.Dash,"project//res//PNG frames//Default Skin//Dash//",1,10);
	
	// Wall friction
	loadGameResources(BG_Camera->P1.Frames.Wall_Friction,"project//res//PNG frames//Default Skin//Wall friction//",1,2);

	// ================================= Player 2 ======================================

	// Rect frame

	BG_Camera->P2.Frame_Blit.w = 180;
	BG_Camera->P2.Frame_Blit.h = 249;
	BG_Camera->P2.Frame_Blit.x = 0;
	BG_Camera->P2.Frame_Blit.y = 0;

	BG_Camera->P2.Pos_Frame = 0;

	// Standing frames
	loadGameResources(BG_Camera->P2.Frames.Standing,"project//res//PNG frames//Default Skin//Default frames//",1,2);

	// Run frames

	// Left
	loadGameResources(BG_Camera->P2.Frames.Run_Left,"project//res//PNG frames//Default Skin//Run frames//Left run//",1,8);

	// Right
	loadGameResources(BG_Camera->P2.Frames.Run_Right,"project//res//PNG frames//Default Skin//Run frames//Right run//",1,8);

	// Jump frames

	// Left jump
	BG_Camera->P2.Frames.Jump_Left = load_img("project//res//PNG frames//Default Skin//Jump//Left frames//3.png");

	// Left
	BG_Camera->P2.Frames.Jump_Right = load_img("project//res//PNG frames//Default Skin//Jump//Right frames//3.png");

	// Dash frames
	loadGameResources(BG_Camera->P2.Frames.Dash,"project//res//PNG frames//Default Skin//Dash//",1,10);
	
	// Wall friction
	loadGameResources(BG_Camera->P2.Frames.Wall_Friction,"project//res//PNG frames//Default Skin//Wall friction//",1,2);


	// Check frame ressources

	// Standing
	while(i<2 && !(*Quit))
	{
		if(!(BG_Camera->P1.Frames.Standing[i] && BG_Camera->P2.Frames.Standing[i]))
			*Quit = 1;
		i++;
	}

	// Wall friction
	i=0;
	while(i<2 && !(*Quit))
	{
		if(!(BG_Camera->P1.Frames.Wall_Friction[i] && BG_Camera->P2.Frames.Wall_Friction[i]))
			*Quit = 1;
		i++;
	}


	// Run
	i=0;
	while(i<8 && !(*Quit))
	{
		if(!(BG_Camera->P1.Frames.Run_Left[i] && BG_Camera->P2.Frames.Run_Left[i]))
			*Quit = 1;
		i++;
	}

	i=0;
	while(i<8 && !(*Quit))
	{
		if(!(BG_Camera->P1.Frames.Run_Right[i] && BG_Camera->P2.Frames.Run_Right[i]))
			*Quit = 1;
		i++;
	}

	// Jump
	if(!(BG_Camera->P1.Frames.Jump_Left && BG_Camera->P2.Frames.Jump_Left && BG_Camera->P1.Frames.Jump_Right && BG_Camera->P2.Frames.Jump_Right))
		*Quit = 1;

	// Dash
	i=0;
	while(i<10 && !(*Quit))
	{
		if(!(BG_Camera->P1.Frames.Dash[i] && BG_Camera->P2.Frames.Dash[i]))
			*Quit = 1;
		i++;
	}
}

///////////////////////////////////

void InitBackgroundSP(BGC* BG_Camera, int* Quit)
{
	// ------------------------- Will be initialised according to the level -------------------------
	/* 
	   NOTE :: Créer deux nouvelles variables d'entrer de type int :
			 - Selon la valeur de la variable int on initialise une mini map différente (1,2,3,4,...)
			 - Lire d'après un fichier l'hauteur et la largeur du background
	*/

	// Chargement image
	BG_Camera->Chargement = load_img("pkg//Testlevel//Chargement.png");

	// Init character health images
	BG_Camera->No_Hit = load_img("pkg//Testlevel//FH.png");
	BG_Camera->Hit_1 = load_img("pkg//Testlevel//1 hit.png");
	BG_Camera->Hit_2 = load_img("pkg//Testlevel//2 hit.png");
	BG_Camera->Hit_3 = load_img("pkg//Testlevel//3 hit.png");
	BG_Camera->Hit_4 = load_img("pkg//Testlevel//4 hit.png");
	BG_Camera->Hit_5 = load_img("pkg//Testlevel//5 hit.png");

	// Number of players
	BG_Camera->Number_P = 1;

	// Initialisation character frames
	InitFramesSP(BG_Camera,Quit);

	// Check if the images have been loaded
	if(!(BG_Camera->Normal_bg && BG_Camera->Dynamic_bg && BG_Camera->Dynamic_2 && BG_Camera->Chargement))
	{
		printf("ERREUR : Probleme d'allocation memoire des images de background\n");
		*Quit = 1;
	}

	// Initialisation of the camera ( Solo mode )
	BG_Camera->Camera.w = 1920;
	BG_Camera->Camera.h = 1080;
	BG_Camera->Camera.x = 0;
	BG_Camera->Camera.y = 0;
}

///////////////////////////////////

void InitBackgroundMP(BGC* BG_Camera, int* Quit)
{
	// ------------------------- Will be initialised according to the level -------------------------
	/* 
	   NOTE :: Créer deux nouvelles variables d'entrer de type int :
			 - Selon la valeur de la variable int on initialise une mini map différente (1,2,3,4,...)
			 - Lire d'après un fichier l'hauteur et la largeur du background
	*/

	// Chargement image
	BG_Camera->Chargement = load_img("pkg//Testlevel//Chargement.png");

	// Init character health images
	BG_Camera->No_Hit = NULL;
	BG_Camera->Hit_1 = NULL;
	BG_Camera->Hit_2 = NULL;
	BG_Camera->Hit_3 = NULL;
	BG_Camera->Hit_4 = NULL;
	BG_Camera->Hit_5 = NULL;

	// Number of players
	BG_Camera->Number_P = 2;

	// Initialisation characters frames	
	InitFramesMP(BG_Camera,Quit);

	// ----------------------------------------------------------------------------------------------

	// Check if the images have been loaded
	if(!(BG_Camera->Normal_bg && BG_Camera->Dynamic_bg && BG_Camera->Chargement))
	{
		printf("ERREUR : Probleme d'allocation memoire des images de background\n");
		*Quit = 1;
	}

	// Player 1

	// Camera player 1
	BG_Camera->Camera1.w = 1920;
	BG_Camera->Camera1.h = 540;
	BG_Camera->Camera1.x = 0;
	BG_Camera->Camera1.y = 0;

	// Player 2

	// Camera player 2
	BG_Camera->Camera2.w = 1920;
	BG_Camera->Camera2.h = 540;
	BG_Camera->Camera2.x = 0;
	BG_Camera->Camera2.y = 0;

	// Position blit camera player 2
	BG_Camera->Position_BC_P2.x = 0;
	BG_Camera->Position_BC_P2.y = 540;
}

///////////////////////////////////

void CheckCameraPosition(SDL_Rect* Camera, SM* P, int WBG, int HBG)
{
	// NOTE : DOIT BOUGER SI LE PERSONNAGE DÉPASSE LE CENTRE

	// Update position
	Camera->x = ( P->A_Pos.x + P->A_Pos.w / 2 ) - Camera->w / 2;
    Camera->y = ( P->A_Pos.y + P->A_Pos.h / 2 ) - Camera->h / 2;

	// Check camera position in the background

	// Check the X axis
	if(Camera->x < 0)
		Camera->x = 0;

	else if(Camera->x + Camera->w > WBG)
		Camera->x =  WBG - Camera->w;

	// Check the Y axis
	if(Camera->y < 0)
		Camera->y = 0;

	else if(Camera->y + Camera->h > HBG)
		Camera->y =  HBG - Camera->h;
}

///////////////////////////////////

void CharacterHealth(BGC* BG_Camera, SM* P)
{
	if(P->N_Death == 0)
		SDL_BlitSurface(BG_Camera->No_Hit,NULL,screen,NULL);
	else if(P->N_Death == 1)
		SDL_BlitSurface(BG_Camera->Hit_1,NULL,screen,NULL);
	else if(P->N_Death == 2)
		SDL_BlitSurface(BG_Camera->Hit_2,NULL,screen,NULL);
	else if(P->N_Death == 3)
		SDL_BlitSurface(BG_Camera->Hit_3,NULL,screen,NULL);
	else if(P->N_Death == 4)
		SDL_BlitSurface(BG_Camera->Hit_4,NULL,screen,NULL);
	else if(P->N_Death == 5)
		SDL_BlitSurface(BG_Camera->Hit_5,NULL,screen,NULL);
}

///////////////////////////////////

void CharacterFrame(BGC* BG_Camera, PF* FP, SM* P)
{
	// Update position rect frame blit
	FP->Frame_Blit.x = ( P->A_Pos.x + P->A_Pos.w / 2 ) - FP->Frame_Blit.w / 2;
    FP->Frame_Blit.y = ( P->A_Pos.y + P->A_Pos.h / 2 ) - 20 - FP->Frame_Blit.h / 2;

	if(P->Dash_Distance)
	{
		switch(P->Dash_Direction)
		{
			case 1:
				SDL_BlitSurface(FP->Frames.Dash[5], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
				break;

			case 2:
				SDL_BlitSurface(FP->Frames.Dash[7], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
				break;

			case 3:
				SDL_BlitSurface(FP->Frames.Dash[2], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
				break;

			case 4:
				SDL_BlitSurface(FP->Frames.Dash[0], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
				break;

			case 5:
				if(P->Default_DD==1)
					SDL_BlitSurface(FP->Frames.Dash[4], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));

				else
					SDL_BlitSurface(FP->Frames.Dash[3], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
				
				break;

			case 6:
				SDL_BlitSurface(FP->Frames.Dash[6], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
				break;

			case 7:
				if(P->Default_DD==1)
					SDL_BlitSurface(FP->Frames.Dash[8], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));

				else
					SDL_BlitSurface(FP->Frames.Dash[9], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
				break;

			case 8:
				SDL_BlitSurface(FP->Frames.Dash[1], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
				break;
		}
	}

	else if(P->Grounded != -1)
	{
		if(P->Move_Right)
		{
			if(FP->Pos_Frame <= 7)
				SDL_BlitSurface(FP->Frames.Run_Right[0], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
			else if(FP->Pos_Frame <= 14)
				SDL_BlitSurface(FP->Frames.Run_Right[1], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
			else if(FP->Pos_Frame <= 21)
				SDL_BlitSurface(FP->Frames.Run_Right[2], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
			else if(FP->Pos_Frame <= 28)
				SDL_BlitSurface(FP->Frames.Run_Right[3], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
			else if(FP->Pos_Frame <= 35)
				SDL_BlitSurface(FP->Frames.Run_Right[4], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
			else if(FP->Pos_Frame <= 42)
				SDL_BlitSurface(FP->Frames.Run_Right[5], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
			else if(FP->Pos_Frame <= 49)
				SDL_BlitSurface(FP->Frames.Run_Right[6], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
			else if(FP->Pos_Frame <= 56)
				SDL_BlitSurface(FP->Frames.Run_Right[7], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));

			if(FP->Pos_Frame == 56)
				FP->Pos_Frame = 0;
			
			else
				FP->Pos_Frame++;

		}

		else if(P->Move_Left)
		{
			if(FP->Pos_Frame <= 7)
				SDL_BlitSurface(FP->Frames.Run_Left[0], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
			else if(FP->Pos_Frame <= 14)
				SDL_BlitSurface(FP->Frames.Run_Left[1], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
			else if(FP->Pos_Frame <= 21)
				SDL_BlitSurface(FP->Frames.Run_Left[2], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
			else if(FP->Pos_Frame <= 28)
				SDL_BlitSurface(FP->Frames.Run_Left[3], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
			else if(FP->Pos_Frame <= 35)
				SDL_BlitSurface(FP->Frames.Run_Left[4], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
			else if(FP->Pos_Frame <= 42)
				SDL_BlitSurface(FP->Frames.Run_Left[5], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
			else if(FP->Pos_Frame <= 49)
				SDL_BlitSurface(FP->Frames.Run_Left[6], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
			else if(FP->Pos_Frame <= 56)
				SDL_BlitSurface(FP->Frames.Run_Left[7], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));

			if(FP->Pos_Frame == 56)
				FP->Pos_Frame = 0;
			
			else
				FP->Pos_Frame++;
		}

		else
		{
			if(P->Default_DD == 1)
				SDL_BlitSurface(FP->Frames.Standing[1], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
			else
				SDL_BlitSurface(FP->Frames.Standing[0], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));			
		}

	}

	else
	{
		if(P->Wall_Friction && !P->Y_Velocity)
		{
			if(P->Wall_Friction == 1)
				SDL_BlitSurface(FP->Frames.Wall_Friction[1], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));

			else
				SDL_BlitSurface(FP->Frames.Wall_Friction[0], NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
		}


		else
		{
			if(P->Default_DD == 1)
				SDL_BlitSurface(FP->Frames.Jump_Right, NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));

			else
				SDL_BlitSurface(FP->Frames.Jump_Left, NULL, BG_Camera->Dynamic_bg, &(FP->Frame_Blit));
		}

	}
}

///////////////////////////////////


void UpdateCameraSP(BGC* BG_Camera, SM* P) {
	// Delete the characters old position on the dynamic image
	SDL_BlitSurface(BG_Camera->Normal_bg, &BG_Camera->P1.Frame_Blit, BG_Camera->Dynamic_bg, &BG_Camera->P1.Frame_Blit);

	// ========================================= TO UPDATE =========================================

	//* pos test
	SDL_Rect pos;
	pos.x = 3924; pos.y = 1104;
	pos.w = 2393; pos.h = 1231;

	if (time(NULL))
		delay++;

	//printf("delay...%d\n", delay);
	test(BG_Camera, pos, delay);

	// =============================================================================================

	// Blit the characters new position on the dynamic image && Update frame rect position
	CharacterFrame(BG_Camera, &(BG_Camera->P1) , P);

	// Screen blit of the background
	SDL_BlitSurface(BG_Camera->Dynamic_bg, &(BG_Camera->Camera), screen, NULL);

	// Blit health
	CharacterHealth(BG_Camera, P);
}

// ========================================= TO UPDATE =========================================

//? test void fn
void test(BGC* BG_Camera, SDL_Rect pos, int delay) {
	if (delay % 100 >= 0 && delay % 100 <= 50)
		SDL_BlitSurface(BG_Camera->Dynamic_2, &pos, BG_Camera->Dynamic_bg, &pos);
	else
		SDL_BlitSurface(BG_Camera->Dynamic_3, &pos, BG_Camera->Dynamic_bg, &pos);
}
// =============================================================================================

///////////////////////////////////

// Passer à la mini map et refaire la même chose

void UpdateBackgroundSP(BGC* BG_Camera, SM* P, int* Quit_Game)
{
	if(P->Keys.Pause)
	{
		PauseGame(Quit_Game, BG_Camera);
		P->Keys.Pause=0;
	}

	else if(P->Keys.Interact)
	{
		P->Keys.Interact = 0;

		// ================ TO UPODATE ================
		if(rand()%2)
			__ttt_game__();
		else
			enigma();
		// ============================================
	}

	else if(P->Lvl_Trans)
		SDL_BlitSurface(BG_Camera->Chargement,NULL,screen,NULL);

	else
	{
		// Update camera position
		CheckCameraPosition(&(BG_Camera->Camera), P, BG_Camera->WBG, BG_Camera->HBG);

		// Update background blit
		UpdateCameraSP(BG_Camera, P);
	}
}

///////////////////////////////////

void UpdateCameraMP(BGC* BG_Camera, SM* P1, SM* P2)
{
	// Delete the characters old position on the dynamic image
	SDL_BlitSurface(BG_Camera->Normal_bg, &BG_Camera->P1.Frame_Blit, BG_Camera->Dynamic_bg, &BG_Camera->P1.Frame_Blit);
	SDL_BlitSurface(BG_Camera->Normal_bg, &BG_Camera->P2.Frame_Blit, BG_Camera->Dynamic_bg, &BG_Camera->P2.Frame_Blit);
	
	// Blit the characters new position on the dynamic image && Update frame rect position
	CharacterFrame(BG_Camera, &(BG_Camera->P1) , P1);
	CharacterFrame(BG_Camera, &(BG_Camera->P2) , P2);

	// Screen blit of the background
	SDL_BlitSurface(BG_Camera->Dynamic_bg, &(BG_Camera->Camera1), screen, NULL);
	SDL_BlitSurface(BG_Camera->Dynamic_bg, &(BG_Camera->Camera2), screen, &(BG_Camera->Position_BC_P2));
}

///////////////////////////////////

void UpdateBackgroundMP(BGC* BG_Camera, SM* P1, SM* P2, int* Quit_Game)
{
	if(P1->Keys.Pause)
	{
		PauseGame(Quit_Game, BG_Camera);
		P1->Keys.Pause=0;
	}

	else if(P1->Lvl_Trans && P2->Lvl_Trans)
		SDL_BlitSurface(BG_Camera->Chargement,NULL,screen,NULL);

	else
	{
		// Update camera position
		CheckCameraPosition(&(BG_Camera->Camera1), P1, BG_Camera->WBG, BG_Camera->HBG);
		CheckCameraPosition(&(BG_Camera->Camera2), P2, BG_Camera->WBG, BG_Camera->HBG);

		// Update background blit
		UpdateCameraMP(BG_Camera, P1, P2);
	}

}

///////////////////////////////////

// NOTE : CREATE 2 FREE FUNCTIONS : FOR MP AND SP

void FreeBackgroundSP(int Lvl, BGC* BG_Camera)
{
	int i;

	SDL_FreeSurface(BG_Camera->Chargement);
	SDL_FreeSurface(BG_Camera->Normal_bg);
	
	if(Lvl == 3)
	{
		SDL_FreeSurface(BG_Camera->Dynamic_bg);
		SDL_FreeSurface(BG_Camera->Dynamic_2);
	}

	// Free frames

	// Standing
	for(i=0;i<2;i++)
		SDL_FreeSurface(BG_Camera->P1.Frames.Standing[i]);

	// Wall friction
	for(i=0;i<2;i++)
		SDL_FreeSurface(BG_Camera->P1.Frames.Wall_Friction[i]);

	// Run
	for(i=0;i<8;i++)
		SDL_FreeSurface(BG_Camera->P1.Frames.Run_Left[i]);

	for(i=0;i<8;i++)
		SDL_FreeSurface(BG_Camera->P1.Frames.Run_Right[i]);

	// Jump
	SDL_FreeSurface(BG_Camera->P1.Frames.Jump_Left);
	SDL_FreeSurface(BG_Camera->P1.Frames.Jump_Right);

	// Dash
	for(i=0;i<10;i++)
		SDL_FreeSurface(BG_Camera->P1.Frames.Dash[i]);
}

///////////////////////////////////

void FreeBackgroundMP(int Lvl, BGC* BG_Camera)
{
	int i;
	
	SDL_FreeSurface(BG_Camera->Chargement);
	SDL_FreeSurface(BG_Camera->Normal_bg);

	if(Lvl == 3)
	{
		SDL_FreeSurface(BG_Camera->Dynamic_bg);
		SDL_FreeSurface(BG_Camera->Dynamic_2);
	}

	// Free frames

	// Standing
	for(i=0;i<2;i++)
	{
		SDL_FreeSurface(BG_Camera->P1.Frames.Standing[i]);
		SDL_FreeSurface(BG_Camera->P2.Frames.Standing[i]);
	}

	// Wall friction
	for(i=0;i<2;i++)
	{
		SDL_FreeSurface(BG_Camera->P1.Frames.Wall_Friction[i]);
		SDL_FreeSurface(BG_Camera->P2.Frames.Wall_Friction[i]);
	}

	// Run
	for(i=0;i<8;i++)
	{
		SDL_FreeSurface(BG_Camera->P1.Frames.Run_Left[i]);
		SDL_FreeSurface(BG_Camera->P2.Frames.Run_Left[i]);
	}

	for(i=0;i<8;i++)
	{
		SDL_FreeSurface(BG_Camera->P1.Frames.Run_Right[i]);
		SDL_FreeSurface(BG_Camera->P2.Frames.Run_Right[i]);
	}

	// Jump
	SDL_FreeSurface(BG_Camera->P1.Frames.Jump_Left);
	SDL_FreeSurface(BG_Camera->P1.Frames.Jump_Right);
	SDL_FreeSurface(BG_Camera->P2.Frames.Jump_Left);
	SDL_FreeSurface(BG_Camera->P2.Frames.Jump_Right);

	// Dash
	for(i=0;i<10;i++)
	{
		SDL_FreeSurface(BG_Camera->P1.Frames.Dash[i]);
		SDL_FreeSurface(BG_Camera->P2.Frames.Dash[i]);
	}
}

///////////////////////////////////