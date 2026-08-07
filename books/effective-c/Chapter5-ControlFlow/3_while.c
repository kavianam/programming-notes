#include <string.h>
#include <stdio.h>

/*
 * Implementation of the C Standard library memset function.
 * memset is a function used to fill a block of memory with a specific value.
 * It's often used to initialize memory, clear sensitive data, or set memory to a default state.
 * The function takes a pointer to the memory block, a value to fill with, and the number of bytes to fill.
 */

void *memset(void *dest, int val, size_t n) {
    unsigned char *ptr = (unsigned char*)dest;
    while (n-- > 0)
        *ptr++ = (unsigned char)val;
    return dest;
}

int main() {
    char array[10];

    char *res = memset(array, 'K', 9);
    // array[9] = '\0';
    printf("%s\n", res);

    puts("--------------------------");

    char str[10];
    memset(str, 'A', sizeof(str) - 1); // Leave space for null terminator
    str[9] = '\0'; // Null-terminate the string

    printf("%s\n", str);

    puts("--------------------------");

    struct Point {
        int x;
        int y;
    };
    struct Point p;
    // struct Point p = {0};  // we can do this instead of using memset

    // Initialize the structure p to zero
    memset(&p, 0, sizeof(p));

    printf("Point coordinates: (%d, %d)\n", p.x, p.y);

    puts("--------------------------");

    int matrix[3][3];
    // int matrix[3][3] = {0};

    // Clear the entire 2D array
    memset(matrix, 0, sizeof(matrix));

    // Print the matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
