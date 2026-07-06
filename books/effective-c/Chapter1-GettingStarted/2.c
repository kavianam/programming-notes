#include <stdio.h>
#include <stdlib.h>

int main(void) {
    if (puts("Hello, world") == EOF) {
        return EXIT_FAILURE;
    }
    int a = puts("Hello, world");
    int b = printf("%d\n", a);
    printf("%d\n", b);
    return EXIT_SUCCESS;
}