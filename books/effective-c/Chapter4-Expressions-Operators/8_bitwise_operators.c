#include <limits.h>
#include <stdio.h>


int main(void) {
    // Complement Operator
    // Returns the bitwise complement of its operand; means each bit of the original value is flipped.
    unsigned char a = UCHAR_MAX;  // 0XFF
    int i = ~a;

    printf("%hhu\n", a);
    printf("%d\n", i);
    printf("%d\n", ~6);  // 6 = 0000 0000 0000 0110 => ~6 (Two's Complement)=  1111 1111 1111 1001 -  +1 : 0000 0000 0000 0111 = -7
    printf("%d\n", !6);

    printf("--------------------------\n");
    // Shift Operators

    printf("%d\n", 2 << 1);  // left-shift: 10 << 1  => 100 = 4
    printf("%d\n", 4 >> 1);  // right-shift: 100 >> 1  => 10 = 2
    printf("%d\n", 4 >> -1);  // right-shift: 100 >> -1  => 1000 = 8

    // Correct right-shift operations
    int si1, si2, sresult;
    unsigned int ui1, ui2, uresult;

    printf("%lu\n", sizeof(int)*CHAR_BIT);  // 32

    if (si2 < 0 || si2 >= sizeof(int)*CHAR_BIT) {
        // Error
    } else {
        sresult = si1 >> si2;
    }

    if (ui2 >= sizeof(unsigned int)*CHAR_BIT) {
        // Error
    } else {
        uresult = ui1 >> ui2;
    }

    printf("--------------------------\n");

    /*
     * AND:
     * 0 & 0 => 0
     * 0 & 1 => 0
     * 1 & 0 => 0
     * 1 & 1 => 1
     *
     * Inclusive OR:
     * 0 | 0 => 0
     * 0 | 1 => 1
     * 1 | 0 => 1
     * 1 | 1 => 1
     *
     * Exclusive OR:
     * 0 ^ 0 => 0
     * 0 ^ 1 => 1
     * 1 ^ 0 => 1
     * 1 ^ 1 => 0
     */

    // 12 = 1100 - 6 = 0110
    printf("%d\n", 12 & 6);
    printf("%d\n", 12 | 6);
    printf("%d\n", 12 ^ 6);
}