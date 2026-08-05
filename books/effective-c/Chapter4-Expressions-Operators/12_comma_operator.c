#include <stdio.h>

/*
 * Comma Operator:
 * The comma (,) operator is a way to evalute one expression before another.
 * First, the left operand of a comma operator is evaluated as a void expression.
 * There is a sequence point between the evaluation of the left operand and the evaluation of the right operand.
 * Then, the right operand is evaluated after the left.
 * Thre result of the comma operation has the type and value of the right operand--monstly because it is the last expression evaluated.
 *
 * In this example, the second comma is a comma operator.
 * The assignment is evaluated first, followed by the addition.
 * Because of the sequence point, the assignment is guaranteed to complete before the addition takes place.
 * The result of the operation has the type int and value 5 of the right-hand operand.
 */

void f(int a, int b, int c) {
    printf("a: %d - b: %d - c: %d\n", a, b, c);
}

int main() {
    int a = 1;
    int b = 2;
    int c = 3;
    int d;

    f(a, b, c);
    f(a, (d=2, d+1), c);

    puts("--------------------------");

    int j = 0;
    for (int i = 0; i<10; j+=2, i++) {
        printf("%d", i);
    }
    printf("\n%d\n", j);
}