#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Car {
    char model[20];
};

void initCar(struct Car *c, const char *modelName) {
    snprintf(c->model, sizeof c->model, "%s", modelName);
    printf("Car created: %s\n", c->model);
}

void destroyCar(const struct Car *c) {
    printf("Car destroyed: %s\n", c->model);
}

int main(void) {
    printf("--- Creating Stack Object ---\n");
    struct Car stackCar;
    initCar(&stackCar, "Toyota");

    printf("\n--- Creating Heap Object ---\n");
    struct Car *heapCar = malloc(sizeof *heapCar);
    if (heapCar == NULL) {
        fprintf(stderr, "Failed to allocate memory for heap car.\n");
        destroyCar(&stackCar);
        return 1;
    }

    initCar(heapCar, "Honda");
    printf("Heap car model: %s\n", heapCar->model);

    printf("\n--- End of main function ---\n");
    destroyCar(heapCar);
    free(heapCar);
    heapCar = NULL;

    return 0;
}
