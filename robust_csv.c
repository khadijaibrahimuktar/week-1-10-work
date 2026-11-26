#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *file = fopen("students.csv", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not find students.csv!\n");
        return 1;
    }

    char line[100];
    int lineNumber = 0;
    printf("--- Processing Student Records ---\n");

    while (fgets(line, sizeof line, file) != NULL) {
        lineNumber++;
        char name[20];
        char scoreStr1[10];
        char scoreStr2[10];
        char scoreStr3[10];
        char extra;
        int s1, s2, s3;

        if (strchr(line, '\n') == NULL && !feof(file)) {
            int ch;
            while ((ch = fgetc(file)) != '\n' && ch != EOF) {
            }
            printf("WARNING: Skipping malformed line format on line %d.\n", lineNumber);
            continue;
        }

        int itemsRead = sscanf(line, "%19[^,],%9[^,],%9[^,],%9[^,\n] %c",
                               name, scoreStr1, scoreStr2, scoreStr3, &extra);
        if (itemsRead != 4) {
            printf("WARNING: Skipping malformed line format on line %d.\n", lineNumber);
            continue;
        }

        char trailing;
        if (sscanf(scoreStr1, "%d %c", &s1, &trailing) != 1 ||
            sscanf(scoreStr2, "%d %c", &s2, &trailing) != 1 ||
            sscanf(scoreStr3, "%d %c", &s3, &trailing) != 1) {
            printf("WARNING: Skipping malformed record for %s (Invalid score data).\n", name);
            continue;
        }

        double average = (s1 + s2 + s3) / 3.0;
        printf("%s -> Average: %.2f\n", name, average);
    }

    if (ferror(file)) {
        fprintf(stderr, "Error: Failed while reading students.csv.\n");
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0) {
        fprintf(stderr, "Error: Could not close students.csv.\n");
        return 1;
    }

    printf("\n--- Processing Complete ---\n");
    return 0;
}
