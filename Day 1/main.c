#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int actual_number, guessed_number;
    int exit = 0;
    int limits[2] = {0, 100};

    srand(time(0));

    while (1)
    {
        actual_number = rand() % (limits[1] + 1 - limits[0]) + limits[0];

        printf("\n\nEnter you guess: ");
        scanf("%d", &guessed_number);

        if (actual_number == guessed_number)
        {
            printf("Correct!");
        }
        else
        {
            printf("Wrong!");
        }

        printf("\n\nEnter 1 to exit or 0 to continue: ");
        scanf("%d", &exit);

        if (exit == 1)
        {
            break;
        }
    }

    return 0;
}