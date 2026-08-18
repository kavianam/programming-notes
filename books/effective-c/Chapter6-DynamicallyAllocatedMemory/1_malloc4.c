#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str = (char *)malloc(16);
    if (str) {
        printf("before: %s\n", str);

        strncpy(str, "123456789abcdef", 15);
        printf("after: %s\n", str);
        /*
         * malloc function does not initialize the returned memory
         * The last byte (16th) of str may be anything, not necessary \0 and this might break our code
         * We should do this to ensure that the last byte is \0:
         */
        str[16] = '\0';

        printf("after: %s\n", str);

        free(str);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
