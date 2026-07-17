#include <stdio.h>
/*
 * Chapter 4 - P. 79
 * Adding or subtracting an expression that has integer type to or from a pointer returns a value with the type of the pointer operand.
 * If the pointer operand points to an element of an array, then the result points to an element offset from the original element.
 * If the resulting pointer is outside the bounds of the array, undefined behavior occurs.
 */

int main() {
    int arr[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};

    int *arrp1 = arr[4];
    int *arrp2 = arrp1 + 2;  // arrp2 points to arr[6]

    printf("%d\n", arrp1);
    printf("%td\n", arrp2-arrp1);
}