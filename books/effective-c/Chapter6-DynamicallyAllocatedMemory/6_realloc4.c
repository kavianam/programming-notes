#include <stdio.h>
#include <stdlib.h>

/*
 * Any pointers that reference the memory previously pointed to must be updated to reference the memory newp pointed to after the call to realloc regardless of whether realloc kept the same address for the storage.
 * One solution to this problem is to go through an extra indirection, sometimes called a handle.
 * If all uses of the reallocated pointer are indirect, they’ll all be updated when that pointer is reassigned.
 *
 * By using a pointer to a pointer, any changes made to the pointer in the resizeMemory function are reflected in the original pointer in main.
 * This approach avoids the need to update multiple references to the pointer throughout the code, ensuring that all references point to the correct memory location after reallocation
 */

void allocateMemory(int **arr, size_t size) {
    // Allocate memory for the array
    *arr = (int *)malloc(size * sizeof(int));
    if (*arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize the array
    for (size_t i = 0; i < size; i++) {
        (*arr)[i] = i + 1; // Fill with values 1, 2, ..., size
    }
}

void resizeMemory(int **arr, size_t new_size) {
    // Resize the array using realloc
    int *temp = (int *)realloc(*arr, new_size * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        return; // Original pointer remains unchanged
    }
    *arr = temp; // Update the original pointer to the new memory block
}

void printArray(int *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *array = NULL;
    size_t initial_size = 5;
    size_t later_size = 10;

    // Allocate initial memory
    allocateMemory(&array, initial_size);

    // Print the initial array
    printf("Initial array: ");
    printArray(array, initial_size);

    // Resize the array to hold 10 integers
    resizeMemory(&array, later_size);

    // Initialize the new elements
    for (size_t i = initial_size; i < later_size; i++) {
        array[i] = i + 1; // Fill with values 6, 7, ..., 10
    }

    // Print the resized array
    printf("Resized array: ");
    printArray(array, later_size);

    // Free the allocated memory
    free(array);
    return 0;
}
