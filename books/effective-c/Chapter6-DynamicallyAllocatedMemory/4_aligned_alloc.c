#include <stdalign.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * The aligned_alloc function is similar to the malloc function, except that it requires you to provide an alignment as well as a size for the allocated object.
 * The function has the following signature, where size specifies the object’s size and alignment specifies its alignment:
 * void *aligned_alloc(size_t alignment, size_t size);
 *
 * Although C requires the dynamically allocated memory from malloc to be sufficiently aligned for all standard types, including arrays and structures, you might occasionally need to override the compiler’s default choices.
 * You can use the aligned_alloc function to request stricter alignment than the default (in other words, a larger power of two)
 */

typedef struct {
    char c[10];
    int i;
    double d;
} widget;

int main() {
    printf("alignof(widget): %lu\n", alignof(widget));  // 8

    widget *p = aligned_alloc(16, sizeof(widget));
    if (p == NULL) {
        puts("Error allocating memory!");
        return EXIT_FAILURE;
    }
    free(p);
}