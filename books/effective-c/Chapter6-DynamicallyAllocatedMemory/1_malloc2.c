#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char c[10];
    int i;
    double d;
} widget;

int main() {
    void *p = malloc(sizeof(widget));
    if (p == NULL) {
        puts("Error allocating memory!");
        return 1;
    }

    // Allocate on Stack
    widget w = {"abc", 9, 3.2};
    printf("w.i: %d\n", w.i);

    memcpy(p, &w, sizeof(widget));
    
    printf("((widget *)p)->i: %d\n", ((widget *)p)->i);

    free(p);
}