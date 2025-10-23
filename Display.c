//This file contains all of the functions that are responsible for display

#include <stdio.h>
#include <windows.h>

/* ------------------------ Function Prototypes ------------------------ */
//Functions for display
void displayTitle();
void displayLine();
void clearScreen();
void changeColor(int nColor);
void displayMenu(int nCurrProg);
void displayMenuOptions(int nCurrProg);
void displayCredits();
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
	Preconditions: None
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


displayOptions()
{
	//Display the option ascii art
	displayLine();
	printf("%s%s%s%s%s%s",
		"  ___        _   _                  \n",
		" / _ \\ _ __ | |_(_) ___  _ __  ___  \n",
		"| | | | '_ \\| __| |/ _ \\| '_ \\/ __| \n",
		"| |_| | |_) | |_| | (_) | | | \\__ \\ \n",
		" \\___/| .__/ \\__|_|\\___/|_| |_|___/ \n",
		"      |_|                           \n"
	);
	displayLine();
	
	//display the options
	printf("1. Dialouge Wait [ON/OFF]");
}