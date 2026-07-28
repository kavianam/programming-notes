#include <limits.h>
#include <stdio.h>


void main(void) {
    signed char c;
    int i = 65;
    // int i = INT_MAX;  // 2147483647
    long k;
    k = (c = i);  // i first converted to signed char. Then, the value of the enclosed parentheses is then converted to the long int.

    printf("c: %c\n", c);
    printf("c: %d\n", c);
    printf("k: %ld\n", k);
}