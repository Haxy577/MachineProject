//This file contains all of the functions that are responsible for display



/* ------------------------ Function Prototypes ------------------------ */
//These functions are responsible for the display
void displayTitle(int bToggleColor);
void displayLine();
void clearScreen(int bToggleClear);
void changeColor(int bToggleColor, int nNumber, int nRed, int nGreen, int nBlue);
void displayMenu(int nCurrProg, int bToggleColor);
void displayCredits();
void displayOptionStatus(int bStatus, int bToggleColor);
void displayOptions(int bToggleColor, int bToggleWait, int bToggleClear,
					int bToggleHUD, int bToggleShowMenu, int bToggleSimple);
void displayOptionStatus(int bStatus, int bToggleColor);
void displayEnding (int nInput, int* nCurrRoom, int* nCurrProg,
					int* nGameEnding);
void displayPlayerHUD(int nHealth, int nScore, int bShinyItem,
					int bTorch, int bRustyKey, int bToggleColor,
					int bToggleHUD);
void displayIntroduction(int nHealth, int nScore, int bShinyItem,
						int bTorch, int bRustyKey, int bToggleColor,
						int bToggleWait, int bToggleHUD, int bToggleShowMenu,
						int bToggleSimple);
void displayRoom1(int nHealth, int nScore, int bShinyItem,
						int bTorch, int bRustyKey, int bToggleColor,
						int bToggleWait, int bToggleHUD, int bToggleShowMenu,
						int bToggleSimple);
void displayRoom2(int nHealth, int nScore, int bShinyItem,
						int bTorch, int bRustyKey, int bToggleColor,
						int bToggleWait, int bToggleHUD, int bToggleShowMenu,
						int bToggleSimple);
void displayRoom3(int nHealth, int nScore, int bShinyItem,
						int bTorch, int bRustyKey, int bToggleColor,
						int bToggleWait, int bToggleHUD, int bToggleShowMenu,
						int bToggleSimple);
void displayRoom4(int nHealth, int nScore, int bShinyItem,
						int bTorch, int bRustyKey, int bToggleColor,
						int bToggleWait, int bToggleHUD, int bToggleShowMenu,
						int bToggleSimple);
void displayRoom5(int nHealth, int nScore, int bShinyItem,
						int bTorch, int bRustyKey, int bToggleColor,
						int bToggleWait, int bToggleHUD, int bToggleShowMenu,
						int bToggleSimple);
void displayRoom6(int nHealth, int nScore, int bShinyItem,
						int bTorch, int bRustyKey, int bToggleColor,
						int bToggleWait, int bToggleHUD, int bToggleShowMenu,
						int bToggleSimple);
void displayRoom7(int nHealth, int nScore, int bShinyItem,
						int bTorch, int bRustyKey, int bToggleColor,
						int bToggleWait, int bToggleHUD, int bToggleShowMenu,
						int bToggleSimple);
void displayRoom8(int nHealth, int nScore, int bShinyItem,
						int bTorch, int bRustyKey, int bToggleColor,
						int bToggleWait, int bToggleHUD, int bToggleShowMenu,
						int bToggleSimple);
void displayRoom9(int nHealth, int nScore, int bShinyItem,
						int bTorch, int bRustyKey, int bToggleColor,
						int bToggleWait, int bToggleHUD, int bToggleShowMenu,
						int bToggleSimple);
void displayRoom10(int nHealth, int nScore, int bShinyItem,
						int bTorch, int bRustyKey, int bToggleColor,
						int bToggleWait, int bToggleHUD, int bToggleShowMenu,
						int bToggleSimple);
void displayEndingPage(int nGameEnding, int nHealth, int nScore,
						int bShinyItem, int bTorch, int bRustyKey,
						int bGotEnding1, int bGotEnding2, int bGotEnding3,
						int bGotEnding4, int bGotHealthy, int bGotPlentiful,
						int bGotCollector, int bGotSpeedrun, int bGotCompletionist);
void displayUnknownAchievement();
void displayAchievements(int bGotEnding1, int bGotEnding2, int bGotEnding3, 
							int bGotEnding4, int bGotHealthy, int bGotPlentiful,
							int bGotCollector, int bGotSpeedrun, int bGotCompletionist,
							int bToggleColor);
/* --------------------------------------------------------------------- */


/*
	This function is responsible for printing the a break line for
		a total of 70 characters
	Preconditions: None since its only for display
*/
void
displayLine()
{
	int i; //used as a counter for the for loop
	/*This would repeat a total of eight times for a total 
		of seventy (80) characters*/
	for (i = 0; i < 8; i++)
		printf("==========");
	
	//print a next line
	printf("\n");
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
	Preconditions: the parameters are non-negative integers and nRed, nGreen, and nBlue are
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
	changeColor(bToggleColor, 1, 128, 128, 128); // this changes the color into a dark gray
	//displays the word "THE LOST"
	printf("%s%s%s%s%s%s",
		":::::::::::: ::   .: .,::::::       :::         ...      .::::::.:::::::::::: \n",
		";;;;;;;;'''',;;   ;;,;;;;''''       ;;;      .;;;;;;;.  ;;;`    `;;;;;;;;'''' \n",
		"     [[    ,[[[,,,[[[ [[cccc        [[[     ,[[     \\[[,'[==/[[[[,    [[      \n",
		"     $$    \"$$$\"\"\"$$$ $$\"\"\"\"        $$'     $$$,     $$$  '''    $    $$      \n",
		"     88,    888   \"88 888oo,__     o88oo,.__\"888,_ _,88P 88b    dP    88,     \n",
		"     MMM    MMM    YM \"\"\"\"YUMMM    \"\"\"\"YUMMM  \"YMMMMMP\"   \"YMmMY\"     MMM     \n\n"
	);
	//displays the word "CAVERN"
	printf("%s%s%s%s%s%s",
		"         .,-:::::   :::.  :::      .::..,:::::: :::::::.. :::.    :::.       \n",
		"       ,;;;'````'   ;;`;; ';;,   ,;;;' ;;;;'''' ;;;;``;;;;`;;;;,  `;;;       \n",
		"       [[[         ,[[ '[[,\\[[  .[[/    [[cccc   [[[,/[[['  [[[[[. '[[       \n",
		"       $$$        c$$$cc$$$cY$c.$$\"     $$\"\"\"\"   $$$$$$c    $$$ \"Y$c$$       \n",
		"       `88bo,__,o, 888   888,Y88P       888oo,__ 888b \"88bo,888    Y88       \n",
		"         \"YUMMMMMP\"YMM   \"\"`  MP        \"\"\"\"YUMMMMMMM   \"W\" MMM     YM     \n"
	);

	changeColor(bToggleColor, 0, 255, 255, 255); //this changes back the color to white
	displayLine();
	
	//displays opening remarks
	printf("Welcome adventurer! A whole world of possibilities awaits you!\n");
	printf("Input the number of the corresponding option:\n\n");
	
	//displays the options
	//if there is already an ongoing game display the continue choice
	if (nCurrProg >= 0)
		printf("0. Continue Game\n\n");

	//display the rest of the choice	
	printf("1. Start new game\n\n");
	printf("2. Achievements\n\n");
	printf("3. Statistics\n\n");
	printf("4. Credits\n\n");
	printf("5. Options\n\n");
	printf("6. Exit\n\n");	
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
	This function displays whether the option is on or off depending on the
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
	@param bToggleWait tracks whether there is a wait between dialogue
	@param bToggleClear tracks whether to clear the screen when moving between rooms
	@param bToggleHUD tracks whether to display a Heads-up Display when playing
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
	@param bToggleSimple tracks whether to display the simplest version of dialogue or not
*/
void
displayOptions(int bToggleColor, int bToggleWait, int bToggleClear,
				int bToggleHUD, int bToggleShowMenu, int bToggleSimple)
{
	//Display the option ascii art
	displayLine();
	changeColor(bToggleColor,0,82,90,163); //change the color to green
	printf("%s%s%s%s%s",
		"   ooooooo  oooooooooo  ooooooooooo ooooo  ooooooo  oooo   oooo oooooooo8   \n",
		"   o888   888o 888    888 88  888  88  888 o888   888o 8888o  88 888          \n",
		"   888     888 888oooo88      888      888 888     888 88 888o88  888oooooo   \n",
		"   888o   o888 888            888      888 888o   o888 88   8888         888  \n",
		"     88ooo88  o888o          o888o    o888o  88ooo88  o88o    88 o88oooo888   \n"
	);
	changeColor(bToggleColor,0,255,255,255); //reset the color back to white
	displayLine();


	//display the options
	printf("%-74s%6s\n\n", "Options:", "Status");

	printf("Display Options:\n");

	//Colored Text option
	printf("%-74s", "1. Colored Texts (ON/OFF)");
	displayOptionStatus(bToggleColor, bToggleColor);

	//Clear Screen option
	printf("%-74s", "2. Clear Screen (ON/OFF)");
	displayOptionStatus(bToggleClear, bToggleColor);

	printf("\nGameplay Options:\n");

	//Dialogue Wait option
	printf("%-74s", "3. Dialogue Wait (ON/OFF)");
	displayOptionStatus(bToggleWait, bToggleColor);

	//Display HUD option
	printf("%-74s", "4. Display Heads-up Display(HUD) (ON/OFF)");
	displayOptionStatus(bToggleHUD, bToggleColor);

	//Display whether to show the return to menu option while playing
	printf("%-74s", "5. Display Return to Menu Choice (ON/OFF)");
	displayOptionStatus(bToggleShowMenu, bToggleColor);

	//Display the simple dialogue option
	printf("%-74s", "6. Simple / Skeleton Dialogue (ON/OFF)");
	displayOptionStatus(bToggleSimple, bToggleColor);

	//Show the go back to menu option
	printf("\n");
	printf("0. Go back to menu\n");

	displayLine();
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
	This function adds a pause between the dialogue
	Preconditions: the parameters are non-negative integers
	@param nSeconds tracks how long it would pause in seconds
	@param bToggleWait tracks whether to add a pause between dialogue or not
*/
void
dialogueWait(int nSeconds, int bToggleWait)
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
	This function displays the dialogue for room 10
	Preconditions: the parameters are non-negative integers
	@param nHealth tracks the current health of the player
	@param nScore tracks the current health of the player
	@param bShinyItem tracks whether the player has the Shiny Item or not
	@param bTorch tracks whether the player has the Torch or not
	@param bRustyColor tracks whether the player has the Rusty Key or not
	@param bToggleColor tracks whether to display color or not
	@param bToggleHUD tracks whether to show the Heads-up Display when playing
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
	@param bToggleSimple tracks whether to display the simplest version of dialogue or not
*/
void
displayIntroduction(int nHealth, int nScore, int bShinyItem,
					int bTorch, int bRustyKey, int bToggleColor,
					int bToggleWait, int bToggleHUD, int bToggleShowMenu,
					int bToggleSimple)
{
	//display the HUD
	displayPlayerHUD(nHealth, nScore, bShinyItem,
						bTorch, bRustyKey, bToggleColor,
						bToggleHUD);

	/*
	Text cutter (70 characters)
	123456789-123456789-12346789-123456789-123456789-123456789-123456789-
	*/

	//display the dialogue
	if (bToggleSimple)
	{
		printf("Welcome to The Lost Cavern. Press ""1"" to continue\n\n");
		
		//display the options
		printf("Choices:\n\n");
		printf("1. Continue\n\n");
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
	else
	{
		printf("%s\n%s\n%s\n%s\n\n",
			"There was only nothingness. No light, no sound, no texture, not even ",
			"the feeling of your heart beating. Just a pure void where you are ",
			"left with nothing but your thoughts. You waited for what felt like ",
			"an eternity, a consciousness without a body."
		);

		dialogueWait(5, bToggleWait);

		printf("%s\n%s\n\n",
			"Then, as if responding to your pleas, the void crackled. A faint and",
			"dry whisper echoes in your head."
			);

			dialogueWait(3, bToggleWait);

		printf("%s\n\n%s\n\n%s\n\n%s\n\n%s\n\n",
			"“Find our treasure and make it yours.”",	
			"You scream to the void the questions that are lingering in your mind.",
			"“Where am I?”",
			"“Who are you?”",
			"“What treasure?”"
			);

			dialogueWait(5, bToggleWait);

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
}


/*
	This function displays the dialogue for room 1
	Preconditions: the parameters are non-negative integers
	@param nHealth tracks the current health of the player
	@param nScore tracks the current health of the player
	@param bShinyItem tracks whether the player has the Shiny Item or not
	@param bTorch tracks whether the player has the Torch or not
	@param bRustyColor tracks whether the player has the Rusty Key or not
	@param bToggleColor tracks whether to display color or not
	@param bToggleHUD tracks whether to show the Heads-up Display when playing
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
	@param bToggleSimple tracks whether to display the simplest version of dialogue or not
*/
void
displayRoom1(int nHealth, int nScore, int bShinyItem,
					int bTorch, int bRustyKey, int bToggleColor,
					int bToggleWait, int bToggleHUD, int bToggleShowMenu,
					int bToggleSimple)
{
//display the HUD
displayPlayerHUD(nHealth, nScore, bShinyItem,
					bTorch, bRustyKey, bToggleColor,
					bToggleHUD);

//display the dialogue
	if (bToggleSimple)
	{
		printf("\n\n");
		
		//display the options
		printf("Choices:\n\n");
		printf("1. Go to the Left\n\n");
		printf("2. Go to the Right\n\n");
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
	else
	{
		//Temp

		//display the options
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
}


/*
	This function displays the dialogue for room 2
	Preconditions: the parameters are non-negative integers
	@param nHealth tracks the current health of the player
	@param nScore tracks the current health of the player
	@param bShinyItem tracks whether the player has the Shiny Item or not
	@param bTorch tracks whether the player has the Torch or not
	@param bRustyColor tracks whether the player has the Rusty Key or not
	@param bToggleColor tracks whether to display color or not
	@param bToggleHUD tracks whether to show the Heads-up Display when playing
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
	@param bToggleSimple tracks whether to display the simplest version of dialogue or not
*/
void
displayRoom2(int nHealth, int nScore, int bShinyItem,
					int bTorch, int bRustyKey, int bToggleColor,
					int bToggleWait, int bToggleHUD, int bToggleShowMenu,
					int bToggleSimple)
{
//display the HUD
displayPlayerHUD(nHealth, nScore, bShinyItem,
					bTorch, bRustyKey, bToggleColor,
					bToggleHUD);

//display the dialogue
	if (bToggleSimple)
	{
		printf("Room 2: lose 10 health and gain 2 points\n\n");
		
		//display the options
		printf("Choices:\n\n");
		printf("1. Continue\n\n");
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
	else
	{
		//Temp

		//display the options
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
}


/*
	This function displays the dialogue for room 3
	Preconditions: the parameters are non-negative integers
	@param nHealth tracks the current health of the player
	@param nScore tracks the current health of the player
	@param bShinyItem tracks whether the player has the Shiny Item or not
	@param bTorch tracks whether the player has the Torch or not
	@param bRustyColor tracks whether the player has the Rusty Key or not
	@param bToggleColor tracks whether to display color or not
	@param bToggleHUD tracks whether to show the Heads-up Display when playing
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
	@param bToggleSimple tracks whether to display the simplest version of dialogue or not
*/
void
displayRoom3(int nHealth, int nScore, int bShinyItem,
					int bTorch, int bRustyKey, int bToggleColor,
					int bToggleWait, int bToggleHUD, int bToggleShowMenu,
					int bToggleSimple)
{
//display the HUD
displayPlayerHUD(nHealth, nScore, bShinyItem,
					bTorch, bRustyKey, bToggleColor,
					bToggleHUD);

//display the dialogue
	if (bToggleSimple)
	{
		printf("Room 3\n\n");
		
		//display the options
		printf("Choices:\n\n");
		printf("1. Pick up shiny item and gain 5 points\n\n");
		printf("2. Ignore\n\n");
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
	else
	{
		//Temp

		//display the options
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
}


/*
	This function displays the dialogue for room 4
	Preconditions: the parameters are non-negative integers
	@param nHealth tracks the current health of the player
	@param nScore tracks the current health of the player
	@param bShinyItem tracks whether the player has the Shiny Item or not
	@param bTorch tracks whether the player has the Torch or not
	@param bRustyColor tracks whether the player has the Rusty Key or not
	@param bToggleColor tracks whether to display color or not
	@param bToggleHUD tracks whether to show the Heads-up Display when playing
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
	@param bToggleSimple tracks whether to display the simplest version of dialogue or not
*/
void
displayRoom4(int nHealth, int nScore, int bShinyItem,
					int bTorch, int bRustyKey, int bToggleColor,
					int bToggleWait, int bToggleHUD, int bToggleShowMenu,
					int bToggleSimple)
{
//display the HUD
displayPlayerHUD(nHealth, nScore, bShinyItem,
					bTorch, bRustyKey, bToggleColor,
					bToggleHUD);

//display the dialogue
	if (bToggleSimple)
	{
		printf("Room 4\n\n");
		
		//display the options
		printf("Choices:\n\n");
		printf("1. Take the boat\n\n");
		printf("2. Swim\n\n");
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
	else
	{
		//Temp

		//display the options
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
}


/*
	This function displays the dialogue for room 5
	Preconditions: the parameters are non-negative integers
	@param nHealth tracks the current health of the player
	@param nScore tracks the current health of the player
	@param bShinyItem tracks whether the player has the Shiny Item or not
	@param bTorch tracks whether the player has the Torch or not
	@param bRustyColor tracks whether the player has the Rusty Key or not
	@param bToggleColor tracks whether to display color or not
	@param bToggleHUD tracks whether to show the Heads-up Display when playing
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
	@param bToggleSimple tracks whether to display the simplest version of dialogue or not
*/
void
displayRoom5(int nHealth, int nScore, int bShinyItem,
					int bTorch, int bRustyKey, int bToggleColor,
					int bToggleWait, int bToggleHUD, int bToggleShowMenu,
					int bToggleSimple)
{
//display the HUD
displayPlayerHUD(nHealth, nScore, bShinyItem,
					bTorch, bRustyKey, bToggleColor,
					bToggleHUD);

//display the dialogue
	if (bToggleSimple)
	{
		printf("Room 5\n\n");
		
		//display the options
		printf("Choices:\n\n");
		printf("1. Take the torch\n\n");
		printf("2. Ignore\n\n");
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
	else
	{
		//Temp

		//display the options
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
}


/*
	This function displays the dialogue for room 6
	Preconditions: the parameters are non-negative integers
	@param nHealth tracks the current health of the player
	@param nScore tracks the current health of the player
	@param bShinyItem tracks whether the player has the Shiny Item or not
	@param bTorch tracks whether the player has the Torch or not
	@param bRustyColor tracks whether the player has the Rusty Key or not
	@param bToggleColor tracks whether to display color or not
	@param bToggleHUD tracks whether to show the Heads-up Display when playing
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
	@param bToggleSimple tracks whether to display the simplest version of dialogue or not
*/
void
displayRoom6(int nHealth, int nScore, int bShinyItem,
					int bTorch, int bRustyKey, int bToggleColor,
					int bToggleWait, int bToggleHUD, int bToggleShowMenu,
					int bToggleSimple)
{
//display the HUD
displayPlayerHUD(nHealth, nScore, bShinyItem,
					bTorch, bRustyKey, bToggleColor,
					bToggleHUD);

//display the dialogue
	if (bToggleSimple)
	{
		printf("Room 6\n\n");
		
		//display the options
		printf("Choices:\n\n");
		printf("1. Continue\n\n");
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
	else
	{
		//Temp

		//display the options
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
}


/*
	This function displays the dialogue for room 7
	Preconditions: the parameters are non-negative integers
	@param nHealth tracks the current health of the player
	@param nScore tracks the current health of the player
	@param bShinyItem tracks whether the player has the Shiny Item or not
	@param bTorch tracks whether the player has the Torch or not
	@param bRustyColor tracks whether the player has the Rusty Key or not
	@param bToggleColor tracks whether to display color or not
	@param bToggleHUD tracks whether to show the Heads-up Display when playing
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
	@param bToggleSimple tracks whether to display the simplest version of dialogue or not
*/
void
displayRoom7(int nHealth, int nScore, int bShinyItem,
					int bTorch, int bRustyKey, int bToggleColor,
					int bToggleWait, int bToggleHUD, int bToggleShowMenu,
					int bToggleSimple)
{
//display the HUD
displayPlayerHUD(nHealth, nScore, bShinyItem,
					bTorch, bRustyKey, bToggleColor,
					bToggleHUD);

//display the dialogue
	if (bToggleSimple)
	{
		printf("Room 7\n\n");
		
		//display the options
		printf("Choices:\n\n");
		printf("1. Go to the left\n\n");
		printf("2. Go to the right\n\n");
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
	else
	{
		//Temp

		//display the options
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
}


/*
	This function displays the dialogue for room 8
	Preconditions: the parameters are non-negative integers
	@param nHealth tracks the current health of the player
	@param nScore tracks the current health of the player
	@param bShinyItem tracks whether the player has the Shiny Item or not
	@param bTorch tracks whether the player has the Torch or not
	@param bRustyColor tracks whether the player has the Rusty Key or not
	@param bToggleColor tracks whether to display color or not
	@param bToggleHUD tracks whether to show the Heads-up Display when playing
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
	@param bToggleSimple tracks whether to display the simplest version of dialogue or not
*/
void
displayRoom8(int nHealth, int nScore, int bShinyItem,
					int bTorch, int bRustyKey, int bToggleColor,
					int bToggleWait, int bToggleHUD, int bToggleShowMenu,
					int bToggleSimple)
{
//display the HUD
displayPlayerHUD(nHealth, nScore, bShinyItem,
					bTorch, bRustyKey, bToggleColor,
					bToggleHUD);

//display the dialogue
	if (bToggleSimple)
	{
		printf("Room 8\n\n");
		
		//display the options
		printf("Choices:\n\n");
		printf("1. Open the door\n\n");
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
	else
	{
		//Temp

		//display the options
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
}


/*
	This function displays the dialogue for room 9
	Preconditions: the parameters are non-negative integers
	@param nHealth tracks the current health of the player
	@param nScore tracks the current health of the player
	@param bShinyItem tracks whether the player has the Shiny Item or not
	@param bTorch tracks whether the player has the Torch or not
	@param bRustyColor tracks whether the player has the Rusty Key or not
	@param bToggleColor tracks whether to display color or not
	@param bToggleHUD tracks whether to show the Heads-up Display when playing
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
	@param bToggleSimple tracks whether to display the simplest version of dialogue or not
*/
void
displayRoom9(int nHealth, int nScore, int bShinyItem,
					int bTorch, int bRustyKey, int bToggleColor,
					int bToggleWait, int bToggleHUD, int bToggleShowMenu,
					int bToggleSimple)
{
//display the HUD
displayPlayerHUD(nHealth, nScore, bShinyItem,
					bTorch, bRustyKey, bToggleColor,
					bToggleHUD);

//display the dialogue
	if (bToggleSimple)
	{
		printf("Room 9\n\n");
		
		//display the options
		printf("Choices:\n\n");
		printf("1. Take the rusty key\n\n");
		printf("2. Ignore it\n\n");
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
	else
	{
		//Temp

		//display the options
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
}


/*
	This function displays the dialogue for room 10
	Preconditions: the parameters are non-negative integers
	@param nHealth tracks the current health of the player
	@param nScore tracks the current health of the player
	@param bShinyItem tracks whether the player has the Shiny Item or not
	@param bTorch tracks whether the player has the Torch or not
	@param bRustyColor tracks whether the player has the Rusty Key or not
	@param bToggleColor tracks whether to display color or not
	@param bToggleHUD tracks whether to show the Heads-up Display when playing
	@param bToggleShowMenu tracks whether to display the option "0. Return to menu" when playing
	@param bToggleSimple tracks whether to display the simplest version of dialogue or not
*/
void
displayRoom10(int nHealth, int nScore, int bShinyItem,
					int bTorch, int bRustyKey, int bToggleColor,
					int bToggleWait, int bToggleHUD, int bToggleShowMenu,
					int bToggleSimple)
{
//display the HUD
displayPlayerHUD(nHealth, nScore, bShinyItem,
					bTorch, bRustyKey, bToggleColor,
					bToggleHUD);

//display the dialogue
	if (bToggleSimple)
	{
		printf("Room 10\n\n");
		
		//display the options
		printf("Choices:\n\n");
		printf("1. Return to menu\n\n");
		printf("2. Quit\n\n");
	}
	else
	{
		//Temp

		//display the options
		displayMenuChoice(bToggleColor, bToggleShowMenu);
	}
}


/*
	This function is responsible for calling the function that is
		responsible for displaying the ending
	Preconditions: nGameEnding is an integer
	@param nGameEnding tracks the type of ending the player got
*/
void
displayEnding (int nInput, int* nCurrRoom, int* nCurrProg,
					int* nGameEnding)
{
    switch (*nGameEnding)
    {
		//Exit
		case 0:
			printf("Thank You For Playing!\n");
			break;

		//Death ending
        case 1:
			printf("Death ending\n");
			break;

		//Trapped ending
		case 2:
			printf("Trapped ending\n");
			break;
		
		//Good ending
		case 3:
			printf("Good ending\n");
			break;

		//Best ending
		case 4:
			printf("Best ending\n");
			break;
    }
}


void
displayEndingPage(int nGameEnding, int nHealth, int nScore,
					int bShinyItem, int bTorch, int bRustyKey,
					int bGotEnding1, int bGotEnding2, int bGotEnding3,
					int bGotEnding4, int bGotHealthy, int bGotPlentiful,
					int bGotCollector, int bGotSpeedrun, int bGotCompletionist)
{
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
			"    \\_/____________________________/. \n\n\n"
		);
}


void
displayUnknownAchievement()
{
	displayLine();
	//display achievement and its description then display its achievement art
	printf("|| %29s%21s ||  ", "?? ??? ??? ?","");
	printf("%17s", "_________  \n");

	printf("|| %29s%21s ||  ", "?? ??? ??? ?","");
	printf("%17s", "\\_____   \\ \n");

	printf("|| %29s%21s ||   ", "?? ??? ??? ?","");
	printf("%17s", "   /   __/  \n");

	printf("|| %29s%21s ||   ", "?? ??? ??? ?","");
	printf("%17s", "   |   |     \n");

	printf("|| %29s%21s ||   ", "?? ??? ??? ?","");
	printf("%17s", "   |   |     \n");

	printf("|| %29s%21s ||  ", "?? ??? ??? ?","");
	printf("%17s", "   <___>    \n");
	displayLine();
}


void
displayAchievements(int bGotEnding1, int bGotEnding2, int bGotEnding3, 
						int bGotEnding4, int bGotHealthy, int bGotPlentiful,
						int bGotCollector, int bGotSpeedrun, int bGotCompletionist,
						int bToggleColor)
{
	//display achievement ascii art
	displayLine();
	printf("%s%s%s%s%s%s",
		"   _____         .__    .__                                          __           \n",
		"  /  _  \\   ____ |  |__ |__| _______  __ ____   _____   ____   _____/  |_  ______ \n",
		" /  /_\\  \\_/ ___\\|  |  \\|  |/ __ \\  \\/ // __ \\ /     \\_/ __ \\ /    \\   __\\/  ___/ \n",
		"/    |    \\  \\___|   Y  \\  \\  ___/\\   /\\  ___/|  Y Y  \\  ___/|   |  \\  |  \\___ \\  \n",
		"\\____|__  /\\___  >___|  /__|\\___  >\\_/  \\___  >__|_|  /\\___  >___|  /__| /____  > \n",
		"        \\/     \\/     \\/        \\/          \\/      \\/     \\/     \\/          \\/  \n"
	);
	displayLine();

	//display achievement 1
	changeColor(bToggleColor,1,255,0,0); //change color to red
	if (bGotEnding1)
	{
		
	}
	else
		displayUnknownAchievement();
	changeColor(bToggleColor,0,255,255,255); //change color back to white
}


void
displayStatistics(int nGameCount, int nGameCompletion, int nTotalMoveCount, int nTotalInputs,
					int nTotalInputError, int nTotalHealthLost, int nTotalScore, int nTotalShinyItem,
					int nTotalTorchItem, int nTotalRustyKeyItem)
{
	displayLine();
	printf("%67s%67s%67s%67s%67s",
		" oooooooo8 ooooooooooo   o   ooooooooooo  oooooooo8   \n",
		"888        88  888  88  888  88  888  88 888          \n",
		" 888oooooo     888     8  88     888      888oooooo   \n",
		"        888    888    8oooo88    888             888  \n",
		"o88oooo888    o888o o88o  o888o o888o    o88oooo888   \n"
	);
	displayLine();
	
	printf("%-70s%10s\n", "Name:", "Statistic:");

	//game stats
	printf("-------------------------------- Game Statistics ------------------------------- \n");
	printf("%-70s%10d\n", "Amount of times you have started a new game:", nGameCount);
	printf("%-70s%10d\n", "Amount of times you have reached an ending:", nGameCompletion);
	printf("%-70s%10d\n", "Amount of times you moved between rooms in a game:", nTotalMoveCount);
	printf("%-70s%10d\n", "Amount of times you made a choice:", nTotalInputs);
	printf("%-70s%10d\n\n", "Amount of times you inputted a invalid input:", nTotalInputError);

	//player stats
	printf("------------------------------- Player Statistics ------------------------------ \n");
	printf("%-70s%10d\n", "Total amount of health you have lost:", nTotalHealthLost);
	printf("%-70s%10d\n", "Total amount of the scores you have obtained:", nTotalScore);
	printf("%-70s%10d\n", "Amount of times you have obtained the Shiny Item:", nTotalShinyItem);
	printf("%-70s%10d\n", "Amount of tines you have obtained the Torch item:", nTotalTorchItem);
	printf("%-70s%10d\n\n\n", "Amount of times you have obtained the Rusty Key item:", nTotalRustyKeyItem);

	//display the choices:
	printf("Choices:\n\n");
	printf("1. Stay.\n\n");
	printf("2. Go back to menu.\n\n");
}