#include <stdio.h>

union {
    struct {
        int type;
    } n;
    struct {
        int type;
        int int_node;
    } ni;
    struct {
        int type;
        double double_node;
    } nf;
} u;


int main(void) {
    u.nf.type = 1;
    u.nf.double_node = 3.14;

    printf("u.nf.type: %d\n", u.nf.type);
    printf("u.ni.type: %d\n", u.ni.type);
    printf("u.n.type: %d\n", u.n.type);

    printf("u.nf.double_node: %f\n", u.nf.double_node);
    printf("u.ni.int_node: %d\n", u.ni.int_node);
}
