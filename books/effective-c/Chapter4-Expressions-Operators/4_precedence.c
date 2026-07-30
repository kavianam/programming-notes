#include <stdio.h>

int main(void) {
    char abc[] = "a.b.c";

    char *p = abc;

    printf("p: %s\n", p);
    printf("*p: %c\n", *p);
    printf("abc: %s\n", abc);
    printf("*abc: %c\n", *abc);

    printf("++*p: %c\n", ++*p);  // *p = a  -  a + 1 => b
    printf("p: %s\n", p);

    printf("--------------------------\n");

    char xyz[] = "x.y.z";
    p = xyz;

    printf("p: %s\n", p);
    printf("p++: %s\n", p++);
    printf("p: %s\n", p);
    printf("*p++: %c\n", *p++);
    printf("p: %s\n", p);
}
