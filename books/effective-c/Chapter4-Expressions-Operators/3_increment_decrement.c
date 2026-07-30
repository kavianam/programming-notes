#include <stdio.h>

int main(void) {
    int i = 5;
    int e;

    e = i++;  // postfix increment: i has the value 6; e has the value 5
    printf("%d\n", e);
    printf("%d\n", i);

    e = i--;  // postfix decrement: i has the value 5; e has the value 6
    printf("%d\n", e);
    printf("%d\n", i);

    e = ++i;  // prefix increment: i has the value 6; e has the value 6
    printf("%d\n", e);
    printf("%d\n", i);

    e = --i;  // prefix decrement: i has the value 5; e has the value 5
    printf("%d\n", e);
    printf("%d\n", i);
}
