#include <stdio.h>

int main(void) {
    int i = 17;
    int *ip = &i;

    printf("Address of i: %p\n", &i);
    printf("Value of ip: %p\n", ip);
    printf("Dereferencing the ip: %d\n", *ip);  // Dereferencing means accessing the value of a pointer

    return 0;
}
