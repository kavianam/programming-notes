#include <string.h>
#include <stdio.h>

// for loop version of memset

void *memset(void *dest, int val, size_t n) {
    unsigned char *ptr = (unsigned char*)dest;
    for (size_t i = 0; i < n; i++) {
        *(ptr + i) = (unsigned char)val;
    }
    return dest;
}

int main() {
    char array[10];

    char *res = memset(array, 'K', 9);
    printf("%s\n", res);
}
