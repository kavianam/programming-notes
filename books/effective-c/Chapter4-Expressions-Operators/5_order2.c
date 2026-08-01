#include <stdio.h>

int main(void) {
    int i = 1;
    int j = 2;
    int k = 3;

    printf("i + j * k: %d\n", i + j * k);
    printf("++i + ++j * --k: %d\n", ++i + ++j * --k);

    printf("--------------------------\n");

    int a = 5;
    printf("a++ * a++: %d\n", a++ * a++);

    printf("--------------------------\n");

    int b = 5;
    int c = b++;

    printf("c: %d\n", c);
    printf("c * b++: %d\n", c * b++);
}
