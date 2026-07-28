#include <limits.h>
#include <stdio.h>

int main(void) {
    int si = 5;
    short ss = 8;
    long sl = (long)si;
    unsigned short us = (unsigned short)(ss + sl);

    printf("sl: %ld\n", sl);
    printf("(int)sl: %d\n", (int)sl);
    printf("us: %d\n", us);

    printf("--------------------------\n");

    unsigned int ui = UINT_MAX;
    signed char c = -1;
    if (c == ui) {
        puts("-1 equals 4,294,967,295 (UINT_MAX)");  // c (signed char) converted to int
        printf("(unsigned int)c: %d\n", (unsigned int)c);
    }
}