/*
 * =============================================================================
 * restrict in C - Type Qualifier for Optimization (C99+)
 * =============================================================================
 * 
 * WHAT IS restrict?
 * -----------------
 * restrict is a promise to the compiler: "This pointer is the ONLY way to
 * access this memory region during its lifetime."
 * 
 * WHY USE restrict?
 * -----------------
 * Without restrict, the compiler must assume pointers might ALIAS (point to
 * the same memory). This prevents many optimizations.
 * 
 * With restrict, the compiler can:
 * ✓ Reorder memory accesses
 * ✓ Cache values in registers
 * ✓ Vectorize loops (SIMD)
 * ✓ Eliminate redundant loads/stores
 * 
 * ⚠️  WARNING: If you lie (pointers DO alias), behavior is UNDEFINED!
 * 
 * Compile: gcc -std=c99 -O3 -Wall -o 16_restrict 16_restrict.c
 */

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* =============================================================================
 * Example 1: Basic restrict Usage (Memory Copy)
 * =============================================================================
 * This is the classic example from your book.
 */

/* Without restrict - compiler must assume p and q might alias */
void copy_no_restrict(int *p, const int *q, size_t n) {
    for (size_t i = 0; i < n; i++) {
        p[i] = q[i];
    }
}

/* With restrict - compiler knows p and q DON'T alias */
void copy_with_restrict(int *restrict p, const int *restrict q, size_t n) {
    for (size_t i = 0; i < n; i++) {
        p[i] = q[i];
    }
}

void demonstrate_basic_restrict(void) {
    printf("\n=== 1. Basic restrict Usage ===\n");
    
    int src[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int dst[10] = {0};
    
    printf("Source: ");
    for (int i = 0; i < 10; i++) printf("%d ", src[i]);
    printf("\n");
    
    copy_with_restrict(dst, src, 10);
    
    printf("Dest:   ");
    for (int i = 0; i < 10; i++) printf("%d ", dst[i]);
    printf("\n");
    printf("✓ Copy completed (no aliasing - safe!)\n");
}

/* =============================================================================
 * Example 2: DANGER - Overlapping Memory (Undefined Behavior!)
 * =============================================================================
 * This demonstrates what happens when you violate the restrict promise.
 */

void demonstrate_overlap_danger(void) {
    printf("\n=== 2. DANGER - Overlapping Memory ===\n");
    printf("⚠️  This shows UNDEFINED BEHAVIOR - don't do this!\n\n");
    
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    printf("Original array: ");
    for (int i = 0; i < 10; i++) printf("%d ", array[i]);
    printf("\n\n");
    
    /* ❌ WRONG: Overlapping regions with restrict */
    printf("Copying with OVERLAP (array+0 → array+3, 7 elements):\n");
    printf("  This VIOLATES the restrict promise!\n");
    copy_with_restrict(array + 3, array, 7);
    
    printf("Result:         ");
    for (int i = 0; i < 10; i++) printf("%d ", array[i]);
    printf("\n");
    printf("  Expected:     1 2 3 1 2 3 4 5 6 7 (if sequential)\n");
    printf("  ⚠️  But result is UNDEFINED - may vary!\n\n");
    
    /* ✅ CORRECT: Use memmove for overlapping regions */
    int array2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Using memmove (safe for overlap):\n");
    memmove(array2 + 3, array2, 7 * sizeof(int));
    
    printf("Result:         ");
    for (int i = 0; i < 10; i++) printf("%d ", array2[i]);
    printf("\n");
    printf("  ✓ Correct and defined behavior!\n");
}

/* =============================================================================
 * Example 3: Performance Comparison
 * =============================================================================
 * Shows how restrict enables better optimization.
 */

#define ARRAY_SIZE (20000000)
#define ITERATIONS 100
// #define ARRAY_SIZE (400000000)
// #define ITERATIONS 1000

void benchmark_copy(void) {
    printf("\n=== 3. Performance Comparison ===\n");
    
    int *src = malloc(ARRAY_SIZE * sizeof(int));
    int *dst1 = malloc(ARRAY_SIZE * sizeof(int));
    int *dst2 = malloc(ARRAY_SIZE * sizeof(int));
    
    if (!src || !dst1 || !dst2) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    /* Initialize data */
    for (int i = 0; i < ARRAY_SIZE; i++) {
        src[i] = i;
    }
    
    /* Benchmark without restrict */
    clock_t start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        copy_no_restrict(dst1, src, ARRAY_SIZE);
    }
    clock_t end = clock();
    double time_no_restrict = (double)(end - start) / CLOCKS_PER_SEC;
    
    /* Benchmark with restrict */
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        copy_with_restrict(dst2, src, ARRAY_SIZE);
    }
    end = clock();
    double time_with_restrict = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("Array size: %d elements\n", ARRAY_SIZE);
    printf("Iterations: %d\n\n", ITERATIONS);
    printf("Without restrict: %.4f seconds\n", time_no_restrict);
    printf("With restrict:    %.4f seconds\n", time_with_restrict);
    
    if (time_no_restrict > 0) {
        double speedup = time_no_restrict / time_with_restrict;
        printf("Speedup:          %.2fx\n", speedup);
    }
    
    printf("\n⚠️  Note: Speedup varies by compiler, optimization level, and CPU.\n");
    printf("   At -O3, restrict enables vectorization (SIMD instructions).\n");
    
    free(src);
    free(dst1);
    free(dst2);
}

/* =============================================================================
 * Example 4: Multiple Restrict Pointers
 * =============================================================================
 * Shows restrict with multiple pointers to different memory regions.
 */

void vector_add(int *restrict result, 
                const int *restrict a, 
                const int *restrict b, 
                size_t n) {
    for (size_t i = 0; i < n; i++) {
        result[i] = a[i] + b[i];
    }
}

void demonstrate_multiple_restrict(void) {
    printf("\n=== 4. Multiple Restrict Pointers ===\n");
    
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {10, 20, 30, 40, 50};
    int result[5] = {0};
    
    printf("Vector A: ");
    for (int i = 0; i < 5; i++) printf("%d ", a[i]);
    printf("\n");
    
    printf("Vector B: ");
    for (int i = 0; i < 5; i++) printf("%d ", b[i]);
    printf("\n");
    
    vector_add(result, a, b, 5);
    
    printf("Result:   ");
    for (int i = 0; i < 5; i++) printf("%d ", result[i]);
    printf("\n");
    printf("✓ All three pointers are restrict - no aliasing allowed\n");
}

/* =============================================================================
 * Example 5: When NOT to Use restrict
 * =============================================================================
 * Shows cases where restrict is inappropriate.
 */

void swap_no_restrict(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_restrict(int *restrict a, int *restrict b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void demonstrate_when_not_to_use(void) {
    printf("\n=== 5. When NOT to Use restrict ===\n");
    
    int x = 10;
    
    printf("x = %d\n", x);
    printf("Calling swap(&x, &x) - same pointer twice!\n\n");
    
    /* This is SAFE without restrict */
    swap_no_restrict(&x, &x);
    printf("Without restrict: x = %d (safe, still 10)\n", x);
    
    swap_restrict(&x, &x);
    printf("With restrict: x = %d (undefined behavior)\n", x);
    printf("swap(&x, &x) would be UNDEFINED BEHAVIOR!\n");
    printf("   Because a and b would alias (both point to x)\n\n");
    
    printf("DON'T use restrict when:\n");
    printf("  ✗ Pointers might alias\n");
    printf("  ✗ Function is generic (can't guarantee no aliasing)\n");
    printf("  ✗ Working with overlapping memory regions\n");
    printf("  ✗ Pointer arithmetic might cause overlap\n");
}

/* =============================================================================
 * Example 6: restrict with Struct Pointers
 * =============================================================================
 */

typedef struct {
    int data[100];
    size_t size;
} buffer_t;

void process_buffers(int *restrict out, 
                     const buffer_t *restrict in1,
                     const buffer_t *restrict in2) {
    for (size_t i = 0; i < in1->size && i < in2->size; i++) {
        out[i] = in1->data[i] * in2->data[i];
    }
}

void demonstrate_struct_restrict(void) {
    printf("\n=== 6. restrict with Struct Pointers ===\n");
    
    buffer_t buf1 = {.size = 5};
    buffer_t buf2 = {.size = 5};
    int result[5] = {0};
    
    for (int i = 0; i < 5; i++) {
        buf1.data[i] = i + 1;
        buf2.data[i] = 10;
    }
    
    process_buffers(result, &buf1, &buf2);
    
    printf("Buffer 1: ");
    for (int i = 0; i < 5; i++) printf("%d ", buf1.data[i]);
    printf("\n");
    
    printf("Buffer 2: ");
    for (int i = 0; i < 5; i++) printf("%d ", buf2.data[i]);
    printf("\n");
    
    printf("Result:   ");
    for (int i = 0; i < 5; i++) printf("%d ", result[i]);
    printf("\n");
    printf("✓ Struct pointers can also be restrict-qualified\n");
}

/* =============================================================================
 * Main Function
 * =============================================================================
 */

int main(void) {
    printf("========================================\n");
    printf("  restrict in C\n");
    printf("========================================\n");
    
    demonstrate_basic_restrict();
    demonstrate_overlap_danger();
    benchmark_copy();
    demonstrate_multiple_restrict();
    demonstrate_when_not_to_use();
    demonstrate_struct_restrict();
    
    printf("\n========================================\n");
    printf("  Key Takeaways\n");
    printf("========================================\n");
    printf("  ✓ restrict is an optimization hint\n");
    printf("  ✓ Tells compiler: 'This pointer is unique'\n");
    printf("  ✓ Enables vectorization and better optimization\n");
    printf("  ⚠️  Violating restrict = UNDEFINED BEHAVIOR\n");
    printf("  ⚠️  Don't use with overlapping memory\n");
    printf("  ✓ Use memmove() for overlapping regions\n");
    printf("  ✓ Compile with -O3 for best results\n");
    
    return 0;
}

/*
 * =============================================================================
 * restrict Quick Reference
 * =============================================================================
 * 
 * SYNTAX:
 * -------
 * int *restrict p;            // restrict pointer to int
 * int *const restrict p;      // const restrict pointer
 * void func(int *restrict p); // restrict parameter
 * 
 * WHEN TO USE restrict:
 * ---------------------
 * ✓ Copying between non-overlapping regions
 * ✓ Processing separate arrays (vector operations)
 * ✓ Output buffer separate from input buffers
 * ✓ Performance-critical code with known no-aliasing
 * 
 * WHEN NOT TO USE restrict:
 * -------------------------
 * ✗ Pointers might alias (point to same memory)
 * ✗ Overlapping memory regions
 * ✗ Generic library functions
 * ✗ When you can't guarantee uniqueness
 * 
 * COMMON PATTERNS:
 * ----------------
 * // Copy
 * void memcpy(void *restrict dst, const void *restrict src, size_t n);
 * 
 * // Vector operations
 * void vec_add(float *restrict out, const float *restrict a, ...);
 * 
 * // Image processing
 * void process(unsigned char *restrict output, 
 *              const unsigned char *restrict input);
 * 
 * COMPILATION:
 * ------------
 * gcc -std=c99 -O3 -Wall -Wextra -o 16_restrict 16_restrict.c
 * 
 *   -O0: restrict has no effect (no optimization)
 *   -O2: some optimization
 *   -O3: full optimization including vectorization
 */