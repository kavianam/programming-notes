#include <limits.h>
#include <stdio.h>

// Wrong!!
int absolute_value1(int a) {
    if (a < 0)
        return -a;
    return a;
}

// Correct!!
int absolute_value2(int a) {
    if (a == INT_MIN)
        return a;
    return a < 0 ? -a : a;
}

int main() {
    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MAX: %d\n", INT_MAX);

    printf("%d\n", absolute_value1(-5));
    printf("%d\n", absolute_value1(INT_MIN));
    printf("%d\n", absolute_value2(INT_MIN));
}