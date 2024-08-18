#include <stdio.h>

void printBoard(char board[3][3]);
int checkWin(char board[3][3]);
int checkDraw(char board[3][3]);
int isValidMove(char board[3][3], int row, int col);
void makeMove(char board[3][3], int row, int col, char player);

int main() {
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int row, col;
    int moveCount = 0;
    char currentPlayer = 'X';

    while (1) {
        printBoard(board);

        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        row--;
        col--;

        if (!isValidMove(board, row, col)) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        makeMove(board, row, col, currentPlayer);
        moveCount++;

        if (checkWin(board)) {
            printBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (checkDraw(board)) {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int checkWin(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] ||
            board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] ||
        board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}

int isValidMove(char board[3][3], int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && (board[row][col] != 'X' && board[row][col] != 'O');
}

void makeMove(char board[3][3], int row, int col, char player) {
    board[row][col] = player;
}
