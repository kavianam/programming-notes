#include <stdio.h>

int main() {
    int a = 10;

    if (a > 0) {
        goto here;
    }
    puts("111");
here:
    puts("222");
}
