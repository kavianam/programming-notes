#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    int a;
    size_t s1 = sizeof(a);  // size_t = long unsigned int
    size_t s2 = sizeof a;
    size_t s3 = sizeof(int);

    printf("%lu\n", s1);  // size in bytes
    printf("%lu\n", s2);
    printf("%lu\n", s3);
    printf("%lu\n", s1 * CHAR_BIT);  // size in bits

    puts("--------------------------");
    // Number of elements in an array

    int array[] = {1, 2, 3, 4, 5};
    // int array[5];

    printf("The total size of the array in bytes: %lu\n", sizeof(array));
    printf("The size of a single element: %lu\n", sizeof(array[0]));
    printf("The number of elements: %lu\n", sizeof(array) / sizeof(array[0]));

    puts("--------------------------");
    // Number of elements in an string array
    char str[6] = "Kav";

    printf("The total size of the str in bytes: %lu\n", sizeof(str));
    printf("The size of a single element: %lu\n", sizeof(str[0]));
    printf("The number of elements: %lu\n", sizeof(str) / sizeof(str[0]));
    // For char arrays, using sizeof alone is enough because chars allocated 1 byte.
    printf("The length of the string: %lu\n", strlen(str));

    puts("--------------------------");

    char *name = "Kavian";
    size_t length = strlen(name); // Length of the string (not including '\0')
    size_t totalSize = length + 1; // Add 1 for the null terminator

    printf("The length of the string is: %zu\n", length); // 6
    printf("The total size of the string in bytes (including '\\0'): %zu\n", totalSize); // 7
    printf("The size of the pointer str in bytes: %zu\n", sizeof(name)); // 8
    // for char*, we have to use the strlen instead of sizeof, because name is declared as a pointer to a string literal, not as an array containing the characters of the string itself. 
    // name is a pointer of type char * that points to the first character of the string literal "Kavian"
    // When you use sizeof(str), you are asking for the size of the pointer str, not the size of the string it points to. On most modern systems (like x86_64 architecture), the size of a pointer is 8 bytes (64 bits), which is why you see 8 as the output.
}
