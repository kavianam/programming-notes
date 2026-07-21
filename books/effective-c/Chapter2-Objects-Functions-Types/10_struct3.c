#include <stdio.h>

struct Car {
    char brand[50];
    char model[50];
    unsigned int year;
};

int main(void) {
    struct Car a = {"BMW", "M5", 2015};

    printf("a.year: %d\n", a.year);

    printf("--------------------------\n");

    struct Car b;
    b = a;  // copy the values in a to b

    printf("b.year: %d\n", b.year);

    printf("--------------------------\n");

    b.year = 2018;

    printf("b.year: %d\n", b.year);
    printf("a.year: %d\n", a.year);  // the value of a doesn't change.

    printf("--------------------------\n");

    struct Car *c;
    c = &a;

    printf("c->year: %d\n", c->year);

    printf("--------------------------\n");

    c->year = 2021;

    printf("c->year: %d\n", c->year);
    printf("a.year: %d\n", a.year);  // The value of a also changed

}