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
    const int tmp = a;
    printf("1: a = %d, b = %d, tmp = %d\n", a, b, tmp);
    a = b;
    printf("2: a = %d, b = %d, tmp = %d\n", a, b, tmp);
    b = tmp;
    printf("3: a = %d, b = %d, tmp = %d\n", a, b, tmp);
}