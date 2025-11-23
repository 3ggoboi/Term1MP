	/***************************************************************************
This is to certify that this project is my own work, based on my personal efforts
in studying and applying the concepts learned. I have constructed the functions
and their respective algorithms and corresponding code by myself. The program
was run, tested, and debugged by my own efforts. I further certify that I have
not copied in part or whole or otherwise plagiarized the work of other students
and/or persons.

Matthew Miguel S. Fabiala, DLSU ID# 12504343
***************************************************************************/

/*
	Description:		This is a minigame almost similar to snakes and ladders
						where there can be up to 4 players playing at a time, 
						and the first to reach exactly 50 points wins! Players
						each take turns to roll a dice, and answer a series of 
						arithmetics sequences, where they have to find the next
						term of a given sequence. 
	Programmed by: 		Matthew Miguel S. Fabiala 	S19C
	Last modified:		November 27, 2025
	Version:			Ver. 15
	[Acknowledgements:	Pikuma(YouTube), GeeksForGeeks.org, TutorialsPoint.com, W3Schools.com,]
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.c"
#include "Game Logic.c"

/*
	This is the Main Function Loop that runs the entire game
	Precondition:	None
	@param score keeps track of each player's score
	@param numberofPlayers is the amount of players playing the game
	@param player_active tells the program if the current player is active or eliminated
	@param Level sets the difficulty that the players will play at
	@param player_turn tells the program which player (1, 2, 3, or 4) is currently playing
	@param last_roll is the value of the last dice roll performed, this is used to check 
					 if a player rolled a 6 so that the program can let the player get
					 an extra turn
	@param game_running is game state. 1 means the game is still on-going, 0 means the game has ended
	@param scoreP1 is the score of Player 1
	@param scoreP2 is the score of Player 2
	@param scoreP3 is the score of Player 3
	@param scoreP4 is the score of Player 4
	@return Players would have played a full game against each other after one player wins and gets
			to the 50th tile first. The game will congratulate everyone for playing, and then terminate.
*/

int main()
{
	int score = 0;
	int numberofPlayers = 0;
	int player_active = 0;
	int Level = 0; // Intialize the level
	int player_turn = 0;
	int last_roll = 0;
	int game_running = 1; //Initialize that the game is running (1 means it's running, 0 means it ended)
	
	//Player Scores
	int scoreP1 = 0;	//Player 1 score
	int scoreP2 = 0;	//Player 2 score
	int scoreP3 = 0;	//Player 3 score
	int scoreP4 = 0;	//Player 4 score
	
	srand(time(NULL));		// seeds the random number generator
	
	printf("Welcome to A Walk in the Sequence Park!\n");
	printf("A mini-game coded by Matthew Miguel S. Fabiala\n");
	printf("For the CCPROG1 Machine Project\n\n");
	
	numberofPlayers = numPlayers(numberofPlayers);	//runs the function asking for number of players
	Level = selectLevel(Level);						//runs the function asking for difficulty level
	
	// Running the main game logic
	do{
		
		//Checks if all players are stil active, if not this runs and ends the game.
		if(numberofPlayers <= 0){
			printf("=======================================================================\n\n\n\n\n\n");
			printf("\tAll players have been eliminated from the game...\n\n\n\n\n\n");
			printf("=======================================================================\n\n");
			game_running = 0;	// Game ends
			continue; 
		}	
		
		// Turn will cycle if the last roll is not 6
		if(last_roll != 6){
			player_turn = player_turn % 4;
			player_active = 0;	//initializes the player's "active" status so we  
								//can trigger the upcoming while loop
			
			//Loop to check if player is eliminated or still active
			while(!player_active){
				
				// This checks if the player turn is equal to or greater than the number of players
				// If it's equal to or greater, it will reset the player cycle to Player 1
				if(player_turn >= numberofPlayers){
					player_turn = 0;
				}
				
				//This allows the program to read each player's updated scores
				switch(player_turn + 1){
					case 1: score = scoreP1; break;
					case 2: score = scoreP2; break;
					case 3: score = scoreP3; break;
					case 4: score = scoreP4; break;
					default: score = -999; break;	// Unlikely that this will trigger, 
													//but it's just here to act as a safety net for errors
				}
				
				// Check if player is active AND within the player count
				if(score != -999 && (player_turn + 1) <= numberofPlayers){
					
					player_active = 1;		// Assigns them as an active player
				}
				//If the player is eliminated/not active
				else{
					player_turn = (player_turn + 1) % 4;	//Cycle to the next player	
				}
			}
		}
		//If the last player rolls a six, player gets an extra turn
		//Take note that this is not the actual function that gives the extra turn
		else{
			printf("=======================================================================\n\n\n\n\n\n");
			printf(">>> You have rolled a 6 on the dice last turn! You now get an extra turn!!! <<<\n\n\n\n\n\n");
		}
		
		//Run the player's turn and CAPTURE THE VALUE of the resulting roll so we can check if they rolled a 6
		last_roll = runPlayerTurn(player_turn, &numberofPlayers, Level, &scoreP1, &scoreP2, &scoreP3, &scoreP4);
		
		//This is the switch case that updates the player scores
		//The if statement triggers for an active player since they always roll higher than 0
		//If an eliminated player rolls 0 (which they always will), skip the score update
		if(last_roll > 0){
			switch(player_turn + 1){
				case 1:
					score = scoreP1;
					break;
				case 2: 
					score = scoreP2;
					break;
				case 3:
					score = scoreP3;
					break;
				case 4:
					score = scoreP4;
					break;
			}
			// If a player reaches the 50th tile, they win
			if(score == 50){
				printf("\n\nPlayer %d wins the game by reaching the 50th tile first! Congratulations!!!", player_turn + 1);
				game_running = 0;
			}
		}
		//This is the if statement that lets the player that rolls a 6 get an extra turn
		if (last_roll != 6 && game_running){
			player_turn++;		//If the player did NOT roll a 6, the player turn is incremented
		}	
		
	}while(game_running);	//while-loop will keep running as long as the game state is not set to 0
	
	//If a player wins, it exits the while loop, and the game is finished!
	printf("\n\nThe game has ended. Thank you for playing! I hope you enjoyed it <3\n");
	
	return 0;
}



