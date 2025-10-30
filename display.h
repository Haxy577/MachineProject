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
					int bTorch, int bRustyKey, int bToggleColor,
					int bToggleHUD);
void displayRoom1(int nHealth, int nScore, int bShinyItem,
					int bTorch, int bRustyKey, int bToggleColor,
					int bToggleWait, int bToggleHUD, int bToggleShowMenu);
/* --------------------------------------------------------------------- */


/*
	This function is responsible for printing the ASCII art
		of the title screen
	Preconditions: bToggleColor is a integer
	@param bToggleColor tracks whether to display different colors or not
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
	{
		displayLine();
		printf("\n\n\n");
	}
}


/*
	This function is responsible for changing the text color in the command prompt
	Preconditions: the parameters are an integer and nRed, nGreen, and nBlue are
					a number from 0 to 255.
	@param bToggleColor tracks whether to display color or not
	@param nNumber tracks the modifier, for example inputing "1" would make the text bold
	@param nRed tracks the intensity of the color red
	@param nGreen tracks the intensity of the color green
	@param nBlue tracks the intensity of the color blue
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
	Preconditions: the parameters are non-negative integers
	@param nCurrProg tracks the current progress of an ongoing game
	@param bToggleColor tracks whether to display color or not
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
	Preconditions: nCurrProg is a non-negative integer
	@param nCurrProg tracks the current progress of an ongoing game
*/
void
displayMenuOptions(int nCurrProg)
{
	//if there is already an ongoing game display the continue option
	if (nCurrProg)
	{
		printf("0. Continue Game\n\n");
	}
			
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


/*
	This funciton displays whether the option is on or off depending on the
		status of the option
	Preconditions: the parameters are non-negative integers
	@param bStatus tracks whether the option is active or inactive
	@param bToggleColor tracks whether to display color or not
*/
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


/*
	This function displays the options page and displays the options available
		and their status whether they are turned off or on
	Preconditions: the parameters are non-negative integers
	@param bToggleColor tracks whether to display color or not
	@param bToggleWait tracks whether there is a wait between dialouge
	@param bToggleClear tracks whether to clear the screen when moving between rooms
	@param bToggleHUD tracks whether to display a Heads-up Display when playing
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
*/
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


/*
	This function displays the Heads-up Display where it displays the current
		health, score, and items the player has
	Preconditions: the parameters are non-negative integers
	@param nHealth tracks the current health of the player
	@param nScore tracks the current health of the player
	@param bShinyItem tracks whether the player has the Shiny Item or not
	@param bTorch tracks whether the player has the Torch or not
	@param bRustyColor tracks whether the player has the Rusty Key or not
	@param bToggleColor tracks whether to display color or not
	@param bToggleHUD tracks whether to show the Heads-up Display when playing
*/
void
displayPlayerHUD(int nHealth, int nScore, int bShinyItem,
					int bTorch, int bRustyKey, int bToggleColor,
					int bToggleHUD)
{
	//makes the red more intense the closer nHealth is to zero
	int nRed;
	nRed = 255 - nHealth * 2;

	//display when the option is turned on
	if (bToggleHUD)
	{
		displayLine();
	
		printf("%9s   ||", "Player");
		printf("%29s\n", "Items");

		//Display player health
		printf("%-8s", "Health:");
		changeColor(bToggleColor,1,nRed,0,0);//set color to red
		printf("%-2d", nHealth);
		changeColor(bToggleColor,0,255,255,255);//reset color to white
		printf("  ||   ");

		if(bShinyItem)
		{
			changeColor(bToggleColor,1,239,191,4);//set color to gold
			printf(" %-15s ","Shiny Item?");
			changeColor(bToggleColor,0,255,255,255);//reset the color to white
		}
	
		if(bTorch)
		{
			changeColor(bToggleColor,1,255,153,51);//set the color to orange
			printf(" %-15s ","Lit Torch");
			changeColor(bToggleColor,0,255,255,255);//reset the color to white
		}
	
		if(bRustyKey)
		{
			changeColor(bToggleColor,1,183,65,14);//set the color to a rust-like color
			printf(" %-15s ","Rusted Key");
			changeColor(bToggleColor,0,255,255,255);//reset the color to white
		}

		printf("\n");
	
		//show
		printf("%-8s", "Score:");
		changeColor(bToggleColor,1,255,255,0);//set color to red
		printf("%-2d", nScore);
		changeColor(bToggleColor,0,255,255,255);//reset the color to white
		printf("  ||\n");

		displayLine();
	}

	//if the option is off print a line instead
	else
		displayLine();
}


/*
	This function adds a pause between the dialouge
	Preconditions: the parameters are non-negative integers
	@param nSeconds tracks how long it would pause in seconds
	@param bToggleWait tracks whether to add a pause between dialouge or not
*/
void
dialougeWait(int nSeconds, int bToggleWait)
{
	int nDuration = nSeconds;
	if (bToggleWait)
		sleep(nDuration);
}

/*
	This function displays the option to return to menu when playing depending if the option
		is turned on or off
	Preconditions: Parameters are non-negative integers
	@param bToggleColor tracks whether to display color or not
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
*/
void
displayMenuChoice(int bToggleColor, int bToggleShowMenu)
{
	if(bToggleShowMenu)
	{
		changeColor(bToggleColor,0,32,32,32);//set the color to gray
		printf("0. Return to the menu.\n\n");
		changeColor(bToggleColor,0,255,255,255);//reset the color to white
	}
}


/*
	This function displays the dialouge for the introduction
	Preconditions: the parameters are non-negative integers
	@param nHealth tracks the current health of the player
	@param nScore tracks the current health of the player
	@param bShinyItem tracks whether the player has the Shiny Item or not
	@param bTorch tracks whether the player has the Torch or not
	@param bRustyColor tracks whether the player has the Rusty Key or not
	@param bToggleColor tracks whether to display color or not
	@param bToggleHUD tracks whether to show the Heads-up Display when playing
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
*/
void
displayRoom1(int nHealth, int nScore, int bShinyItem,
					int bTorch, int bRustyKey, int bToggleColor,
					int bToggleWait, int bToggleHUD, int bToggleShowMenu)
{
	displayPlayerHUD(nHealth, nScore, bShinyItem,
						bTorch, bRustyKey, bToggleColor,
						bToggleHUD);

/*
Text cutter (70 characters)
123456789-123456789-12346789-123456789-123456789-123456789-123456789-
*/

	//display the dialouge
	printf("%s\n%s\n%s\n%s\n\n",
		"There was only nothingness. No light, no sound, no texture, not even ",
		"the feeling of your heart beating. Just a pure void where you are ",
		"left with nothing but your thoughts. You waited for what felt like ",
		"an eternity, a consciousness without a body."
		);

	dialougeWait(5, bToggleWait);

	printf("%s\n%s\n\n",
		"Then, as if responding to your pleas, the void crackled. A faint and",
		"dry whisper echoes in your head."
		);

		dialougeWait(3, bToggleWait);

	printf("%s\n\n%s\n\n%s\n\n%s\n\n%s\n\n",
		"“Find our treasure and make it yours.”",	
		"You scream to the void the questions that are lingering in your mind.",
		"“Where am I?”",
		"“Who are you?”",
		"“What treasure?”"
		);

		dialougeWait(5, bToggleWait);

	printf("%s\n%s\n%s\n\n%s\n%s\n%s\n%s\n%s\n%s\n\n%s\n\n",
		"Despite your incessant questioning, it was only met by the maddening",
		"repetition. The phrase repeated again and again, multiplying, growing",
		"into a crowd screaming for you to find their treasure.",
		"You instinctively try to cover your ears with your hands to stop the",
		"sound. However the voices only grew louder and louder to the point",
		"where it felt like it was tearing your mind apart. Until, as abruptly",
		"as it began, the voices vanished. Feeling confused you lower your",
		"hands and look around, ears still ringing. When the voices suddenly",
		"came back like a bomb, screaming",
		"“Wake up!”"
		);

	//display the options
	displayMenuChoice(bToggleColor, bToggleShowMenu);
}