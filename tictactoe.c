#include <stdio.h>

// Function prototypes
void printBoard(char board[3][3]);
int checkWin(char board[3][3]);
int checkFull(char board[3][3]);

int main() {
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    int player = 1;
    int choice;
    int row, col;
    int gameStatus = 0; // 0: ongoing, 1: win, -1: draw

    while (gameStatus == 0) {
        printBoard(board);
        printf("Player %d, enter your move (1-9): ", player);
        scanf("%d", &choice);

        // Determine the row and column based on the choice
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        // Check if the chosen cell is valid
        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Invalid move, try again.\n");
            continue;
        }

        // Mark the board with the player's symbol
        board[row][col] = (player == 1) ? 'X' : 'O';

        // Check for a win or draw
        if (checkWin(board)) {
            printBoard(board);
            printf("Player %d wins!\n", player);
            gameStatus = 1;
        } else if (checkFull(board)) {
            printBoard(board);
            printf("It's a draw!\n");
            gameStatus = -1;
        } else {
            // Switch players
            player = (player == 1) ? 2 : 1;
        }
    }

    return 0;
}

// Function to print the current state of the board
void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if a player has won
int checkWin(char board[3][3]) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1;
    }

    return 0;
}

// Function to check if the board is full (draw)
int checkFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}
