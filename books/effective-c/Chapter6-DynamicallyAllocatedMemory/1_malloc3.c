#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char c[10];
    int i;
    double d;
} widget;

int main() {
    widget *p = (widget *)malloc(sizeof(widget));
    // casting is unnecessary

    if (p == NULL) {
        puts("Error allocating memory!");
        return 1;
    }

    free(p);
}