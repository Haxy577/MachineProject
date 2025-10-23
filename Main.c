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
	Last Modified: October 23, 2025
	Version: 1.0
	Acknowledgements:	https://www.asciiart.eu/text-to-ascii-art - for providing the title art
						https://stackoverflow.com/questions/9203362/c-color-text-in-terminal-applications-in-windows - for the changing the color code
*/

#include <stdio.h>
#include <windows.h>
#include "Display.c"
#include "GameLogic.c"
#include "RoomLogic.c"


/* ------------------------ Function Prototypes ------------------------ */

/* --------------------------------------------------------------------- */



int main()
{
	//tracks game state
	int nGameEnding = 0; //tracks the ending the player will recieve
	int nCurrRoom = 0; // tracks the current room
	int nCurrProg = 0; //tracks total progress of the game by rooms; does not include the menu
	int nInput = 0; //tracks the player's choice
	int nMinInput = 0;
	int nMaxInput = 0;
	
	//player stats
	int nHealth = 50; //default health is 50
	int nScore = 0; //default score is 0
	
	/*player items. 0 means the player does not have that item
		and 1 means the player has the item*/
	int bShinyItem = 0;
	int bTorch = 0;
	int bRustyKey = 0;
	
	//main game loop
	while (nHealth > 0 && nGameEnding == 0)
	{
		nInput = 0; //reset the input
		displayCurrentRoom(nCurrRoom, nCurrProg);
		updateInputRange(nCurrRoom, &nMinInput, &nMaxInput);
		getChoice(&nInput, nMinInput, nMaxInput);
		
		//respond to the choice made by the player
		//updateHealth();
		//updateScore();
		//updateItems();
		updateGame(&nInput, &nGameEnding, &nCurrRoom, &nCurrProg,
			&nHealth, &nScore, &bShinyItem, &bTorch,
			&bRustyKey);

		clearScreen();
	}
	
	//display ending message
	displayEnding(nGameEnding);
	
    return 0;
}
