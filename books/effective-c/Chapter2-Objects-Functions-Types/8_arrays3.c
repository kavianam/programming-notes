#include <stdio.h>
#include <string.h>

/*
 * Char Array VS. Pointer To String Literal
 *
 * Char Array (char array[]):
 * An array of characters that reserves a fixed block of memory to store a sequence of characters.
 * The size is determined at compile time (or runtime if it is a variable-length array in C99 and later).
 * The content of a char array can be modified. However, the array name itself (which acts as a pointer to the first element) cannot be reassigned.
 * Suitable for storing strings of a known, fixed size, and when you need to modify the string content directly.
 *
 * Pointer To String Literal (char *):
 * A pointer to a character, which can point to a single character or the beginning of a C-style string (a sequence of characters terminated by a null character, \0).
 * It doesn't automatically allocate memory for the string; it simply stores an address.
 * Memory must be explicitly allocated using functions like malloc() or it can point to a string literal stored in read-only memory.
 * If the char * points to a string literal, the content is typically read-only and cannot be modified.
 * If it points to memory allocated using malloc() or a similar function, the content can be modified.
 * The pointer itself can be reassigned to point to a different memory location.
 * Commonly used for dynamic memory allocation, function arguments (where the size of the string may not be known at compile time), and when dealing with string literals.
 */

int main(void) {
    char a[] = "abcd";
    // char a[] = {'a', 'b', 'c', 'd'};

    printf("a: %s\n", a);
    a[0] = 'X';
    printf("a: %s\n", a);

    char *b = "abcd";

    printf("b: %s\n", b);
    // b[0] = 'X';  // Error - because it is stored in read-only section of memory (typically in the program's data segment)
    printf("b: %s\n", b);


    printf("--------------------------\n");
    // In Pointer To String Literal, the pointer itself can be reassigned to point to a different memory location.
    // In Char Array, the array name itself (which acts as a pointer to the first element) cannot be reassigned.

    b++;  // b now points to the next character which is b
    printf("b: %s\n", b);

    b = "xyzd";  // This is a new String Literal somewhere in the memory and b now points to this String Literal
    printf("b: %s\n", b);

    // The content of a char array can be modified. However, the array name itself (which acts as a pointer to the first element) cannot be reassigned.
    // a++;  // Error - We cannot do this with an array, because 'char *' is a pointer and 'char []' is more like a constant pointer
    // a = "xyz";  // Error
    char c[] = "efg";
    *a = *c;  // we are reassigning the a[0] not the whole char array
    printf("a: %s\n", a);

    strcpy(a, "xyzd");  // Correct

    printf("a: %s\n", a);


    printf("--------------------------\n");


    printf("sizeof(a): %lu\n", sizeof(a));  // 5 - the array is xyzd plus a null character
    printf("sizeof(b): %lu\n", sizeof(b));  // 8 - b is a pointer, so 8 is a size of the pointer not the values that b points to
    printf("strlen(a): %lu\n", strlen(a));  // 4
    printf("strlen(b): %lu\n", strlen(b));  // 4
}