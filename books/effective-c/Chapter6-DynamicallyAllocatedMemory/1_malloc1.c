#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char c[10];
    int i;
    double d;
} widget;

int main() {
    printf("%ld\n", sizeof(widget));  // 10 (array) + 2 (alignment) + 4 (int) + 8 (double) = 24

    widget *p = malloc(sizeof(widget));

    if (p == NULL) {
        puts("Error allocating memory!");
        return 1;
    }
    puts("Memory allocated successfully");

    p->i = 29;
    printf("p->i: %d\n", p->i);

    // p->c = "Kavian";  // Error
    strcpy(p->c, "Kavian");
    printf("%s\n", p->c);

    free(p);
}