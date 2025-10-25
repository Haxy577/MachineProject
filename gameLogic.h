/*This file is responsible for deciding and updating the game based
	on the decisions of the player
*/





/* ------------------------ Function Prototypes ------------------------ */
void getChoice(int* nInput, int nMinInput, int nMaxInput);
void updateInputRange(int nCurrRoom, int* nMinInput, int* nMaxInput);
void displayCurrentRoom(int nCurrRoom, int nCurrProg);
void updateGame(int* nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg,
				int* nHealth, int* Score, int* bShinyItem, int* bTorch,
				int* bRustyKey);
void roomOptionsLogic(int nInput, int* nCurrRoom, int* nCurrProg);
void roomCreditsLogic(int nInput, int* nCurrRoom, int* nCurrProg);
void roomMenuLogic (int nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg);
void resetGame(int* nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg,
			int* nHealth, int* nScore, int* bShinyItem, int* bTorch,
			int* bRustyKey);
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
getChoice(int* nInput, int nMinInput, int nMaxInput)
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
					changeColor(1,255,0,0); //change the color to red
					printf("Invalid input. Please input a integer between %d and %d\n", nMinInput, nMaxInput);
					changeColor(0,255,255,255); // change the color back to white
				}

				//clear the buffer if there are extra characters
                if (cChar != '\n')
                    while (getchar() != '\n');
                break;


            default:
				changeColor(1,255,0,0); //change the color to red
                printf("Invalid input. Please input a valid integer.\n");
				changeColor(0,255,255,255); // change the color back to white
				
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
			*nMaxInput = 3;
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
displayCurrentRoom(int nCurrRoom, int nCurrProg)
{
	switch (nCurrRoom)
	{
		//Options
		case -3:
			displayOptions();
			break;

		//Credits page
		case -2:
			displayCredits();
			break;
			
		//Menu
		case -1:
		case 0:
			displayMenu(nCurrProg);
			break;
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
			int* bRustyKey)
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
			roomOptionsLogic(*nInput, nCurrRoom, nCurrProg);
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
			*nCurrRoom = -1;
			break;
	}
}


void
roomOptionsLogic(int nInput, int* nCurrRoom, int* nCurrProg)
{
	/*
	The option page has n choices
	0. Return to meni
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


void
resetGame(int* nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg,
			int* nHealth, int* nScore, int* bShinyItem, int* bTorch,
			int* bRustyKey)
{
	//reset everything back to its original values
	*nInput = 0;
	*nGameEnding = 0;
	*nCurrRoom = 0;
	*nCurrProg = 0;
	*nHealth = 50;
	*nScore = 0;
	*bShinyItem = 0;
	*bTorch = 0;
	*bRustyKey = 0;
}


