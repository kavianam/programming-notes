#include <stdio.h>

int glob;

int f(void) {
    puts("In f");
    return glob + 10;
}

int g(void) {
    puts("In g");
    glob = 42;
    return glob;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}


int main(void) {
    printf("glob: %d\n", glob);

    printf("max(f(), g()): %d\n", max(f(), g()));

    glob = 0;
    printf("max(g(), f()): %d\n", max(g(), f()));
}