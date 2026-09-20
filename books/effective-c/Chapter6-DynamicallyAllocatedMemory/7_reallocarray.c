#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Both signed integer overflow and unsigned integer wraparound are serious problems that can result in buffer overflows and other security vulnerabilities.
 * In the following code snippet, for example, the expression num * size might wrap around before being passed as the size argument in the call to realloc:
 * newp = realloc(p, num * size)
 *
 * The reallocarray function can reallocate storage for an array, but like calloc, it checks for wraparound during array size calculations, which saves you from having to perform these checks.
 * The reallocarray function has the following signature:
 * void *reallocarray(void *ptr, size_t nmemb, size_t size);
 *
 * ptr: A pointer to the previously allocated memory block. If ptr is NULL, reallocarray behaves like malloc and allocates a new block of memory.
 * nmemb: The number of elements to allocate.
 * size: The size of each element in bytes.
 * Return Value:
 * On success, it returns a pointer to the newly allocated memory block.
 * On failure, it returns NULL, and the original memory block remains unchanged.
 *
 * The reallocarray function allocates storage for nmemb members of size and checks for wraparound in the nmemb * size calculation.
 * The reallocarray function does not zero out the allocated storage.
 * The reallocarray function is useful when two values are multiplied to determine the size of the allocation:
 * newp = reallocarray(p, num, size)
 * This call to the reallocarray function will fail and return a null pointer if num * size would wrap around.
 */

int main() {
    printf("sizeof(int): %lu\n", sizeof(int));  // 4
    printf("ULONG_MAX: %lu\n", ULONG_MAX);  // 18446744073709551615

    size_t initial_size = 5;
    size_t new_size = 20;
    // size_t new_size = SIZE_MAX;

    // Allocate memory
    int *arr = reallocarray(NULL, initial_size, sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Initialize the array
    for (size_t i = 0; i < initial_size; i++) {
        arr[i] = i + 1; // Fill with values 1, 2, ..., size
    }

    // Print the initial array
    printf("Initial array: ");
    for (size_t i = 0; i < initial_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int *tmp = realloc(arr, new_size * sizeof(int));  // May integer overflow
    // int *tmp = reallocarray(arr, new_size, sizeof(int));
    if (tmp == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        free(arr); // Free the original array if realloc fails
        return EXIT_FAILURE;
    }
    arr = tmp; // Update the original pointer to the new memory block

    // Initialize the new elements
    for (size_t i = initial_size; i < new_size; i++) {
        arr[i] = i + 1; // Fill with values 6, 7, ..., 10
    }

    // Print the resized array
    printf("Resized array: ");
    for (size_t i = 0; i < new_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}
