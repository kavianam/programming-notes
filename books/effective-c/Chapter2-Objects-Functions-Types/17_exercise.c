#include <stdio.h>

typedef void (*f)();

void first() {
    printf("In first\n");
}

void second() {
    printf("In second\n");
}

void third() {
    printf("In third\n");
}

void caller(int i) {
    f array[3] = {first, second, third};

    if (i == 0) {
        array[0]();
    } else if (i == 1) {
        array[1]();
    } else if (i == 2) {
        array[2]();
    }
    // array[i]();
}


int main(void) {
    // My answer:
    caller(2);

    // Chatgpt's answers:
    void (*fp[3])(void) = {first, second, third};
    fp[0]();
}