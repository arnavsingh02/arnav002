//Created By Arnav Singh
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int rollDice();
int checkSnakeLadder(int position);
void updateBoard(int player1_position, int player2_position, int board[100]);
void clearScreen();

int main() {
    int board[100] = {0};
    int player1_position = 1;
    int player2_position = 1;
    int turn = 1;

    srand(time(0));
    printf("Press enter to start the game.\n");
    getchar();
    printf("        ** SNAKE AND LADDER GAME **\n");
    printf("Snakes:  17 to 7, 64 to 48, 99 to 78.\nLadders: 4 to 14, 20 to 38, 40 to 59, 71 to 91.\n");

    printf("Select game mode:\n1. 2 players (2 v 2)\n2. Exit\n");
    int mode;
    scanf("%d", &mode);
    if (mode != 1) {
        printf("Thanks for entering the game.\n");
        exit(0);
    }
    clearScreen(); 
    getchar(); 

    while (player1_position < 100 && player2_position < 100) {
        if (turn % 2 == 1) {
            printf("Player 1, it's your turn. Press enter to roll the dice.\n");
            getchar();
            int dice_roll = rollDice();
            printf("You rolled a %d.\n", dice_roll);
            player1_position += dice_roll;
            player1_position = checkSnakeLadder(player1_position);
            if (player1_position > 100) {
                player1_position -= dice_roll;
            }
            printf("Your new position is %d.\n", player1_position);
        } else {
            printf("Player 2, it's your turn. Press enter to roll the dice.\n");
            getchar();
            int dice_roll = rollDice();
            printf("You rolled a %d.\n", dice_roll);
            player2_position += dice_roll;
            player2_position = checkSnakeLadder(player2_position);
            if (player2_position > 100) {
                player2_position -= dice_roll;
            }
            printf("Your new position is %d.\n", player2_position);
        }

        if (turn % 2 != 0) {
            clearScreen(); 
        }
        
        updateBoard(player1_position, player2_position, board);
        turn++;
    }

    if (player1_position >= 100) {
        printf("Congratulations Player 1, you won!\n");
    } else {
        printf("Congratulations Player 2, you won!\n");
    }

    return 0;
}


int rollDice() {
    return (rand() % 6) + 1;
}


int checkSnakeLadder(int position) {
    int new_position = position;
    switch (position) {
        case 4:
            new_position = 14;
            printf("You climbed a ladder from 4 to 14.\n");
            break;
        case 17:
            new_position = 7;
            printf("You were bitten by a snake from 17 to 7.\n");
            break;
        case 20:
            new_position = 38;
            printf("You climbed a ladder from 20 to 38.\n");
            break;
        case 40:
            new_position = 59;
            printf("You climbed a ladder from 40 to 59.\n");
            break;
        case 64:
            new_position = 48;
            printf("You were bitten by a snake from 64 to 48.\n");
            break;
        case 71:
            new_position = 91;
            printf("You climbed a ladder from 71 to 91.\n");
            break;
        case 99:
            new_position = 78;
            printf("You were bitten by a snake from 99 to 78.\n");
            break;
    }
    return new_position;
}


void updateBoard(int player1_position, int player2_position, int board[100]) {
    int i, j, position;

    
    for (i = 0; i < 100; i++) {
        board[i] = 0;
    }
    
    board[player1_position - 1] = 1;
    board[player2_position - 1] = 2;

    printf("Current board:\n\n");

    
    for (i = 9; i >= 0; i--) {
        if (i % 2 == 0) { 
            for (j = 0; j < 10; j++) {
                position = i * 10 + j;
                if (board[position] == 1) {
                    printf(" P1 \t");
                } else if (board[position] == 2) {
                    printf(" P2 \t");
                } else {
                    printf("%3d \t", position + 1);
                }
            }
        } else { 
            for (j = 9; j >= 0; j--) {
                position = i * 10 + j;
                if (board[position] == 1) {
                    printf(" P1 \t");
                } else if (board[position] == 2) {
                    printf(" P2 \t");
                } else {
                    printf("%3d \t", position + 1);
                }
            }
        }
        printf("\n\n");
    }
}


void clearScreen() {
    
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
