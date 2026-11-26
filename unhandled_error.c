#include <stdio.h>

int main(void) {
    FILE *myFile = fopen("missing_file.txt", "r");
    char data[100];

    printf("Attempting to read from missing file...\n");

    if (fscanf(myFile, "%99s", data) == 1) {
        printf("Data read: %s\n", data);
    }

    fclose(myFile);
    return 0;
}
