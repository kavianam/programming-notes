#include <stdio.h>
#include "swap.h"

/*
 * gcc 1_swap4.c  ->  Error: 4_swap4.c:(.text+0x51): undefined reference to `swap'
 * gcc 1_swap4.c swap.h  ->  Error: 4_swap4.c:(.text+0x51): undefined reference to `swap'
 * gcc 1_swap4.c swap.c  ->  Correct
 */

int main(void) {
    int a = 21;
    int b = 17;

    printf("Before: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After: a = %d, b = %d\n", a, b);
    return 0;
}