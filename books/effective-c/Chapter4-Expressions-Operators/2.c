#include <stdio.h>

int f(void) {
    puts("In f");
    return 0;
}

// When you declare a function parameter with a function type, C automatically adjusts it to a function pointer type. (See Chapter2-Objects-Functions-Types/13_function_type2.c)
void g(int (*func)(void)) {
// void g(int func(void)) {
    func();
    puts("In g");
}

void main(void) {
    g(f);
}