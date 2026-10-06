#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * If you call one of the free functions on the same pointer more than once, undefined behavior occurs.
 * These defects can result in a security flaw known as a double-free vulnerability.
 * One consequence is that they might be exploited to execute arbitrary code with the permissions of the vulnerable process.
 * Another common error is to access memory that has already been freed.
 * This type of error frequently goes undetected because the code might appear to work but then fails in an unexpected manner away from the actual error.
 * We refer to pointers to already freed memory as dangling pointers.
 * 
 * Since version 2.26, glibc uses a mechanism called tcache which stores keys/addresses to detect if a chunk is being freed twice. If detected, the program aborts immediately.
 * 
 * To understand how a double-free leads to arbitrary code execution, you need to understand what happens "under the hood" when memory is managed. It comes down to how the memory allocator (like malloc and free) keeps track of free memory.
 * When you call malloc, the allocator gives you a block of memory. When you call free, it doesn't just wipe the memory; it adds that block to a Free List (a linked list of available memory chunks) so it can be reused later.
 * If you call free(ptr) twice, the allocator is tricked into thinking two separate chunks are available, but they actually point to the same physical memory address.
 * Because the allocator thinks there are two free chunks, the next two malloc calls will hand out the same memory address to two different pointers.
 */

int main() {
    // Allocate memory for an integer
    int *ptr = malloc(sizeof(int));
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    *ptr = 42;
    printf("Value: %d\n", *ptr);

    // Free the allocated memory
    free(ptr);
    free(ptr); // This is the double-free vulnerability

    return EXIT_SUCCESS;
}