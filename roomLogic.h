/*This file is responsible for deciding and updating the game based
	on the decisions of the player
*/



/* ------------------------ Function Prototypes ------------------------ */
void roomOptionsLogic(int nInput, int* nCurrRoom, int* nCurrProg,
						int* bToggleColor, int* bToggleWait,
						int* bToggleClear);
void roomCreditsLogic(int nInput, int* nCurrRoom, int* nCurrProg);
void roomMenuLogic (int nInput, int* nGameEnding, int* nCurrRoom, 
                        int* nCurrProg);
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
roomOptionsLogic(int nInput, int* nCurrRoom, int* nCurrProg,
				int* bToggleColor, int* bToggleWait,
				int* bToggleClear)
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
			if(*bToggleColor)
				*bToggleColor = 0;
			else
				*bToggleColor = 1;
			break;

		case 2:
			if(*bToggleWait)
				*bToggleWait = 0;
			else
				*bToggleWait = 1;
			break;

		case 3:
			if(*bToggleClear)
				*bToggleClear = 0;
			else
				*bToggleClear = 1;
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
		case 1:
			*nCurrRoom = 0;
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