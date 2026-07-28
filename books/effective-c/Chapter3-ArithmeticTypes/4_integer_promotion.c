#include <limits.h>
#include <stdio.h>

/*
 * Integer promotion is a process that occurs when smaller integer types (such as char and short) are converted to
 * a larger integer type (typically int or unsigned int) during expressions and operations.
 * This is part of the C language's type conversion rules, which ensure that operations are performed on compatible types.
 *
 * Types Affected: The types that are promoted include:
 * 1. char (both signed and unsigned)
 * 2. short (both signed and unsigned)
 * 3. Any enumeration type (enum)
 *
 * Promotion Rules: When an expression involves smaller integer types, they are automatically promoted to int or unsigned int before the operation is performed.
 * The rules are:
 * 1. If the value of the smaller type can be represented by an int, it is promoted to int.
 * 2. If the value cannot be represented by an int (for example, if it is larger than INT_MAX), it is promoted to unsigned int.
 *
 * Integer promotions serve two primary purposes.
 * First, they encourage operations to be performed in a natural size ( int ) for the architecture, which improves performance.
 * Second, they help avoid arithmetic errors from the overflow of intermediate values.
 */

int main() {
    signed char cresult, c1, c2, c3;
    c1 = 100;
    c2 = 3;
    c3 = 4;
    cresult = c1 * c2 / c3;

    printf("%hhd\n", SCHAR_MAX);
    printf("%hhd\n", c1 * c2);
    printf("%hhd\n", cresult);  // c1 * c2 > 127 (SCHAR_MAX). However, with integer promotion the result is correct
}
