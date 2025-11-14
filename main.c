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
	Last Modified: November 15, 2025
	Version: 1.17
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
#include <stdlib.h>
#include <unistd.h>
#include "display.h"
#include "roomLogic.h"
#include "gameLogic.h"


/* ------------------------ Function Prototypes ------------------------ */

/* --------------------------------------------------------------------- */




int main()
{
	//Tracks game settings
	int bToggleColor = 1;
	int bToggleWait = 1;
	int bToggleClear = 1;
	int bToggleHUD = 1;
	int bToggleShowMenu = 1;
	int bToggleSimple = 1;

	//tracks global game state
	int nGameCount = 0; //tracks the amount of games started
	int nGameCompletion = 0; // tracks the amount of completions
	int nTotalMoveCount = 0;
	int nTotalInputs = 0;
	int nTotalInputError = 0;
	int nInputSum = 0;
	int nAverageInput = 0;
	int nTotalHealthLost = 0;
	int nTotalScore = 0;
	int nTotalShinyItem = 0;
	int nTotalTorchItem = 0;
	int nTotalRustyKeyItem = 0;

	//tracks game state
	int nGameEnding = 1; //tracks the ending the player will receive
	int nCurrRoom = -1; // tracks the current room the player is in
	int nPrevRoom = 0; //tracks the previous room the player has been during the game
	int nCurrProg = -1; //tracks total progress of the game by rooms; does not include the menu
	int nInput = 0; //tracks the player's choice
	int nMinInput = 0; //tracks the minumum range a player can input
	int nMaxInput = 0; //tracks the maximum range a player can input
	int nMoveCount = 0; //tracks the number of rooms the player has been in
	
	//player stats
	int nHealth = 50; //default health is 50
	int nPrevHealth = 50;
	int nScore = 0; //default score is 0
	int nPrevScore = 0;
	
	//player items
	int bShinyItem = 0; //tracks whether the player has the item "shiny item" or not
	int bTorch = 0; //tracks whether the player has the item "torch" or not
	int bRustyKey = 0; //tracks whether the player has the item "rusty key" or not

	//tracks achievements
	int bGotEnding1 = 0;
	int bGotEnding2 = 0;
	int bGotEnding3 = 0;
	int bGotEnding4 = 0;
	int bGotHealthy = 0;
	int bGotPlentiful = 0;
	int bGotSpeedrun = 0;
	int bGotCollector = 0;
	int bGotCompletionist = 0;



//main loop - This loop decides to end the program if the player wishes to exit the program
while (nGameEnding)
{
	//game loop
	while (nHealth > 0 && nGameEnding == 1)
	{
		//clear the screen
		clearScreen(bToggleClear);
		
		printf("Previous room: %d\n", nPrevRoom);

		//display the room the player is currently in
		displayCurrentRoom(
			/*Global game stats*/
			nGameCount, nGameCompletion, nTotalMoveCount, nTotalInputs,
			nTotalInputError, nAverageInput, nTotalHealthLost, nTotalScore,
			nTotalShinyItem, nTotalTorchItem, nTotalRustyKeyItem,

			/*Local game states*/
			nCurrRoom, nCurrProg,

			/*Player stats and inventory*/
			nHealth, nScore, bShinyItem, bTorch, bRustyKey,
			
			/*Achievements*/
			bGotEnding1, bGotEnding2, bGotEnding3, bGotEnding4,
			bGotHealthy, bGotPlentiful, bGotCollector, bGotSpeedrun,
			bGotCompletionist,
			
			/*UI and gameplay settings*/
			bToggleColor, bToggleWait, bToggleClear, bToggleHUD,
			bToggleShowMenu, bToggleSimple
		);


		//update the minimum and maximum integer the player can input depending on the room
		updateInputRange(nCurrRoom, &nMinInput, &nMaxInput);


		//ask for the player to input their choice
		getChoice(&nTotalInputs, &nTotalInputError, &nInput, nMinInput, nMaxInput, bToggleColor);


		//update the game
		updateGame(
			/*Local game states*/
			nInput, &nGameEnding, &nCurrRoom, &nPrevRoom, &nCurrProg,

			/*Player stats and inventory*/
			&nHealth, &nScore, &bShinyItem, &bTorch, &bRustyKey,
			
			/*UI and gameplay settings*/
			&bToggleColor, &bToggleWait, &bToggleClear, &bToggleHUD,
			&bToggleShowMenu, &bToggleSimple);


		//update the game
		updateStatistics(
			/*Global game stats*/
			&nTotalMoveCount, nTotalInputs, nTotalInputError, &nInputSum,
			&nAverageInput, &nTotalHealthLost, &nTotalScore, &nTotalShinyItem,
			&nTotalTorchItem, &nTotalRustyKeyItem,

			/*Local game states*/
			nInput, nCurrRoom, &nMoveCount,

			/*Player stats and inventory*/
			nHealth, &nPrevHealth, nScore, &nPrevScore,
			&bShinyItem, &bTorch, &bRustyKey
		);
	}


	//increment the variable nGameCompletion since when the loop ends an ending has been reached
	nGameCompletion++;


	//ending loop
	while (nCurrProg != -1 && nGameEnding)
	{
		//clear the screen
		clearScreen(bToggleClear);


		//update achievements
		updateAchievements(
			/*Local game states*/
			nGameEnding, nMoveCount,
			
			/*Player stats and inventory*/
			nHealth, nScore, bShinyItem, bTorch, bRustyKey,

			/*Achievements*/
			&bGotEnding1, &bGotEnding2, &bGotEnding3, &bGotEnding4,
			&bGotHealthy, &bGotPlentiful, &bGotCollector, &bGotSpeedrun,
			&bGotCompletionist
		);


		//display the ending page
		displayEndingPage(
			/*Local game states*/
			nGameEnding,
			
			/*Player stats and inventory*/
			nHealth, nScore, bShinyItem, bTorch, bRustyKey,

			/*Achievements*/
			bGotEnding1, bGotEnding2, bGotEnding3, bGotEnding4,
			bGotHealthy, bGotPlentiful, bGotCollector, bGotSpeedrun,
			bGotCompletionist
		);


		//display choices
		printf("Choices:\n\n");
		printf("1. Return to menu\n\n");
		printf("2. Quit\n\n");


		//update the input range
		nMinInput = 1;
		nMaxInput = 2;


		//get the player choice and respond
		getChoice(&nTotalInputs, &nTotalInputError, &nInput, nMinInput, nMaxInput, bToggleColor);


		//respond to the player's choice
		roomEndingLogic(
			/*Local game states*/
			nInput, &nCurrRoom, &nCurrProg, &nGameEnding, &nMoveCount,
			
			/*Player stats and inventory*/
			&nHealth, &nScore, &bShinyItem, &bTorch, &bRustyKey);
	}
}

	//display ending thank you message
	printf("Thank You For Playing!\n");

    return 0;
}
