#include <stdio.h>

void swap(int, int);

int main(void) {
    int a = 21;
    int b = 17;

    printf("Before: a = %d, b = %d\n", a, b);
    swap(a, b);
    printf("After: a = %d, b = %d\n", a, b);
    return 0;
}

void swap(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}