#include <stdio.h>
#include <stdlib.h>

// If an error occurs while allocating a resource, the code uses a goto to jump to the appropriate location in cleanup code and releases only those resources that have been allocated.
// kernel/fork.c has many goto, worth checking out: https://github.com/torvalds/linux/blob/master/kernel/fork.c

int main() {
    FILE *file1, *file2;
    char buffer[256];
    int ret_val = 0;

    // file1 = fopen("Chapter5-ControlFlow/a.txt", "r");
    file1 = fopen("./a.txt", "r");
    if (file1 == NULL) {
        puts("Can't open the file1");
        ret_val = -1;
        goto FAIL_FILE1;
    }

    // file2 = fopen("./b.txt", "r");
    file2 = fopen("./b.txt", "a");
    // file2 = fopen("Chapter5-ControlFlow/b.txt", "r");
    // file2 = fopen("Chapter5-ControlFlow/b.txt", "w");
    if (file2 == NULL) {
        puts("Can't open the file2");
        ret_val = -1;
        goto FAIL_FILE2;
    }

    // Read each line from the file
    while (fgets(buffer, sizeof(buffer), file1) != NULL) {
        printf("%s", buffer);
        fputs(buffer, file2);
    }
    puts("");

    int *a;
    a = malloc(sizeof(int));

    if (a == NULL) {
        puts("Can't allocate memory");
        ret_val = -1;
        goto FAIL_OBJ;
    }


    // Clean up everything
    free(a);
FAIL_OBJ:
    puts("Closing file2");
    fclose(file2);
FAIL_FILE2:
    puts("Closing file1");
    fclose(file1);
FAIL_FILE1:
    return ret_val;
}
