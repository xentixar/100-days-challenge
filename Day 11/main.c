#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 7
#define EMPTY ' '
#define PLAYER1 'X'
#define PLAYER2 'O'

void initializeBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        for (int j = 0; j < COLS; j++) {
            printf("|---");
        }
        printf("|\n");
    }
    for (int j = 0; j < COLS; j++) {
        printf("  %d ", j + 1);
    }
    printf("\n");
}

int dropPiece(char board[ROWS][COLS], int col, char piece) {
    if (col < 0 || col >= COLS || board[0][col] != EMPTY) {
        return 0;
    }
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == EMPTY) {
            board[i][col] = piece;
            return 1;
        }
    }
    return 0;
}

int checkWin(char board[ROWS][COLS], char piece) {
    // Check horizontal
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS - 3; c++) {
            if (board[r][c] == piece && board[r][c + 1] == piece && board[r][c + 2] == piece && board[r][c + 3] == piece) {
                return 1;
            }
        }
    }

    // Check vertical
    for (int c = 0; c < COLS; c++) {
        for (int r = 0; r < ROWS - 3; r++) {
            if (board[r][c] == piece && board[r + 1][c] == piece && board[r + 2][c] == piece && board[r + 3][c] == piece) {
                return 1;
            }
        }
    }

    // Check diagonal (bottom-left to top-right)
    for (int r = 3; r < ROWS; r++) {
        for (int c = 0; c < COLS - 3; c++) {
            if (board[r][c] == piece && board[r - 1][c + 1] == piece && board[r - 2][c + 2] == piece && board[r - 3][c + 3] == piece) {
                return 1;
            }
        }
    }

    // Check diagonal (top-left to bottom-right)
    for (int r = 0; r < ROWS - 3; r++) {
        for (int c = 0; c < COLS - 3; c++) {
            if (board[r][c] == piece && board[r + 1][c + 1] == piece && board[r + 2][c + 2] == piece && board[r + 3][c + 3] == piece) {
                return 1;
            }
        }
    }

    return 0;
}

int isBoardFull(char board[ROWS][COLS]) {
    for (int c = 0; c < COLS; c++) {
        if (board[0][c] == EMPTY) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char board[ROWS][COLS];
    int col;
    int currentPlayer = 1;
    char currentPiece;

    initializeBoard(board);

    while (1) {
        printBoard(board);
        currentPiece = (currentPlayer == 1) ? PLAYER1 : PLAYER2;

        printf("Player %d (%c), choose a column (1-%d): ", currentPlayer, currentPiece, COLS);
        scanf("%d", &col);
        col--;

        if (!dropPiece(board, col, currentPiece)) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        if (checkWin(board, currentPiece)) {
            printBoard(board);
            printf("Player %d (%c) wins!\n", currentPlayer, currentPiece);
            break;
        }

        if (isBoardFull(board)) {
            printBoard(board);
            printf("The game is a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}
