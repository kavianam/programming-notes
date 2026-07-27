#include <limits.h>
#include <stdio.h>

int main(void) {
    // Max values
    printf("UCHAR_MAX: %u\n", UCHAR_MAX);
    printf("USHRT_MAX: %u\n", USHRT_MAX);
    printf("UINT_MAX: %u\n", UINT_MAX);
    printf("ULONG_MAX: %llu\n", ULONG_MAX);
    printf("ULLONG_MAX: %llu\n", ULLONG_MAX);

    printf("--------------------------\n");

    unsigned int ui = UINT_MAX;
    printf("ui: %u\n", ui);
    ui++;
    printf("ui: %u\n", ui);
    ui--;
    printf("ui: %u\n", ui);

    printf("--------------------------\n");

    unsigned int a = UINT_MAX;
    unsigned int b = 1;

    printf("a + b: %u\n", a + b);

    // Wrong!
    if (a + b > UINT_MAX)
        printf("Too big!\n");
    else
        printf("Not big!\n");

    // Correct
    if (a > UINT_MAX - b)
        printf("Too big!\n");
    else
        printf("Not big!\n");

    printf("--------------------------\n");

    unsigned int i = 0;
    unsigned int j = 1;

    printf("i - j: %u\n", i - j);

    // Wrong
    if (i - j < 0)
        printf("Negative\n");
    else
        printf("Positive\n");

    // Correct
    if (i < j)
        printf("Negative\n");
    else
        printf("Positive\n");

}