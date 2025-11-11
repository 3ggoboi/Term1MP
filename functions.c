#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int printRandNums(int min, int max) 
{
	// Get the system time.
    unsigned seed = time(0);
    
    // Seed the random number generator.
    srand(seed);
	
	// Find the random number in the range [min, max]
    int rd_num = rand() % (max - min + 1) + min;
}

int numOfPlayers()
{    
	int nPlayers = 1;

    printf("How many players will be playing the game?\n\n");
    printf("\t>>> Single Player <<<\n");
    printf("\t    2 Players\n");
    printf("\t    3 Players\n");
    printf("\t    4 Players\n");

    do
	{
		printf("\nHow many players will be playing? (1-4): ");
		scanf("%d", &nPlayers);
		
		if(nPlayers < 1 || nPlayers > 4)
		{
			printf("\nPlease pick within the options given:\n\n");
			printf("\t>>> Single Player <<<\n");
    		printf("\t    2 Players\n");
    		printf("\t    3 Players\n");
    		printf("\t    4 Players\n\n");
		}
	}while(nPlayers < 1 || nPlayers > 4);
	
	
	printf("\n\nYou will now play in %d player mode", nPlayers);
}

int diceRoll()
{
	int nRoll, min = 1, max = 6;
	
	nRoll = printRandNums(min, max);
	printf("\n\nThe number rolled on the die is: %d", nRoll);
}