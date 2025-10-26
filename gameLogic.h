/*This file is responsible for deciding and updating the game based
	on the decisions of the player
*/





/* ------------------------ Function Prototypes ------------------------ */
void getChoice(int* nInput, int nMinInput, int nMaxInput, int bToggleColor);
void updateInputRange(int nCurrRoom, int* nMinInput, int* nMaxInput);
void displayCurrentRoom(int nCurrRoom, int nCurrProg, int bToggleColor,
						int bToggleWait, int bToggleClear, int bToggleHUD,
						int bToggleShowMenu);
void updateGame(int* nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg,
				int* nHealth, int* Score, int* bShinyItem, int* bTorch,
				int* bRustyKey, int* bToggleColor, int* bToggleWait,
				int* bToggleClear, int*bToggleHUD, int* bToggleShowMenu);
void roomOptionsLogic(int nInput, int* nCurrRoom, int* nCurrProg,
						int* bToggleColor, int* bToggleWait,
						int* bToggleClear, int* bToggleHUD,
						int* bToggleShowMenu);
void roomCreditsLogic(int nInput, int* nCurrRoom, int* nCurrProg);
void roomMenuLogic (int nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg);
/* --------------------------------------------------------------------- */



/*
	This function gets the value inputted by the player and
		checks if its valid, if not then it asks again
	Preconditions: input is an integer
	@param nInput is where the function will store the choice
	@param nMinInput is the minimum integer value the player can input
	@param nMaxInput is the maximum integer value the player can input
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
	This function is changes the ranges of input based on the current
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
		
	}
}


/*
	This function calls the functions that is responsible for
		printing the information for the current room
	Preconditions: nCurrRoom is an integer
	@param nCurrRoom tracks the current room the player is in
*/
void
displayCurrentRoom(int nCurrRoom, int nCurrProg, int bToggleColor,
					int bToggleWait, int bToggleClear, int bToggleHUD,
					int bToggleShowMenu)
{
	switch (nCurrRoom)
	{
		//Options
		case -3:
			displayOptions(bToggleColor, bToggleWait, bToggleClear,
							bToggleHUD, bToggleShowMenu);
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

		case 1:
			displayRoom1();
	}
}


/*
	This function is responsible for responding to the player's choice
	Preconditions: nCurrRoom is an integer
	@param nCurrRoom tracks the current room the player is in
*/
void
updateGame(int* nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg,
			int* nHealth, int* Score, int* bShinyItem, int* bTorch,
			int* bRustyKey, int* bToggleColor, int* bToggleWait,
			int* bToggleClear, int* bToggleHUD, int* bToggleShowMenu)
{
	/*room number for each room
	room_Optioms = -3
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
								bToggleShowMenu);
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
		
		//Room 1
		case 1:
			*nCurrRoom = 1;
			break;
	}
}

