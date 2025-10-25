/*This file is responsible for deciding and updating the game based
	on the decisions of the player
*/



/* ------------------------ Function Prototypes ------------------------ */
void handleRoomCredits(int nInput, int* nCurrRoom, int* nCurrProg);
void handleRoomMenu (int nInput, int* nGameEnding, int* nCurrRoom, 
                        int* nCurrProg);
/* --------------------------------------------------------------------- */


/*
Room Index:
-3 = options
-2 = credits
-1 = menu with continue option
0 = menu
1 = room 1
2 = room 2
3 = room 3
4 = room 4
5 = room 5
6 = room 6
7 = room 7
8 = room 8
9 = room 9
10 = room 10
*/


/*
	This function is responsible for the logic of the credits page
	Preconditions: nInput is an integer and nCurrRoom and nCurrProg
                    are integer pointers
    @param nInput tracks the input the player has made
	@param nCurrRoom tracks the current room the player is in
    @param nCurrProg tracks the total progress of the player
*/
void
handleRoomCredits(int nInput, int* nCurrRoom, int* nCurrProg)
{
	/*
    The credit page has two (2) choices:
		1. To stay in the credits page
		2. Go back to menu
	*/

    if (nInput == 2)
        if (*nCurrProg)
			*nCurrRoom = -1; //where -1 is the menu page with a continue option
		else
			*nCurrRoom = 0; //where 0 is the normal menu page
}


/*
	This function is responsible for responding to the player's choice
	Preconditions: nInput is an integer and nGameEdning, nCurrRoom, 
                    and nCurrProg are integer pointers
    @param nInput tracks the input the player has made
    @param nGameEnding tracks the ending the player would get at the end
	@param nCurrRoom tracks the current room the player is in
    @param nCurrProg tracks the total progress of the player
*/
void
handleRoomMenu (int nInput, int* nGameEnding, int* nCurrRoom, int* nCurrProg)
{
	switch (nInput)
		{
        //start the game
		case 1:
			*nCurrRoom = 0;
			*nCurrProg = 1;
			break;
				
		//Go to the credits
		case 2:
			*nCurrRoom = -2;
			break;

        //Go to the options
        case 3:
            *nCurrRoom = -3;
				
		//terminate the program
		case 4:
			*nGameEnding = -1;
		}
}