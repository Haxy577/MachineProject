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
	Last Modified: October 21, 2025
	Version: 1.0
	Acknowledgements:	https://www.asciiart.eu/text-to-ascii-art - for providing the title art
						https://stackoverflow.com/questions/9203362/c-color-text-in-terminal-applications-in-windows - for the changing the color code
*/

#include <stdio.h>
#include <windows.h>


/* ------------------------ Function Prototypes ------------------------ */
void displayTitle();
void displayLine();
void clearScreen();
void changeColor(int nColor);
void getChoice(int* nInput, int nMinInput, int nMaxInput);
void displayMenu(int nCurrProg);
void displayMenuOptions(int nCurrProg);
void displayCredits();
void updateInputRange(int nCurrRoom, int* nMinInput, int* nMaxInput);
void displayCurrentRoom(int nCurrRoom, int nCurrProg);
void updateGame(int* nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg,
				int* nHealth, int* Score, int* bShinyItem, int* bTorch,
				int* bRustyKey);
void handleRoomCredits(int nInput, int* nCurrRoom, int* nCurrProg);
void handleRoomMenu (int nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg);
void displayGameEnding(int nGameEnding);
void resetGame(int* nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg,
			int* nHealth, int* nScore, int* bShinyItem, int* bTorch,
			int* bRustyKey);
/* --------------------------------------------------------------------- */

/*
	This function is responsible for printing the ASCII art
		of the title screen
	Preconditions: None since its only for display
*/
void
displayTitle()
{
	changeColor(8); // this changes the color into a dark gray
	//This prints the words "The Lost"
	printf("%s%s%s%s%s%s%s",
			" ______  __                    __                       __      \n",
			"/\\__  _\\/\\ \\                  /\\ \\                     /\\ \\__   \n",
			"\\/_/\\ \\/\\ \\ \\___      __      \\ \\ \\        ___     ____\\ \\ ,_\\  \n",
			"   \\ \\ \\ \\ \\  _ `\\  /'__`\\     \\ \\ \\  __  / __`\\  /',__\\\\ \\ \\/  \n",
			"    \\ \\ \\ \\ \\ \\ \\ \\/\\  __/      \\ \\ \\L\\ \\/\\ \\L\\ \\/\\__, `\\\\ \\ \\_ \n",
			"     \\ \\_\\ \\ \\_\\ \\_\\ \\____\\      \\ \\____/\\ \\____/\\/\\____/ \\ \\__\\ \n",
			"      \\/_/  \\/_/\\/_/\\/____/       \\/___/  \\/___/  \\/___/   \\/__/ \n"
	);
	
	//This prints the word "Cavern"
	printf("%s%s%s%s%s%s%s",
		"            ____                                                 \n",
		"           /\\  _`\\                                               \n",
		"           \\ \\ \\/\\_\\     __     __  __     __   _ __    ___      \n",
		"            \\ \\ \\/_/_  /'__`\\  /\\ \\/\\ \\  /'__`\\/\\`'__\\/' _ `\\    \n",
		"             \\ \\ \\L\\ \\/\\ \\L\\.\\_\\ \\ \\_/ |/\\  __/\\ \\ \\/ /\\ \\/\\ \\   \n",
		"              \\ \\____/\\ \\__/.\\_\\\\ \\___/ \\ \\____\\\\ \\_\\ \\ \\_\\ \\_\\  \n",
		"               \\/___/  \\/__/\\/_/ \\/__/   \\/____/ \\/_/  \\/_/\\/_/  \n"
	);
	changeColor(7); //this changes back the color to white
}


/*
	This function is responsible for printing the a break line for
		a total of 70 characters
	Preconditions: None since its only for display
*/
void
displayLine()
{
	/*This would repeat a total of seven times for a total 
		of seventy (70) characters*/
	printf("%s%s%s%s%s%s%s",
		"==========",
		"==========",
		"==========",
		"==========",
		"==========",
		"==========",
		"==========\n"
	);
}


/*
	This function is responsible for clearing the screen in command prompt
	Preconditions: None since its only for display
*/
void
clearScreen()
{
	system("cls"); //clears the screen of all text
}


/*
	This function is responsible for changing the text color in command prompt
	Preconditions: nColor is between 0 to 15
	@param nColor decides the color of the text
*/
void
changeColor(int nColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get handle to CMD output
	SetConsoleTextAttribute(hConsole, nColor);
}


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
	This function displays the title screen, start the game,
		view the credits, or to close/exit the game
	Preconditions: bIsPlaying is either 0 or 1
	@param bIsPlaying is tracking whether there is already a game ongoing
*/
void
displayMenu(int nCurrProg)
{
	//displays the title screen
	displayLine();
	displayTitle();
	displayLine();
	
	//displays opening remarks
	printf("Welcome adventurer! A whole world of possibilities awaits you!\n");
	printf("Input the number of the corresponding option:\n\n");
	
	//displays the options
	displayMenuOptions(nCurrProg);
}


/*
	This function displays options available for the menu
	Preconditions: nCurrProg is a integer
	@param bIsPlaying is tracking whether there is already a game ongoing
*/
void
displayMenuOptions(int nCurrProg)
{
	//if there is already an ongoing game display the continue option
	if (nCurrProg != 0)
		printf("0. Continue Game\n\n");
			
		printf("1. Start new game\n\n");
		printf("2. Credits\n\n");
		printf("3. Exit\n\n");	
}


/*
	This function displays the credits for the game
	Preconditions: bIsPlaying is either 0 or 1
	@param bIsPlaying is tracking whether there is already a game ongoing
*/
void
displayCredits()
{
	displayLine();
	printf("Credits:\n");
	printf("Creator and programmer: Richmond Jase Von M. Salvador  S15\n");
	printf("Special thanks to John Alexander Cox Santillana\n");
	displayLine();
	
	//give the option to stay or to return to the menu
	printf("1. Stay.\n\n");
	printf("2. Go back to menu.\n\n");
	
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
displayGameEnding(int nGameEnding)
{
	switch (nGameEnding)
	{
		//For exiting the game at the menu
		case -1:
			printf("Thank you for playing!\n\n");
			
		//For health is equal or below 0
		case 0:
			printf("You ded. Git Gud\n\n");
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
	
	displayGameEnding(nGameEnding);
	
	/*get choice of the player whether to start a new game,
		to go back to the menu, or to quit the program*/
		printf("1. Start a new game?\n\n");
		printf("2. Go back to menu.\n\n");
		
		getChoice(&nInput, 1, 2);
		switch (nInput)
		{
			case 1:
				resetGame(&nInput, &nGameEnding, &nCurrRoom, &nCurrProg,
							&nHealth, &nScore, &bShinyItem, &bTorch,
							&bRustyKey);
				break;
				
			case 2:
				resetGame(&nInput, &nGameEnding, &nCurrRoom, &nCurrProg,
							&nHealth, &nScore, &bShinyItem, &bTorch,
							&bRustyKey);
				break;
		}
	
    return 0;
}
