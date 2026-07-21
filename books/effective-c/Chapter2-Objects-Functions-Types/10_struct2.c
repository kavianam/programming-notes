#include <stdio.h>
#include <string.h>

struct sigrecord {
    int signum;
    char signame[20];
    char sigdesc[100];
};

int main(void) {
    struct sigrecord a;

    a.signum = 1;
    strcpy(a.signame, "SIGINT");

    printf("a.signum: %d\n", a.signum);
    printf("a.signame: %s\n", a.signame);

    printf("--------------------------\n");

    struct sigrecord b;

    printf("b.signum: %d\n", b.signum);

    b.signum = 2;
    printf("b.signum: %d\n", b.signum);
    printf("a.signum: %d\n", a.signum);  // a doesn't change

    printf("--------------------------\n");

    struct sigrecord *c;

    // printf("%d\n", c->signum);  // Error
    // c->signum = 3;
    //printf("%d\n", c->signum);  // Error

    c = &b;

    printf("c->signum: %d\n", c->signum);
    c->signum = 3;
    printf("c->signum: %d\n", c->signum);
    printf("b.signum: %d\n", b.signum);  // b also changed
}