/*
 * For more information about Linkage, chehckout:
 * Chapter10-ProgramStructure/3_linkage
 */

#include <stdio.h>

static unsigned int counter = 0;  // Internal Linkage

void increment(void) {
    // static unsigned int counter = 0;  // No Linkage
    counter++;
    printf("%d\n", counter);
}

void decrement(void) {
    counter--;
    printf("%d\n", counter);
}

int main(void) {
    for (int i = 0; i < 10; i++) {
      increment();
    }
    decrement();
    
    return 0;
}