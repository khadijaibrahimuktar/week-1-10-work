#include <errno.h>
#include <stdio.h>
#include <string.h>

int readFileWithReturnCode(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return 1;
    }

    if (fclose(file) != 0) {
        fprintf(stderr, "Error closing file: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}

int main(void) {
    printf("--- Testing Return Code Strategy ---\n");

    if (readFileWithReturnCode("data.txt") == 1) {
        printf("Main function: Handled error gracefully. Program continues.\n");
    }

    printf("\n--- Evaluation ---\n");
    printf("In C, we must manually check return codes.\n");
    printf("If the programmer forgets to check, the program might continue with bad data.\n");

    return 0;
}
