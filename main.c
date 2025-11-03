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
	Last Modified: November 3, 2025
	Version: 1.15
	Acknowledgements:	https://www.asciiart.eu/text-to-ascii-art -> for providing the title art
						https://www.asciiart.eu/art-and-design/borders -> for providing the border for the ending page
						https://patorjk.com/software/taag/ -> for providing the ascii art for the achievements
						https://en.wikipedia.org/wiki/ANSI_escape_code -> for the changing the color code
						https://stackoverflow.com/questions/7898215/how-can-i-clear-an-input-buffer-in-c -> for the scanf fix
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


/*
Ideas for additional content:
1. Make a gambling house where the player can bet their points
2. Make points actually useful like tying points to the player's strength. Something like experience points.
3. Add a secret ending maybe?
4. Boss fight? definitely
5. Add achievements
*/


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
	int nGameCount = 0; //tracks the amount of completions

	//tracks game state
	int nGameEnding = 1; //tracks the ending the player will receive
	int nCurrRoom = -1; // tracks the current room the player is in
	int nCurrProg = 0; //tracks total progress of the game by rooms; does not include the menu
	int nInput = 0; //tracks the player's choice
	int nMinInput = 0; //tracks the minumum range a player can input
	int nMaxInput = 0; //tracks the maximum range a player can input
	int nMoveCount = 0; //tracks the number of rooms the player has been in
	
	//player stats
	int nHealth = 50; //default health is 50
	int nScore = 0; //default score is 0
	
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
		
		//display the room the player is currently in
		displayCurrentRoom(nCurrRoom, nCurrProg, nHealth,
							nScore, bShinyItem, bTorch,
							bRustyKey, bToggleColor, bToggleWait,
							bToggleClear, bToggleHUD, bToggleShowMenu,
							bToggleSimple);

		//update the minimum and maximum integer the player can input depending on the room
		updateInputRange(nCurrRoom, &nMinInput, &nMaxInput);

		//ask for the player to input their choice
		getChoice(&nInput, nMinInput, nMaxInput, bToggleColor);
		
		//update the game
		updateGame(&nInput, &nGameEnding, &nCurrRoom, &nCurrProg,
					&nHealth, &nScore, &bShinyItem, &bTorch,
					&bRustyKey, &bToggleColor, &bToggleWait,
					&bToggleClear, &bToggleHUD, &bToggleShowMenu,
					&bToggleSimple);

		//increment the variable nMoveCount
		if (nCurrRoom > 0)
			nMoveCount++;
	}

	//ending loop
	while (nCurrProg && nGameEnding)
	{
		//clear the screen
		clearScreen(bToggleClear);

		//display heading
		printf("%s%s",
			"   ______________________________ \n",
			" / \\                             \\. \n"
		);
		
		//display the type of game ending
		switch (nGameEnding)
		{
			//death ending
			case 1:
				printf("|   |  %18s        |. \n", "Death Ending");
				break;
			
			//trapped ending
			case 2:
				printf("|   |  %19s       |. \n", "Trapped Ending");
				break;
			
			//good ending
			case 3:
				printf("|   |  %17s         |. \n", "Good Ending");
				break;

			//best ending
			case 4:
				printf("|   |  %17s         |. \n", "Best Ending");
				break;
		}

		//display player stats
		printf(" \\_ |                            |. \n");
		printf("    |  Player 1                  |. \n");
		printf("    |  Health: %02d                |. \n", nHealth);
		printf("    |  Score: %02d                 |. \n", nScore);
		printf("    |  Items:                    |. \n");

		//display the player items
		if (bShinyItem)
			printf("    |     Shiny Item             |. \n");
		if (bTorch)
			printf("    |     Torch                  |. \n");
		if (bRustyKey)
			printf("    |     Rusty Key              |. \n");

		//display achievements
		achievementsLogic(nGameEnding, nMoveCount, nHealth,
					nScore, bShinyItem, bTorch,
					bRustyKey, &bGotEnding1, &bGotEnding2,
					&bGotEnding3, &bGotEnding4, &bGotHealthy,
					&bGotPlentiful, &bGotCollector, &bGotSpeedrun,
					&bGotCompletionist);

		printf("    |                            |. \n");
		printf("    |        Achievements        |. \n");

		//display unique obtained achievements
		//Ending 1 achievement
		if (bGotEnding1 == 1)
		{
			//display the achievement
			printf("    |  %-24s  |. \n", "Ending 1 (Death Ending)");

			//increment by 1 so that it does not display again
			bGotEnding1++;
		}

		//Ending 2 achievement
		if (bGotEnding2 == 1)
		{
			//display the achievement
			printf("    |  %-24s |. \n", "Ending 2 (Trapped Ending)");

			//increment by 1 so that it does not display again
			bGotEnding2++;
		}

		//Ending 3 achievement
		if (bGotEnding3 == 1)
		{
			//display the achievement
			printf("    |  %-24s  |. \n", "Ending 3 (Good Ending)");

			//increment by 1 so that it does not display again
			bGotEnding3++;
		}

		//Ending 4 achievement
		if (bGotEnding4 == 1)
		{
			//display the achievement
			printf("    |  %-24s  |. \n", "Ending 4 (Best Ending)");

			//increment by 1 so that it does not display again
			bGotEnding4++;
		}

		//Healthy achievement
		if (bGotHealthy == 1)
		{
			//display the achievement
			printf("    |  %-24s  |. \n", "Healthy");

			//increment by 1 so that it does not display again
			bGotHealthy++;
		}

		//Plentiful achievement
		if (bGotPlentiful == 1)
		{
			//display the achievement
			printf("    |  %-24s  |. \n", "Plentiful");

			//increment by 1 so that it does not display again
			bGotPlentiful++;
		}

		//Collector achievement
		if (bGotCollector == 1)
		{
			//display the achievement
			printf("    |  %-24s  |. \n", "Collector");

			//increment by 1 so that it does not display again
			bGotCollector++;
		}

		//Speedrunner achievement
		if (bGotSpeedrun == 1)
		{
			//display the achievement
			printf("    |  %-24s  |. \n", "Speedrunner");

			//increment by 1 so that it does not display again
			bGotSpeedrun++;
		}

		//Completionist achievement
		if (bGotCompletionist == 1)
		{
			//display the achievement
			printf("    |  %-24s  |. \n", "Completionist");

			//increment by 1 so that it does not display again
			bGotCompletionist++;
		}
		
		//display footer
		printf("%s%s%s%s",
			"    |                            |. \n",
			"    |   _________________________|___ \n",
			"    |  /                            /. \n",
			"    \\_/____________________________/. \n\n"
		);

		//display choices
		printf("Choices:\n\n");
		printf("1. Return to menu\n\n");
		printf("2. Quit\n\n");

		//get the player choice and respond
		getChoice(&nInput, nMinInput, nMaxInput, bToggleColor);
		switch (nInput)
		{
			//reset game variables to its default
			case 1:
			//tracks game state
			nGameEnding = 1; //tracks the ending the player will receive
			nCurrRoom = -1; // tracks the current room the player is in
			nCurrProg = 0; //tracks total progress of the game by rooms; does not include the menu
			nInput = 0; //tracks the player's choice
			nMinInput = 0; //tracks the minumum range a player can input
			nMaxInput = 0; //tracks the maximum range a player can input
	
			//player stats
			nHealth = 50; //default health is 50
			nScore = 0; //default score is 0
	
			//player items
			bShinyItem = 0; //tracks whether the player has the item "shiny item" or not
			bTorch = 0; //tracks whether the player has the item "torch" or not
			bRustyKey = 0; // tracks whether the player has the item "rusty key" or not
			break;

			//terminate the loop and program
			case 2:
				nGameEnding = 0;
				break;
		}
	}
}

	//display ending thank you message
	printf("Thank You For Playing!\n");

    return 0;
}
