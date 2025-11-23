/*This file is responsible for deciding and updating the game based
	on the decisions of the player
*/



/* ------------------------ Function Prototypes ------------------------ */
//These functions are responsible for the game logic
void 
getChoice(
	/*Global game states*/
	int* nTotalInputs,
	int* nTotalInputError,

	/*Local game states*/
	int* nInput,
	int nMinInput,
	int nMaxInput,

	/*UI and gameplay settings*/
	int bToggleColor
);

void
updateInputRange(
	/*Local game states*/
	int nCurrRoom,
	int* nMinInput,
	int* nMaxInput
);

void
displayCurrentRoom(
	/*Global game states*/
	int nGameCount,
	int nGameCompletion,
	int nTotalMoveCount,
	int nTotalInputs,
	int nTotalInputError,
	int nAverageInput,
	int nTotalHealthLost,
	int nTotalScore,
	int nTotalShinyItem,
	int nTotalTorchItem,
	int nTotalRustyKeyItem,

	/*Local game states*/
	int nCurrRoom,
	int nPrevRoom,

	/*Player stats*/
	int nHealth,
	int nScore,

	/*Player inventory*/
	int bShinyItem,
	int bTorch,
	int bRustyKey,

	/*Achievements*/
	int bGotEnding1,
	int bGotEnding2,
	int bGotEnding3,
	int bGotEnding4,
	int bGotHealthy,
	int bGotPlentiful,
	int bGotCollector,
	int bGotSpeedrun,
	int bGotCompletionist,

	/*UI and gameplay settings*/
	int bToggleColor,
	int bToggleWait,
	int bToggleClear,
	int bToggleHUD,
	int bToggleShowMenu,
	int bToggleSimple
);

void
updateGame(
	/*Global game count*/
	int* nGameCount,

	/*Local game states*/
	int nInput,
	int* nGameEnding,
	int* nCurrRoom,
	int* nPrevRoom,
	int* nCurrProg,
	int* nMoveCount,

	/*Player stats*/
	int* nHealth,
	int* nScore,
	int* nPrevHealth,
	int* nPrevScore,
	
	/*Player inventory*/
	int* bShinyItem,
	int* bTorch,
	int* bRustyKey,

	/*UI and gameplay settings*/
	int* bToggleColor,
	int* bToggleWait,
	int* bToggleClear,
	int* bToggleHUD,
	int* bToggleShowMenu,
	int* bToggleSimple
);

void
updateAchievements(
	/*Local game states*/
	int nGameEnding,
	int nMoveCount,

	/*Player stats*/
	int nHealth,
	int nScore,

	/*Player inventory*/
	int bShinyItem,
	int bTorch,
	int bRustyKey,

	/*Achievements*/
	int* nGotEnding1,
	int* nGotEnding2,
	int* nGotEnding3, 
	int* nGotEnding4,
	int* nGotHealthy,
	int* nGotPlentiful,
	int* nGotCollector,
	int* nGotSpeedrun,
	int* nGotCompletionist
);

void
updateStatistics(
	/*Global game states*/
	int* nTotalMoveCount,
	int nTotalInputs,
	int nTotalInputError,
	int* nInputSum,
	int* nAverageInput,
	int* nTotalHealthLost,
	int* nTotalScore,
	int* nTotalShinyItem,
	int* nTotalTorchItem,
	int* nTotalRustyKeyItem,

	/*Local game states*/
	int nInput,
	int nCurrRoom,
	int* nMoveCount,

	/*Player stats*/
	int nHealth,
	int nScore,
	int* nPrevHealth,
	int* nPrevScore,

	/*Player inventory*/
	int* bShinyItem,
	int* bTorch,
	int* bRustyKey
);
/* --------------------------------------------------------------------- */



/*
	This function gets the value inputted by the player and
		checks if its valid, if not then it asks again.
	Preconditions: parameters are integers

	//Global game states
	@param *nTotalInputs tracks the total amount of inputs the player has made
	@param *nTotalInputError tracks the total amount of invalid inputs the player has made

	//Local game states
	@param *nInput tracks the player's choice/input
	@param nMinInput tracks the minumum range a player can input
	@param nMaxInput tracks the maximum range a player can input

	//UI and gameplay settings
	@param bToggleColor tracks whether to display color or not
*/
void
getChoice(
	/*Global game states*/
	int* nTotalInputs,
	int* nTotalInputError,
	
	/*Local game states*/
	int* nInput,
	int nMinInput,
	int nMaxInput,
	
	/*UI and gameplay settings*/
	int bToggleColor
)
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
		room the player is in currently.
	Preconditions: nCurrRoom, nMinInput, and nMaxInput are integers
	@param nCurrRoom tracks the current room the player is in
	@param *nMinInput tracks the minumum range a player can input
	@param *nMaxInput tracks the maximum range a player can input
*/
void
updateInputRange(int nCurrRoom, int* nMinInput, int* nMaxInput)
{
	switch (nCurrRoom)
	{
		//Options
		case -6:
			*nMinInput = 0;
			*nMaxInput = 6;
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
			*nMaxInput = 6;
			break;
			
		//Menu
		case -1:
			*nMinInput = 1;
			*nMaxInput = 6;
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
		printing the information for the current room.
	Preconditions: parameters are integers

	//Global game states
	@param nGameCount tracks the amount of games started
	@param nGameCompletion tracks the amount of games that have reached an ending
	@param nTotalMoveCount tracks the total amount of moves the player has made during all games
	@param nTotalInputs tracks the total amount of inputs the player has made
	@param nTotalInputError tracks the total amount of invalid inputs the player has made
	@param nAverageInput tracks the average value of the valid inputs the player has made
	@param nTotalHealthLost tracks the total amount of health the player has lost
	@param nTotalScore tracks the total amount of score the player has gained
	@param nTotalShinyItem tracks the total number of times the player has obtained the shiny item
	@param nTotalTorchItem tracks the total amount of times the player has obtained the torch item
	@param nTotalRustyKeyItem tracks the total amount of times the player has obtained the rusty key item

	//Local game states
	@param nCurrRoom tracks the current room the player is in
	@param nPrevRoom tracks the previous room the player has been during the game

	//Player stats
	@param nHealth tracks the current health of the player
	@param nScore tracks the current score of the player

	//Player inventory
	@param bShinyItem tracks whether the player has the Shiny Item or not
	@param bTorch tracks whether the player has the Torch or not
	@param bRustyKey tracks whether the player has the Rusty Key or not

	//Achievements
	@param nGotEnding1 tracks the amount of times the player has achieved the achievement "Ending 1"
	@param nGotEnding2 tracks the amount of times the player has achieved the achievement "Ending 2"
	@param nGotEnding3 tracks the amount of times the player has achieved the achievement "Ending 3"
	@param nGotEnding4 tracks the amount of times the player has achieved the achievement "Ending 4"
	@param nGotHealthy tracks the amount of times the player has achieved the achievement "Healthy"
	@param nGotPlentiful tracks the amount of times the player has achieved the achievement "Plentiful"
	@param nGotSpeedrun tracks the amount of times the player has achieved the achievement "Speedrun"
	@param nGotCollector tracks the amount of times the player has achieved the achievement "Collector"
	@param nGotCompletionist tracks the amount of times the player has achieved the achievement "Completionist"

	//UI and gameplay settings
	@param bToggleColor tracks whether to display color or not
	@param bToggleWait tracks whether there is a pause between dialogues or not
	@param bToggleClear tracks whether to clear the screen when moving between screens or not
	@param bToggleHUD tracks whether to show the Heads-up Display when playing
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
	@param bToggleSimple tracks whether to display simplified dialogue or not
*/
void
displayCurrentRoom(
	/*Global game states*/
	int nGameCount,
	int nGameCompletion,
	int nTotalMoveCount,
	int nTotalInputs,
	int nTotalInputError,
	int nAverageInput,
	int nTotalHealthLost,
	int nTotalScore,
	int nTotalShinyItem,
	int nTotalTorchItem,
	int nTotalRustyKeyItem,

	/*Local game states*/
	int nCurrRoom,
	int nPrevRoom,

	/*Player stats*/
	int nHealth,
	int nScore,

	/*Player inventory*/
	int bShinyItem,
	int bTorch,
	int bRustyKey,

	/*Achievements*/
	int bGotEnding1,
	int bGotEnding2,
	int bGotEnding3,
	int bGotEnding4,
	int bGotHealthy,
	int bGotPlentiful,
	int bGotCollector,
	int bGotSpeedrun,
	int bGotCompletionist,

	/*UI and gameplay settings*/
	int bToggleColor,
	int bToggleWait,
	int bToggleClear,
	int bToggleHUD,
	int bToggleShowMenu,
	int bToggleSimple
)
{
	//display the HUD whenever the player is in a game room and its enabled
	if (nCurrRoom >= 0 && bToggleHUD)
		displayPlayerHUD(nHealth, nScore, bShinyItem,
						bTorch, bRustyKey, bToggleColor,
						bToggleHUD);

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
				/*Global game states*/
				nGameCount, nGameCompletion, nTotalMoveCount, nTotalInputs,
				nTotalInputError, nAverageInput, nTotalHealthLost, nTotalScore,
				nTotalShinyItem, nTotalTorchItem, nTotalRustyKeyItem,

				/*UI and gameplay settings*/
				bToggleColor
			);
			break;
			
		//Achievements page
		case -3:
			displayAchievements(
				/*Achievements*/
				bGotEnding1, bGotEnding2, bGotEnding3, bGotEnding4,
				bGotHealthy, bGotPlentiful, bGotCollector, bGotSpeedrun,
				bGotCompletionist,

				/*UI and gameplay settings*/
				bToggleColor
			);
			break;

		//Menu with continue choice
		case -2:
		//Intentional fallthrough

		//Menu page
		case -1:
			displayMenu(nCurrRoom, bToggleColor);
			break;
		
		//Introduction
		case 0:
			displayIntroduction(
				/*UI and gameplay settings*/
				bToggleColor,
				bToggleWait,
				bToggleShowMenu,
				bToggleSimple
			);
			break;
		
		//Room 1
		case 1:
			displayRoom1(
				/*UI and gameplay settings*/
				bToggleColor,
				bToggleWait,
				bToggleShowMenu,
				bToggleSimple
			);
			break;

		//Room 2
		case 2:
			displayRoom2(
				/*Local game states*/
				nPrevRoom,

				/*UI and gameplay settings*/
				bToggleColor,
				bToggleWait,
				bToggleShowMenu,
				bToggleSimple
			);
			break;

		//Room 3
		case 3:
			displayRoom3(
				/*Local game states*/
				nPrevRoom,

				/*UI and gameplay settings*/
				bToggleColor,
				bToggleWait,
				bToggleShowMenu,
				bToggleSimple
			);
			break;

		//Room 4
		case 4:
			displayRoom4(
				/*Local game states*/
				nPrevRoom,

				/*Player inventory*/
				bShinyItem,

				/*UI and gameplay settings*/
				bToggleColor,
				bToggleWait,
				bToggleShowMenu,
				bToggleSimple
			);
			break;

		//Room 5
		case 5:
			displayRoom5(
				/*Local game states*/
				nPrevRoom,

				/*Player stats*/
				nHealth,
				nScore,

				/*UI and gameplay settings*/
				bToggleColor,
				bToggleWait,
				bToggleShowMenu,
				bToggleSimple
			);
			break;

		//Room 6
		case 6:
			displayRoom6(
				/*Local game states*/
				nPrevRoom,

				/*Player inventory*/
				bTorch,

				/*UI and gameplay settings*/
				bToggleColor,
				bToggleWait,
				bToggleShowMenu,
				bToggleSimple
			);
			break;

		//Room 7
		case 7:
			displayRoom7(
				/*Local game states*/
				nPrevRoom,

				/*Player inventory*/
				bTorch,

				/*UI and gameplay settings*/
				bToggleColor,
				bToggleWait,
				bToggleShowMenu,
				bToggleSimple
			);
			break;

		//Room 8
		case 8:
			displayRoom8(
				/*Local game states*/
				nPrevRoom,

				/*Player inventory*/
				bRustyKey,

				/*UI and gameplay settings*/
				bToggleColor,
				bToggleWait,
				bToggleShowMenu,
				bToggleSimple
			);
			break;

		//Room 9
		case 9:
			displayRoom9(
				/*Local game states*/
				nPrevRoom,

				/*UI and gameplay settings*/
				bToggleColor,
				bToggleWait,
				bToggleShowMenu,
				bToggleSimple
			);
			break;

		//Room 10
		case 10:
			displayRoom10(
				/*Local game states*/
				nPrevRoom,

				/*Player inventory*/
				bShinyItem,

				/*UI and gameplay settings*/
				bToggleColor,
				bToggleWait,
				bToggleShowMenu,
				bToggleSimple
			);
			break;
	}
}


/*
	This function is responsible for updating the game based on the input of the player.
	Preconditions: parameters are integers

	//Global game states
	@param nGameCount tracks the amount of games started

	//Local game states
	@param nInput tracks the player's choice/input
	@param *nGameEnding tracks the ending the player will receive
	@param *nCurrRoom tracks the current room the player is in
	@param *nPrevRoom tracks the previous room the player has been during the game
	@param *nCurrProg tracks the current progress of an ongoing game

	//Player stats
	@param *nHealth tracks the current health of the player
	@param *nScore tracks the current score of the player

	//Player inventory
	@param *bShinyItem tracks whether the player has the Shiny Item or not
	@param *bTorch tracks whether the player has the Torch or not
	@param *bRustyKey tracks whether the player has the Rusty Key or not

	//UI and gameplay settings
	@param *bToggleColor tracks whether to display color or not
	@param *bToggleWait tracks whether there is a pause between dialogues or not
	@param *bToggleClear tracks whether to clear the screen when moving between screens or not
	@param *bToggleHUD tracks whether to show the Heads-up Display when playing
	@param *bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
	@param *bToggleSimple tracks whether to display simplified dialogue or not
*/
void
updateGame(
	/*Global game states*/
	int* nGameCount,

	/*Local game states*/
	int nInput,
	int* nGameEnding,
	int* nCurrRoom,
	int* nPrevRoom,
	int* nCurrProg,
	int* nMoveCount,

	/*Player stats*/
	int* nHealth,
	int* nScore,
	int* nPrevHealth,
	int* nPrevScore,
	
	/*Player inventory*/
	int* bShinyItem,
	int* bTorch,
	int* bRustyKey,

	/*UI and gameplay settings*/
	int* bToggleColor,
	int* bToggleWait,
	int* bToggleClear,
	int* bToggleHUD,
	int* bToggleShowMenu,
	int* bToggleSimple
)
{
	//call the function responsible for the logic of the current room
	switch (*nCurrRoom)
	{
		//Options page
		case -6:
			roomOptionsLogic(
				/*Local game states*/
				nInput,
				nCurrRoom,
				nCurrProg,

				/*UI and gameplay settings*/
				bToggleColor,
				bToggleWait,
				bToggleClear,
				bToggleHUD,
				bToggleShowMenu,
				bToggleSimple
			);
			break;

		//Credits page
		case -5:
			roomCreditsLogic(
				/*Local game states*/
				nInput,
				nCurrRoom,
				nCurrProg
			);
			break;

		//Statistics page
		case -4:
			roomStatisticsLogic(
				/*Local game states*/
				nInput,
				nCurrRoom,
				nCurrProg
			);
			break;

		//Achievements page
		case -3:
			roomAchievementsLogic(
				/*Local game states*/
				nInput,
				nCurrRoom,
				nCurrProg
			);
			break;

		//Menu with continue option
		case -2:
		//Intentional Fallthrough
		
		//Menu page
		case -1:
			roomMenuLogic(
				/*Global game states*/
				nGameCount,

				/*Local game states*/
				nInput,
				nGameEnding,
				nCurrRoom,
				nPrevRoom,
				nCurrProg,
				nMoveCount,

				/*Player stats*/
				nHealth,
				nScore,
				nPrevHealth,
				nPrevScore,

				/*Player inventory*/
				bShinyItem,
				bTorch,
				bRustyKey
			);
			break;
		
		//Introduction page
		case 0:
			introductionLogic(
				/*Local game states*/
				nInput,
				nCurrRoom,
				nPrevRoom,
				nCurrProg
			);
			break;

		//Room 1
		case 1:
			room1Logic(
				/*Local game states*/
				nInput,
				nCurrRoom,
				nPrevRoom,
				nCurrProg
			);
			break;

		//Room 2
		case 2:
			room2Logic(
				/*Local game states*/
				nInput,
				nCurrRoom,
				nPrevRoom,
				nCurrProg,

				/*Player stats*/
				nHealth,
				nScore
			);
			break;

		//Room 3
		case 3:
			room3Logic(
				/*Local game states*/
				nInput,
				nCurrRoom,
				nPrevRoom,
				nCurrProg,

				/*Player stats*/
				nScore,

				/*Player inventory*/
				bShinyItem
			);
			break;

		//Room 4
		case 4:
			room4Logic(
				/*Local game states*/
				nInput,
				nCurrRoom,
				nPrevRoom,
				nCurrProg,

				/*Player stats*/
				nHealth
			);
			break;

		//Room 5
		case 5:
			room5Logic(
				/*Local game states*/
				nInput,
				nCurrRoom,
				nPrevRoom,
				nCurrProg,

				/*Player inventory*/
				bTorch
			);
			break;

		//Room 6
		case 6:
			room6Logic(
				/*Local game states*/
				nInput,
				nCurrRoom,
				nPrevRoom,
				nCurrProg,

				/*Player stats*/
				nHealth,
				nScore,

				/*Player inventory*/
				*bTorch
			);
			break;

		//Room 7
		case 7:
			room7Logic(
				/*Local game states*/
				nInput,
				nCurrRoom,
				nPrevRoom,
				nCurrProg
			);
			break;

		//Room 8
		case 8:
			room8Logic(
				/*Local game states*/
				nInput,
				nCurrRoom,
				nPrevRoom,
				nCurrProg,

				/*Player inventory*/
				*bRustyKey
			);
			break;

		//Room 9
		case 9:
			room9Logic(
				/*Local game states*/
				nInput,
				nCurrRoom,
				nPrevRoom,
				nCurrProg,
				nGameEnding,

				/*Player stats*/
				nHealth,

				/*Player inventory*/
				bRustyKey
			);
			break;

		//Room 10
		case 10:
			room10Logic(
				/*Local game states*/
				nInput,
				nCurrRoom,
				nGameEnding,

				/*Player stats*/
				nScore,

				/*Player inventory*/
				*bShinyItem
			);
			break;
	}
}


/*
	This function is responsible for updating the achievement variables whenever the
		player has achieved them.
	Preconditions: parameters are integers

	//Local game states
	@param nGameEnding tracks the ending the player will receive
	@param nMoveCount tracks the number of rooms the player has been in
	
	//Player stats
	@param nHealth tracks the current health of the player
	@param nScore tracks the current score of the player

	//Player inventory
	@param bShinyItem tracks whether the player has the Shiny Item or not
	@param bTorch tracks whether the player has the Torch or not
	@param bRustyKey tracks whether the player has the Rusty Key or not

	//Achievements
	@param *nGotEnding1 tracks the amount of times the player has achieved the achievement "Ending 1"
	@param *nGotEnding2 tracks the amount of times the player has achieved the achievement "Ending 2"
	@param *nGotEnding3 tracks the amount of times the player has achieved the achievement "Ending 3"
	@param *nGotEnding4 tracks the amount of times the player has achieved the achievement "Ending 4"
	@param *nGotHealthy tracks the amount of times the player has achieved the achievement "Healthy"
	@param *nGotPlentiful tracks the amount of times the player has achieved the achievement "Plentiful"
	@param *nGotSpeedrun tracks the amount of times the player has achieved the achievement "Speedrun"
	@param *nGotCollector tracks the amount of times the player has achieved the achievement "Collector"
	@param *nGotCompletionist tracks the amount of times the player has achieved the achievement "Completionist"
*/
void
updateAchievements(
	/*Local game states*/
	int nGameEnding,
	int nMoveCount,

	/*Player stats*/
	int nHealth,
	int nScore,

	/*Player inventory*/
	int bShinyItem,
	int bTorch,
	int bRustyKey,

	/*Achievements*/
	int* nGotEnding1,
	int* nGotEnding2,
	int* nGotEnding3, 
	int* nGotEnding4,
	int* nGotHealthy,
	int* nGotPlentiful,
	int* nGotCollector,
	int* nGotSpeedrun,
	int* nGotCompletionist
)
{
	//Ending achievements
	switch (nGameEnding)
	{
		case 1:
			*nGotEnding1 += 1;
			break;
		
		case 2:
			*nGotEnding2 += 1;
			break;

		case 3:
			*nGotEnding3 += 1;
			break;

		case 4:
			*nGotEnding4 += 1;
			break;
	}

	//Other achievements
	if (nHealth >= 40)
		*nGotHealthy += 1;

	if (nScore >= 30)
		*nGotPlentiful += 1;

	if (bShinyItem && bTorch && bRustyKey)
		*nGotCollector += 1;

	if (nMoveCount <= 10)
		*nGotSpeedrun += 1;

	if (*nGotEnding1 && *nGotEnding2 &&*nGotEnding3 &&  *nGotEnding4 && 
			*nGotHealthy && *nGotPlentiful && *nGotCollector && *nGotSpeedrun)
		*nGotCompletionist += 1;
}


/*
	This function is responsible for updating the different statistic variables
	Preconditions: parameters are integers

	//Global game states
	@param *nGameCompletion tracks the amount of games that have reached an ending
	@param *nTotalMoveCount tracks the total amount of moves the player has made during all games
	@param *nTotalInputs tracks the total amount of inputs the player has made
	@param *nTotalInputError tracks the total amount of invalid inputs the player has made
	@param *nInputSum tracks the sum of all the valid inputs the player has made
	@param *nAverageInput tracks the average value of the valid inputs the player has made
	@param *nTotalHealthLost tracks the total amount of health the player has lost
	@param *nTotalScore tracks the total amount of score the player has gained
	@param *nTotalShinyItem tracks the total number of times the player has obtained the shiny item
	@param *nTotalTorchItem tracks the total amount of times the player has obtained the torch item
	@param *nTotalRustyKeyItem tracks the total amount of times the player has obtained the rusty key item

	//Local game states
	@param nInput tracks the player's choice/input
	@param nCurrRoom tracks the current room the player is in
	@param *nMoveCount tracks the number of rooms the player has been in

	//Player stats
	@param nHealth tracks the current health of the player
	@param nScore tracks the current score of the player
	@param *nPrevHealth tracks the previous health of the player
	@param *nPrevScore tracks the previous score of the player

	//Player inventory
	@param *bShinyItem tracks whether the player has the Shiny Item or not
	@param *bTorch tracks whether the player has the Torch or not
	@param *bRustyKey tracks whether the player has the Rusty Key or not
*/
void
updateStatistics(
	/*Global game states*/
	int* nTotalMoveCount,
	int nTotalInputs,
	int nTotalInputError,
	int* nInputSum,
	int* nAverageInput,
	int* nTotalHealthLost,
	int* nTotalScore,
	int* nTotalShinyItem,
	int* nTotalTorchItem,
	int* nTotalRustyKeyItem,

	/*Local game states*/
	int nInput,
	int nCurrRoom,
	int* nMoveCount,

	/*Player stats*/
	int nHealth,
	int nScore,
	int* nPrevHealth,
	int* nPrevScore,

	/*Player inventory*/
	int* bShinyItem,
	int* bTorch,
	int* bRustyKey
)
{
	//compute the average user input
	*nInputSum += nInput;
	*nAverageInput = *nInputSum / (nTotalInputs - nTotalInputError);

	//total move count
	if (nCurrRoom >= 0)
	{
		*nMoveCount += 1;
		*nTotalMoveCount += 1;
	}

	//total health lost
	if (nHealth < *nPrevHealth)
	{
		*nTotalHealthLost += *nPrevHealth - nHealth;
		*nPrevHealth = nHealth;
	}

	//total score gained
	if (nScore > *nPrevScore)
	{
		*nTotalScore += nScore - *nPrevScore;
		*nPrevScore = nScore;
	}


	//total shiny item obtained
	if (*bShinyItem == 1)
	{
		*nTotalShinyItem += 1;
		*bShinyItem += 1;
	}

	//total torch item obtained
	if (*bTorch == 1)
	{
		*nTotalTorchItem += 1;
		*bTorch += 1;
	}

	//total rusty key item obtained
	if (*bRustyKey == 1)
	{
		*nTotalRustyKeyItem += 1;
		*bRustyKey += 1;
	}
}