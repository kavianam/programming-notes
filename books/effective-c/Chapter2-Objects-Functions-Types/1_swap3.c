#include <stdio.h>

void swap(int*, int*);

int main(void) {
    int a = 21;
    int b = 17;

    printf("Before: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After: a = %d, b = %d\n", a, b);
    return 0;
}

void swap(int *pa, int *pb) {
    const int tmp = *pa;
    printf("1: a = %d, b = %d, tmp = %d\n", *pa, *pb, tmp);
    *pa = *pb;
    printf("2: a = %d, b = %d, tmp = %d\n", *pa, *pb, tmp);
    *pb = tmp;
    printf("3: a = %d, b = %d, tmp = %d\n", *pa, *pb, tmp);
}