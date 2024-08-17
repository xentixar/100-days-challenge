#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_TRIES 6
#define WORD_COUNT 5

const char *words[WORD_COUNT] = {"programming", "hangman", "developer", "computer", "science"};

void displayWord(char *word, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c ", word[i]);
    }
    printf("\n");
}

void displayHangman(int tries) {
    printf("\n");
    printf("  +---+\n");
    printf("  |   |\n");
    printf("  %c   |\n", (tries >= 1 ? 'O' : ' '));
    printf(" %c%c%c  |\n", (tries >= 3 ? '/' : ' '), (tries >= 2 ? '|' : ' '), (tries >= 4 ? '\\' : ' '));
    printf(" %c %c |\n", (tries >= 5 ? '/' : ' '), (tries >= 6 ? '\\' : ' '));
    printf("      |\n");
    printf("=========\n");
}

int checkGuess(char *word, char *guessedWord, char guess, int length) {
    int correct = 0;
    for (int i = 0; i < length; i++) {
        if (word[i] == guess && guessedWord[i] == '_') {
            guessedWord[i] = guess;
            correct = 1;
        }
    }
    return correct;
}

int isAlreadyGuessed(char guess, char *guessedLetters, int guessedCount) {
    for (int i = 0; i < guessedCount; i++) {
        if (guessedLetters[i] == guess) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(0));
    char guess;
    int wordIndex = rand() % WORD_COUNT;
    const char *word = words[wordIndex];
    int wordLength = strlen(word);

    char guessedWord[wordLength];
    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '_';
    }

    char guessedLetters[MAX_TRIES * 2];
    int guessedCount = 0;
    int tries = 0;
    int guessed = 0;

    printf("Welcome to Hangman!\n");

    while (tries < MAX_TRIES && !guessed) {
        displayHangman(tries);
        printf("Word to guess: ");
        displayWord(guessedWord, wordLength);

        printf("Tries left: %d\n", MAX_TRIES - tries);

        while (1) {
            printf("Enter your guess: ");
            guess = getchar();

            while (getchar() != '\n');

            if (isalpha(guess)) {
                guess = tolower(guess);
                if (isAlreadyGuessed(guess, guessedLetters, guessedCount)) {
                    printf("You've already guessed '%c'. Try again.\n", guess);
                } else {
                    guessedLetters[guessedCount++] = guess;
                    break;
                }
            } else {
                printf("Please enter a single valid character.\n");
            }
        }
        if (checkGuess((char *)word, guessedWord, guess, wordLength)) {
            printf("Good guess!\n");
        } else {
            printf("Wrong guess!\n");
            tries++;
        }


        if (strcmp(word, guessedWord) == 0) {
            guessed = 1;
            checkGuess((char *)word, guessedWord, guess, wordLength);
            displayHangman(tries);
            printf("Word to guess: ");
            displayWord(guessedWord, wordLength);
            break;
        }
    }

    if (guessed) {
        printf("\nCongratulations! You guessed the word: %s\n", word);
    } else {
        displayHangman(tries);
        printf("\nSorry, you lost. The word was: %s\n", word);
    }

    return 0;
}
