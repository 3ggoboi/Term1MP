#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int runLevelOne(int score){
	int first_num, next_num, current_num, player_guess;
	int sequence_length, common_diff, correct_answer;
	int min = 1, max = 50;
	
	
    printf("Welcome to the Number Sequence Guessing Game!\n");
    printf("I will show you a number, and you guess the next one in the sequence.\n");

	first_num = rand() % 100 + 1;
	common_diff = giveRandNums(min, max);
	current_num = first_num;

    printf("Find the next number in the sequence: ");
        
	for(sequence_length = 0; sequence_length < 5; sequence_length++){
	
		printf("%d ", current_num);
	
		current_num = current_num + common_diff;
	}

    correct_answer = current_num;
        
    printf("\n\nWhat is your guess for the next number? ");
    scanf("%d", &player_guess);


    if (player_guess == correct_answer) {
        printf("Correct! You guessed the next number!\n");
        score = score + 1;
        return score;
    } else {
        printf("Incorrect. The next number was %d.\n", correct_answer);
    	score = playerPunish(score);
		
		return score;
    }
}

