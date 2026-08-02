#include <stdbool.h>
#include <stdio.h>

bool f(void) {
    printf("In f");
    return true;
}

bool isN(int* ptr, int n) {
    // This code tests the value of ptr. If pts is NULL, the second && operand is not evaluated, preventing a null pointer dereference.
    return ptr && *ptr == n;
}

int main(void) {
    printf("0 && f(): %d\n", 0 && f());  // short-circuit: the second operand is not evaluated if the result can be deduced solely by evaluating the first operand.
    printf("1 || f(): %d\n", 1 || f());

    printf("--------------------------\n");

    int a = 5;
    int *ptr = &a;
    int *ptr2;

    printf("isN(ptr, a): %d\n", isN(ptr, a));
    printf("isN(ptr2, a): %d\n", isN(ptr2, a));
}