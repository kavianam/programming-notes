#include <stdio.h>

typedef void fv(int);

void aa(int i) {
    printf("aa called with %d\n", i);
}

//void bb(aa a, int i) {  // Wrong
// void bb(void (*a)(int), int i) {  // Correct
// void bb(void (a)(int), int i) {  // Correct
void bb(fv a, int i) {  // Correct. Why? When you declare a function parameter with a function type, C automatically adjusts it to a function pointer type.
// void bb(fv *a, int i) {  // Correct
    printf("Size of parameter a: %zu bytes\n", sizeof(a));  // This shows that a is a pointer (8 bytes), not a function.
    a(i);
}

void cc(fv *a, int i) {
    a(i);
}


int main() {
    bb(aa, 1);
    bb(&aa, 2);

    cc(aa, 3);
    cc(&aa, 4);

    // aa == &aa
    printf("aa: %p\n", aa);
    printf("&aa: %p\n", &aa);
}

/*
 * In C, the name of a function can be used as a pointer to that function.
 * When you pass the function name to another function or directly call it, it automatically translates to & (the address of) the function.
 * Thus, aa and &aa mean the same thing when passed as arguments.
 * 
 * When you declare a function parameter with a function type, C automatically adjusts it to a function pointer type.
 * // Function parameters (special rule applies):
 * void func1(fv a);      // OK - converted to fv*
 * void func2(fv *a);     // OK
 * 
 * // Variable declarations (no special rule):
 * fv a;                  // ERROR - can't declare variable of function type
 * fv *b;                 // OK - function pointer
 */