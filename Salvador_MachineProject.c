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
	Last Modified: October 20, 2025
	Version: 1.0
	Acknowledgements: 	https://www.asciiart.eu/text-to-ascii-art - for providing the title art
						
*/

//the max string length for this program is 70 characters

#include <stdio.h>
#include <stdlib.h>



/*
	This function is responsible for printing the ASCII art
		of the title screen
	Preconditions: None since its only for display
*/
void
displayTitle()
{
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
}


/*
	This function is responsible for printing the a break line
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
	This function gets the value inputted by the player
	Preconditions: input is an integer
	@return is the integer inputted by the player
*/
int
getChoice()
{
	int nInput = 0;
	
	printf("Your Choice: ");
	scanf("%d", &nInput);
	
	return nInput;
}


/*
	This function displays options available for the menu
	Preconditions: bIsPlaying is either 0 or 1
	@param bIsPlaying is tracking whether there is already a game ongoing
*/
void
displayOptions(int bIsPlaying)
{
	//if there is already an ongoing game display the continue option
	switch (bIsPlaying)
	{
		case 1:
			printf("0. Continue Game\n\n");
			
		default:
			printf("1. Start new game\n\n");
			printf("2. Credits\n\n");
			printf("3. Exit\n\n");
	}	
}


/*
	This function displays the credits for the game
	Preconditions: bIsPlaying is either 0 or 1
	@param bIsPlaying is tracking whether there is already a game ongoing
*/
void
displayCredit(int* bIsPlaying)
{
	displayLine();
	printf("Credits:\n");
	printf("Creator and programmer: Richmond Jase Von M. Salvador  S15\n");
	printf("Special thanks to John Alexander Cox Santillana\n");
	displayLine();
	
	//give the option to stay or to return to the menu
	printf("1. Stay.\n\n");
	printf("2. Go back to menu.\n\n");
	
	//ask for an input and respond
	switch (getChoice())
	{
		//return the player back to the credits
		case 1:
			clearScreen();
			displayCredit(bIsPlaying);
			break;
		
		//return the player to the menu	
		case 2:
			clearScreen();
			displayMenu(bIsPlaying);
			break;
		
		/*informs the user that the number does not fall under the given options
			and calls the function again to retry*/
		default:
			clearScreen();
			printf("Please choose a valid number\n\n");
			displayCredit(bIsPlaying);
	}
	
}


/*
	This function displays the title screen, start the game,
		view the credits, or to close/exit the game
	Preconditions: bIsPlaying is either 0 or 1
	@param bIsPlaying is tracking whether there is already a game ongoing
*/
void
displayMenu(int* bIsPlaying)
{
	//displays the title screen
	displayLine();
	displayTitle();
	displayLine();
	
	//displays opening remarks
	printf("Welcome adventurer! A whole world of possibilities awaits you!\n");
	printf("Input the number of the corresponding option:\n\n");
	
	//displays the options
	displayOptions(*bIsPlaying);
	
	//ask for an input and respond accordingly
	switch (getChoice())
	{
		//For continue game option
		case 0:
			//Check if there is a game ongoing
			switch (*bIsPlaying)
			{
				//if there is a game saved then it continues the game
				case 1:
					printf("Continuing the game");
				
				/*if there was no prior game then it would inform the player
					and calls the function again*/	
				default:
					clearScreen();
					printf("There is no ongoing game.\nPlease start a new game.\n\n\n");
					displayMenu(bIsPlaying);
			}
			break;
		
		//For start new game option
		case 1:
			printf("%s", "new game\n");
			*bIsPlaying = 1;
			printf("%d", *bIsPlaying);
			break;
		
		//for credit option	
		case 2:
			clearScreen();
			displayCredit(bIsPlaying);
			break;
		
		//for exit option	
		case 3:
			printf("Thank you for playing!");
			exit(0); //This ends the program
			break;
		
		/*informs the user that the number does not fall under the given options
			and calls the function again to retry*/
		default:
			clearScreen();
			printf("Please choose a valid number\n\n");
			displayMenu(bIsPlaying);
	}
}

int main()
{
	int bIsPlaying = 0;
	displayMenu(&bIsPlaying);

    return 0;
}
