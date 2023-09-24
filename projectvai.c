#include <stdio.h>
#include <conio.h>

#define MAX_ROWS 10
#define MAX_COLS 10
int i, j;
char board[MAX_ROWS][MAX_COLS] = {
    "##########",
    "#  .     #",
    "#  *     #",
    "#@       #",
    "##########"
};

int playerRow, playerCol;

void printBoard() {
    system("cls");
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int isCompleted() {
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (board[i][j] == '.' || board[i][j] == '*') {
                return 0; // Sokoban is not completed
            }
        }
    }
    return 1; // Sokoban is completed
}

int main() {
    int ch;

    // Find player's initial position
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (board[i][j] == '@') {
                playerRow = i;
                playerCol = j;
                break;
            }
        }
    }

    printBoard();

    while (1) {
        ch = getch();
        switch (ch) {
            case 'w':
                if (board[playerRow - 1][playerCol] == ' ') {
                    board[playerRow][playerCol] = ' ';
                    playerRow--;
                    board[playerRow][playerCol] = '@';
                } else if (board[playerRow - 1][playerCol] == '.') {
                    board[playerRow][playerCol] = ' ';
                    playerRow--;
                    board[playerRow][playerCol] = '@';
                } else if (board[playerRow - 1][playerCol] == '*') {
                    if (board[playerRow - 2][playerCol] == ' ' || board[playerRow - 2][playerCol] == '.') {
                        board[playerRow][playerCol] = ' ';
                        playerRow--;
                        board[playerRow][playerCol] = '@';
                        board[playerRow - 1][playerCol] = '*';
                    }
                }
                break;

            case 's':
                // Implement down movement
                break;

            case 'a':
                // Implement left movement
                break;

            case 'd':
                // Implement right movement
                break;

            case 'q':
                return 0;
        }

        printBoard();

        if (isCompleted()) {
            printf("Congratulations! You won!\n");
            break;
        }
    }

    return 0;
}
