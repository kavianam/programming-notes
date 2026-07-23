#include <stdio.h>
#include <string.h>

/*
 * The  strcpy()  function copies the string pointed to by src, including the terminating
 * null byte ('\0'), to the buffer pointed to by dest.  The strings may not overlap,  and
 * the destination string dest must be large enough to receive the copy.  Beware of buffer overruns!
 *
 * The strncpy() function is similar, except that at most n  bytes  of  src  are  copied.
 * Warning: If there is no null byte among the first n bytes of src, the string placed ind est will not be null-terminated.
 *
 * If the length of src is less than n, strncpy() writes additional null bytes to dest to ensure that a total of n bytes are written.
 * Source: `man strcpy`
 */

int main(void) {
    char a[5];

    strcpy(a, "abcd");
    printf("a: %s\n", a);

    strncpy(a, "xyz", 2);
    printf("a: %s\n", a);

    char b[] = {'a', 'b', 'c', '\0'};  // Same as char b[] = "abc";
    printf("b: %s\n", b);

    strcpy(a, "abcdef");
    printf("a: %s\n", a);
}
