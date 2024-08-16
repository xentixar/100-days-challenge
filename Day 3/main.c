#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

int main(int argc, const char * argv[]) {
    int dice_count = 1;
    int exit_code = 0;
    time_t t1;
    srand(time(&t1));

    do{
        printf("Enter the number of dice: ");
        scanf("%d", &dice_count);
        if (dice_count > 0) {
            int dice[dice_count];
            printf("\n\x1b[32mRolling %d dice:\n", dice_count);
            printf("\x1b[0m");
            for (int i = 0; i < dice_count; i++) {
                dice[i] = rand() % 6 + 1;
                printf("Dice %d = %d\n", i+1, dice[i]);
            }
            printf("\nDo you want to play again?(1 = yes / 0 = no): ");
            scanf("%d", &exit_code);
        }
    }while(exit_code == 1);

    return 0;
}