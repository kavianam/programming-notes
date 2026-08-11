#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 0;

before:
    printf("%d\n", a);
    if (a < 10) {
        goto loop;
    } else {
        exit(0);
    }
loop:
    a += 1;
    goto before;
}
