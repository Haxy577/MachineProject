/********************************************************************************************
*
This is to certify that this project is my own work, based on my personal efforts in studying
and applying the concepts learned. I have constructed the functions and their respective
algorithms and corresponding code by myself. The program was run, tested, and debugged
by my own efforts. I further certify that I have not copied in part or whole or otherwise
plagiarized the work of other students and/or persons.
										 Richmond Jase Von M. Salvador, DLSU ID# 12506338
*********************************************************************************************
*/



/*
	Description: A menu-driven text-based adventure game written in C.
					It demonstrates the use of functions, loops, and
					pointers.
	Programmed by: Richmond Jase Von M. Salvador  S15B
	Last Modified: November 23, 2025
	Version: 1.20
	Acknowledgements:	https://www.asciiart.eu/text-to-ascii-art -> for providing the title art
						https://www.asciiart.eu/art-and-design/borders -> for providing the border for the ending page
						https://patorjk.com/software/taag/ -> for providing the ascii art for the achievements
						https://en.wikipedia.org/wiki/ANSI_escape_code -> for the changing the color code
						https://stackoverflow.com/questions/7898215/how-can-i-clear-an-input-buffer-in-c -> for the scanf fix
						https://docs.google.com/document/d/1A6FD6wY_JtmRuOXaPN6XP9McPrFmBW8s0fMwnb_uHkI/edit?usp=sharing -> the document with all of the dialogue
						https://github.com/Haxy577/MachineProject.git -> repository of the project
	Compiled with: gcc -Wall -Wextra -pedantic -Werror -std=c99 -g main.c -o out
*/

#include <stdio.h>
#include <windows.h>
#include "display.h"
#include "roomLogic.h"
#include "gameLogic.h"


/* ------------------------ Function Prototypes ------------------------ */

/* --------------------------------------------------------------------- */




int main()
{
	//declare variables
	/*Global game states*/
	int nGameCount = 0;				//tracks the amount of games started
	int nGameCompletion = 0;		//tracks the amount of games that have reached an ending
	int nTotalMoveCount = 0;		//tracks the total amount of moves the player has made during all games
	int nTotalInputs = 0;			//tracks the total amount of inputs the player has made
	int nTotalInputError = 0;		//tracks the total amount of invalid inputs the player has made
	int nInputSum = 0;				//tracks the sum of all the valid inputs the player has made
	int nAverageInput = 0;			//tracks the average value of the valid inputs the player has made
	int nTotalHealthLost = 0;		//tracks the total amount of health the player has lost
	int nTotalScore = 0;			//tracks the total amount of score the player has gained
	int nTotalShinyItem = 0;		//tracks the total number of times the player has obtained the shiny item
	int nTotalTorchItem = 0;		//tracks the total amount of times the player has obtained the torch item
	int nTotalRustyKeyItem = 0;		//tracks the total amount of times the player has obtained the rusty key item

	/*Local game states*/
	int nGameEnding = 1;			//tracks the ending the player will receive
	int nCurrRoom = -1;				//tracks the current room the player is in
	int nPrevRoom = 0;				//tracks the previous room the player has been during the game
	int nCurrProg = 0;				//tracks total progress of the game by rooms. This does not include the menu
	int nInput = 0;					//tracks the player's choice/input
	int nMinInput = 1;				//tracks the minumum range a player can input
	int nMaxInput = 6;				//tracks the maximum range a player can input
	int nMoveCount = 0;				//tracks the number of rooms the player has been in
	
	/*Player stats*/
	int nHealth = 50;				//tracks the current health of the player during a game
	int nScore = 0;					//tracks the current score of the player during a game
	int nPrevHealth = 50;			//tracks the previous health of the player during a game
	int nPrevScore = 0;				//tracks the previous score of the player during a game
	
	/*Player inventory*/
	int bShinyItem = 0;				//tracks whether the player has the item "shiny item" or not
	int bTorch = 0;					//tracks whether the player has the item "torch" or not
	int bRustyKey = 0;				//tracks whether the player has the item "rusty key" or not

	/*Achievements*/
	int nGotEnding1 = 0;			//tracks the amount of times the player has achieved the achievement "Ending 1"
	int nGotEnding2 = 0;			//tracks the amount of times the player has achieved the achievement "Ending 2"
	int nGotEnding3 = 0;			//tracks the amount of times the player has achieved the achievement "Ending 3"
	int nGotEnding4 = 0;			//tracks the amount of times the player has achieved the achievement "Ending 4"
	int nGotHealthy = 0;			//tracks the amount of times the player has achieved the achievement "Healthy"
	int nGotPlentiful = 0;			//tracks the amount of times the player has achieved the achievement "Plentiful"
	int nGotSpeedrun = 0;			//tracks the amount of times the player has achieved the achievement "Speedrun"
	int nGotCollector = 0;			//tracks the amount of times the player has achieved the achievement "Collector"
	int nGotCompletionist = 0;		//tracks the amount of times the player has achieved the achievement "Completionist"

	/*Gameplay and UI settings*/
	int bToggleColor = 1;			//tracks whether to display color or not
	int bToggleWait = 1;			//tracks whether there is a delay between dialogues or not
	int bToggleClear = 1;			//tracks whether to clear the screen when moving between screens or not
	int bToggleHUD = 1;				//tracks whether to show the Heads-up Display when playing
	int bToggleShowMenu = 1;		//tracks whether to display the option "0. Return to menu" when playing
	int bToggleSimple = 1;			//tracks whether to display simplified dialogue or not



//main loop - This loop decides to end the program if the player wishes to exit the program
while (nGameEnding)
{
	//game loop
	while (nHealth > 0 && nGameEnding == 1)
	{
		//clear the screen
		clearScreen(bToggleClear);

		//display the room the player is currently in
		displayCurrentRoom(
			/*Global game states*/
			nGameCount,
			nGameCompletion,
			nTotalMoveCount,
			nTotalInputs,
			nTotalInputError,
			nAverageInput,
			nTotalHealthLost,
			nTotalScore,
			nTotalShinyItem,
			nTotalTorchItem,
			nTotalRustyKeyItem,

			/*Local game states*/
			nCurrRoom,
			nPrevRoom,
			nCurrProg,

			/*Player stats*/
			nHealth,
			nScore,
			
			/*Player inventory*/
			bShinyItem,
			bTorch,
			bRustyKey,
			
			/*Achievements*/
			nGotEnding1,
			nGotEnding2,
			nGotEnding3,
			nGotEnding4,
			nGotHealthy,
			nGotPlentiful,
			nGotCollector,
			nGotSpeedrun,
			nGotCompletionist,
			
			/*UI and gameplay settings*/
			bToggleColor,
			bToggleWait,
			bToggleClear,
			bToggleHUD,
			bToggleShowMenu,
			bToggleSimple
		);


		//update the minimum and maximum integer the player can input depending on the room
		updateInputRange(
			/*Local game states*/
			nCurrRoom,
			&nMinInput,
			&nMaxInput
		);


		//ask for the player to input their choice
		getChoice(
			/*Global game states*/
			&nTotalInputs,
			&nTotalInputError,
			
			/*Local game states*/
			&nInput,
			nMinInput,
			nMaxInput,
			
			/*UI and gameplay settings*/
			bToggleColor
		);


		//update the game
		updateGame(
			/*Global game states*/
			&nGameCount,

			/*Local game states*/
			nInput,
			&nGameEnding,
			&nCurrRoom,
			&nPrevRoom,
			&nCurrProg,
			&nMoveCount,

			/*Player stats*/
			&nHealth,
			&nScore,
			&nPrevHealth,
			&nPrevScore,

			/*Player inventory*/
			&bShinyItem,
			&bTorch,
			&bRustyKey,

			/*UI and gameplay settings*/
			&bToggleColor,
			&bToggleWait,
			&bToggleClear,
			&bToggleHUD,
			&bToggleShowMenu,
			&bToggleSimple
		);


		//update the game statistics
		updateStatistics(
			/*Global game stats*/
			&nTotalMoveCount,
			nTotalInputs,
			nTotalInputError,
			&nInputSum,	
			&nAverageInput,
			&nTotalHealthLost,
			&nTotalScore,
			&nTotalShinyItem,
			&nTotalTorchItem,
			&nTotalRustyKeyItem,

			/*Local game states*/
			nInput,
			nCurrRoom,
			&nMoveCount,

			/*Player stats*/
			nHealth,
			nScore,
			&nPrevHealth,
			&nPrevScore,

			/*Player inventory*/
			&bShinyItem,
			&bTorch,
			&bRustyKey
		);
	}



	//increment the variable nGameCompletion since when the loop ends an ending has been reached
	nGameCompletion++;


	//ending loop
	while (nCurrProg != 0 && nGameEnding)
	{
		//clear the screen
		clearScreen(bToggleClear);


		//update achievements
		updateAchievements(
			/*Local game states*/
			nGameEnding, 
			nMoveCount,
			
			/*Player stats*/
			nHealth,
			nScore,
			
			/*Player inventory*/
			bShinyItem,
			bTorch,
			bRustyKey,

			/*Achievements*/
			&nGotEnding1,
			&nGotEnding2,
			&nGotEnding3,
			&nGotEnding4,
			&nGotHealthy,
			&nGotPlentiful,
			&nGotCollector,
			&nGotSpeedrun,
			&nGotCompletionist
		);


		//display the ending page
		displayEndingPage(
			/*Local game states*/
			nGameEnding,
			
			/*Player stats*/
			nHealth,
			nScore,
			
			/*Player inventory*/
			bShinyItem,
			bTorch,
			bRustyKey,

			/*Achievements*/
			&nGotEnding1,
			&nGotEnding2,
			&nGotEnding3,
			&nGotEnding4,
			&nGotHealthy,
			&nGotPlentiful,
			&nGotCollector,
			&nGotSpeedrun,
			&nGotCompletionist,

			/*UI and gameplay settings*/
			bToggleColor,
			bToggleWait,
			bToggleSimple
		);


		//display choices
		printf("Choices:\n\n");
		printf("1. Return to menu\n\n");
		printf("2. Quit\n\n");


		//update the input range
		nMinInput = 1;
		nMaxInput = 2;


		//get the player choice and respond
		getChoice(
			/*Global game states*/
			&nTotalInputs,
			&nTotalInputError,
			
			/*Local game states*/
			&nInput,
			nMinInput,
			nMaxInput,
			
			/*UI and gameplay settings*/
			bToggleColor
		);


		//respond to the player's choice
		roomEndingLogic(
			/*Local game states*/
			nInput,
			&nCurrRoom,
			&nPrevRoom,
			&nCurrProg,
			&nGameEnding,
			&nMoveCount,
			
			/*Player stats*/
			&nHealth,
			&nScore,
			&nPrevHealth,
			&nPrevScore,
			
			/*Player inventory*/
			&bShinyItem,
			&bTorch,
			&bRustyKey
		);
	}
}

	//display ending thank you message
	printf("Thank You For Playing!\n");

    return 0;
}
