#include <stdio.h>
#include <stdlib.h>

void fixLeak(void) {
    int *ptr = malloc(sizeof *ptr);
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    *ptr = 42;
    printf("Inside fixed function. Value: %d\n", *ptr);
    printf("Memory allocated at address: %p\n", (void *)ptr);

    free(ptr);
    ptr = NULL;

    printf("Memory has been successfully freed.\n");
}

int main(void) {
    printf("--- Testing the Fix ---\n");
    fixLeak();
    return 0;
}
