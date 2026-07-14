#include <stdio.h>

int main(void) {
    /*
     * An array is implemented as a contiguous block of memory that holds elements of the same data type
     * The array name itself acts as a pointer to the first element of the array.
     * Thus, numbers array is equivalent to &numbers[0].
     */
    int ia[11];
    float *afp[17];

    int numbers[5] = {1, 3, 5, 7, 9};

    printf("numbers: %p\n", numbers);
    printf("&numbers: %p\n", &numbers);
    printf("&numbers[0]: %p\n", &numbers[0]);
    printf("numbers[1]: %d\n", numbers[1]);

    puts("--------------------------");

    printf("*numbers: %d\n", *numbers);
    printf("numbers+1: %p\n", numbers+1);
    printf("*(numbers+1): %d\n", *(numbers+1));  // Accesses the second element  -  *(numbers+i) == numbers[i]
    printf("*numbers+1: %d\n", *numbers+1);  // Wrong - add 1 to the first element

    puts("--------------------------");

    char c[] = {'a', 'z', 'b', 'y'};

    printf("c: %p\n", c);
    printf("&(c[0]): %p\n", &(c[0]));
    printf("&c: %p\n", &c);
    printf("c[0]: %c\n", c[0]);
    printf("*(c+1): %c\n", *(c+1));

    puts("--------------------------");

    int *ptr = numbers;
    printf("ptr: %p\n", ptr);
    printf("*ptr: %d\n", *ptr);
    printf("a[1]: %d\n", *(ptr + 1));  // Accesses the second element
}