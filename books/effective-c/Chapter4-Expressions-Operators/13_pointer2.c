#include <stdio.h>

/*
 * the sum_m_elems function return the sum of elements in the m array.
 */

int m[2] = {1, 2};

int sum_m_elems(void) {
    int *pi;
    int j = 0;
    for (pi = &m[0]; pi < &m[2]; ++pi)  // m[2] is the too-far index, meaning one after the last index.
        j += *pi;
    return j;
}

int main() {
    int res = sum_m_elems();
    printf("%d\n", res);
}
