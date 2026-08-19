#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * When we run the person with char * we get Segmentation Fault.
 * The error arises from the way you're handling the name member of the person struct.
 * Specifically, the name pointer is not initialized to point to a valid memory location before you attempt to copy a string into it using strcpy.
 *
 * Here's a breakdown of the issue:
 * 1. Uninitialized Pointer: In person struct, char *name; is a pointer that is meant to point to a string.
 * However, when you allocate memory for the person struct with malloc, the name pointer is not automatically initialized to point to any valid memory. It contains a garbage value.
 * 2. Using strcpy: When you call strcpy(p->name, "Kavian");, you are trying to copy the string "Kavian" into the memory location pointed to by p->name.
 * Since p->name is uninitialized, this leads to undefined behavior, which can result in a segmentation fault or other runtime errors.
 *
 * Using a char array instead of a char* pointer for the name member in the person struct can indeed simplify memory management and reduce the risk of errors related to dynamic memory allocation.
 * Here are some advantages of using a char array:
 * 1. Automatic Memory Management: When you declare a char array, the memory is allocated on the stack (if declared locally) or as part of the struct (if declared as a member).
 * This means you don't need to manually allocate and free memory, which reduces the risk of memory leaks and errors.
 * 2. Simplicity: Using a fixed-size array can make your code simpler and easier to read, as you don't have to deal with malloc, free, and error checking for memory allocation.
 * 3. Performance: Accessing stack memory (for local arrays) can be faster than heap memory (for dynamically allocated memory), although this difference is often negligible for small allocations.
 */

typedef struct {
    char *name;
    // char name[20];
    int age;
} person;

int main() {
    person *p = malloc(sizeof(person));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    p->age = 29;

    // Allocate memory for the name
    p->name = malloc(7 * sizeof(char)); // 7 bytes for "Kavian" + null terminator
    if (p->name == NULL) {
        fprintf(stderr, "Memory allocation for name failed\n");
        free(p); // Free previously allocated memory
        return EXIT_FAILURE;
    }
    strcpy(p->name, "Kavian");

    printf("person(name=%s, age=%d)\n", p->name, p->age);

    // Free allocated memory
    free(p->name); // Free the name memory first
    free(p); // Then free the person struct
}