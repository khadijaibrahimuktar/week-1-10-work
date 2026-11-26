#include <stdio.h>

int main(void) {
    FILE *inputFile = fopen("numbers.txt", "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error: Could not open numbers.txt for reading!\n");
        return 1;
    }

    int num;
    int sum = 0;
    int readResult;

    printf("Reading numbers from file...\n");
    while ((readResult = fscanf(inputFile, "%d", &num)) == 1) {
        printf("Read: %d\n", num);
        sum += num;
    }

    if (readResult != EOF) {
        fprintf(stderr, "Error: numbers.txt contains invalid data.\n");
        fclose(inputFile);
        return 1;
    }

    if (fclose(inputFile) != 0) {
        fprintf(stderr, "Error: Could not close numbers.txt.\n");
        return 1;
    }

    printf("Total Sum: %d\n", sum);

    FILE *outputFile = fopen("sum.txt", "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Error: Could not create sum.txt for writing!\n");
        return 1;
    }

    int writeResult = fprintf(outputFile,
                              "The total sum is: %d\n"
                              "Calculated automatically by the C program.\n",
                              sum);
    if (writeResult < 0 || fclose(outputFile) != 0) {
        fprintf(stderr, "Error: Could not write or close sum.txt.\n");
        return 1;
    }

    printf("Result successfully saved to sum.txt!\n");
    return 0;
}
