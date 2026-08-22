#include <stdio.h>

/*
 * void * is a special type of pointer known as a "generic pointer."
 * It can point to any data type, but it does not have a specific type associated with it.
 *
 * Characteristics of void *:
 * 1. Generic Pointer: A void * pointer can hold the address of any data type (e.g., int, char, float, structures, etc.).
 * This makes it useful for functions that need to handle different types of data without knowing their specific types in advance.
 *
 * 2. No Type Information: Since void * does not have type information, you cannot directly dereference it or access its members.
 * You must first cast it to the appropriate pointer type before dereferencing or accessing its members.
 *
 * 3. Memory Management: void * is often used in dynamic memory allocation functions like malloc, which returns a void * pointer to the allocated memory.
 * This allows the allocated memory to be used for any data type.
 *
 * 4.Function Parameters: void * is commonly used in function parameters to allow functions to accept pointers to any data type.
 * This is particularly useful in callback functions or when implementing data structures like linked lists or trees that can store different types of data.
 */

void printValue(void *ptr, char type) {
    if (type == 'i') {
        printf("Integer: %d\n", *(int *)ptr); // Cast to int*
    } else if (type == 'f') {
        printf("Float: %.2f\n", *(float *)ptr); // Cast to float*
    } else if (type == 'c') {
        printf("Character: %c\n", *(char *)ptr); // Cast to char*
    }
}

int main() {
    int a = 10;
    float b = 5.5;
    char c = 'A';

    printValue(&a, 'i'); // Pass address of int
    printValue(&b, 'f'); // Pass address of float
    printValue(&c, 'c'); // Pass address of char

    return 0;
}
