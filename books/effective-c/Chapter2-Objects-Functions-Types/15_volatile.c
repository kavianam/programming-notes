/*
 * =============================================================================
 * volatile in C
 * =============================================================================
 * 
 * WHAT IS volatile?
 * -----------------
 * volatile tells the compiler: "This value may change unexpectedly - don't
 * optimize accesses to it!"
 * 
 * WHY USE volatile?
 * -----------------
 * 1. Memory-mapped I/O registers (hardware devices)
 * 2. Variables modified by signal handlers
 * 3. Variables shared between setjmp/longjmp
 * 4. Real-time clocks or hardware counters
 * 5. Memory shared with external processes/ISR
 * 
 * WHAT volatile DOES:
 * -------------------
 * ✓ Every read occurs exactly as written in source code
 * ✓ Every write occurs exactly as written in source code
 * ✓ Order of accesses is preserved
 * ✓ Cannot be optimized away or cached
 * 
 * WHAT volatile DOES NOT DO:
 * --------------------------
 * ✗ Does NOT provide thread synchronization (use atomics/mutexes!)
 * ✗ Does NOT guarantee atomicity
 * ✗ Does NOT provide memory ordering between threads
 * 
 * ⚠️ You have to compile the program yourself, because we are using 
 * multithreaded and your program should be link against the pthread library.
 * 
 * Compile: gcc -std=c11 -pthread -O2 -Wall -Wextra -o 15_volatile 15_volatile.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdatomic.h>
#include <threads.h>

/* =============================================================================
 * Example 1: volatile Prevents Optimization
 * =============================================================================
 * Without volatile, compiler may optimize away "useless" reads/writes.
 * With volatile, every access occurs exactly as written.
 */

void demonstrate_optimization_prevention(void) {
    printf("\n=== 1. volatile Prevents Optimization ===\n");
    
    /* Non-volatile: compiler may optimize away */
    int non_volatile = 0;
    for (int i = 0; i < 3; i++) {
        non_volatile = i;  /* May be optimized! */
    }
    printf("non_volatile   = %d (may be optimized)\n", non_volatile);
    
    /* Volatile: every write MUST occur */
    volatile int volatile_var = 0;
    for (int i = 0; i < 3; i++) {
        volatile_var = i;  /* Every write occurs! */
    }
    printf("volatile_var   = %d (every write occurred)\n", volatile_var);
    
    /* Self-assignment example from book */
    volatile int port = 42;
    port = port;  /* Without volatile: optimized away as no-op */
                  /* With volatile: read THEN write MUST occur */
    printf("port = port    = %d (read+write occurred)\n", port);
}

/* =============================================================================
 * Example 2: Memory-Mapped I/O Simulation
 * =============================================================================
 * Hardware registers can change between reads. volatile ensures each read
 * actually accesses the hardware, not a cached value.
 */

/* Simulated hardware register (could change externally) */
volatile int hardware_register = 100;

void simulate_hardware_change(void) {
    /* Simulate external hardware changing the value */
    hardware_register += 10;
}

void demonstrate_memory_mapped_io(void) {
    printf("\n=== 2. Memory-Mapped I/O Simulation ===\n");
    
    /* Non-volatile: may cache value */
    int cached = hardware_register;
    simulate_hardware_change();  /* External change */
    printf("Non-volatile read: %d (cached, missed change!)\n", cached);
    
    /* Volatile: always reads fresh value */
    volatile int *hw_ptr = &hardware_register;
    int read1 = *hw_ptr;
    simulate_hardware_change();  /* External change */
    int read2 = *hw_ptr;
    printf("Volatile read 1:   %d\n", read1);
    printf("Volatile read 2:   %d (saw external change!)\n", read2);
}

/* =============================================================================
 * Example 3: Signal Handler Usage
 * =============================================================================
 * Variables modified by signal handlers MUST be volatile.
 * Otherwise, main loop may cache old value and never see the change.
 */

volatile sig_atomic_t signal_received = 0;

void signal_handler(int sig) {
    (void)sig;
    signal_received = 1;  /* MUST be volatile! */
}

void demonstrate_signal_handler(void) {
    printf("\n=== 3. Signal Handler Usage ===\n");
    printf("Run on terminal instead of running on VSCode!\n");
    printf("Waiting for INT... (send: kill -INT %d)\n", getpid());
    printf("Or press Ctrl+C within 6 seconds to continue\n\n");
    
    signal(SIGINT, signal_handler);
    
    /* Without volatile, this loop might never see signal_received change! */
    int timeout = 60;  /* 6 seconds (100ms * 60) */
    while (!signal_received && timeout-- > 0) {
        usleep(100000);  /* 100ms */
    }
    
    if (signal_received) {
        printf(" ✓ Signal received! (volatile worked)\n");
    } else {
        printf("⚠ Timeout (no signal received)\n");
    }

    /* Reset SIGINT to default for clean exit */
    signal(SIGINT, SIG_DFL);
}

/* =============================================================================
 * Example 4: Real-Time Clock Simulation
 * =============================================================================
 * Clock values change without program writing to them.
 * volatile ensures each read gets the current value.
 */

volatile int simulated_clock = 0;

void tick_clock(void) {
    simulated_clock++;  /* Simulates external clock increment */
}

void demonstrate_realtime_clock(void) {
    printf("\n=== 4. Real-Time Clock Simulation ===\n");
    
    /* Non-volatile: may cache old value */
    int cached_time = simulated_clock;
    tick_clock();
    tick_clock();
    tick_clock();
    printf("Non-volatile:    %d (cached, missed ticks!)\n", cached_time);
    
    /* Volatile: always reads current value */
    tick_clock();
    int current_time = simulated_clock;
    printf("Volatile:        %d (current value)\n", current_time);
}


/* =============================================================================
 * Example 5: const volatile Pattern
 * =============================================================================
 * const volatile: Read-only to program, but can change externally.
 * Example: Hardware status register (read-only, but hardware updates it).
 */

void demonstrate_const_volatile(void) {
    printf("\n=== 5. const volatile Pattern ===\n");
    
    /* Hardware register: program can't write, but hardware changes it */
    const volatile int *hardware_status = (const volatile int *)0x1000;
    
    printf("const volatile: Read-only to program\n");
    printf("                Can change externally (hardware)\n");
    printf("                Example: Status registers, sensors\n");
    
    /* Simulated usage */
    volatile int sensor_reading = 42;
    printf("Sensor reading:  %d (can change externally)\n", sensor_reading);
    printf("Program can read, but not modify (conceptually)\n");
}

/* =============================================================================
 * Example 6: volatile Does NOT Synchronize Threads!
 * =============================================================================
 * CRITICAL: volatile is NOT for thread synchronization!
 * Use atomics or mutexes instead.
 */

/* ❌ WRONG: volatile for thread sync */
volatile int volatile_counter = 0;

/* ✅ CORRECT: atomics for thread sync */
atomic_int atomic_counter = 0;

/* Thread function using volatile (WRONG!) */
int volatile_thread_func(void* arg) {
    int iterations = *(int*)arg;
    for (int i = 0; i < iterations; i++) {
        volatile_counter++;  /* ❌ Race condition! */
    }
    return 0;  /* ✅ C11 threads return int */
}

/* Thread function using atomics (CORRECT!) */
int atomic_thread_func(void* arg) {
    int iterations = *(int*)arg;
    for (int i = 0; i < iterations; i++) {
        atomic_fetch_add(&atomic_counter, 1);  /* ✅ Thread-safe */
    }
    return 0;  /* ✅ C11 threads return int */
}

void demonstrate_thread_warning(void) {
    printf("\n=== 6. volatile Does NOT Sync Threads! (LIVE TEST) ===\n");
    
    const int NUM_THREADS = 4;
    const int ITERATIONS = 10000;
    const int EXPECTED = NUM_THREADS * ITERATIONS;
    
    thrd_t threads[NUM_THREADS];
    int iterations = ITERATIONS;
    
    /* --- Test 1: volatile (WRONG!) --- */
    printf("\n--- Test 1: volatile counter (WRONG!) ---\n");
    volatile_counter = 0;
    
    printf("Starting %d threads, %d iterations each...\n", NUM_THREADS, ITERATIONS);
    printf("Expected final value: %d\n\n", EXPECTED);
    
    for (int i = 0; i < NUM_THREADS; i++) {
        thrd_create(&threads[i], volatile_thread_func, &iterations);
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        thrd_join(threads[i], NULL);
    }
    
    printf("volatile_counter = %d\n", volatile_counter);
    if (volatile_counter == EXPECTED) {
        printf("  ✓ Got expected value (lucky!)\n");
    } else {
        printf("  ✗ RACE CONDITION! Lost %d updates\n", EXPECTED - volatile_counter);
    }
    
    /* --- Test 2: atomics (CORRECT!) --- */
    printf("\n--- Test 2: atomic counter (CORRECT!) ---\n");
    atomic_store(&atomic_counter, 0);
    
    for (int i = 0; i < NUM_THREADS; i++) {
        thrd_create(&threads[i], atomic_thread_func, &iterations);
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        thrd_join(threads[i], NULL);
    }
    
    int final_value = atomic_load(&atomic_counter);
    printf("atomic_counter   = %d\n", final_value);
    if (final_value == EXPECTED) {
        printf("  ✓ Perfect! All updates counted\n");
    } else {
        printf("  ✗ Unexpected error (shouldn't happen!)\n");
    }
    
    /* --- Summary --- */
    printf("\n--- CONCLUSION ---\n");
    printf("volatile: %d / %d (%.1f%% accuracy)\n", 
           volatile_counter, EXPECTED, 
           (volatile_counter * 100.0) / EXPECTED);
    printf("atomic:   %d / %d (%.1f%% accuracy)\n", 
           final_value, EXPECTED,
           (final_value * 100.0) / EXPECTED);
    printf("\n⚠️  volatile is NOT for thread synchronization!\n");
    printf("   Use <stdatomic.h> or mutexes instead.\n");
}


/* =============================================================================
 * Main Function
 * =============================================================================
 */
int main(void) {
    printf("========================================\n");
    printf("  volatile in C\n");
    printf("========================================\n");
    
    demonstrate_optimization_prevention();
    demonstrate_memory_mapped_io();
    demonstrate_signal_handler();
    demonstrate_realtime_clock();
    demonstrate_const_volatile();
    demonstrate_thread_warning();
    
    printf("\n========================================\n");
    printf("  Key Takeaways\n");
    printf("========================================\n");
    printf("  ✓ volatile prevents optimization\n");
    printf("  ✓ Use for: I/O, signals, setjmp, hardware\n");
    printf("  ✓ Every read/write occurs exactly once\n");
    printf("  ✓ Order of accesses is preserved\n");
    printf("  ✗ NOT for thread synchronization!\n");
    printf("  ✗ Use atomics/mutexes for threads\n");
    printf("  ✓ Compile with -O2 to see optimization effects\n");
    
    return 0;
}

/*
 * =============================================================================
 * volatile Quick Reference
 * =============================================================================
 * 
 * WHEN TO USE volatile:
 * ---------------------
 * ✓ Memory-mapped I/O registers
 * ✓ Variables modified by signal handlers
 * ✓ Variables accessed by setjmp/longjmp
 * ✓ Hardware counters/timers
 * ✓ Shared memory with external processes
 * 
 * WHEN NOT TO USE volatile:
 * -------------------------
 * ✗ Thread synchronization (use atomics/mutexes)
 * ✗ Inter-thread communication (use atomics)
 * ✗ Performance optimization (it DISABLES optimizations!)
 * 
 * COMMON PATTERNS:
 * ----------------
 * volatile int reg;              // R/W hardware register
 * const volatile int status;     // Read-only hardware status
 * volatile sig_atomic_t flag;    // Signal handler flag
 * 
 * COMPILATION:
 * ------------
 * gcc -O2 -o volatile_demo volatile_demo.c
 *   (-O2 enables optimizations that volatile prevents)
 */