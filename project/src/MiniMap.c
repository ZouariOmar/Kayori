#include "../inc/Mini_Map.h"

///////////////////////////////////

void InitMiniMapSP(MAP* Mini_Map, int* Quit)
{
	// ------------------------- Will be initialised according to the level -------------------------
	/* 
	   NOTE :: Créer une nouvelle variable d'entrer de type int :
			 - Selon la valeur de la variable int on initialise une mini map différente (1,2,3,4,...)
	*/

	// Initialisation of the image of the mini map character
	Mini_Map->PMMR = load_img("pkg//Testlevel//Kayori head MM Right .png");
	Mini_Map->PMML = load_img("pkg//Testlevel//Kayori head MM Left .png");

	// Initialisation of the the interrogation point image and frame rate
	Mini_Map->IP = load_img("pkg//Testlevel//Mini map PI.png");
	Mini_Map->Rect_IP.w = 41;
	Mini_Map->Rect_IP.h = 57;
	Mini_Map->FR = 1;

	// ----------------------------------------------------------------------------------------------

	// Check initialisation
	if(!(Mini_Map->Normal_MM && Mini_Map->Dynamic_MM && Mini_Map->PMMR && Mini_Map->PMML && Mini_Map->IP))
	{
		printf("ERREUR : Probleme d'allocation memoire des images de la mini map\n");
		*Quit = 1;
	}

	// ========== Single player ========== //

	// Initialisation of the surface ( Type : SDL_Rect)
	Mini_Map->Surface.w = (int)((1920.0*0.2));
	Mini_Map->Surface.h = (int)((1080.0*0.2));
	Mini_Map->Surface.x = 1920 - Mini_Map->Surface.w;
	Mini_Map->Surface.y = 0;

	// Initialisation of the mini map player solo
	Mini_Map->P.h = 33;
	Mini_Map->P.w = 47;
	Mini_Map->P.x = 0;
	Mini_Map->P.y = 0;

	Mini_Map->MMLP.h = 33;
	Mini_Map->MMLP.w = 47;
	Mini_Map->MMLP.x = 0;
	Mini_Map->MMLP.y = 0;

	// Initialisation of the camera
	Mini_Map->Camera.w = Mini_Map->Surface.w;
	Mini_Map->Camera.h = Mini_Map->Surface.h;
	Mini_Map->Camera.x = 0;
	Mini_Map->Camera.y = 0;
}

///////////////////////////////////

void InitMiniMapMP(MAP* Mini_Map, int* Quit)
{
	// ------------------------- Will be initialised according to the level -------------------------
	/* 
	   NOTE :: Créer une nouvelle variable d'entrer de type int :
			 - Selon la valeur de la variable int on initialise une mini map différente (1,2,3,4,...)
	*/
	
	// Initialisation of the image of the mini map character
	Mini_Map->PMMR = load_img("pkg//Testlevel//Kayori head MM Right .png");
	Mini_Map->PMML = load_img("pkg//Testlevel//Kayori head MM Left .png");

	// Initialisation of the the interrogation point image and frame rate
	Mini_Map->IP = NULL;
	Mini_Map->Rect_IP.x = 0;
	Mini_Map->Rect_IP.y = 0;
	Mini_Map->Rect_IP.w = 0;
	Mini_Map->Rect_IP.h = 0;
	Mini_Map->FR = 0;

	// ----------------------------------------------------------------------------------------------

	// Check initialisation
	if(!(Mini_Map->Normal_MM && Mini_Map->Dynamic_MM && Mini_Map->PMMR && Mini_Map->PMML))
	{
		printf("ERREUR : Probleme d'allocation memoire des images de la mini map\n");
		*Quit = 1;
	}

	// Player 1

	// Initialisation of the surface ( Type : SDL_Rect)
	Mini_Map->Surface1.w = (int)((1920.0*0.2));
	Mini_Map->Surface1.h = (int)((540.0*0.2));
	Mini_Map->Surface1.x = 1920 - Mini_Map->Surface1.w;
	Mini_Map->Surface1.y = 0;

	// Initialisation of the mini map player solo
	Mini_Map->P1.h = 33;
	Mini_Map->P1.w = 47;
	Mini_Map->P1.x = 0;
	Mini_Map->P1.y = 0;

	Mini_Map->MMLP1.h = 33;
	Mini_Map->MMLP1.w = 47;
	Mini_Map->MMLP1.x = 0;
	Mini_Map->MMLP1.y = 0;

	// Initialisation of the camera
	Mini_Map->Camera1.w = Mini_Map->Surface1.w;
	Mini_Map->Camera1.h = Mini_Map->Surface1.h;
	Mini_Map->Camera1.x = 0;
	Mini_Map->Camera1.y = 0;

	// Player 2

	// Initialisation of the surface ( Type : SDL_Rect)
	Mini_Map->Surface2.w = (int)((1920.0*0.2));
	Mini_Map->Surface2.h = (int)((540.0*0.2));
	Mini_Map->Surface2.x = 1920 - Mini_Map->Surface2.w;
	Mini_Map->Surface2.y = 540;

	// Initialisation of the mini map player solo
	Mini_Map->P2.h = 33;
	Mini_Map->P2.w = 47;
	Mini_Map->P2.x = 0;
	Mini_Map->P2.y = 0;

	Mini_Map->MMLP2.h = 33;
	Mini_Map->MMLP2.w = 47;
	Mini_Map->MMLP2.x = 0;
	Mini_Map->MMLP2.y = 0;

	// Initialisation of the camera
	Mini_Map->Camera2.w = Mini_Map->Surface2.w;
	Mini_Map->Camera2.h = Mini_Map->Surface2.h;
	Mini_Map->Camera2.x = 0;
	Mini_Map->Camera2.y = 0;

}

///////////////////////////////////

void AnimationMM(MAP* Mini_Map)
{
	if(Mini_Map->FR < 16 )
		SDL_BlitSurface(Mini_Map->IP,NULL,Mini_Map->Dynamic_MM,&(Mini_Map->Rect_IP));

	else if(Mini_Map->FR == 16)
		SDL_BlitSurface(Mini_Map->Normal_MM,&(Mini_Map->Rect_IP),Mini_Map->Dynamic_MM,&(Mini_Map->Rect_IP));
	
	if(Mini_Map->FR == 32)
		Mini_Map->FR = 0;

	Mini_Map->FR++;
}

///////////////////////////////////

void UpdateVariables(SDL_Rect* MM_P, SDL_Rect* MMLP , SDL_Rect* MM_Camera, SDL_Rect Camera, SM* P)
{
	// Update the mini map players last position
	MMLP->x = MM_P->x;
	MMLP->y = MM_P->y;

	// Update the mini map players position
	MM_P->x = (int)(P->A_Pos.x*0.2);
	MM_P->y = (int)(P->A_Pos.y*0.2) - 17;

	// Update the mini map cameras position
	MM_Camera->x = (int)(Camera.x*0.2);
	MM_Camera->y = (int)(Camera.y*0.2);
}

///////////////////////////////////

void UpdateCameraMM(MAP* Mini_Map, SDL_Rect Surface, SDL_Rect P, SDL_Rect MMLP, SDL_Rect MM_Camera, int Side)
{
	// Delete the characters old position on the dynamic image
	SDL_BlitSurface(Mini_Map->Normal_MM, &MMLP, Mini_Map->Dynamic_MM, &MMLP);

	// Animation Interrogation point
	AnimationMM(Mini_Map);
	
	// Blit the characters new position on the dynamic image
	if(Side == 1)
		SDL_BlitSurface(Mini_Map->PMMR, NULL, Mini_Map->Dynamic_MM, &P);
	else
		SDL_BlitSurface(Mini_Map->PMML, NULL, Mini_Map->Dynamic_MM, &P);
	
	// Screen blit of the mini map
	SDL_BlitSurface(Mini_Map->Dynamic_MM, &MM_Camera, screen, &Surface);
}

///////////////////////////////////

void UpdateMMSolo(MAP* Mini_Map, BGC* BG_Camera, SM* P)
{
	// Update the variables of the mini map
	UpdateVariables( &(Mini_Map->P), &(Mini_Map->MMLP), &(Mini_Map->Camera), BG_Camera->Camera, P);

	// Update the mini map blit
	UpdateCameraMM(Mini_Map, Mini_Map->Surface, Mini_Map->P, Mini_Map->MMLP, Mini_Map->Camera, P->Default_DD);
}

///////////////////////////////////

void UpdateMMMulti(MAP* Mini_Map, BGC* BG_Camera, SM* P1, SM* P2)
{
	// Player 1

	// Update the variables of the mini map
	UpdateVariables( &(Mini_Map->P1), &(Mini_Map->MMLP1), &(Mini_Map->Camera1), BG_Camera->Camera1, P1);

	// Update the mini map blit
	UpdateCameraMM(Mini_Map, Mini_Map->Surface1, Mini_Map->P1, Mini_Map->MMLP1, Mini_Map->Camera1, P1->Default_DD);

	// Player 2

	// Update the variables of the mini map
	UpdateVariables( &(Mini_Map->P2), &(Mini_Map->MMLP2), &(Mini_Map->Camera2), BG_Camera->Camera2, P2);

	// Update the mini map blit
	UpdateCameraMM(Mini_Map, Mini_Map->Surface2, Mini_Map->P2, Mini_Map->MMLP2, Mini_Map->Camera2, P2->Default_DD);
}

///////////////////////////////////

void FreeMM(MAP* Mini_Map)
{
	SDL_FreeSurface(Mini_Map->Normal_MM);
	SDL_FreeSurface(Mini_Map->Dynamic_MM);
	SDL_FreeSurface(Mini_Map->PMMR);
	SDL_FreeSurface(Mini_Map->PMML);
	SDL_FreeSurface(Mini_Map->IP);
}

///////////////////////////////////