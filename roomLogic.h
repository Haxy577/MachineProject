/*This file is responsible for deciding and updating the game based
	on the decisions of the player
*/



/* ------------------------ Function Prototypes ------------------------ */
void roomOptionsLogic(int nInput, int* nCurrRoom, int* nCurrProg,
						int* bToggleColor, int* bToggleWait,
						int* bToggleClear, int* bToggleHUD,
						int* bToggleShowMenu);
void roomCreditsLogic(int nInput, int* nCurrRoom, int* nCurrProg);
void roomMenuLogic (int nInput, int* nGameEnding, int* nCurrRoom, 
                        int* nCurrProg);
void room1Logic(int nInput, int* nCurrRoom, int* nCurrProg,
				int* nHealth);
/* --------------------------------------------------------------------- */


/*
Room Index:
-3 = options
-2 = credits
-1 = menu with continue option
0 = menu
1 = room 1
2 = room 2
3 = room 3
4 = room 4
5 = room 5
6 = room 6
7 = room 7
8 = room 8
9 = room 9
10 = room 10
*/


void
toggleOptionLogic(int* bOption)
{
	//sets the option to 0 if it is currently a nonzero value
	if(*bOption)
		*bOption = 0;

	//sets the option to 1 if the option is a zero
	else
		*bOption = 1;
}


void
roomOptionsLogic(int nInput, int* nCurrRoom, int* nCurrProg,
				int* bToggleColor, int* bToggleWait,
				int* bToggleClear, int* bToggleHUD,
				int* bToggleShowMenu)
{
	/*
	The option page has n choices
	0. Return to menu
	1...
	*/
	switch (nInput)
	{
		case 0:
			if (*nCurrProg)
				*nCurrRoom = -1; //where -1 is the menu page with a continue option
			else
				*nCurrRoom = 0; //where 0 is the normal menu page
			break;
		
		case 1:
			toggleOptionLogic(bToggleColor);
			break;

		case 2:
			toggleOptionLogic(bToggleWait);
			break;

		case 3:
			toggleOptionLogic(bToggleClear);
			break;
			
		case 4:
			toggleOptionLogic(bToggleHUD);
			break;

		case 5:
			toggleOptionLogic(bToggleShowMenu);
			break;
	}
}

void
roomCreditsLogic(int nInput, int* nCurrRoom, int* nCurrProg)
{
	/*
	The credit page has two (2) choices:
		1. To stay
		2. Go back to menu
	*/
	switch (nInput)
	{
		case 2:
			if (*nCurrProg)
				*nCurrRoom = -1; //where -1 is the menu page with a continue option
			else
				*nCurrRoom = 0; //where 0 is the normal menu page
	}
}


void
roomMenuLogic (int nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg)
{
	switch (nInput)
		{
		case 0:
			*nCurrRoom = *nCurrProg;
			break;
		
		case 1:
			*nCurrRoom = 1;
			*nCurrProg = 1;
			break;
				
		//Go to the credits
		case 2:
			*nCurrRoom = -2;
			break;

		//Go to the credits
		case 3:
			*nCurrRoom = -3;
			break;
				
		//terminate the program
		case 4:
			*nGameEnding = -1;
		}
}


void
room1Logic(int nInput, int* nCurrRoom, int* nCurrProg,
			int* nHealth)
{
	/*
	This room has 3 choices:
		0. Return to menu
		1. Go to room 2
		2. Go to room 3
	*/
	switch (nInput)
	{
		case 0:
			*nCurrRoom = -1;
			break;
		
		case 1:
			*nHealth -= 2;
			break;
	}
}


void
room2Logic()
{
	/*
	This room has 2 choices:
		0. Return to menu
		1. Go to room 4
	*/
}


void
room3Logic()
{
	/*
	This room has 3 choices:
		0. Return to menu
		1. Pick up the Shiny Item and gain 5 points then move to room 4
		2. Ignore then move to room 4
	*/
}


void
room4Logic()
{
	/*
	This room has 3 choices:
		0. Return to menu
		1. Take the boat then move to room 5
		2. Swim and lose 20 health then move to room 5
	*/
}


void
room5Logic()
{
	/*
	This room has 3 choices:
		0. Return to menu
		1. Take the torch then move to room 6
		2. Ignore then move to room 6
	*/
}


void
room6Logic()
{
	/*
	This room has 2 choices:
		0. Return to menu
		1. display the actions
			1.1. Take out the torch and gain 5 points then move to room 7
			1.2. Run and lose 15 health then move to room 7
	*/
}


void
room7Logic()
{
	/*
	This room has 3 choices:
		0. Return to menu
		1. Move to room 8
		2. Move to room 9
	*/
}


void
room8Logic()
{
	/*
	This room has 2 choices:
		0. Return to menu
		1. Check if the player has the Rusty Key item
			1.1. If the player does not have the key then move back to room 9
			1.2. If the player does have the key then move to room 10
	*/
}


void
room9Logic()
{
	/*
	This room has 3 choices and starts with losing 10 health:
		0. Return to menu
		1. Take the rusty key then move to room 8
		2. Ignore the rusty key then set the ending to the "trapped ending"
	*/
}


void
room10Logic()
{
	/*
	This room has 3 choices:
	The player gains 20 points if the player has the shiny item
		0. Return to menu
		1. New game
		2. Quit
	*/
}