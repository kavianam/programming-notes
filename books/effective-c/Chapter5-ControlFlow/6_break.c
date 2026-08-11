#include <ctype.h>
#include <stdio.h>

int main(void) {
    int c;
    int temp;

    for (;;) {
        puts("Press any key, Q to quit: ");
        c = toupper(getchar());

        // Consume the rest of the line (including the newline)
        while ((temp = getchar()) != '\n' && temp != EOF); 

        if (c == 'Q')
            break;
    }
}
