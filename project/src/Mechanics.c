#include "../inc/Mechanics.h"

///////////////////////////////////

void InitKeys(SM* P1, SM* P2)
{
	// Player 1

	P1->Keys.Right = SDLK_RIGHT;
	P1->Keys.Left  = SDLK_LEFT;
	P1->Keys.Up = SDLK_UP;
	P1->Keys.Down = SDLK_DOWN;
	P1->Keys.Jump = SDLK_SPACE;
	P1->Keys.Dash = SDLK_c;
	P1->Keys.Inter = SDLK_x;
	P1->Keys.Pause=0;
	P1->Keys.Interact = 0;
	// Player 2

	P2->Keys.Right = SDLK_d;
	P2->Keys.Left  = SDLK_q;
	P2->Keys.Up = SDLK_z;
	P2->Keys.Down = SDLK_s;
	P2->Keys.Jump = SDLK_o;
	P2->Keys.Dash = SDLK_p;
	P2->Keys.Inter = SDLK_i;
	P2->Keys.Pause=0;
	P2->Keys.Interact = 0;
}

///////////////////////////////////

// Initialisation of the player

void InitPlayer(SM* P1, SM* P2)
{
	// Initialisation of the keys
	InitKeys(P1, P2);

	// ======= Player 1 ======= //

	// PLayer surface
	P1->A_Pos.h=80;
	P1->A_Pos.w=156;

	// Initialize death
	P1->Death=0;
	P1->N_Death=0;

	// Initialize player mechanics 
	P1->Move_Up=0;
	P1->Move_Down=0;
	P1->Move_Right=0;
	P1->Move_Left=0;
	P1->Move_Speed=0;
	P1->Move_Acc=1.005;

	// Initialize jump
	P1->Y_Velocity=0;
	P1->X_Velocity=0;
	P1->Wall_Jump=0;

	// Initialize dash
	P1->Dash_Direction=0;
	P1->Dash_Distance=0;
	P1->Default_DD=1;

	// Wall friction
	P1->Wall_Friction=0;

	// Ground check
	P1->Grounded=-1;

	// Level transition
	P1->Lvl_Trans = 0;

	// ======= Player 2 ======= //

	// PLayer surface
	P2->A_Pos.h=80;
	P2->A_Pos.w=156;

	// Players actual position
	P2->A_Pos.x=P2->Default_X;
	P2->A_Pos.y=P2->Default_Y;

	// Players last position
	P2->L_Pos.x=P2->Default_X;
	P2->L_Pos.y=P2->Default_Y;

	// Initialize death
	P2->Death=0;
	P2->N_Death=0;

	// Initialize player mechanics 
	P2->Move_Up=0;
	P2->Move_Down=0;
	P2->Move_Right=0;
	P2->Move_Left=0;
	P2->Move_Speed=0;
	P2->Move_Acc=1.005;

	// Initialize jump
	P2->Y_Velocity=0;
	P2->X_Velocity=0;
	P2->Wall_Jump=0;

	// Initialize dash
	P2->Dash_Direction=0;
	P2->Dash_Distance=0;
	P2->Default_DD=1;

	// Wall friction
	P2->Wall_Friction=0;

	// Ground check
	P2->Grounded=-1;

	// Level transition
	P2->Lvl_Trans = 0;
}

///////////////////////////////////

// Reinit the players position of he dies

void PlayerDeath(SM* P)
{
	SDL_Delay(100);
	P->Death=0;
	P->N_Death++;

	// Players actual position
	P->A_Pos.x=P->Default_X;
	P->A_Pos.y=P->Default_Y;

	// Players last position
	P->L_Pos.x=P->Default_X;
	P->L_Pos.y=P->Default_Y;
}

///////////////////////////////////

void InteractCheck(int Lvl, SM* P)
{
	switch(Lvl)
	{
		case 2:
			if(P->A_Pos.x >= 5267  && P->A_Pos.x <= 5605 && P->A_Pos.y >= 3009 && P->A_Pos.y <= 3398 )
				P->Keys.Interact=1;
			break;

		case 3:
			if(P->A_Pos.x >= 7945  && P->A_Pos.x <= 8635 && P->A_Pos.y >= 3684 && P->A_Pos.y <= 4346 )
				P->Keys.Interact=1;
			break;
	}
}

///////////////////////////////////

// Set movements

void InitMovements(int Lvl, SM* P)
{
	if(event.key.keysym.sym == P->Keys.Right)
	{
		// Initialisation of the movement and the default dash direction

		P->Move_Right=1;
		P->Move_Speed=DEFAULT_SPEED;
		P->Default_DD=1;
	}

	else if(event.key.keysym.sym == P->Keys.Left)
	{
		// Initialisation of the movement and the default dash direction

		P->Move_Left=1;
		P->Move_Speed=DEFAULT_SPEED;
		P->Default_DD=2;		
	}

	else if(event.key.keysym.sym == P->Keys.Up)
		P->Move_Up=1;

	else if(event.key.keysym.sym == P->Keys.Down)
		P->Move_Down=1;

	else if(event.key.keysym.sym == P->Keys.Dash)
	{
		if(P->Y_Velocity)
			P->Y_Velocity=0;

		if(!(P->Dash_Distance))
			DashDirection(P);
	}

	else if(event.key.keysym.sym == P->Keys.Jump)
	{
		if(P->Grounded!=-1)
		{
			P->Y_Velocity = Y_VELOCITY;
			P->Grounded=-1;
		}

		else if(P->Wall_Friction && !P->Wall_Jump)
		{ 
			P->Y_Velocity = Y_VELOCITY;

			if(P->Wall_Friction == 1)
			{
				P->X_Velocity = -X_VELOCITY;
				P->Wall_Jump = 1;
			}
			
			else
			{
				P->X_Velocity = X_VELOCITY;
				P->Wall_Jump = 2;
			}

			P->Wall_Friction = 0;
		}
	}

	else if(event.key.keysym.sym == P->Keys.Inter)
		InteractCheck(Lvl, P);

}

///////////////////////////////////

// Reset movements

void ReinitBMovements(SM* P)
{
	if(event.key.keysym.sym == P->Keys.Right)
	{
		P->Move_Right=0;
		P->Move_Speed=0;
	}

	else if(event.key.keysym.sym == P->Keys.Left)
	{
		P->Move_Left=0;
		P->Move_Speed=0;
	}

	else if(event.key.keysym.sym == P->Keys.Up)
			P->Move_Up=0;

	else if(event.key.keysym.sym == P->Keys.Down)
			P->Move_Down=0;
}

///////////////////////////////////

// Move the player

void Movements(SM* P)
{
	// Check if two buttons are pressed

	if(P->Move_Right && P->Move_Left)
		return;

	// Check if speed is 0 else increase it

	if(!P->Move_Speed)
		P->Move_Speed=DEFAULT_SPEED;

	else if(P->Move_Speed < 8)
		P->Move_Speed *= P->Move_Acc;

	// New actual position

	if(P->Move_Right)
		P->A_Pos.x+=P->Move_Speed;

	else if(P->Move_Left)
		P->A_Pos.x-=P->Move_Speed;
}

///////////////////////////////////

void Jump(SM* P)
{
	// Update the Y axis
	P->A_Pos.y += P->Y_Velocity;
	P->Y_Velocity += 1;

	// Update the X axis
	if(P->Wall_Jump)
	{
		P->A_Pos.x += P->X_Velocity;

		// If the jump occured in the left
		if(P->Wall_Jump == 1)
			P->X_Velocity += 1;

		// If the jump occured in the right
		else
			P->X_Velocity -= 1;
		
		// If the push back is over
		if(P->X_Velocity == 0)
			P->Wall_Jump = 0;
	}
}

///////////////////////////////////

// Detect the direction of the dash and its lenght

void DashDirection(SM* P)
{
	if(P->Move_Up && P->Move_Right)
	{
		P->Dash_Direction=1;
		P->Dash_Distance=280;
	}

	else if(P->Move_Down && P->Move_Right)
	{
		P->Dash_Direction=2;
		P->Dash_Distance=280;
	}

	else if(P->Move_Up && P->Move_Left)
	{
		P->Dash_Direction=3;
		P->Dash_Distance=280;
	}

	else if(P->Move_Down && P->Move_Left)
	{
		P->Dash_Direction=4;
		P->Dash_Distance=280;
	}

	else if(P->Move_Up)
	{
		P->Dash_Direction=5;
		P->Dash_Distance=400;
	}

	else if(P->Move_Right)
	{
		P->Dash_Direction=6;
		P->Dash_Distance=400;
	}

	else if(P->Move_Down)
	{
		P->Dash_Direction=7;
		P->Dash_Distance=400;
	}

	else if(P->Move_Left)
	{
		P->Dash_Direction=8;
		P->Dash_Distance=400;
	}

	else
	{
		if(P->Default_DD==1)
		{
			P->Dash_Direction=6;
			P->Dash_Distance=400;	
		}

		else
		{
			P->Dash_Direction=8;
			P->Dash_Distance=400;
		}
	}
}

///////////////////////////////////

// Move the player each frame if dashing

void Dash(SM* P)
{
	switch(P->Dash_Direction)
	{
		case 1:
			P->A_Pos.x+=14;
			P->A_Pos.y-=14;

			P->Dash_Distance-=14;
			break;

		case 2:
			P->A_Pos.x+=14;
			P->A_Pos.y+=14;

			P->Dash_Distance-=14;
			break;

		case 3:
			P->A_Pos.x-=14;
			P->A_Pos.y-=14;

			P->Dash_Distance-=14;
			break;

		case 4:
			P->A_Pos.x-=14;
			P->A_Pos.y+=14;

			P->Dash_Distance-=14;
			break;

		case 5:
			P->A_Pos.y-=20;

			P->Dash_Distance-=20;
			break;

		case 6:
			P->A_Pos.x+=20;

			P->Dash_Distance-=20;
			break;

		case 7:
			P->A_Pos.y+=20;

			P->Dash_Distance-=20;
			break;

		case 8:
			P->A_Pos.x-=20;

			P->Dash_Distance-=20;
			break;
	}

	// If the dash is over -> reset grounded
	if(!(P->Dash_Distance))
		P->Grounded=-1;
}

///////////////////////////////////

void GravityFunc(SM* P)
{
	if( !(P->Y_Velocity) && !(P->Dash_Distance) && P->Grounded == -1  )
	{
		if(P->Wall_Friction)
		{
			P->A_Pos.y+=Gravity/2;
			P->Wall_Friction=0;
		}

		else if(P->Move_Down)
			P->A_Pos.y+=Gravity*2;
		
		else
			P->A_Pos.y+=Gravity;
	}
}

///////////////////////////////////

// Check the mechanics

void Mechanics(int Lvl, SM* P, int* Quit, Col* C_Tab, int i)
{
	// Update last position
	P->L_Pos = P->A_Pos;

	// Check events
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				*Quit = 1;
				break;


		    case SDL_KEYDOWN:

		    	// Check the inputs
		    	if(event.key.keysym.sym==SDLK_ESCAPE)
		    		P->Keys.Pause=1;
		    	else
		    		InitMovements(Lvl, P);

		    	break;

		    case SDL_KEYUP:

		    	// Check basic movements
		    	
		    	ReinitBMovements(P);
		    	break;

		    default:
				break;
		}
	}

	// Check if the player is dead

	if(P->Death)
	{
		// Update the players position
		PlayerDeath(P);

		// return to end the function and update the position
		return;
	}

	// Dash check

	if(P->Dash_Distance)
		Dash(P);

	// Movements check (Move right or left)

	if( !(P->Dash_Distance) && ( P->Move_Right || P->Move_Left ) )
		Movements(P);

	// Jump and Slide check

	if(P->Y_Velocity && !(P->Dash_Distance) )
		Jump(P);

	//if (Player.Slide)
		// Slide

	// Gravity force

	GravityFunc(P);

	// Collision check

	CollisionCheck(Lvl, P,C_Tab,i);
}

///////////////////////////////////

// Check the mechanics

void MechanicsMulti(int Lvl, SM* P1, SM* P2, int* Quit, Col* C_Tab, int i)
{
	// Update last position
	P1->L_Pos = P1->A_Pos;
	P2->L_Pos = P2->A_Pos;

	// Check events
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				*Quit = 1;
				break;


		    case SDL_KEYDOWN:

		    	// Check the inputs
		    	if(event.key.keysym.sym==SDLK_ESCAPE)
		    		P1->Keys.Pause=1;
		    	else
		    	{
		    		if(event.key.keysym.sym==P1->Keys.Right || event.key.keysym.sym==P1->Keys.Left || event.key.keysym.sym==P1->Keys.Up || event.key.keysym.sym==P1->Keys.Down || event.key.keysym.sym==P1->Keys.Dash || event.key.keysym.sym==P1->Keys.Jump)
		    			InitMovements(Lvl, P1);
		    		else
		    			InitMovements(Lvl, P2);
		    	}

		    	break;

		    case SDL_KEYUP:

		    	// Check basic movements
		    	if(event.key.keysym.sym==P1->Keys.Right || event.key.keysym.sym==P1->Keys.Left || event.key.keysym.sym==P1->Keys.Up || event.key.keysym.sym==P1->Keys.Down || event.key.keysym.sym==P1->Keys.Dash)
					ReinitBMovements(P1);
				else
					ReinitBMovements(P2);

		    	break;

		    default:
				break;
		}
	}

	// ============= Player 1 ============= //

	// Check if the player is dead

	if(P1->Death)
	{
		// Update the players position
		PlayerDeath(P1);

		// return to end the function and update the position
		return;
	}

	// Dash check

	if(P1->Dash_Distance)
		Dash(P1);

	// Movements check (Move right or left)

	if( !(P1->Dash_Distance) && ( P1->Move_Right || P1->Move_Left ) )
		Movements(P1);

	// Jump and Slide check

	if(P1->Y_Velocity && !(P1->Dash_Distance) )
		Jump(P1);

	// Gravity force

	GravityFunc(P1);

	// Collision check

	CollisionCheck(Lvl, P1,C_Tab,i);

	// ============= Player 2 ============= //

	// Check if the player is dead

	if(P2->Death)
	{
		// Update the players position
		PlayerDeath(P2);

		// return to end the function and update the position
		return;
	}

	// Dash check

	if(P2->Dash_Distance)
		Dash(P2);

	// Movements check (Move right or left)

	if( !(P2->Dash_Distance) && ( P2->Move_Right || P2->Move_Left ) )
		Movements(P2);

	// Jump and Slide check

	if(P2->Y_Velocity && !(P2->Dash_Distance) )
		Jump(P2);

	// Gravity force

	GravityFunc(P2);

	// Collision check

	CollisionCheck(Lvl, P2,C_Tab,i);
}

///////////////////////////////////