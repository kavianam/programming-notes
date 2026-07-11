#include <limits.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>

int main(void) {
    printf("Int max: %d\n", INT_MAX);
    printf("Unsigned long max: %lu\n", ULONG_MAX);
    printf("%d\n", __WORDSIZE);

    return 0;
}
