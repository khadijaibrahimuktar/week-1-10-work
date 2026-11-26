#include <stdio.h>
#include <string.h>

int main(void) {
    char name[50];

    printf("Enter your name: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        printf("Could not read the name.\n");
        return 1;
    }

    name[strcspn(name, "\n")] = '\0';

    printf("Name: %s\n", name);
    printf("Length: %zu\n", strlen(name));

    if (name[0] != '\0') {
        printf("First character: %c\n", name[0]);
    } else {
        printf("First character: (none)\n");
    }

    char copy[sizeof(name)];
    strcpy(copy, name);
    printf("Copy: %s\n", copy);

    return 0;
}
