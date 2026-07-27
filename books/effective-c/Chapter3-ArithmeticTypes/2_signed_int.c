#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Max values
    printf("SCHAR_MIN: %d\n", SCHAR_MIN);
    printf("SCHAR_MAX: %d\n", SCHAR_MAX);
    printf("SHRT_MIN: %d\n", SHRT_MIN);
    printf("SHRT_MAX: %d\n", SHRT_MAX);
    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MAX: %d\n", INT_MAX);
    printf("LONG_MIN: %ld\n", LONG_MIN);
    printf("LONG_MAX: %ld\n", LONG_MAX);
    printf("LLONG_MIN: %lld\n", LLONG_MIN);
    printf("LLONG_MAX: %lld\n", LLONG_MAX);

    printf("--------------------------\n");

    // Compute absolute value
    // Wrong
    #define Abs(i) ((i) < 0 ? -(i) : (i))

    printf("Abs(-25): %d\n", Abs(-25));
    printf("Abs(INT_MIN): %d\n", Abs(INT_MIN));

    // Correct
    #define Abs2(i, flag) ((i) < 0 ? i == flag ? flag : -(i) : (i))

    printf("Abs2(-25, INT_MIN): %d\n", Abs2(-25, INT_MIN));
    printf("Abs2(INT_MIN, INT_MIN): %d\n", Abs2(INT_MIN, INT_MIN));

    // Correct also
    #define Abs3(i) ((i) >= 0 ? i : -(unsigned)i)

    printf("Abs3(-25): %d\n", Abs3(-25));
    printf("Abs3(INT_MIN): %d\n", Abs3(INT_MIN));

    // abs in stdlib
    printf("abs(-25): %d\n", abs(-25));
    printf("abs(INT_MIN): %d\n", abs(INT_MIN));
}