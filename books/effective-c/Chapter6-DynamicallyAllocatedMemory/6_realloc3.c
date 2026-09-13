#include <stdio.h>
#include <stdlib.h>

/*
* Any pointers that reference the memory a previously pointed to must be updated to reference the memory newp pointed to after the call to realloc regardless of whether realloc kept the same address for the storage.
* One solution to this problem is to go through an extra indirection, sometimes called a handle.
* If all uses of the reallocated pointer are indirect, they’ll all be updated when that pointer is reassigned.
 */

int main() {
    int **handler;

    int *a = malloc(sizeof(int) * 2);

    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    handler = &a;

    *a = 5;  // *a = a[0]
    *(a+1) = 7;  // *(a+1) = a[1]
    
    printf("%d, %d\n", *a, *(a+1));
    printf("%d\n", **handler);
    printf("%d\n", *(*handler+1));  // *handler[1]

    int *b = realloc(a, sizeof(int) * 10);
    if (b == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(a);
        return EXIT_FAILURE;
    }

    printf("a: %p - b: %p\n", a, b);

    // The following test is not allowed:
    if (a == b) {
        printf("Equals address\n");
    }

    a = b;  // No need to change the handler

    // *(a+2) = 9;
    a[2] = 9;  // *(a+2) == a[2]
    a[3] = 11;

    printf("%d, %d, %d, %d\n", a[0], a[1], a[2], a[3]);
    printf("%d, %d, %d, %d\n", **handler, *(*handler+1), *(*handler+2), *(*handler+3));

    free(a);
}
