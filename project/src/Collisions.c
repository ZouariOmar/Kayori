#include "../inc/inc.h"
#include "../inc/Collisions.h"
#include <time.h>

///////////////////////////////////

// Initialisation of the collisions

void InitCollisions(Col** C_Tab, int* N_Collision, int Lvl ,int* Quit)
{
	// Open the collision file and initialisation of the variables

	FILE* file;

	switch(Lvl)
	{
		case 1:
			file = fopen("Tuto collisions","r");
			break;

		case 2:
			file = fopen("Level1 collisions","r");
			break;

		case 3:
			file = fopen("Level2 collisions","r");
			break;

		default:
			break;
	}


	int T, X, Y, W, H, i=0;

	if(file==NULL)
	{
		printf("ERREUR : Echec de l'ouverture fichier collision\n");
		*Quit = 1;
		return;
	}

	// Get the number of rect to allocate

	while(!feof(file))
	{
		fscanf(file,"%d %d %d %d %d",&T,&X,&Y,&W,&H);
		(*N_Collision)++;
	}

	// Reinitialisation of the position of the cursor

	rewind(file);

	// Allocation of the rects

	*C_Tab = malloc(sizeof(Col)*(*N_Collision));

	if(*C_Tab == NULL)
	{
		printf("ERREUR : Echec de l'allocation dynamique des collisions\n");
		*Quit = 1;
		return;
	}

	// Fill the rects

	while(!feof(file))
	{
		fscanf(file,"%d %d %d %d %d",&T,&X,&Y,&W,&H);

		(*(*C_Tab + i)).Type_Col=T;
		(*(*C_Tab + i)).Spec_Col.x=X;
		(*(*C_Tab + i)).Spec_Col.y=Y;
		(*(*C_Tab + i)).Spec_Col.w=W;
		(*(*C_Tab + i)).Spec_Col.h=H;

		i++;
	}
}

///////////////////////////////////
int delay = 0;

// Check each collision
void CollisionCheck(int Lvl, SM* P, Col* C_Tab, int i)
{
	int j;

	if(Lvl == 3)
	{
		if (time(NULL))
			delay++;

		if (delay % 100 >= 0 && delay % 100 <= 50) {
			// del the dyn_collision number 2
			C_Tab[24].Spec_Col.x = 0; C_Tab[24].Spec_Col.y = 0;
			C_Tab[24].Spec_Col.w = 0; C_Tab[24].Spec_Col.h = 0;

			// del the dyn_collision number 4
			C_Tab[30].Spec_Col.x = 0; C_Tab[30].Spec_Col.y = 0;
			C_Tab[30].Spec_Col.w = 0; C_Tab[30].Spec_Col.h = 0;


			// reset the dyn_collision number 1
			C_Tab[21].Spec_Col.x = 4079; C_Tab[21].Spec_Col.y = 1308;
			C_Tab[21].Spec_Col.w = 38;   C_Tab[21].Spec_Col.h = 766;
			
			// reset the dyn_collision number 3
			C_Tab[27].Spec_Col.x = 5451; C_Tab[27].Spec_Col.y = 1303;
			C_Tab[27].Spec_Col.w = 40; C_Tab[27].Spec_Col.h = 745;
		} else {
			// del the dyn_collision number 1
			C_Tab[21].Spec_Col.x = 0; C_Tab[21].Spec_Col.y = 0;
			C_Tab[21].Spec_Col.w = 0; C_Tab[21].Spec_Col.h = 0;
			
			// del the dyn_collision number 3
			C_Tab[27].Spec_Col.x = 0; C_Tab[27].Spec_Col.y = 0;
			C_Tab[27].Spec_Col.w = 0; C_Tab[27].Spec_Col.h = 0;

			// reset the dyn_collision number 2
			C_Tab[24].Spec_Col.x = 4777; C_Tab[24].Spec_Col.y = 1311;
			C_Tab[24].Spec_Col.w = 40; C_Tab[24].Spec_Col.h = 891;

			// reset the dyn_collision number 4
			C_Tab[30].Spec_Col.x = 6113; C_Tab[30].Spec_Col.y = 1304;
			C_Tab[30].Spec_Col.w = 36;   C_Tab[30].Spec_Col.h = 678;
		}
	}

	//C_Tab[24].Spec_Col.x = 0; C_Tab[24].Spec_Col.y = 0;
	//C_Tab[24].Spec_Col.w = 0; C_Tab[24].Spec_Col.h = 0;
	///////////////////

	// Check every collision
	for(j=0;j<i;j++)
	{
		if(!(P->A_Pos.x <= C_Tab[j].Spec_Col.x - P->A_Pos.w || P->A_Pos.x >= C_Tab[j].Spec_Col.x + C_Tab[j].Spec_Col.w ||
			P->A_Pos.y <= C_Tab[j].Spec_Col.y - P->A_Pos.h || P->A_Pos.y >= C_Tab[j].Spec_Col.y + C_Tab[j].Spec_Col.h))
		{
			// Cancel the dash if dashing and reset grounded

			if(P->Dash_Distance)
			{
				P->Dash_Distance=0;
				P->Grounded = -1;
			}

			// Checks the X axes

			if(P->L_Pos.x <= C_Tab[j].Spec_Col.x - P->A_Pos.w)
			{
				// Reposition in the X axes

				P->A_Pos.x = C_Tab[j].Spec_Col.x - P->A_Pos.w;

				// Check wall friction

				P->Wall_Friction=1;
			}

			else if(P->L_Pos.x >= C_Tab[j].Spec_Col.x + C_Tab[j].Spec_Col.w)
			{
				// Reposition in the X axes

				P->A_Pos.x = C_Tab[j].Spec_Col.x + C_Tab[j].Spec_Col.w;
				
				// Check wall friction

				P->Wall_Friction=2;
			}

			// Checks the Y axes

			if(P->Grounded == -1 &&  P->L_Pos.y <= C_Tab[j].Spec_Col.y - P->A_Pos.h )
			{
				P->A_Pos.y = C_Tab[j].Spec_Col.y - P->A_Pos.h;
				P->Grounded = j;
			}

			else if(P->L_Pos.y >= C_Tab[j].Spec_Col.y + C_Tab[j].Spec_Col.h)
				P->A_Pos.y = C_Tab[j].Spec_Col.y + C_Tab[j].Spec_Col.h;
		

			// Check deadly collision

			if(C_Tab[j].Type_Col == 1 || C_Tab[j].Type_Col == 2)
			{
				P->Death=1;

				//Reinitialize grounded
				P->Grounded = -1;
				return;
			}
			
			// Check level transition

			if(C_Tab[j].Type_Col == 3)
				P->Lvl_Trans = 1;
		}

	}

	// Check the edges if the P is grounded

	if( P->Grounded > -1 && ( P->A_Pos.x < C_Tab[P->Grounded].Spec_Col.x - P->A_Pos.w || P->A_Pos.x > C_Tab[P->Grounded].Spec_Col.x + C_Tab[P->Grounded].Spec_Col.w ) )
		P->Grounded = -1;
}

///////////////////////////////////

void FreeCollisions(Col* Tab)
{
	free(Tab);
}

///////////////////////////////////