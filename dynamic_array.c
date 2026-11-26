#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

int initArray(DynamicArray *arr, int initialCapacity) {
    if (initialCapacity <= 0) {
        printf("Initial capacity must be positive.\n");
        return 0;
    }

    arr->data = malloc((size_t)initialCapacity * sizeof *arr->data);
    if (arr->data == NULL) {
        printf("Failed to allocate memory.\n");
        arr->size = 0;
        arr->capacity = 0;
        return 0;
    }

    arr->size = 0;
    arr->capacity = initialCapacity;
    return 1;
}

void freeArray(DynamicArray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

int push_back(DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        int newCapacity = arr->capacity * 2;
        int *newData = malloc((size_t)newCapacity * sizeof *newData);
        if (newData == NULL) {
            printf("Failed to allocate memory during resize.\n");
            return 0;
        }

        for (int i = 0; i < arr->size; i++) {
            newData[i] = arr->data[i];
        }

        int oldCapacity = arr->capacity;
        free(arr->data);
        arr->data = newData;
        arr->capacity = newCapacity;

        printf("[Resized capacity from %d to %d]\n", oldCapacity, arr->capacity);
    }

    arr->data[arr->size] = value;
    arr->size++;
    return 1;
}

void display(const DynamicArray *arr) {
    printf("Array (Size: %d, Capacity: %d): ", arr->size, arr->capacity);
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int main(void) {
    DynamicArray myArray;

    if (!initArray(&myArray, 2)) {
        return 1;
    }
    printf("Created dynamic array with capacity 2.\n");

    if (!push_back(&myArray, 10) ||
        !push_back(&myArray, 20)) {
        freeArray(&myArray);
        return 1;
    }
    display(&myArray);

    printf("\nAdding third element...\n");
    if (!push_back(&myArray, 30)) {
        freeArray(&myArray);
        return 1;
    }
    display(&myArray);

    printf("\nAdding fourth and fifth elements...\n");
    if (!push_back(&myArray, 40) ||
        !push_back(&myArray, 50)) {
        freeArray(&myArray);
        return 1;
    }
    display(&myArray);

    freeArray(&myArray);
    return 0;
}
