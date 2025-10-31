/*This file is responsible for deciding and updating the game based
	on the decisions of the player
*/





/* ------------------------ Function Prototypes ------------------------ */
void getChoice(int* nInput, int nMinInput, int nMaxInput, int bToggleColor);
void updateInputRange(int nCurrRoom, int* nMinInput, int* nMaxInput);
void displayCurrentRoom(int nCurrRoom, int nCurrProg, int nHealth,
					int nScore, int bShinyItem, int bTorch,
					int bRustyKey, int bToggleColor, int bToggleWait,
					int bToggleClear, int bToggleHUD, int bToggleShowMenu,
					int bToggleSimple);
void updateGame(int* nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg,
				int* nHealth, int* Score, int* bShinyItem, int* bTorch,
				int* bRustyKey, int* bToggleColor, int* bToggleWait,
				int* bToggleClear, int*bToggleHUD, int* bToggleShowMenu,
				int* bToggleSimple);
void roomOptionsLogic(int nInput, int* nCurrRoom, int* nCurrProg,
						int* bToggleColor, int* bToggleWait,
						int* bToggleClear, int* bToggleHUD,
						int* bToggleShowMenu, int* bToggleSimple);
void roomCreditsLogic(int nInput, int* nCurrRoom, int* nCurrProg);
void roomMenuLogic (int nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg);
void introductionLogic(int nInput, int* nCurrRoom, int* nCurrProg);
/* --------------------------------------------------------------------- */



/*
	This function gets the value inputted by the player and
		checks if its valid, if not then it asks again
	Preconditions: parameters are integers
	@param nInput is where the function will store the choice
	@param nMinInput is the minimum integer value the player can input
	@param nMaxInput is the maximum integer value the player can input
	@param bToggleColor tracks whether to display color or not
*/
void
getChoice(int* nInput, int nMinInput, int nMaxInput, int bToggleColor)
{
    int bIsInputValid = 0; //tracks if the input made by the user is valid and within the range
    int nIsScanValid; //tracks if the input follows the scanf format specifiers
    char cChar; //stores inputted characters
    do
    {
        printf("Your choice: ");
        nIsScanValid = scanf("%d%c", nInput, &cChar);
        
        switch (nIsScanValid)
        {
            case 2:
                if (*nInput >= nMinInput && *nInput <= nMaxInput && cChar == '\n')
                    bIsInputValid = 1;

                else
                {
					changeColor(bToggleColor,1,255,0,0); //change the color to red
					printf("Invalid input. Please input a integer between %d and %d\n", nMinInput, nMaxInput);
					changeColor(bToggleColor,0,255,255,255); // change the color back to white
				}

				//clear the buffer if there are extra characters
                if (cChar != '\n')
                    while (getchar() != '\n');
                break;


            default:
				changeColor(bToggleColor,1,255,0,0); //change the color to red
                printf("Invalid input. Please input a valid integer.\n");
				changeColor(bToggleColor,0,255,255,255); // change the color back to white
				
				//clear the buffer
                while (getchar() != '\n');
        }
    } while (bIsInputValid == 0);
}


/*
	This function changes the ranges of input based on the current
		room the player is in currently
	Preconditions: nCurrRoom, nMinInput, and nMaxInput are integers
	@param nCurrRoom is tracking the current room the player is in
	@param nMinInput is the minimum integer value the player can input
	@param nMaxInput is the maximum integer value the player can input
*/
void
updateInputRange(int nCurrRoom, int* nMinInput, int* nMaxInput)
{
	switch (nCurrRoom)
	{
		//Options
		case -3:
			*nMinInput = 0;
			*nMaxInput = 10;
			break;

		//Credits
		case -2:
			*nMinInput = 1;
			*nMaxInput = 2;
			break;
			
		//Menu with continue game option
		case -1:
			*nMinInput = 0;
			*nMaxInput = 4;
			break;
			
		//Menu
		case 0:
			*nMinInput = 1;
			*nMaxInput = 4;
			break;

		//Introduction
		case -4:
			*nMinInput = 0;
			*nMaxInput = 1;

		//Room 1
		case 1:
			*nMinInput = 0;
			*nMaxInput = 2;
			break;

		//Room 2
		case 2:
			*nMinInput = 0;
			*nMaxInput = 1;
			break;

		//Room 3
		case 3:
			*nMinInput = 0;
			*nMaxInput = 2;
			break;

		//Room 4
		case 4:
			*nMinInput = 0;
			*nMaxInput = 2;
			break;

		//Room 5
		case 5:
			*nMinInput = 0;
			*nMaxInput = 2;
			break;

		//Room 6
		case 6:
			*nMinInput = 0;
			*nMaxInput = 1;
			break;

		//Room 7
		case 7:
			*nMinInput = 0;
			*nMaxInput = 2;
			break;

		//Room 8
		case 8:
			*nMinInput = 0;
			*nMaxInput = 2;
			break;

		//Room 9
		case 9:
			*nMinInput = 0;
			*nMaxInput = 2;
			break;

		//Room 10
		case 10:
			*nMinInput = 0;
			*nMaxInput = 2;
			break;
		
	}
}


/*
	This function calls the functions that is responsible for
		printing the information for the current room
	Preconditions: parameters are integers
	@param nCurrRoom tracks the current room the player is in
	@param nCurrProg tracks the current progress of an ongoing game
	@param nHealth tracks the current health of the player
	@param nScore tracks the current health of the player
	@param bShinyItem tracks whether the player has the Shiny Item or not
	@param bTorch tracks whether the player has the Torch or not
	@param bRustyKey tracks whether the player has the Rusty Key or not
	@param bToggleColor tracks whether to display color or not
	@param bToggleWait tracks whether there is a pause between dialogues or not
	@param bToggleClear tracks whether to clear the screen when moving between screens or not
	@param bToggleHUD tracks whether to show the Heads-up Display when playing
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
*/
void
displayCurrentRoom(int nCurrRoom, int nCurrProg, int nHealth,
					int nScore, int bShinyItem, int bTorch,
					int bRustyKey, int bToggleColor, int bToggleWait,
					int bToggleClear, int bToggleHUD, int bToggleShowMenu,
					int bToggleSimple)
{
	switch (nCurrRoom)
	{
		//Options
		case -3:
			displayOptions(bToggleColor, bToggleWait, bToggleClear,
							bToggleHUD, bToggleShowMenu, bToggleSimple);
			break;

		//Credits page
		case -2:
			displayCredits();
			break;	
			
		//Menu
		case -1:
		case 0:
			displayMenu(nCurrProg, bToggleColor);
			break;

		case -4:
			displayIntroduction(nHealth, nScore, bShinyItem,
									bTorch, bRustyKey, bToggleColor,
									bToggleWait, bToggleHUD, bToggleShowMenu,
									bToggleSimple);
			break;
		
		/*case 1:
			displayRoom1(nHealth, nScore, bShinyItem,
							bTorch, bRustyKey, bToggleColor,
							bToggleWait, bToggleHUD, bToggleShowMenu,
							bToggleSimple);
			break;*/
	}
}


/*
	This function is responsible for updating the game based on the input of the player
	Preconditions: parameters are integers
	@param nInput tracks the choice the player has made
	@param nGameEnding tracks the type of ending the player got
	@param nCurrRoom tracks the current room the player is in
	@param nCurrProg tracks the current progress of an ongoing game
	@param nHealth tracks the current health of the player
	@param nScore tracks the current health of the player
	@param bShinyItem tracks whether the player has the Shiny Item or not
	@param bTorch tracks whether the player has the Torch or not
	@param bRustyKey tracks whether the player has the Rusty Key or not
	@param bToggleColor tracks whether to display color or not
	@param bToggleWait tracks whether there is a pause between dialogues or not
	@param bToggleClear tracks whether to clear the screen when moving between screens or not
	@param bToggleHUD tracks whether to show the Heads-up Display when playing
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
*/
void
updateGame(int* nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg,
			int* nHealth, int* Score, int* bShinyItem, int* bTorch,
			int* bRustyKey, int* bToggleColor, int* bToggleWait,
			int* bToggleClear, int* bToggleHUD, int* bToggleShowMenu,
			int* bToggleSimple)
{
	/*room number for each room
	room_Options = -3
	room_Credits = -2
	room_Menu = -1 and 0
	room_1 = 1
	room_2 = 2
	room_3 = 3
	room_4 = 4
	room_5 = 5
	room_6 = 6
	room_7 = 7
	room_8 = 8
	room_9 = 9
	room_10 = 10
	*/
	
	switch (*nCurrRoom)
	{
		//Options page
		case -3:
			roomOptionsLogic(*nInput, nCurrRoom, nCurrProg,
								bToggleColor, bToggleWait,
								bToggleClear, bToggleHUD,
								bToggleShowMenu, bToggleSimple);
			break;

		//Credits page
		case -2:
			roomCreditsLogic(*nInput, nCurrRoom, nCurrProg);
			break;
		
		//Menu
		case 0:
			roomMenuLogic(*nInput, nGameEnding, nCurrRoom, nCurrProg);
			break;
		case -1:
			roomMenuLogic(*nInput, nGameEnding, nCurrRoom, nCurrProg);
			break;
		
		//Introduction
		case -4:
			introductionLogic(*nInput, nCurrRoom, nCurrProg);
			break;
	}
}


/*
	This function updates the variables that track whether the player has been in the room before.
	Preconditions:
*/
