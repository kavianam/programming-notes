#include <stdio.h>

void aa(int);

int main(void) {
    typedef void fv(int), (*pfv)(int);
    /*
    This single line declares two typedefs:
    1. typedef void fv(int):
        Creates a type alias fv for a function type.
        fv is a function that takes an int and returns void.
    2. typedef void (*pfv)(int):
        Creates a type alias pfv for a function pointer type.
        pfv is a pointer to a function that takes an int and returns void.
    */

    // fv a = aa;  // Not works. Functions are not objects you can store in variables. We can only have function pointers.
    fv *a1 = &aa;  // Works
    fv *a2 = aa;  // Also works. (function name decays to pointer)
    a1(3);

    // aa == &aa
    printf("a: %p\n", aa);
    printf("&aa: %p\n", &aa);

    pfv b = &aa;
    b(32);
}


void aa(int i) {
    printf("i: %d\n", i);
}