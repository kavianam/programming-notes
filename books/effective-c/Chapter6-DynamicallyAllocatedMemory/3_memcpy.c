#include <stdio.h>
#include <string.h>

/*
 * The memcpy function copies the specified number of bytes from one memory location to another memory location regardless of the type of data stored. 
 *
 * memcpy(*to, *from, numBytes);
 * to: A pointer to the memory location where the copied data will be stored.
 * from: A pointer to the memory location from where the data is to be copied.
 * numBytes: The number of bytes to be copied.
 * 
 * memcpy() copies the memory in a byte-by-byte format without any checks or transformations, meaning it does not handle type conversions or alignment issues, check for overflow or \0.
 * memcpy() makes a shallow copy as it only copies the raw bytes of the memory from one location to another. It does not perform a deep copy or handle objects at a higher level.
 * memcpy() only copies the pointer values (i.e., the addresses they hold), not the actual objects or data those pointers reference.
 */

int main() {
    int a = 20;
    int b = 10;
    
    printf("Value of b before calling memcpy: %d\n", b);

    // Use memcpy to copy the value of 'a' into 'b'
    memcpy(&b, &a, sizeof(int)); 

    printf("Value of b after calling memcpy: %d\n", b);

    puts("--------------------------");

    char str1[] = "Geeks";
    char str2[6] = "";

    printf("sizeof: %lu\n", sizeof(str1));  // 6
    printf("strlen: %lu\n", strlen(str1));  // 5 - checkout Chapter4/6_sizeof.c
    
    printf("Before: %s\n", str2);

    memcpy(str2, str1, sizeof(str1));

    printf("After: %s\n", str2);
}