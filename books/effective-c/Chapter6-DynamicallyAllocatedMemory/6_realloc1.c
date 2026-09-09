#include <stdio.h>
#include <stdlib.h>

/*
 * realloc is a function that is used to resize a previously allocated memory block.
 * It can increase or decrease the size of the memory block pointed to by a pointer.
 * If the new size is larger, realloc may allocate a new memory block, copy the existing data to the new block, and free the old block.
 * If the new size is smaller, it simply reduces the size of the existing block.
 *
 * If the newly allocated storage is larger than the old contents, realloc leaves the additional storage uninitialized.
 * If realloc succeeds in allocating the new object, it calls free to deallocate the old object.
 * The pointer to the new object may have the same value as a pointer to the old object.
 * If the allocation fails, the realloc function retains the old object data at the same address and returns a null pointer.
 * A call to realloc can fail, for example, when insufficient memory is available to allocate the requested number of bytes.
 *
 * void* realloc(void* ptr, size_t new_size);
 * ptr: A pointer to the memory block that you want to resize. If ptr is NULL, realloc behaves like malloc and allocates a new block of memory.
 * new_size: The new size for the memory block in bytes.
 * Return Value:
 * On success, it returns a pointer to the newly allocated memory block.
 * On failure, it returns NULL, and the original memory block remains unchanged.
 */

typedef struct {
    char c[10];
    int i;
    double d;
} widget;

// increase the size
int main() {
    // Initial allocation of memory for 5 integers
    int *arr = malloc(5 * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("arr: %p\n", arr);

    // Initialize the array
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1; // arr = {1, 2, 3, 4, 5}
    }

    // Resize the array to hold 10 integers
    int *new_arr = realloc(arr, 10 * sizeof(int));
    if (new_arr == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        free(arr); // Free the original array if realloc fails
        return 1;
    }
    printf("new_arr: %p\n", new_arr);

    arr = new_arr; // Update the pointer to the new memory block

    // Initialize the new elements
    for (int i = 5; i < 10; i++) {
        arr[i] = i + 1; // arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);
    return 0;
}


// decrease the size
int main2() {
    int *arr = malloc(10 * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("arr: %p\n", arr);

    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
    }

    int *new_arr = realloc(arr, 5 * sizeof(int));
    if (new_arr == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        free(arr); // Free the original array if realloc fails
        return 1;
    }
    printf("new_arr: %p\n", new_arr);

    arr = new_arr; // Update the pointer to the new memory block


    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}