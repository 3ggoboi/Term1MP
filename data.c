#include <stdio.h>

int selectLevel(int Level){	
	do{
		printf("Select the game difficulty (Levels 1-3):");
		scanf("%d", &Level);
		
		switch(Level)
		{
			case 1:
				printf("You have selected the Easy Difficulty\n");
				printf("The following sequence problems will deal with numbers\n\n");
				break;
			case 2:
				printf("You have selected the Easy Difficulty\n");
				printf("The following sequence problems will deal with letters\n\n");
				break;
			case 3:
				printf("You have selected the Hard Difficulty\n");
				printf("The following sequence problems will deal with both letters and numbers\n\n");
				break;
			default:
				printf("Please input a valid difficulty level\n\n");
				break;
		}
	}while(Level != 1 && Level != 2 && Level != 3);
	
}

int numPlayers(int nPlayers){

    printf("How many players will be playing the game?\n\n");
    printf("\tSingle Player\n");
    printf("\t2 Players\n");
    printf("\t3 Players\n");
    printf("\t4 Players\n");

    do
	{
		printf("\nHow many players will be playing? (1-4): ");
		scanf("%d", &nPlayers);
		
		if(nPlayers < 1 || nPlayers > 4)
		{
			printf("\nPlease pick within the options given:\n\n");
			printf("\tSingle Player\n");
    		printf("\t2 Players\n");
    		printf("\t3 Players\n");
    		printf("\t4 Players\n\n");
		}
	}while(nPlayers < 1 || nPlayers > 4);
	
	
	printf("\n\nYou will now play in %d player mode", nPlayers);
}


int playAI(){
	// 50/50 chance the bot guesses right
}
