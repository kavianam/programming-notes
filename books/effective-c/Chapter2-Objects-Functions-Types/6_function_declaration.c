#include <stdio.h>

int *f(void);  // void means no parameter
int *fip();  // empty parameter means accepting any number of arguments of any type. Always use void when meaning no parameter. In C++, empty parameter means no parameter.
void g(int i, int j);
void h(int, int);

int main(void) {
    int a = 1;
    int b = 0;
    // int *c = f(a, &b);
    int *c = fip(a, &b);
    printf("%d\n", *c);
    return 0;
}

// int *f(int a, int* b) {
int *fip(int a, int* b) {
    *b = a + 2;
    return b;
}
