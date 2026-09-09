#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = malloc(5 * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1; // arr = {1, 2, 3, 4, 5}
    }

    // Wrong - If the call to realloc fails, arr is assigned the value NULL, but realloc doesn't deallocate the storage reference by arr, resulting in this memory being leaked.
    // arr = realloc(arr, 10 * sizeof(int));
    // if (arr == NULL) {
    //     fprintf(stderr, "Memory allocation failed\n");
    //     return 1;
    // }

    // Correct
    int *new_arr = realloc(arr, 10 * sizeof(int));
    if (new_arr == NULL) {
        free(arr);
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    arr = new_arr;

    free(arr);
}
