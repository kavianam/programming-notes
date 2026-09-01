#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * The calloc function is used to allocate memory for an array of elements and initialize all bytes in the allocated memory to zero.
 * The signature:
 * 
 * void* calloc(size_t num, size_t size);
 * num: The number of elements to allocate.
 * size: The size of each element in bytes.
 *
 * Key Features:
 * 1. Unlike malloc, which allocates memory without initializing it, calloc initializes all allocated memory to zero. This can help prevent issues related to uninitialized memory.
 * 2. Array Allocation: calloc is particularly useful for allocating memory for arrays, as it takes both the number of elements and the size of each element as parameters.
 */

typedef struct {
    char c[10];
    int i;
    double d;
} widget;

int main() {
    printf("sizeof(widget): %ld\n", sizeof(widget));  // 10 (array) + 2 (alignment) + 4 (int) + 8 (double) = 24

    widget *arr = calloc(5, sizeof(widget));
    if (arr == NULL) {
        return EXIT_FAILURE;
    }
    printf("%ld\n", sizeof(arr));  // 8
    printf("%ld\n", sizeof(*arr));  // 24

    for (size_t i = 0; i < 5; i++) {
        printf("element: %zu - c: %s - i: %d - d: %f\n", i, arr[i].c, arr[i].i, arr[i].d); // All values will be 0
    }

    free(arr);
}