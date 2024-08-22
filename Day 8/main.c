#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

void playGame() {
    int currentNumber, nextNumber;
    char userGuess;
    int score = 0;
    char playAgain;

    srand(time(NULL));

    currentNumber = rand() % MAX_NUMBER;

    printf("Welcome to the Higher or Lower game!\n");

    do {
        printf("\nCurrent number: %d\n", currentNumber);

        nextNumber = rand() % MAX_NUMBER;

        printf("Will the next number be (h)igher or (l)ower? ");
        scanf(" %c", &userGuess);

        if ((userGuess == 'h' && nextNumber > currentNumber) ||
            (userGuess == 'l' && nextNumber < currentNumber)) {
            printf("Correct! The next number was %d.\n", nextNumber);
            score++;
            } else {
                printf("Incorrect. The next number was %d.\n", nextNumber);
                score--;
            }

        currentNumber = nextNumber;

        printf("Your score is %d.\n", score);
        printf("Do you want to play again? (y/n) ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing! Your final score is %d.\n", score);
}

int main() {
    playGame();
    return 0;
}
