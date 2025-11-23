#include <stdio.h>
#include <stdbool.h>

int selectLevel(int Level){	
	int check_scanf; // Checking if the given input is valid
	
	do{
		
		printf("=======================================================================\n");
		printf("\t\t   Pick any of the levels below!\n\n");
		printf("\t --- LEVEL 1     (Number & Letter Sequences)      ---\n");
		printf("\t --- LEVEL 2     (Number & Letter Sequences)      ---\n");
		printf("\t --- LEVEL 3 (Combined Number & Letter Sequences) ---\n\n");
		printf("=======================================================================\n\n");
		printf("Select the game difficulty: ");
		
		check_scanf = scanf("%d", &Level);
		
		
		if(check_scanf == 1)
			switch(Level)
			{
				case 1:
					printf("\n\nYou have selected the Easy Difficulty\n");
					printf("The following sequence problems will deal with numbers and letters\n");
					printf("While asking for the next term in the sequence!(e.g. A B C D __)\n\n");
					return 1;;
				case 2:
					printf("\n\nYou have selected the Easy Difficulty\n");
					printf("The following sequence problems will deal with numbers and letters\n");
					printf("While asking for the next term in the sequence!(e.g. 1 3 5 7 __ __)\n\n");
					return 2;
				case 3:
					printf("\n\nYou have selected the Hard Difficulty\n");
					printf("The following sequence problems will deal with combined letter and number sequences\n\n");
						printf("While asking for the next TWO terms in the sequence!(e.g. A1 C3 E5 G7 __ __)\n\n");
					return 3;
				default:
					printf("ERROR: Please input a valid difficulty level!!!\n\n");
					break;
			}
		else {
			printf("Invalid Input. Please try again...");
			
			Level = 0;
		}
	}while(Level != 1 && Level != 2 && Level != 3);
	
}

int numPlayers(int nPlayers){
	int check_scanf;
	
    printf("========================================================\n");
	printf("How many players will be playing the game?\n\n");
    printf("\tSingle Player\n");
    printf("\t2 Players\n");
    printf("\t3 Players\n");
    printf("\t4 Players\n");

	do {
        printf("\nPlease input a value between 1 and 4: ");
        check_scanf = scanf("%d", &nPlayers);

        if (check_scanf == 1) {
            // Check if the inputs given are correct
            switch (nPlayers) {
                case 1:
                case 2:
                case 3:
                case 4:
                    // If the given input is 1, 2, 3, or 4, it passes the check
                    printf("\n\nYou will now play in %d player mode.\n", nPlayers);
                    return nPlayers;
                default:
                    // Otherwise
                    printf("========================================================\n");
					printf("\n!!! Please pick within the options given !!!\n\n");
    				printf("\tSingle Player\n");
				    printf("\t2 Players\n");
				    printf("\t3 Players\n");
				    printf("\t4 Players\n");
				    printf("========================================================\n");
                    break;
            }
        } else {
            // ERROR INPUT
            printf("\nInvalid input! Please only enter a number between 1 and 4...\n");
            
            nPlayers = 0; // Reset value to redo the loop
        }
    } while (true); // Loop runs until a valid number is returned
}




