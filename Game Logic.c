#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
// This is the file that holds the majority of the functions that run the game's main logic


// General Functions that help the game to run


/*	This function allows users to set the level of difficulty they want to play in. There
	are a total of 3 levels. This function allows the program to tell which runLevel function
	to run, so it can generate the appropriate sequences. 
	Precondition:	The level must be a non-negative integer in-between the values 1 and 3
	@param Level is the level of difficulty player's will choose to play in	
*/
int selectLevel(int Level){	
	int check_scanf; // Checking if the given input is valid
	
	//The main do-while loop
	do{
		
		printf("=======================================================================\n");
		printf("\t\t   Pick any of the levels below!\n\n");
		printf("\t --- LEVEL 1     (Number & Letter Sequences)      ---\n");
		printf("\t --- LEVEL 2     (Number & Letter Sequences)      ---\n");
		printf("\t --- LEVEL 3 (Combined Number & Letter Sequences) ---\n\n");
		printf("=======================================================================\n\n");
		printf("Select the game difficulty: ");
		
		check_scanf = scanf("%d", &Level);
		
		// If the input is a valid integer players can see the menu to choose the difficulty levels
		if(check_scanf == 1)
			switch(Level)	//Based on the valid inputs given, gives brief descriptions on the level chosen
			{
				case 1:
					printf("\n\n\t\t>>> You have selected the Easy Difficulty <<<\n\n");
					printf("\tThe following sequence problems will deal with numbers and letters\n");
					printf("\tWhile asking for the next term in the sequence!(e.g. A B C D __)\n\n\n");
					return 1;
				case 2:
					printf("\n\t\t>>> You have selected the Medium Difficulty <<<\n\n");
					printf("\tThe following sequence problems will deal with numbers and letters\n");
					printf("\tWhile asking for the next term in the sequence!(e.g. 1 3 5 7 __ __)\n\n\n");
					return 2;
				case 3:
					printf("\n\n\t\t>>> You have selected the Hard Difficulty <<<\n\n");
					printf("\tThe following sequence problems will deal with combined letter and number sequences\n");
						printf("\tWhile asking for the next TWO terms in the sequence!(e.g. A1 C3 E5 G7 __ __)\n\n\n");
					return 3;
				default:
					break;
			}
		//If given an invalid character that's not an integer, show error, and ask for input again by
		//retriggering the loop until given the right input. 
		else{
            //ERROR INPUT
			printf("\n\n\n#######################################################################\n\n");
			
			printf("\t\tERROR: Invalid Input! Please try again...");
			scanf("%*[^\n]%*c"); //Clear input buffer, reads, and discards all characters
			
			printf("\n\n########################################################################\n\n\n\n");
		}
	}while(Level < 1 || Level > 3);		//Loop will not exit until a valid level (1-3) is chosen and assigned
}

/*	This function decides the amount of players that will be playing the game. 
	Precondition:	The amount of players must be a non-negative integer in-between the values 1 and 4
	@param nPlayers is the amount of players that will play the game
	@param check_scanf checks if the inputs given are valid and can be used
*/
int numPlayers(int nPlayers){
	int check_scanf;
	
    printf("========================================================\n");
	printf("How many players will be playing the game?\n\n");
    printf("\tSingle Player\n");
    printf("\t2 Players\n");
    printf("\t3 Players\n");
    printf("\t4 Players\n");
	
	//The do-while loop that verifies if the input is valid
	do {
        printf("\nPlease input a value between 1 and 4: ");
        check_scanf = scanf("%d", &nPlayers);	//Assigning a value so we can use it in the if statement
		
		//If statement triggers if input is valid
        if (check_scanf == 1) {
            // Check if the inputs given are within 1 and 4
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
                    break;	//Do-while loop triggers again
            }
        } 
        //This triggers if input is invalid
		else{
            //ERROR INPUT
			printf("\n\n\n#######################################################################\n\n");
			
			printf("\t\tERROR: Invalid Input! Please try again...");
			scanf("%*[^\n]%*c"); //Clear input buffer, reads, and discards all characters
			
			printf("\n\n########################################################################\n\n\n\n");
        }
    } while (1); // Loop runs until a valid number is returned
}

/*	This function calculates how many spaces a player moves on the "board". This also checks
	and calculates if a player overshoots the maximum 50 tiles, and sets them back by the amount
	overshot (e.g. Player is on tile 45, rolls a 6, so they land on tile 49)
	Precondition:	The player's score must not be negative, and the rolls are non-negative integers
					between 1 and 6.
	@param *score is the current player's score
	@param roll is the value of the current dice roll
	@param possible_score is the score before it is possibly deducted if the player overshoots
	@param player_overshoot is value of the player's score subtracted by the maximum tile value
*/
void playerMoves(int *score, int roll){
	int possible_score, player_overshoot;
	
	possible_score = *score + roll;	//Calculate the possible score so we can use it if overshot
	
	//If statement triggers if the player overshoots the maximum tile limit
	if (possible_score > 50){
		
		player_overshoot = possible_score - 50;	//Forumula to get the amount overshot
		
		*score = 50 - player_overshoot;	//Subtracts the current score by the amount overshot
		
		printf("\n\t>>> You rolled a %d, which put you %d over the 50th tile! <<<", roll, player_overshoot);
        printf("\n\t>>> You BOUNCE BACK and land on tile %d. <<<\n\n\n", *score);
	}
	//If the player does not overshoot, their score increases by the amount they rolled
	else{
			*score += roll; 
	printf("\t\t>>> Current score: %d <<<\n\n", *score);
	}
}

/*	This function checks if a player's score has fallen below 0 (in the negative values). If they have
	the player is eliminated/ejected from the game.
	Precondition:	The player's score is below 0 (or negative)
	@param *score is the current player's score
	@param current_player is the player currently playing
	@param numberofPlayers is the amount of players currently playing the game
*/
void eliminatePlayer(int *score, int current_player, int *numberofPlayers){
	
	//Check if the score is below 0, if it is, triggers the text and the player gets eliminated
	if(*score < 0){
		printf("\n\n####################################################################\n");
        printf("!!! PLAYER %d HAS BEEN ELIMINATED! Their score dropped below 0... !!!\n", current_player);
        printf("####################################################################\n\n");
        
        *score = -999;	//Kill the player and don't give them a chance to even come back
        
        (*numberofPlayers)--; //Decreases the original amount of players playing by 1 (e.g. numberofPlayers = 4 becomes numberofPlayers = 3)
	}
}

// Level Functions

/*	This function handles the generation of sequences, answer checking, and scoring for the 1st difficulty
	Precondition:	The value of Level is equal to 1
	@param score is the current score of the player
	@param first_num is the first number randomly generated in the number sequence problems
	@param current_num is used to verify the proceeding numbers of the sequence without revealing them to the player
					   and can also be used to see if the player answers correctly
	@param first_letter is the first letter randomly generated in the letter sequence problems
	@param current_letter is used to verift the proceeding letter of the sequence without revealing them to the player
						  and can also be used to see if the player answers correctly
	@param sequence_length determines how many numbers or letters will be generated in order for the sequence
	@param common_diff is the common difference between letters or numbers (e.g. sequences "A C E G" and "1 3 5 7" have a common difference of 2)
	@param player_guess is the player's answer to the number sequence given
	@param correct_answer is the correct value that the player must input to not get punished
	@param player_char_guess is the player's answer for the letter sequence given
	@param sequence_type determines if the program will give a number or letter sequence
	@param min is the minimum value of the common difference range
	@param max is the maximum value of the common difference range
*/
int runLevelOne(int *score){
	int first_num, current_num;
	int first_letter, current_letter;
	int sequence_length, common_diff;
	
	int player_guess, correct_answer;
	char player_char_guess;
	
	int sequence_type = rand() % 2;	//randomly generate numbers so that there is a 50/50 chance to get a number or letter sequence
	int min = 1, max = 10;			//set the minimum and maximum range for the common difference
	
	promptRoll();				//prompt the user to roll
	
	int roll = diceRoll(); 		// Getting the points for the player's turn
	
	playerMoves(score, roll);	//Calculate how much the player will move and update the score
	
	// Generating a random number sequence
	if(sequence_type == 1){
		
		first_num = rand() % 100 + 1;			//generate a random first number within the range of 1 to 100
		common_diff = giveRandNums(min, max);	//get the common difference
		current_num = first_num;				//set the current number to the first number

		printf("=======================================================\n");	
	    printf("Find the next number in the sequence: ");
		
		//For-loop to generate 4 more numbers to the sequence
		for(sequence_length = 0; sequence_length < 5; sequence_length++){
		
			printf("%d ", current_num);					//prints the numbers
		
			current_num = current_num + common_diff;	//updates each number so that the last number is added by the common difference
			
		}
		printf("\n=======================================================\n");
		
		correct_answer = current_num;	//assigns the last generated number in the sequence to be the correct answer
	}
	//Generating a random letter sequence
	else{
		common_diff = giveRandNums(min, max);	//get the common difference
		
		first_letter = (rand() % ('W' - 'A' + 1) + 'A');	//Randomly generates the first letter from A through W 
															//The range cannot end at 'Z' or else it will give ASCII values beyond 'Z'
		
		current_letter = first_letter;						//Assigns the first letter to be the current letter
		
		printf("=======================================================\n");
		printf("Find the next letter in the sequence: ");
		
		//Generates the letter sequence
		for (sequence_length = 0; sequence_length < 5; sequence_length++) {
	            
	            printf("%c ", current_letter);
	            
	            // Calculate the next term
	            current_letter = current_letter + common_diff;
	            
	            // Handle wrap-around: If past 'Z', loop back to 'A'
	            if (current_letter > 'Z') {
	                current_letter = current_letter - ('Z' - 'A' + 1); // Subtract 26
	            }
	        }
	    printf("\n=======================================================\n");
	    
        correct_answer = current_letter;	//Assigns the next letter (now the current letter) as the correct answer
	}
    
	// Getting the player's answer 
    printf("\n\nWhat is the next number/letter? ");
    
    // Changes the scanf type since we will be getting two possible types of inputs
	if(sequence_type == 1){
		scanf("%d", &player_guess);
		scanf("%*[^\n]%*c"); // Clearing out old input
	}
	else {
		// Reads char value, converts to uppercase, then to integer
		scanf(" %c", &player_char_guess);
		player_char_guess = toupper(player_char_guess);
		player_guess = (int)player_char_guess;
		scanf("%*[^\n]%*c"); // Clearing out old input
	}

	
	// Scoring
	
	// The player gets the right answer
    if (player_guess == correct_answer) {
        printf("Correct! You guessed it right!\n\n\n");
        printf("\t>>> You have successfully moved up %d spaces! <<<\n\n", roll);
    } 
    // The player gets the wrong answer
	else{
        printf("Incorrect. The next term in the sequence was: ");
        
        if(sequence_type == 1){
        	printf("%d\n", correct_answer);
		}
		else{
			printf("%c\n", (char)correct_answer);
		}
        
    	*score = playerPunish(*score);	//Punish the player if they get the answer wrong
    }
    
	printf("\t     >>> Your current score is now: %d <<<\n\n", *score);
	
	return roll;	//return the roll value since we need it if the player rolls a 6
}

/*	This function handles the generation of sequences, answer checking, and scoring for the 2nd difficulty
	Precondition:	The value of Level is equal to 2
	@param score is the current score of the player
	@param first_num is the first number randomly generated in the number sequence problems
	@param current_num is used to verify the proceeding numbers of the sequence without revealing them to the player
					   and can also be used to see if the player answers correctly
	@param first_letter is the first letter randomly generated in the letter sequence problems
	@param current_letter is used to verify the proceeding letter of the sequence without revealing them to the player
						  and can also be used to see if the player answers correctly
	@param sequence_length determines how many numbers or letters will be generated in order for the sequence
	@param common_diff is the common difference between letters or numbers (e.g. sequences "A C E G" and "1 3 5 7" have a common difference of 2)
	@param player_guess1 is the player's first answer to the number sequence given
	@param player_guess2 is the player's second answer to the number sequence given
	@param correct_answer1 is the first correct value that the player must input to not get punished
	@param correct_answer2 is the second correct value that the player must input to not get punished
	@param player_char_guess1 is the player's first answer for the letter sequence given
	@param player_char_guess2 is the player's second answer for the letter sequence given
	@param sequence_type determines if the program will give a number or letter sequence
	@param min is the minimum value of the common difference range
	@param max is the maximum value of the common difference range
*/
int runLevelTwo(int *score){
	int first_num, current_num;
	int first_letter, current_letter;
	int sequence_length, common_diff;
	
	int player_guess1, player_guess2;
	int correct_answer1, correct_answer2;
	char player_char_guess1, player_char_guess2;
	
	int sequence_type = rand() % 2; 	//randomly generate numbers so that there is a 50/50 chance to get a number or letter sequence
	int min = 1, max = 10;				//set the minimum and maximum range for the common difference
	
	promptRoll(); 						//Prompts the user to roll
	
	int roll = diceRoll(); 				// Getting the points for the player's turn
	
	playerMoves(score, roll);			//Calculate how much the player will move and update the score
		
	// Generating a random number sequence
	if(sequence_type == 1){
		
		first_num = rand() % 100 + 1;			//generate a random first number within the range of 1 to 100
		common_diff = giveRandNums(min, max);	//get the common difference
		current_num = first_num;				//set the current number to the first number

		printf("=======================================================\n");	
	    printf("Find the next TWO numbers in the sequence: ");
		
		//For-loop to generate 4 more numbers to the sequence
		for(sequence_length = 0; sequence_length < 5; sequence_length++){
		
			printf("%d ", current_num);
		
			current_num = current_num + common_diff;	//updates each number so that the last number is added by the common difference
			
		}
		printf("\n=======================================================\n");
		
		correct_answer1 = current_num;				//Assign the sixth term for the first correct answer
		current_num = current_num + common_diff;	//Getting the seventh term
		correct_answer2 = current_num;				//Assign the seventh term for the second correct answer
	}
	//Generating a random letter sequence
	else{
		common_diff = giveRandNums(min, max);				//get the common difference
		
		first_letter = (rand() % ('W' - 'A' + 1) + 'A');	//Randomly generates the first letter from A through W 
		
		current_letter = first_letter;						//Assign the first letter as the current letter
		
		printf("==========================================================\n");
		printf("Find the next TWO letters in the sequence: ");
		
		//Generates the letter sequence
		for (sequence_length = 0; sequence_length < 5; sequence_length++) {
	            
	            printf("%c ", current_letter);
	            
	            // Calculate the next term
	            current_letter = current_letter + common_diff;
	            
	            // Handle wrap-around: If past 'Z', loop back to 'A'
	            if (current_letter > 'Z') {
	                current_letter = current_letter - ('Z' - 'A' + 1); // Subtract 26
	            }
	        }
	    printf("\n==========================================================\n");
	    
        correct_answer1 = current_letter;						//Assigns the sixth letter (now the current letter) as the first correct answer
        current_letter = current_letter + common_diff;			//Gets the value of the seventh letter
		if(current_letter > 'Z'){								// Handle wrap-around: If past 'Z', loop back to 'A'
        	current_letter = current_letter - ('Z' - 'A' + 1);
		}
		correct_answer2 = current_letter;						//Assigns the seventh letter as the second correct answer
	}
    
	// Getting the player's FIRST answer 
    printf("\n\nWhat is the sixth number/letter in the sequence? ");
    	// Changes the scanf type since we will be getting two possible types of inputs
		if(sequence_type == 1){
			scanf("%d", &player_guess1);
			scanf("%*[^\n]%*c"); // Clearing out old input
		}
		else {
			// Reads char value, converts to uppercase, then to integer
			scanf(" %c", &player_char_guess1);
			player_char_guess1 = toupper(player_char_guess1);
			player_guess1 = (int)player_char_guess1;
			scanf("%*[^\n]%*c"); // Clearing out old input
		}
	
		
	// Getting the player's SECOND answer
	printf("What is the seventh number/letter in the sequence? ");
    	// Changes the scanf type since we will be getting two possible types of inputs
		if(sequence_type == 1){
			scanf("%d", &player_guess2);
			scanf("%*[^\n]%*c"); // Clearing out old input
		}
		else {
			// Reads char value, converts to uppercase, then to integer
			scanf(" %c", &player_char_guess2);
			player_char_guess2 = toupper(player_char_guess2);
			player_guess2 = (int)player_char_guess2;
			scanf("%*[^\n]%*c"); // Clearing out old input
		}
	
	// Scoring
	
	// The player gets the right answer
    if (player_guess1 == correct_answer1 && player_guess2 == correct_answer2) {
        printf("Correct! You got both terms right!\n\n");
        printf("\t>>> You have successfully moved up %d spaces! <<<\n\n", roll);
    } 
    // The player gets the wrong answer
	else{
        printf("Incorrect. The next two terms in the sequence are: ");
        
        //If statement determines which printf statement is appropriate to use depending on the sequence type
        if(sequence_type == 1){
        	printf("%d and %d\n", correct_answer1, correct_answer2);
		}
		else{
			printf("%c and %c\n", (char)correct_answer1, (char)correct_answer2);
		}
        
    	*score = playerPunish(*score);	//Punishes the player for inputting wrong answers
    }
	
    printf("\t     >>> Your current score is now: %d <<<\n\n", *score);
	
	return roll;	//return the roll value since we need it if the player rolls a 6
}

/*	This function handles the generation of sequences, answer checking, and scoring for the 3rd difficulty
	Precondition:	The value of Level is equal to 3
	@param score is the current score of the player
	@param first_num is the first number randomly generated in the number sequence problems
	@param current_num is used to verify the proceeding numbers of the sequence without revealing them to the player
					   and can also be used to see if the player answers correctly
	@param first_letter is the first letter randomly generated in the letter sequence problems
	@param current_letter is used to verify the proceeding letter of the sequence without revealing them to the player
						  and can also be used to see if the player answers correctly
	@param sequence_length determines how many numbers or letters will be generated in order for the sequence
	@param common_diff is the common difference between letters or numbers (e.g. sequences "A C E G" and "1 3 5 7" have a common difference of 2)
	@param player_guess1 is the player's first answer to the number sequence given
	@param player_guess2 is the player's second answer to the number sequence given
	@param correct_answer1 is the first correct value that the player must input to not get punished
	@param correct_answer2 is the second correct value that the player must input to not get punished
	@param player_char_guess1 is the player's first answer for the letter sequence given
	@param player_char_guess2 is the player's second answer for the letter sequence given
	@param char_input1 is the first raw character input given by the player
	@param char_input2 is the second raw character input given by the player
	@param min is the minimum value of the common difference range
	@param max is the maximum value of the common difference range
*/
int runLevelThree(int *score){
	int first_num, current_num;
	int first_letter, current_letter;
	int sequence_length, common_diff;
	
	int player_guess1, player_guess2;
	int player_guess_char1, player_guess_char2; 
	char char_input1, char_input2; 						//We need this for the raw scanf input
	
	int correct_num1, correct_num2;
	int correct_char1, correct_char2;
	
	int min = 1, max = 4;								//initialize the minimum and maximum common difference

	common_diff = giveRandNums(min, max);				//get the common difference
    
    first_num = rand() % 10 + 1; 						// Start with any of the numbers 1-10
    first_letter = (rand() % ('W' - 'A' + 1) + 'A');	//Randomly generates the first letter from A through W 
    
    current_num = first_num;							//Assigns the first number as the current number
    current_letter = first_letter;						//Assigns the first letter as the current letter
	
	promptRoll();										// Prompts user to roll
	int roll = diceRoll(); 								// Getting the points for the player's turn
	
	playerMoves(score, roll);							//Calculate how much the player will move and update the score
	
	printf("===========================================================================\n");	
    printf("Find the next TWO terms in this combined sequence: ");
    
    //Generates the random combined number and letter sequence
    for(sequence_length = 0; sequence_length < 5; sequence_length++){
    	printf("%c%d ", (char)current_letter, current_num);
    	
    	current_num = current_num + common_diff;				//Calculate the next number
    	current_letter = current_letter + common_diff;			//Calculate the next letter
    	
    	if(current_letter > 'Z'){								// Handle wrap-around: If past 'Z', loop back to 'A'
    		current_letter = current_letter - ('Z' - 'A' + 1);
		}	
	}
	
	printf("\n===========================================================================\n");
	
	//Getting the 6th Term Answer
	correct_char1 = current_letter;							//Assigns the sixth letter (now the current letter) as the first correct answer
	correct_num1 = current_num;								//Assign the sixth term as the first correct answer
	
	//Getting the 7th Term
	current_num = current_num + common_diff;				//Calculate the 7th number in the sequence
	current_letter = current_letter + common_diff;			//Calculate the 7th letter in the sequence
	if(current_letter > 'Z'){								// Handle wrap-around: If past 'Z', loop back to 'A'
		current_letter = current_letter - ('Z' - 'A' + 1);
	}
	
	//Getting the 7th Term Answer
	correct_char2 = current_letter;							//Assigns the seventh letter as the second correct answer
	correct_num2 = current_num;								//Assign the seventh term as the second correct answer
	
	// Getting the player's FIRST answer 
    printf("\n\nWhat is the SIXTH term in the sequence? (e.g. enter a letter then a number, like G10)\n");
	printf("Take note that answers with spaces in between, like 'G 10' will not work\n\n");
	printf("Your Answer: ");
	scanf(" %c%d", &char_input1, &player_guess1);
	
	//Converting to uppercase
	char_input1 = toupper(char_input1);
	player_guess_char1 = (int)char_input1;

	scanf("%*[^\n]%*c"); // Clearing out old input

	// Getting the player's SECOND answer 
    printf("\n\nWhat is the SEVENTH term in the sequence? (e.g. enter a letter then a number, like G10)\n");
	printf("Remember that answers with spaces in between, like 'G 10' will not work\n\n");
	printf("Your Answer: ");
	scanf(" %c%d", &char_input2, &player_guess2);
	
	//Converting to uppercase
	char_input2 = toupper(char_input2);
	player_guess_char2 = (int)char_input2;
	
	scanf("%*[^\n]%*c"); // Clearing out old input
	
	//Scoring
	
	// Player gets all terms right
    if (player_guess_char1 == correct_char1 && 
        player_guess1 == correct_num1 &&
        player_guess_char2 == correct_char2 &&
        player_guess2 == correct_num2) {
        
        printf("Correct! You got both complex terms right!\n\n");
        printf("\t>>> You have successfully moved up %d spaces! <<<\n\n", roll);
    }
    
    // Player gets the wrong answer
	else{
        printf("Incorrect. The next two terms in the sequence are: ");
        
        printf("%c%d and %c%d\n", (char)correct_char1, correct_num1,(char)correct_char2, correct_num2);
        
        *score = playerPunish(*score);	//Punishes the player for inputting wrong answers
    }
    
    printf("\t     >>> Your current score is now: %d <<<\n\n", *score);
    
    return roll;	//return the roll value since we need it if the player rolls a 6
}


//Main Player Turn Loop

/*	This is the main loop that determines how a player's turn is supposed to happen.
	Precondition:	The Number of players is greater than 1 and less than 4. Any of the valid levels (1-3) are decided.
					Level must not be less than 1 or greater than 3. Player score must not be equal to -999. Player turn
					is either postive integer values 1, 2, 3, or 4. 
	@param player_turn determines which player is currently playing (Player 1, 2, 3, or 4)
	@param numberofPlayers is the amount of players currently playing the game
	@param Level is the level of difficulty player's will choose to play in	
	@param scoreP1 is the score of Player 1
	@param scoreP2 is the score of Player 2
	@param scoreP3 is the score of Player 3
	@param scoreP4 is the score of Player 4
	@param score_display displays the current player's current score
	@param current_player is the player currently playing their turn
	@param roll_result is the value given when the dice is rolled
	@param scoreToUpdate is the current player's score before it is updated by adding it to the recently stored score values
*/
int runPlayerTurn(int player_turn, int *numberofPlayers, int Level, int *scoreP1, int *scoreP2, int *scoreP3, int *scoreP4){
	int score_display;
	int current_player = player_turn + 1;		//Assign player_turn values to each player
	int roll_result = 0; 						//We are using this parameter to catch if the player rolls a 6. So we first initialize it as 0.

	int *scoreToUpdate = NULL;
	
	//Switch-case updates and assigns the values of scores for each player
	switch(current_player){
		case 1:
			scoreToUpdate = scoreP1;
			break;
		case 2:
			scoreToUpdate = scoreP2;
			break;
		case 3:
			scoreToUpdate = scoreP3;
			break;
		case 4:
			scoreToUpdate = scoreP4;
			break;
		default:
			printf("!!! ERROR: Invalid player count !!!");
			break;
	}
	
	score_display = *scoreToUpdate;		//Using this so that we can display the score before it is updated
	
	scanf("%*[^\n]%*c"); //Clears any uncessary inputs
	
	// Check if the current player is eliminated
	if(*scoreToUpdate == -999){
		printf("\n\t>>> Player %d is ejected from the game and skips this turn... <<<", current_player);
		return 0; //Returns the player's roll as 0
	}
	
	printf("=======================================================================\n\n");
	printf("\n\t  =======================================================\n");
    printf("\t    >>> It is now Player %d's turn! Current Score: %d <<<\n", current_player, score_display);
    printf("\t  =======================================================\n\n");
    
    //Switch-case decides which difficulty to run based on the value assigned to Level
    switch(Level){
    	case 1:
    		roll_result = runLevelOne(scoreToUpdate);	//Grab the roll value gained from the round
    		break;
    	case 2:
    		roll_result = runLevelTwo(scoreToUpdate);	//Grab the roll value gained from the round
    		break;
    	case 3:
    		roll_result = runLevelThree(scoreToUpdate);	//Grab the roll value gained from the round
    		break;
    	default:
    		break;
	}
	
	eliminatePlayer(scoreToUpdate, current_player, numberofPlayers);	//Runs the function everytime at the end of loop to check if 
																		//the current player's score dropped below zero
	
	return roll_result;		//return the roll result so that we can that we got from the round and return it to the main function
							//so that we can determine if the player gets an extra turn if they rolled a 6
}
