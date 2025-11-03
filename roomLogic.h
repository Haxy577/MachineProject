/*This file is responsible for deciding and updating the game based
	on the decisions of the player
*/



/* ------------------------ Function Prototypes ------------------------ */
//These functions are responsible for the logic for each individual room
void toggleOptionLogic(int* bOption);
void roomOptionsLogic(int nInput, int* nCurrRoom, int* nCurrProg,
						int* bToggleColor, int* bToggleWait,
						int* bToggleClear, int* bToggleHUD,
						int* bToggleShowMenu, int* bToggleSimple);
void roomCreditsLogic(int nInput, int* nCurrRoom, int* nCurrProg);
void roomMenuLogic (int nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg);
void introductionLogic(int nInput, int* nCurrRoom, int* nCurrProg);
void room1Logic(int nInput, int* nCurrRoom, int* nCurrProg);
void room2Logic(int nInput, int* nCurrRoom, int* nCurrProg,
				int* nHealth, int* nScore);
void room3Logic(int nInput, int* nCurrRoom, int* nCurrProg,
				int* nScore, int* bShinyItem);
void room4Logic(int nInput, int* nCurrRoom, int* nCurrProg,
				int* nHealth);
void room5Logic(int nInput, int* nCurrRoom, int* nCurrProg,
				int* bTorch);
void room6Logic(int nInput, int* nCurrRoom, int* nCurrProg,
				int* nHealth, int* nScore, int bTorch);
void room7Logic(int nInput, int* nCurrRoom, int* nCurrProg);
void room8Logic(int nInput, int* nCurrRoom, int* nCurrProg,
				int bRustyKey);
void room9Logic(int nInput, int* nCurrRoom, int* nCurrProg,
				int* nGameEnding, int* nHealth, int* bRustyKey);
void room10Logic(int nInput, int* nCurrRoom, int* nGameEnding,
					int* nScore, int bShinyItem);
void achievementsLogic(int nGameEnding, int nMoveCount, int nHealth,
						int nScore, int bShinyItem, int bTorch,
						int bRustyKey, int* bGotEnding1, int* bGotEnding2,
						int* bGotEnding3, int* bGotEnding4, int* bGotHealthy,
						int* bGotPlentiful, int* bGotCollector, int* bGotSpeedrun,
						int* bGotCompletionist);
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


/*
	This function is responsible of switching the value of the option from
		1 to 0 or 0 to 1 when called
	Precondition: bOption is a integer
	@param bOption contains the value of the option that is being changed
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


/*
	This function turns the setting off or on based on the input of the player
	Precondition: parameters are integers
	@param nInput tracks the choice the player has made
	@param nCurrRoom tracks the current room the player is in
	@param nCurrProg tracks the current progress of an ongoing game
	@param bToggleColor tracks whether to display color or not
	@param bToggleWait tracks whether there is a wait between dialogue
	@param bToggleClear tracks whether to clear the screen when moving between rooms
	@param bToggleHUD tracks whether to display a Heads-up Display when playing
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
*/
void
roomOptionsLogic(int nInput, int* nCurrRoom, int* nCurrProg,
					int* bToggleColor, int* bToggleWait,
					int* bToggleClear, int* bToggleHUD,
					int* bToggleShowMenu, int* bToggleSimple)
{
	/*
	The option page has 7 choices
	0. Return to menu
	1. Toggle text color
	3. Toggle clear screen
	2. Toggle dialogue wait
	4. Toggle display HUD
	5. Toggle display return to menu option
	6. Toggle simple dialogue
	*/
	switch (nInput)
	{
		//Return to menu
		case 0:
			if (*nCurrProg)
				*nCurrRoom = -2; //where -2 is the menu page with a continue option
			else
				*nCurrRoom = -1; //where -1 is the normal menu page
			break;
		
		//These options are responsible for the game display
		//Toggle text color
		case 1:
			toggleOptionLogic(bToggleColor);
			break;

		case 2:
			toggleOptionLogic(bToggleClear);
			break;

		case 3:
			toggleOptionLogic(bToggleWait);
			break;
			
		case 4:
			toggleOptionLogic(bToggleHUD);
			break;

		case 5:
			toggleOptionLogic(bToggleShowMenu);
			break;

		case 6:
			toggleOptionLogic(bToggleSimple);
			break;
	}
}


/*
	This function responds to the input of the player based on the choices
		in the credits page
	Precondition: parameters are integers
	@param nInput tracks the choice the player has made
	@param nCurrRoom tracks the current room the player is in
	@param nCurrProg tracks the current progress of an ongoing game
*/
void
roomCreditsLogic(int nInput, int* nCurrRoom, int* nCurrProg)
{
	/*
	The credit page has two 2 choices:
		1. To stay
		2. Go back to menu
	*/
	switch (nInput)
	{
		case 2:
			if (*nCurrProg)
				*nCurrRoom = -2; //where -2 is the menu page with a continue option
			else
				*nCurrRoom = -1; //where -1 is the normal menu page
	}
}


/*
	This function responds to the input of the player based on the choices
		in the menu page
	Precondition: parameters are integers
	@param nInput tracks the choice the player has made
	@param nGameEnding tracks the type of ending the player got
	@param nCurrRoom tracks the current room the player is in
	@param nCurrProg tracks the current progress of an ongoing game
*/
void
roomMenuLogic (int nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg)
{
	switch (nInput)
		{
		case 0:
			*nCurrRoom = *nCurrProg;
			break;
		
		case 1:
			*nCurrRoom = 0;
			*nCurrProg = 0;
			break;
				
		//Go to the credits
		case 2:
			*nCurrRoom = -3;
			break;

		//Go to the options
		case 3:
			*nCurrRoom = -4;
			break;
				
		//terminate the program
		case 4:
			*nGameEnding = 0;
		}
}

/*
	This function is responsible for the logic of the introduction page
	Preconditions: parameters are integers
	@param nInput tracks the choice the player has made
	@param nCurrRoom tracks the current room the player is in
	@param nCurrProg tracks the current progress of an ongoing game
*/
void
introductionLogic(int nInput, int* nCurrRoom, int* nCurrProg)
{
	/*
	This room has 2 choices:
		0. Return to menu
		1. Continue
	*/
	switch (nInput)
	{
		//return to menu
		case 0:
			*nCurrRoom = -2;
			break;
		
		//move to room 1
		case 1:
			*nCurrRoom = 1;
			*nCurrProg = 1;
			break;
	}
}


/*
	This function is responsible for the logic of room 1
	Preconditions: parameters are integers
	@param nInput tracks the choice the player has made
	@param nCurrRoom tracks the current room the player is in
	@param nCurrProg tracks the current progress of an ongoing game
*/
void
room1Logic(int nInput, int* nCurrRoom, int* nCurrProg)
{
	/*
	This room has 3 choices:
		0. Return to menu
		1. Go to room 2
		2. Go to room 3
	*/
	switch (nInput)
	{
		//return to menu
		case 0:
			*nCurrRoom = -2;
			break;
		
		//move to room 2
		case 1:
			*nCurrRoom = 2;
			*nCurrProg = 2;
			break;

		//move to room 3
		case 2:
			*nCurrRoom = 3;
			*nCurrProg = 3;
			break;
	}
}


/*
	This function is responsible for the logic of room 2
	Preconditions: parameters are integers
	@param nInput tracks the choice the player has made
	@param nCurrRoom tracks the current room the player is in
	@param nCurrProg tracks the current progress of an ongoing game
	@param nHealth tracks the current health of the player
	@param nScore tracks the current score of the player
*/
void
room2Logic(int nInput, int* nCurrRoom, int* nCurrProg,
			int* nHealth, int* nScore)
{
	//The player loses 10 health and gains 2 points
	*nHealth -= 10; //subtracts 10 from the player's health
	*nScore += 2; //adds 2 to the player's score

	/*
	This room has 2 choices:
		0. Return to menu
		1. Go to room 4
	*/
	switch (nInput)
	{
	//return to menu
	case 0:
		*nCurrRoom = -2;
		break;

	//move to room 4
	case 1:
		*nCurrRoom = 4;
		*nCurrProg = 4;
		break;
	}
}


/*
	This function is responsible for the logic of room 3
	Preconditions: parameters are integers
	@param nInput tracks the choice the player has made
	@param nCurrRoom tracks the current room the player is in
	@param nCurrProg tracks the current progress of an ongoing game
	@param nScore tracks the current score of the player
	@param bShinyItem tracks whether the player has the Shiny Item or not
*/
void
room3Logic(int nInput, int* nCurrRoom, int* nCurrProg,
			int* nScore, int* bShinyItem)
{
	/*
	This room has 3 choices:
		0. Return to menu
		1. Pick up the Shiny Item and gain 5 points then move to room 4
		2. Ignore then move to room 4
	*/
	switch (nInput)
	{
		//return to menu
		case 0:
			*nCurrRoom = -2;
			break;

		//obtain the shiny item and gain 5 points
		case 1:
			*bShinyItem = 1;//update that the player has the shiny item
			*nScore += 5; 	//adds 5 points to the player's score
			//Intentional Fallthrough
		
		//move to room 4
		case 2:
			*nCurrRoom = 4;
			*nCurrProg = 4;
			break;
	}
}


/*
	This function is responsible for the logic of room 4
	Preconditions: parameters are integers
	@param nInput tracks the choice the player has made
	@param nCurrRoom tracks the current room the player is in
	@param nCurrProg tracks the current progress of an ongoing game
	@param nHealth tracks the current health of the player
*/
void
room4Logic(int nInput, int* nCurrRoom, int* nCurrProg,
			int* nHealth)
{
	/*
	This room has 3 choices:
		0. Return to menu
		1. Take the boat then move to room 5
		2. Swim and lose 20 health then move to room 5
	*/
	switch (nInput)
	{
		//return to menu
		case 0:
			*nCurrRoom = -2; //go to the menu with the continue option
			break;

		//lose 20 health then move to room 5
		case 2:
			*nHealth -= 20; //The player loses 20 health
			//Intentional fallthrough

		//move to room 5
		case 1:
			*nCurrRoom = 5;	//update the current room with the next room
			*nCurrProg = 5;	//update the current progress with the next room
			break;
	}
}


/*
	This function is responsible for the logic of room 5
	Preconditions: parameters are integers
	@param nInput tracks the choice the player has made
	@param nCurrRoom tracks the current room the player is in
	@param nCurrProg tracks the current progress of an ongoing game
	@param bTorch tracks whether the player has the item Torch or not
*/
void
room5Logic(int nInput, int* nCurrRoom, int* nCurrProg,
			int* bTorch)
{
	/*
	This room has 3 choices:
		0. Return to menu
		1. Take the torch then move to room 6
		2. Ignore then move to room 6
	*/
	switch (nInput)
	{
		//return to menu
		case 0:
			*nCurrRoom = -2; //go to the menu with the continue option
			break;

		//obtain torch item
		case 1:
			*bTorch = 1; //updates that the player has the torch item
			//Intentional Fallthrough

		//move to room 6
		case 2:
			*nCurrRoom = 6;	//update the current room with the next room
			*nCurrProg = 6;	//update the current progress with the next room
			break;
	}
}


/*
	This function is responsible for the logic of room 6
	Preconditions: parameters are integers
	@param nInput tracks the choice the player has made
	@param nCurrRoom tracks the current room the player is in
	@param nCurrProg tracks the current progress of an ongoing game
	@param nHealth tracks the current health of the player
	@param nScore tracks the current score of the player
	@param bTorch tracks whether the player has the item Torch or not
*/
void
room6Logic(int nInput, int* nCurrRoom, int* nCurrProg,
			int* nHealth, int* nScore, int bTorch)
{
	/*
	This room has 2 possible outcomes:
	1. The player gains 5 points if the player has the torch item
	2. The player loses 15 health if the player does not have the torch item
	*/
	if (bTorch)
		*nScore += 5;
	else
		*nHealth -= 15;

	/*
	This room has 2 choices:
	0. Retrun to menu
	1. Move to room 7
	*/
	switch (nInput)
	{
		//return to menu
		case 0:
			*nCurrRoom = -2; //go to the menu with the continue option
			break;

		//move to room 7
		case 1:
			*nCurrRoom = 7;	//update the current room with the next room
			*nCurrProg = 7;	//update the current progress with the next room
			break;
	}
}


/*
	This function is responsible for the logic of room 7
	Preconditions: parameters are integers
	@param nInput tracks the choice the player has made
	@param nCurrRoom tracks the current room the player is in
	@param nCurrProg tracks the current progress of an ongoing game
*/
void
room7Logic(int nInput, int* nCurrRoom, int* nCurrProg)
{
	/*
	This room has 3 choices:
		0. Return to menu
		1. Move to room 8
		2. Move to room 9
	*/
	switch (nInput)
	{
		//return to menu
		case 0:
			*nCurrRoom = -2; //go to the menu with the continue option
			break;

		//move to room 8
		case 1:
			*nCurrRoom = 8;	//update the current room with the next room
			*nCurrProg = 8;	//update the current progress with the next room
			break;
		
		//move to room 9
		case 2:
			*nCurrRoom = 9;	//update the current room with the next room
			*nCurrProg = 9;	//update the current progress with the next room
			break;
	}
}


/*
	This function is responsible for the logic of room 8
	Preconditions: parameters are integers
	@param nInput tracks the choice the player has made
	@param nCurrRoom tracks the current room the player is in
	@param nCurrProg tracks the current progress of an ongoing game
	@param bRustyKey tracks whether the player has the Rusty Key or not
*/
void
room8Logic(int nInput, int* nCurrRoom, int* nCurrProg,
			int bRustyKey)
{
	/*
	This room has 2 choices:
		0. Return to menu
		1. Check if the player has the Rusty Key item
			1.1. If the player does not have the key then move back to room 9
			1.2. If the player does have the key then move to room 10
	*/
	switch (nInput)
	{
		//return to menu
		case 0:
			*nCurrRoom = -2; //go to the menu with the continue option
			break;

		//move to room 9 or 10 depending if the player has the rusty key or not
		case 1:
			//if the player has the rusty key item, move to room 10
			if (bRustyKey)
			{
				*nCurrRoom = 10;	//update the current room with the next room
				*nCurrProg = 10;	//update the current progress with the next room
			}
			//if the player does not have the rusty key item, move to room 9
			else
			{
				*nCurrRoom = 9;	//update the current room with the next room
				*nCurrProg = 9;	//update the current progress with the next room
			}
			break;
	}
}


/*
	This function is responsible for the logic of room 9
	Preconditions: parameters are integers
	@param nInput tracks the choice the player has made
	@param nCurrRoom tracks the current room the player is in
	@param nCurrProg tracks the current progress of an ongoing game
	@param nGameEnding tracks the type of ending the player got
	@param nHealth tracks the current health of the player
	@param bRustyKey tracks whether the player has the Rusty Key or not
*/
void
room9Logic(int nInput, int* nCurrRoom, int* nCurrProg,
			int* nGameEnding, int* nHealth, int* bRustyKey)
{
	//This room starts with the player losing 10 health:
	*nHealth -= 10;

	/*
	This room has 3 choices:
		0. Return to menu
		1. Take the rusty key then move to room 8
		2. Ignore the rusty key then set the ending to the "trapped ending"
	*/
	switch (nInput)
	{
		//return to menu
		case 0:
			*nCurrRoom = -2; //go to the menu with the continue option
			break;

		//obtain the rusty key item and move to room 8
		case 1:
			*bRustyKey = 1; //updates that the player has the rusty key item
			*nCurrRoom = 8;	//update the current room with the next room
			*nCurrProg = 8;	//update the current progress with the next room
			break;

		//the player gets the trapped ending
		case 2:
			*nGameEnding = 2; //number 2 represents the trapped ending
			break;
	}
}


/*
	This function is responsible for the logic of room 1
	Preconditions: parameters are integers
	@param nInput tracks the choice the player has made
	@param nCurrRoom tracks the current room the player is in
	@param nCurrProg tracks the current progress of an ongoing game
	@param nGameEnding tracks the type of ending the player got
	@param nScore tracks the current score of the player
	@param bShinyItem tracks whether the player has the Shiny Item or not
*/
void
room10Logic(int nInput, int* nCurrRoom, int* nGameEnding,
				int* nScore, int bShinyItem)
{
	
	//The player earns 20 points and the best ending if the player has the shiny item
	if (bShinyItem)
	{
		*nScore += 20; //the player gains 20 points
		*nGameEnding = 4; //number 4 represents the best ending
	}
	//else the player only gets the good ending
	else
		*nGameEnding = 3; //number 3 represents the good ending

	/*
	This room has 2 choices:
	The player gains 20 points if the player has the shiny item
		1. Return to menu
		2. Quit
	*/
	switch (nInput)
	{
		//return to menu
		case 1:
			*nCurrRoom = -2; //go to the menu with the continue option
			break;

		//Terminate the program
		case 2:
			*nGameEnding = 0; //terminates the main game loop
			break;
	}
}


void
achievementsLogic(int nGameEnding, int nMoveCount, int nHealth,
					int nScore, int bShinyItem, int bTorch,
					int bRustyKey, int* bGotEnding1, int* bGotEnding2,
					int* bGotEnding3, int* bGotEnding4, int* bGotHealthy,
					int* bGotPlentiful, int* bGotCollector, int* bGotSpeedrun,
					int* bGotCompletionist)
{
	//Ending achievements
	switch (nGameEnding)
	{
		case 1:
			*bGotEnding1 += 1;
			break;
		
		case 2:
			*bGotEnding2 += 1;
			break;

		case 3:
			*bGotEnding3 += 1;
			break;

		case 4:
			*bGotEnding4 += 1;
	}

	//Other achievements
	if (nHealth >= 40)
		*bGotHealthy += 1;

	if (nScore >= 30)
		*bGotPlentiful += 1;

	if (bShinyItem && bTorch && bRustyKey)
		*bGotCollector += 1;

	if (nMoveCount <= 10)
		*bGotSpeedrun += 1;

	if (*bGotEnding1 && *bGotEnding2 &&*bGotEnding3 && 
			*bGotEnding4 && *bGotHealthy && *bGotPlentiful && 
			*bGotCollector && *bGotSpeedrun && *bGotCompletionist)
		*bGotCompletionist += 1;
}