/*This file is responsible for deciding and updating the game based
	on the decisions of the player
*/


#include <stdio.h>
#include <windows.h>


/* ------------------------ Function Prototypes ------------------------ */
void getChoice(int* nInput, int nMinInput, int nMaxInput);
void updateInputRange(int nCurrRoom, int* nMinInput, int* nMaxInput);
void displayCurrentRoom(int nCurrRoom, int nCurrProg);
void updateGame(int* nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg,
				int* nHealth, int* Score, int* bShinyItem, int* bTorch,
				int* bRustyKey);
void handleRoomCredits(int nInput, int* nCurrRoom, int* nCurrProg);
void handleRoomMenu (int nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg);
void resetGame(int* nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg,
			int* nHealth, int* nScore, int* bShinyItem, int* bTorch,
			int* bRustyKey);
void displayEnding (int nGameEnding);
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
	int invalid = 0; //tracks the number of invalid inputs
	
	do
	{
		switch (invalid)
		{
			case 0:
				printf("Your choice: ");
				scanf("%d", nInput);
				break;
			
			//inform the player to retry
			default:
				changeColor(4); //change to color red
				printf("Invalid choice. Please try again.\n");
				changeColor(7); //change back to white
				printf("Your choice: ");
				scanf("%d", nInput);
		}
		
		invalid++;
	}
	while (nMinInput > *nInput || nMaxInput < *nInput); //should be true if input is invalid to loop again
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
		//Credits
		case -2:
			*nMinInput = 1;
			*nMaxInput = 2;
			break;
			
		//Menu with continue game option
		case -1:
			*nMinInput = 0;
			*nMaxInput = 3;
			break;
			
		//Menu
		case 0:
			*nMinInput = 1;
			*nMaxInput = 3;
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
	room_Credits = 0
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
		//Credits page
		case -2:
			handleRoomCredits(*nInput, nCurrRoom, nCurrProg);
			break;
		
		//Menu
		case 0:
		case -1:
			handleRoomMenu(*nInput, nGameEnding, nCurrRoom, nCurrProg);
			break;
		
		//Room 1
		case 1:
			*nCurrRoom = -1;
			break;
	}
}


void
handleRoomCredits(int nInput, int* nCurrRoom, int* nCurrProg)
{
	/*The credit page has two (2) choices:
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
handleRoomMenu (int nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg)
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
				
		//terminate the program
		case 3:
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


/*
	This function is responsible for calling the function that is
		responsible for displaying the ending
	Preconditions: nGameEnding is an integer
	@param nGameEnding tracks the type of ending the player got
*/
void
displayEnding (int nGameEnding)
{
    switch (nGameEnding)
    {
		//Death ending
        case 0:
			printf("Death ending");
			break;

		//Trapped ending
		case 1:
			printf("Trapped ending");
			break;
		
		//Good ending
		case 2:
			printf("Good ending");
			break;

		//Best ending
		case 3:
			printf("Best ending");
			break;

		//Exit
		default:
			printf("Thank You for Playing");
    }
}
