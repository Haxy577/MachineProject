/*This file is responsible for deciding and updating the game based
	on the decisions of the player
*/



/* ------------------------ Function Prototypes ------------------------ */
//These functions are responsible for the game logic
void getChoice(int* nTotalInputs, int* nTotalInputError, int* nInput, int nMinInput, int nMaxInput, int bToggleColor);
void updateInputRange( int nCurrRoom, int* nMinInput, int* nMaxInput);
void displayCurrentRoom(
		/*Global game stats*/
			int nGameCount, int nGameCompletion, int nTotalMoveCount, int nTotalInputs,
			int nTotalInputError, int nAverageInput, int nTotalHealthLost, int nTotalScore,
			int nTotalShinyItem, int nTotalTorchItem, int nTotalRustyKeyItem,

		/*Local game states*/
			int nCurrRoom, int nCurrProg,

		/*Player stats and inventory*/
			int nHealth, int nScore, int bShinyItem, int bTorch, int bRustyKey,
			
		/*Achievements*/
			int bGotEnding1, int bGotEnding2, int bGotEnding3, int bGotEnding4,
			int bGotHealthy, int bGotPlentiful, int bGotCollector, int bGotSpeedrun,
			int bGotCompletionist,
			
		/*UI and gameplay settings*/
			int bToggleColor, int bToggleWait, int bToggleClear, int bToggleHUD,
			int bToggleShowMenu, int bToggleSimple
		);
void updateGame(
		/*Local game states*/
		int nInput, int* nGameEnding, int* nCurrRoom, int* nPrevRoom, int* nCurrProg,

		/*Player stats and inventory*/
		int* nHealth, int* nScore, int* bShinyItem, int* bTorch, int* bRustyKey,

		/*UI and gameplay settings*/
		int* bToggleColor, int* bToggleWait, int* bToggleClear, int* bToggleHUD,
		int* bToggleShowMenu, int* bToggleSimple);
/*
void updateGame(int nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg,
				int* nHealth, int* Score, int* bShinyItem, int* bTorch,
				int* bRustyKey, int* bToggleColor, int* bToggleWait,
				int* bToggleClear, int*bToggleHUD, int* bToggleShowMenu,
				int* bToggleSimple);*/
void updateAchievements(int nGameEnding, int nMoveCount, int nHealth,
						int nScore, int bShinyItem, int bTorch,
						int bRustyKey, int* bGotEnding1, int* bGotEnding2,
						int* bGotEnding3, int* bGotEnding4, int* bGotHealthy,
						int* bGotPlentiful, int* bGotCollector, int* bGotSpeedrun,
						int* bGotCompletionist);
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
getChoice(int* nTotalInputs, int* nTotalInputError, int* nInput, int nMinInput, int nMaxInput, int bToggleColor)
{
    int bIsInputValid = 0; //tracks if the input made by the user is valid and within the range
    int nIsScanValid; //tracks if the input follows the scanf format specifiers
    char cChar; //stores inputted characters
    do
    {
		*nTotalInputs += 1;
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
					*nTotalInputError += 1;
				}

				//clear the buffer if there are extra characters
                if (cChar != '\n')
                    while (getchar() != '\n');
                break;


            default:
				changeColor(bToggleColor,1,255,0,0); //change the color to red
                printf("Invalid input. Please input a valid integer.\n");
				changeColor(bToggleColor,0,255,255,255); // change the color back to white
				*nTotalInputError += 1;
				
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
		case -6:
			*nMinInput = 0;
			*nMaxInput = 10;
			break;

		//Credits
		case -5:
			*nMinInput = 1;
			*nMaxInput = 2;
			break;
		
		//Statistics
		case -4:
			*nMinInput = 1;
			*nMaxInput = 2;
			break;

		//Achievements
		case -3:
			*nMinInput = 1;
			*nMaxInput = 2;
			break;
			
		//Menu with continue game option
		case -2:
			*nMinInput = 0;
			*nMaxInput = 7;
			break;
			
		//Menu
		case -1:
			*nMinInput = 1;
			*nMaxInput = 7;
			break;

		//Introduction
		case 0:
			*nMinInput = 0;
			*nMaxInput = 1;
			break;

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
			*nMaxInput = 1;
			break;

		//Room 9
		case 9:
			*nMinInput = 0;
			*nMaxInput = 2;
			break;

		//Room 10
		case 10:
			*nMinInput = 1;
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
	@param nScore tracks the current score of the player
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
displayCurrentRoom(
		/*Global game stats*/
			int nGameCount, int nGameCompletion, int nTotalMoveCount, int nTotalInputs,
			int nTotalInputError, int nAverageInput, int nTotalHealthLost, int nTotalScore,
			int nTotalShinyItem, int nTotalTorchItem, int nTotalRustyKeyItem,

		/*Local game states*/
			int nCurrRoom, int nCurrProg,

		/*Player stats and inventory*/
			int nHealth, int nScore, int bShinyItem, int bTorch, int bRustyKey,
			
		/*Achievements*/
			int bGotEnding1, int bGotEnding2, int bGotEnding3, int bGotEnding4,
			int bGotHealthy, int bGotPlentiful, int bGotCollector, int bGotSpeedrun,
			int bGotCompletionist,
			
		/*UI and gameplay settings*/
			int bToggleColor, int bToggleWait, int bToggleClear, int bToggleHUD,
			int bToggleShowMenu, int bToggleSimple
		)
{
	switch (nCurrRoom)
	{
		//Options
		case -6:
			displayOptions(bToggleColor, bToggleWait, bToggleClear,
							bToggleHUD, bToggleShowMenu, bToggleSimple);
			break;

		//Credits page
		case -5:
			displayCredits();
			break;

		//Statistics page
		case -4:
			displayStatistics(
				nGameCount, nGameCompletion, nTotalMoveCount, nTotalInputs,
				nTotalInputError, nAverageInput, nTotalHealthLost, nTotalScore,
				nTotalShinyItem, nTotalTorchItem, nTotalRustyKeyItem
			);
			break;
			
		//Achievements page
		case -3:
			displayAchievements(bGotEnding1, bGotEnding2, bGotEnding3, 
						bGotEnding4, bGotHealthy, bGotPlentiful,
						bGotCollector, bGotSpeedrun, bGotCompletionist,
						bToggleColor);
			break;

		//Menu with continue choice
		case -2:
		//Intentional fallthrough

		//Menu page
		case -1:
			displayMenu(nCurrProg, bToggleColor);
			break;
		
		//Introduction
		case 0:
			displayIntroduction(nHealth, nScore, bShinyItem,
									bTorch, bRustyKey, bToggleColor,
									bToggleWait, bToggleHUD, bToggleShowMenu,
									bToggleSimple);
			break;
		
		//Room 1
		case 1:
			displayRoom1(nHealth, nScore, bShinyItem,
							bTorch, bRustyKey, bToggleColor,
							bToggleWait, bToggleHUD, bToggleShowMenu,
							bToggleSimple);
			break;

		//Room 2
		case 2:
			displayRoom2(nHealth, nScore, bShinyItem,
							bTorch, bRustyKey, bToggleColor,
							bToggleWait, bToggleHUD, bToggleShowMenu,
							bToggleSimple);
			break;

		//Room 3
		case 3:
			displayRoom3(nHealth, nScore, bShinyItem,
							bTorch, bRustyKey, bToggleColor,
							bToggleWait, bToggleHUD, bToggleShowMenu,
							bToggleSimple);
			break;

		//Room 4
		case 4:
			displayRoom4(nHealth, nScore, bShinyItem,
							bTorch, bRustyKey, bToggleColor,
							bToggleWait, bToggleHUD, bToggleShowMenu,
							bToggleSimple);
			break;

		//Room 5
		case 5:
			displayRoom5(nHealth, nScore, bShinyItem,
							bTorch, bRustyKey, bToggleColor,
							bToggleWait, bToggleHUD, bToggleShowMenu,
							bToggleSimple);
			break;

		//Room 6
		case 6:
			displayRoom6(nHealth, nScore, bShinyItem,
							bTorch, bRustyKey, bToggleColor,
							bToggleWait, bToggleHUD, bToggleShowMenu,
							bToggleSimple);
			break;

		//Room 7
		case 7:
			displayRoom7(nHealth, nScore, bShinyItem,
							bTorch, bRustyKey, bToggleColor,
							bToggleWait, bToggleHUD, bToggleShowMenu,
							bToggleSimple);
			break;

		//Room 8
		case 8:
			displayRoom8(nHealth, nScore, bShinyItem,
							bTorch, bRustyKey, bToggleColor,
							bToggleWait, bToggleHUD, bToggleShowMenu,
							bToggleSimple);
			break;

		//Room 9
		case 9:
			displayRoom9(nHealth, nScore, bShinyItem,
							bTorch, bRustyKey, bToggleColor,
							bToggleWait, bToggleHUD, bToggleShowMenu,
							bToggleSimple);
			break;

		//Room 10
		case 10:
			displayRoom10(nHealth, nScore, bShinyItem,
							bTorch, bRustyKey, bToggleColor,
							bToggleWait, bToggleHUD, bToggleShowMenu,
							bToggleSimple);
			break;
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
	@param nScore tracks the current score of the player
	@param bShinyItem tracks whether the player has the Shiny Item or not
	@param bTorch tracks whether the player has the item Torch or not
	@param bRustyKey tracks whether the player has the Rusty Key or not
	@param bToggleColor tracks whether to display color or not
	@param bToggleWait tracks whether there is a pause between dialogues or not
	@param bToggleClear tracks whether to clear the screen when moving between screens or not
	@param bToggleHUD tracks whether to show the Heads-up Display when playing
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
*/
void
updateGame(
		/*Local game states*/
		int nInput, int* nGameEnding, int* nCurrRoom, int* nPrevRoom, int* nCurrProg,

		/*Player stats and inventory*/
		int* nHealth, int* nScore, int* bShinyItem, int* bTorch, int* bRustyKey,

		/*UI and gameplay settings*/
		int* bToggleColor, int* bToggleWait, int* bToggleClear, int* bToggleHUD,
		int* bToggleShowMenu, int* bToggleSimple)
{
	//store the value in nCurrRoom into nPrevRoom before moving to another room
		
	//call the function responsible for the logic of the current room
	switch (*nCurrRoom)
	{
		//Options page
		case -6:
			roomOptionsLogic(nInput, nCurrRoom, nCurrProg,
								bToggleColor, bToggleWait,
								bToggleClear, bToggleHUD,
								bToggleShowMenu, bToggleSimple);
			break;

		//Credits page
		case -5:
			roomCreditsLogic(nInput, nCurrRoom, nCurrProg);
			break;

		//Statistics page
		case -4:
			roomStatisticsLogic(nInput, nCurrRoom, nCurrProg);
			break;

		//Achievements page
		case -3:
			roomAchievementsLogic(nInput, nCurrRoom, nCurrProg);
			break;

		//Menu with continue option
		case -2:
			roomMenuLogic(nInput, nCurrRoom, nCurrProg,
							nGameEnding, nHealth, nScore,
							bShinyItem, bTorch, bRustyKey);
			break;
		
		//Menu page
		case -1:
			roomMenuLogic(nInput, nCurrRoom, nCurrProg,
							nGameEnding, nHealth, nScore,
							bShinyItem, bTorch, bRustyKey);
			break;
		
		//Introduction page
		case 0:
			introductionLogic(nInput, nCurrRoom, nCurrProg);
			break;

		//Room 1
		case 1:
			room1Logic(nInput, nCurrRoom, nCurrProg);
			break;

		//Room 2
		case 2:
			room2Logic(nInput, nCurrRoom, nCurrProg,
						nHealth, nScore);
			break;

		//Room 3
		case 3:
			room3Logic(nInput, nCurrRoom, nCurrProg,
						nScore, bShinyItem);
			break;

		//Room 4
		case 4:
			room4Logic(nInput, nCurrRoom, nCurrProg,
						nHealth);
			break;

		//Room 5
		case 5:
			room5Logic(nInput, nCurrRoom, nCurrProg,
						bTorch);
			break;

		//Room 6
		case 6:
			room6Logic(nInput, nCurrRoom, nCurrProg,
						nHealth, nScore, *bTorch);
			break;

		//Room 7
		case 7:
			room7Logic(nInput, nCurrRoom, nCurrProg);
			break;

		//Room 8
		case 8:
			room8Logic(nInput, nCurrRoom, nCurrProg,
						*bRustyKey);
			break;

		//Room 9
		case 9:
			room9Logic(nInput, nCurrRoom, nCurrProg,
						nGameEnding, nHealth, bRustyKey);
			break;

		//Room 10
		case 10:
			room10Logic(nInput, nCurrRoom, nGameEnding,
							nScore, *bShinyItem);
			break;
	}
}


void
updateAchievements(int nGameEnding, int nMoveCount, int nHealth,
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


void
updateStatistics(
			/*Global game stats*/
			int* nTotalMoveCount, int nTotalInputs, int nTotalInputError, int* nInputSum,
			int* nAverageInput, int* nTotalHealthLost, int* nTotalScore, int* nTotalShinyItem,
			int* nTotalTorchItem, int* nTotalRustyKeyItem,

			/*Local game states*/
			int nInput, int nCurrRoom, int* nMoveCount,

			/*Player stats and inventory*/
			int nHealth, int* nPrevHealth, int nScore, int* nPrevScore,
			int* bShinyItem, int* bTorch, int* bRustyKey
		)
{

	//total move count
	if (nCurrRoom >= 0)
	{
		*nMoveCount += 1;
		*nTotalMoveCount += 1;
	}

	if (nHealth < *nPrevHealth)
	{
		*nTotalHealthLost += *nPrevHealth - nHealth;
		*nPrevHealth = nHealth;
	}

	
	if (nScore > *nPrevScore)
	{
		*nTotalScore += nScore - *nPrevScore;
		*nPrevScore = nScore;
	}


	
	if (*bShinyItem == 1)
	{
		*nTotalShinyItem += 1;
		*bShinyItem += 1;
	}

	if (*bTorch == 1)
	{
		*nTotalTorchItem += 1;
		*bTorch += 1;
	}

	if (*bRustyKey == 1)
	{
		*nTotalRustyKeyItem += 1;
		*bRustyKey += 1;
	}

	//average user inputs
	*nInputSum += nInput;
	*nAverageInput = *nInputSum / (nTotalInputs - nTotalInputError);
}