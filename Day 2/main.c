#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, const char *argv[]) {
    char options[3][20] = {"rock", "paper", "scissors"};
    int exit_code = 0;

    time_t t1;
    srand(time(&t1));

    do {
        char input[20];
        char computer[20];

        strcpy(computer, options[rand() % 3]);

        printf("\nEnter any one of the following: \n");
        for (int i = 0; i < 3; i++) {
            printf("%d) %s\n", i + 1, options[i]);
        }
        printf("\nYour option: ");
        scanf("%s", input);

        printf("Computer's option: %s\n", computer);

        printf("\n\x1b[32mResult: ");
        printf("\x1b[0m");

        if (strcmp(input, computer) == 0) {
            printf("\x1b[31m");
            printf("Tie");
        } else if (strcmp(input, "rock") == 0 && strcmp(computer, "paper") == 0) {
            printf("\x1b[31m");
            printf("You lose");
        } else if (strcmp(input, "scissors") == 0 && strcmp(computer, "paper") == 0) {
            printf("\x1b[31m");
            printf("You lose");
        } else if (strcmp(input, "rock") == 0 && strcmp(computer, "scissors") == 0) {
            printf("\x1b[32m");
            printf("You win");
        } else if (strcmp(input, "paper") == 0 && strcmp(computer, "scissors") == 0) {
            printf("\x1b[31m");
            printf("You lose");
        } else if (strcmp(input, "paper") == 0 && strcmp(computer, "rock") == 0) {
            printf("\x1b[32m");
            printf("You win");
        } else if (strcmp(input, "scissors") == 0 && strcmp(computer, "rock") == 0) {
            printf("\x1b[31m");
            printf("You lose");
        } else {
            printf("Nothing happened");
        }

        printf("\x1b[0m");
        printf("\n");

        printf("\nEnter 0 to continue and 1 to exit: ");
        scanf("%d", &exit_code);

    } while (exit_code == 0);

    return 0;
}
