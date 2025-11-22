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
	
	printf("\n\n=======================================================\n\n");
	printf("The number rolled on the die is: %d\n", nRoll);
	printf("You will now have a chance to move up to %d space(s)!\n\n", nRoll);	
	printf("=======================================================\n\n");
	
	return nRoll;
}

int playerPunish(int score){
	int get_punished;
	int min = 1, max = 3;
	
	get_punished = giveRandNums(min, max);
	
	score = score - get_punished;
	printf("\n\n\t>>> You have unfortunately moved down %d spaces... <<<\n\n", get_punished);
	
	return score;
}

int playAI(){
	// 50/50 chance the bot guesses right
}

