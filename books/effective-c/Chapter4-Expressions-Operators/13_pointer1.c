#include <stdio.h>
/*
 * Chapter 4 - P. 79
 * Adding or subtracting an expression that has integer type to or from a pointer returns a value with the type of the pointer operand.
 * If the pointer operand points to an element of an array, then the result points to an element offset from the original element.
 * If the resulting pointer is outside the bounds of the array, undefined behavior occurs.
 */

int main() {
    int arr[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};

    int *arrp1 = &arr[4];
    int *arrp2 = arrp1 + 2;  // 60 - arrp2 points to arr[6]

    printf("arrp1: %d\n", *arrp1);  // 40
    printf("*(arr + 2): %d\n", *(arr + 2));  // 20 - arr[0 + 2] = 20
    printf("arrp2: %d\n", *arrp2);  // 60 - arr[4 + 2] = arr[6]
    printf("arr: %p - &arr[4]: %p - arrp1: %p - arrp2: %p\n", arr, &arr[4], arrp1, arrp2);
    printf("%td\n", arrp2-arrp1);  // 2

    puts("--------------------------");

    int array[100];
    int *arr_p1 = &array[40];
    int *arr_p2 = arr_p1 + 20; // arr_p2 points to array[60]

    printf("%p\n", arr_p1);  // 0x7fffffffd4f0
    printf("%p\n", arr_p2);  // 0x7fffffffd540
    printf("%td\n", arr_p2 - arr_p1);  // 20 - ((0x7fffffffd540 - 0x7fffffffd4f0) / 4 = 20)
}
