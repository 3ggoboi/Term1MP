/*
CCPROG1 Machine Project
"A Walk in The Sequence Park"
Student Name: Matthew Miguel S. Fabiala
Section : S19B
*/

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
	srand(time(NULL));		// seeds the random number generator
	
	do{
		// Running the main game logic
		score =	runLevelThree(score);
	}while(score != 3);
	
	printf("\n\nCongratulations! You have won the game!");
	
	return 0;
}


/* Dev Notes:
- Will just see how to make each function work first, before I see how I can
connect each function to work with one another
- My brain hurts
- God bless CCPROG1
*/
