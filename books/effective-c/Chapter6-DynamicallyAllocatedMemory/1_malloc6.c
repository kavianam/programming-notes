#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *p = malloc(10);

    memset(p, 'A', 5);

    // This is OK
    for (int i=0; i<5; i++) {
        printf("%d: %c  ", i+1, p[i]);
    }
    printf("\n");

    // Not OK
    // The first 5 bytes are allocated and initialized, while the last 5 bytes are allocated but uninitialized.
    // Initialized bytes can be read, but uninitialized bytes must not be read
    for (int i = 0; i < 10; i++) {
        printf("%d: %c  ", i + 1, p[i]);
    }

    free(p);
}
