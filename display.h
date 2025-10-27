//This file contains all of the functions that are responsible for display



/* ------------------------ Function Prototypes ------------------------ */
//Functions for display
void displayTitle(int bToggleColor);
void displayLine();
void clearScreen(int bToggleClear);
void changeColor(int bToggleColor, int nNumber, int nRed, int nGreen, int nBlue);
void displayMenu(int nCurrProg, int bToggleColor);
void displayMenuOptions(int nCurrProg);
void displayCredits();
void displayOptions(int bToggleColor, int bToggleWait, int bToggleClear,
					int bToggleHUD, int bToggleShowMenu);
void displayOptionStatus(int bStatus, int bToggleColor);
void displayEnding (int nGameEnding);
void displayPlayerHUD(int nHealth, int nScore, int bShinyItem,
					int bTorch, int bRustyKey, int bToggleColor);
void displayRoom1(int nHealth, int nScore, int bShinyItem,
					int bTorch, int bRustyKey, int bToggleColor,
					int bToggleWait, int bToggleHUD, int bToggleShowMenu);
/* --------------------------------------------------------------------- */


/*
	This function is responsible for printing the ASCII art
		of the title screen
	Preconditions: None since its only for display
*/
void
displayTitle(int bToggleColor)
{
	changeColor(bToggleColor, 1, 128, 128, 128); // this changes the color into a dark gray
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
	changeColor(bToggleColor, 0, 255, 255, 255); //this changes back the color to white
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
	Preconditions: bToggleClear is 0 or 1
	@param bToggleClear tracks the setting on whether to clear the
		screen when moving rooms
*/
void
clearScreen(int bToggleClear)
{
	if (bToggleClear)
		system("clear"); //clears the screen of all text
	else
		printf("\n\n\n");
}


/*
	This function is responsible for changing the text color in command prompt
	Preconditions: nColor is between 0 to 15
	@param nColor decides the color of the text
*/
void
changeColor(int bToggleColor, int nNumber, int nRed, int nGreen, int nBlue)
{
	if (bToggleColor)
	{
		//validate if the rgb values are within 0 to 255
		if (nRed > -1 && nRed < 256 &&
			nGreen > -1 && nGreen < 256 &&
			nBlue > -1 && nBlue < 256)
				printf("\x1b[%d;38;2;%d;%d;%dm", nNumber, nRed, nGreen, nBlue);
	}
}


/*
	This function displays the title screen, start the game,
		view the credits, or to close/exit the game
	Preconditions: bIsPlaying is either 0 or 1
	@param bIsPlaying is tracking whether there is already a game ongoing
*/
void
displayMenu(int nCurrProg, int bToggleColor)
{
	//displays the title screen
	displayLine();
	displayTitle(bToggleColor);
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
		printf("3. Options\n\n");
		printf("4. Exit\n\n");	
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


void
displayOptionStatus(int bStatus, int bToggleColor)
{
	if (bStatus)
	{
		changeColor(bToggleColor,1,0,125,0);
		printf("%6s\n", "[ON]");
		changeColor(bToggleColor,0,255,255,255);
	}
	else
	{
		changeColor(bToggleColor,1,255,0,0);
		printf("%6s\n", "[OFF]");
		changeColor(bToggleColor,0,255,255,255);
	}
}


void
displayOptions(int bToggleColor, int bToggleWait, int bToggleClear,
				int bToggleHUD, int bToggleShowMenu)
{
	//Display the option ascii art
	displayLine();
	printf("%53s%53s%53s%53s%53s%53s",
		"  ___        _   _                  \n",
		" / _ \\ _ __ | |_(_) ___  _ __  ___  \n",
		"| | | | '_ \\| __| |/ _ \\| '_ \\/ __| \n",
		"| |_| | |_) | |_| | (_) | | | \\__ \\ \n",
		" \\___/| .__/ \\__|_|\\___/|_| |_|___/ \n",
		"      |_|                           \n"
	);
	displayLine();
	
	//display the options
	printf("%-64s%6s\n", "Options:", "Status");

	//Colored Text option
	printf("%-64s", "1. Colored Texts (ON/OFF)");
	displayOptionStatus(bToggleColor, bToggleColor);

	//Dialouge Wait option
	printf("%-64s", "2. Dialouge Wait (ON/OFF)");
	displayOptionStatus(bToggleWait, bToggleColor);

	//Clear Screen option
	printf("%-64s", "3. Clear Screen (ON/OFF)");
	displayOptionStatus(bToggleClear, bToggleColor);

	//Display HUD option
	printf("%-64s", "4. Display Heads-up Display(HUD) (ON/OFF)");
	displayOptionStatus(bToggleHUD, bToggleColor);

	//Display whether to show the return to menu option while playing
	printf("%-64s", "5. Display Return to Menu Choice (ON/OFF)");
	displayOptionStatus(bToggleShowMenu, bToggleColor);

	//Show the go back to menu option
	printf("\n");
	printf("0. Go back to menu\n");

	displayLine();
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
			printf("Death ending\n");
			break;

		//Trapped ending
		case 1:
			printf("Trapped ending\n");
			break;
		
		//Good ending
		case 2:
			printf("Good ending\n");
			break;

		//Best ending
		case 3:
			printf("Best ending\n");
			break;

		//Exit
		default:
			printf("Thank You For Playing!\n");
    }
}


void
displayPlayerHUD(int nHealth, int nScore, int bShinyItem,
					int bTorch, int bRustyKey, int bToggleColor)
{
	//makes the red more intense the closer nHealth is to zero
	int nRed;
	nRed = 255 - nHealth * 2;

	displayLine();
	
	printf("%9s   ||", "Player");
	printf("%29s\n", "Items");

	//Display player health
	printf("%-8s", "Health:");
	changeColor(bToggleColor,1,nRed,0,0);//set color to red
	printf("%-2d", nHealth);
	changeColor(bToggleColor,0,255,255,255);
	printf("  ||   ");

	if(bShinyItem)
	{
		changeColor(bToggleColor,1,239,191,4);
		printf(" %-15s ","Shiny Item?");
		changeColor(bToggleColor,0,255,255,255);
	}
	
	if(bTorch)
	{
		changeColor(bToggleColor,1,255,153,51);
		printf(" %-15s ","Lit Torch");
		changeColor(bToggleColor,0,255,255,255);
	}
	
	if(bRustyKey)
	{
		changeColor(bToggleColor,1,183,65,14);
		printf(" %-15s ","Rusted Key");
		changeColor(bToggleColor,0,255,255,255);
	}
	
	printf("\n");
	
	//show
	printf("%-8s", "Score:");
	changeColor(bToggleColor,1,255,255,0);//set color to red
	printf("%-2d", nScore);
	changeColor(bToggleColor,0,255,255,255);
	printf("  ||\n");

	displayLine();
}


void
displayRoom1(int nHealth, int nScore, int bShinyItem,
					int bTorch, int bRustyKey, int bToggleColor,
					int bToggleWait, int bToggleHUD, int bToggleShowMenu)
{
	if(bToggleHUD)
	{
	displayPlayerHUD(nHealth, nScore, bShinyItem,
						bTorch, bRustyKey, bToggleColor);
	}

	//display the options

	if(bToggleShowMenu)
	{
		changeColor(bToggleColor,0,32,32,32);
		printf("0. Return to the menu.\n\n");
		changeColor(bToggleColor,0,255,255,255);
	}
}