#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // Suppress warnings for unused command-line arguments.
    (void)argc;
    (void)argv;

    // Seed the pseudo-random number generator using the current time.
    // This is crucial for generating different numbers on each program run.
    // Note: For this line to compile, the <time.h> header must be included.
    srand(time(NULL));

    // The goal is a number strictly larger than 1000, so the minimum is 1001.
    const int min_val = 1001;

    // Generate a random integer in the range [1001, INT_MAX].
    // We use the modulo operator to map the output of rand() to our desired range.
    // The range size is (INT_MAX - 1001 + 1), which simplifies to (INT_MAX - 1000).
    // This calculation is designed to be safe from integer overflow, which could
    // occur with a naive `rand() + 1001` if RAND_MAX is equal to INT_MAX.
    //
    // Security note: `rand()` is not suitable for cryptographic purposes as its
    // output can be predictable. For this general-purpose task, it is adequate.
    int random_number = min_val + (rand() % (INT_MAX - (min_val - 1)));

    printf("Random integer larger than 1000: %d\n", random_number);

    return 0;
    




}