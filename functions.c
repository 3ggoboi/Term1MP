#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int giveRandNums(int min, int max) {
	srand(time(NULL));
	
	// Find the random number in the range [min, max]
    int rd_num = rand() % (max - min + 1) + min;
}

int diceRoll(){
	int nRoll, min = 1, max = 6;
	
	nRoll = giveRandNums(min, max);
	printf("\n\nThe number rolled on the die is: %d", nRoll);
}

int playerPunish(int score){
	int min = 1, max = 3;
	
	score = score - giveRandNums(min, max);
	
	return score;
}

int playAI(){
	// 50/50 chance the bot guesses right
}

