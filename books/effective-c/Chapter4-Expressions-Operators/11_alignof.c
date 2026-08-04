#include <assert.h>
#include <stdalign.h>
#include <stddef.h>
#include <stdio.h>

/*
 * alignment:
 * Data types in C have specific alignment requirements, which dictate how they should be placed in memory.
 * For example, an int might need to be aligned to a 4-byte boundary, while a double might need to be aligned to an 8-byte boundary.
 * This means that the address of a variable of a certain type should be a multiple of its size.
 * For instance, if an int is 4 bytes, it should be located at an address that is a multiple of 4 (e.g., 0x0000, 0x0004, 0x0008, etc.).
 * To satisfy alignment requirements, the compiler may insert padding bytes between variables or at the end of structures.
 * This ensures that each member of a structure is aligned correctly.
 * For example, if you have a structure with a char (1 byte) followed by an int (4 bytes), the compiler may add 3 padding bytes after the char to align the int on a 4-byte boundary.
 *
 * assert:
 * The assert macro is used to perform runtime checks.
 * It is primarily used for debugging purposes to verify assumptions made by the program during execution.
 *
 * static_assert:
 * The static_assert is used for compile-time assertions.
 * It checks conditions at compile time rather than at runtime, ensuring that certain conditions are met before the program is compiled.
 * If the condition evaluates to false, a compilation error occurs, preventing the code from being compiled.
 *
 * Some compilers such as GCC and Clang provide the -Wparentheses flag that diagnoses parentheses like this example.
 * gcc 11_alignof.c -Wparentheses
 * 11_alignof.c:23:26: warning: comparisons like ‘X<=Y<=Z’ do not have their mathematical meaning [-Wparentheses]
 * 23 |     printf("%d\n", 1 < 3 < 2);
 */


int main() {
    int arr[10];
    static_assert(_Alignof(arr) == 4, "unexpected alignment");  // static assert
    assert(alignof(max_align_t) == 16);  // runtime assertion
    printf("Alignment of arr = %zu\n", _Alignof(arr));
    printf("Alignment of max_align_t = %zu\n", alignof(max_align_t));

    puts("--------------------------");

    printf("%d\n", 1 < 3 < 2);
    printf("%d\n", (1 < 3) < 2);
    printf("%d\n", 1 < (3 < 2));

    puts("--------------------------");

    struct Example1 {
        char a;      // 1 byte
        int b;       // 4 bytes
        char c;      // 1 byte
    };

    struct Example2 {
        char a;      // 1 byte
        char c;      // 1 byte
        int b;       // 4 bytes
    };

    printf("Size of struct Example1: %zu\n", sizeof(struct Example1));
    printf("Size of struct Example2: %zu\n", sizeof(struct Example2));
    // In this example, the struct Example may have a size greater than 6 bytes (1 + 4 + 1) due to padding.
    // The actual size might be 12 bytes on a system where int needs to be aligned to a 4-byte boundary.
}
