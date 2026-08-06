#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

bool safe_div(int dividend, int divisor, int *quotient) {
    if (!quotient) return false;
    if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
        return false;
    *quotient = dividend / divisor;
    return true;
}

int main() {
    int res;

    int is_successful = safe_div(10, 3, &res);
    // int is_successful = safe_div(10, 3, res);
    if (is_successful)
        printf("%d\n", res);
    else
        printf("The divide wasn't successful: %d\n", is_successful);
}