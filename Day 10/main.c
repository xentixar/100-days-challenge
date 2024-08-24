#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 100
#define NUM_COLORS 4

const char *colors[NUM_COLORS] = {"Red", "Green", "Blue", "Yellow"};

void generateSequence(char sequence[], int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = rand() % NUM_COLORS;
    }
}

void printSequence(const char sequence[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%s ", colors[sequence[i]]);
    }
    printf("\n");
}

int checkSequence(const char userSequence[], const char correctSequence[], int length) {
    for (int i = 0; i < length; i++) {
        if (userSequence[i] != correctSequence[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));

    char sequence[MAX_SEQUENCE_LENGTH];
    char userSequence[MAX_SEQUENCE_LENGTH];
    int length = 1;
    int correct;

    printf("Welcome to Simon Says with Colors!\n");

    while (1) {
        generateSequence(sequence, length);

        printf("Remember this sequence:\n");
        printSequence(sequence, length);

        printf("Press Enter to continue...\n");
        getchar();
        system("clear");

        printf("Enter the sequence: \n");
        for (int i = 0; i < length; i++) {
            printf("%d ", i + 1);
            char color[10];
            fgets(color, sizeof(color), stdin);
            color[strcspn(color, "\n")] = 0;

            int colorIndex = -1;
            for (int j = 0; j < NUM_COLORS; j++) {
                if (strcmp(color, colors[j]) == 0) {
                    colorIndex = j;
                    break;
                }
            }

            if (colorIndex == -1) {
                printf("Invalid color! Try again.\n");
                i--;
            } else {
                userSequence[i] = colorIndex;
            }
        }

        correct = checkSequence(userSequence, sequence, length);
        if (correct) {
            printf("Correct! Moving to the next round.\n");
            length++;
        } else {
            printf("Incorrect sequence. Game Over.\n");
            break;
        }
    }

    return 0;
}
