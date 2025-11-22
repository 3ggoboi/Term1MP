#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int printRandNums(int min, int max) {
	// Get the system time.
    unsigned seed = time(0);
    
    // Seed the random number generator.
    srand(seed);
	
	// Find the random number in the range [min, max]
    int rd_num = rand() % (max - min + 1) + min;
}

int diceRoll(){
	int nRoll, min = 1, max = 6;
	
	nRoll = printRandNums(min, max);
	printf("\n\nThe number rolled on the die is: %d", nRoll);
}

int playerPunish(){
	// make player go back 1 or 3 tiles
}
