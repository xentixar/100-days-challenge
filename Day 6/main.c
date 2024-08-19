#include <stdio.h>

#define LEVELS 3

void print_pyramid(int pyramid[LEVELS][LEVELS]) {
    for (int i = 0; i < LEVELS; ++i) {
        for (int j = 0; j < LEVELS - i - 1; ++j) {
            printf("   ");
        }
        for (int j = 0; j <= i; ++j) {
            printf("%4d", pyramid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int pyramid[LEVELS][LEVELS] = {
        {0},
        {0, 0},
        {0, 0, 0}
    };

    int hints[LEVELS] = {15, 23, 10};

    printf("Welcome to the Number Pyramid Game!\n");
    printf("Try to guess the numbers in the pyramid based on the following hints:\n");

    for (int i = 0; i < LEVELS; ++i) {
        printf("Hint for level %d: The sum of the numbers in this level is %d\n", i + 1, hints[i]);
    }

    printf("\nPlease enter your guesses for the pyramid:\n");

    for (int i = 0; i < LEVELS; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("Enter number for pyramid[%d][%d]: ", i, j);
            scanf("%d", &pyramid[i][j]);
        }
    }

    printf("\nYour entered pyramid:\n");
    print_pyramid(pyramid);

    for (int i = 0; i < LEVELS; ++i) {
        int sum = 0;
        for (int j = 0; j <= i; ++j) {
            sum += pyramid[i][j];
        }
        if (sum == hints[i]) {
            printf("Level %d is correct!\n", i + 1);
        } else {
            printf("Level %d is incorrect. The correct sum should be %d.\n", i + 1, hints[i]);
        }
    }

    return 0;
}
