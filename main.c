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
	Last Modified: October 24, 2025
	Version: 1.0
	Acknowledgements:	https://www.asciiart.eu/text-to-ascii-art -> for providing the title art
						https://en.wikipedia.org/wiki/ANSI_escape_code -> for the changing the color code
						https://stackoverflow.com/questions/7898215/how-can-i-clear-an-input-buffer-in-c -> for the scanf fix
*/

#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include "gameLogic.h"
#include "roomLogic.h"


/* ------------------------ Function Prototypes ------------------------ */

/* --------------------------------------------------------------------- */



int main()
{
	//Tracks game settings
	int bToggleColor = 1;
	int bToggleWait = 1;
	int bToggleClear = 1;

	//tracks game state
	int nGameEnding = 0; //tracks the ending the player will recieve
	int nCurrRoom = 0; // tracks the current room
	int nCurrProg = 0; //tracks total progress of the game by rooms; does not include the menu
	int nInput = 0; //tracks the player's choice
	int nMinInput = 0; //tracks the minumum range a player can input
	int nMaxInput = 0; //tracks the maximum range a player can input
	
	//player stats
	int nHealth = 50; //default health is 50
	int nScore = 0; //default score is 0
	
	/*Player items 
	0 means the player does not have that item
		and 1 means the player has the item*/
	int bShinyItem = 0;
	int bTorch = 0;
	int bRustyKey = 0;
	
	//main game loop
	while (nHealth > 0 && nGameEnding == 0)
	{
		nInput = 0; //reset the input
		clearScreen(bToggleClear);
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
	}
	
	//display ending message
	displayEnding(nGameEnding);
	
    return 0;
}
