#include <stdio.h>

/*
 * In C, strings are arrays of characters terminated by a null character ('\0').
 * To store a string of 10 characters, you need an array of size 11 to accommodate the extra terminating character.
 */

int main(void) {
    char str[11];
    for (unsigned int i = 0; i < 10; ++i) {
        str[i] = '0' + i; // same as 48 + i ('0' is character with ASCII value 48)
    }
    str[10] = '\0';

    printf("%s\n", str);
}
