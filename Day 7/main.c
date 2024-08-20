#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define NUM_CARDS (SIZE * SIZE)
#define EMPTY ' '

void initializeBoard(char board[SIZE][SIZE], char values[NUM_CARDS]) {
    int i, j;
    char value;
    int pos1, pos2;

    for (i = 0; i < NUM_CARDS; i++) {
        values[i] = 'A' + i / 2;
    }
    for (i = 0; i < NUM_CARDS; i++) {
        int r = rand() % NUM_CARDS;
        char temp = values[i];
        values[i] = values[r];
        values[r] = temp;
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = values[i * SIZE + j];
        }
    }
}

void printBoard(char board[SIZE][SIZE], int reveal[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (reveal[i][j]) {
                printf(" %c ", board[i][j]);
            } else {
                printf(" * ");
            }
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            for (j = 0; j < SIZE; j++) {
                printf("---");
                if (j < SIZE - 1) printf("+");
            }
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    char board[SIZE][SIZE];
    char values[NUM_CARDS];
    int reveal[SIZE][SIZE] = {0};
    int x1, y1, x2, y2;
    int pairsLeft = NUM_CARDS / 2;
    int matchFound;

    srand(time(NULL));

    initializeBoard(board, values);

    while (pairsLeft > 0) {
        printBoard(board, reveal);

        printf("Enter the coordinates (row col) for the first card: ");
        scanf("%d %d", &x1, &y1);
        x1--; y1--;

        reveal[x1][y1] = 1;
        printBoard(board, reveal);

        printf("Enter the coordinates (row col) for the second card: ");
        scanf("%d %d", &x2, &y2);
        x2--; y2--;

        reveal[x2][y2] = 1;
        printBoard(board, reveal);

        if (board[x1][y1] == board[x2][y2]) {
            printf("It's a match!\n");
            pairsLeft--;
            matchFound = 1;
        } else {
            printf("Not a match!\n");
            reveal[x1][y1] = 0;
            reveal[x2][y2] = 0;
            matchFound = 0;
        }

        if (!matchFound) {
            printf("Press Enter to continue...\n");
            getchar();
            getchar();
        }
    }

    printf("Congratulations! You've matched all the pairs.\n");

    return 0;
}
