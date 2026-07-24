/*
It’s possible to accidentally convince your compiler to change a const object 
for you. In the following example, we take the address of a const object i 
and tell the compiler that it’s actually a pointer to an int.
This code might appear to work, but it’s defective and may fail later. 
For example, the compiler might place the const object in  read-only memory,
causing a memory fault when trying to store a value in the object at runtime.
Be careful not to pass a const -qualified pointer to a function that modifies
the object.
*/
#include <stdio.h>

int main() {
    const int i = 1;
    // i = 2;  // Error

    int *ip = &i;
    *ip = 2;  // undefined behavior

    printf("i: %d\n", i);

    return 0;
}