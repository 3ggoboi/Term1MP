/***************************************************************************
This is to certify that this project is my own work, based on my personal efforts
in studying and applying the concepts learned. I have constructed the functions
and their respective algorithms and corresponding code by myself. The program
was run, tested, and debugged by my own efforts. I further certify that I have
not copied in part or whole or otherwise plagiarized the work of other students
and/or persons.

Matthew Miguel S. Fabiala, DLSU ID# 12504343
***************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.c"
#include "data.c"
#include "Game Logic.c"


int main()
{
	int score = 0;
	int numberofPlayers = 0;
	int Level = 0; // Intialize the level
	int player_turn;
	
	//Player Scores
	int scoreP1 = 0;
	int scoreP2 = 0;
	int scoreP3 = 0;
	int scoreP4 = 0;
	
	srand(time(NULL));		// seeds the random number generator
	
	printf("Welcome to A Walk in the Sequence Park!\n");
	printf("A mini-game coded by Matthew Miguel S. Fabiala\n");
	printf("For the CCPROG1 Machine Project\n\n");
	
	numberofPlayers = numPlayers(numberofPlayers);
	Level = selectLevel(Level);
	
	// Running the main game logic
	do{
		
		switch(Level){
			case 1:
				score =	runLevelOne(score);
				break;
			case 2:
				score = runLevelTwo(score);
				break;
			case 3:
				score = runLevelThree(score);
				break;
		}
	
	}while(score != 50);
	
	printf("\n\nCongratulations! You have won the game!");
	
	return 0;
}


/* Dev Notes:
- Will just see how to make each function work first, before I see how I can
connect each function to work with one another
- My brain hurts
- God bless CCPROG1
*/
