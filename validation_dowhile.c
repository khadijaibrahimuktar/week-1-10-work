#include <stdio.h>

int main(void) {
    int number = 0;

    do {
        printf("Enter a positive number: ");
        scanf("%d", &number);

        if (number <= 0) {
            printf("Invalid! ");
        }
    } while (number <= 0);

    printf("You entered: %d\n", number);

    return 0;
}
