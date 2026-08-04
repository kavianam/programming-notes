#include <stdint.h>
#include <stdio.h>

void main(void) {
    double x = 1.9;
    int sum = (int)x + 1;

    printf("%d\n", sum);

    puts("--------------------------");

    int a = 5;
    intptr_t i = (intptr_t)&a;

    printf("%p\n", &a);
    printf("%ld\n", i);

    puts("--------------------------");

    double b = 3.2;
    int c = (int)b;

    printf("%d\n", c);
}
