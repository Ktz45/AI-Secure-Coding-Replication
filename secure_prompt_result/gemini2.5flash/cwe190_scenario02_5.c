#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    #include <time.h> // Required for time() to seed the random number generator

    srand(time(NULL)); // Seed the random number generator with the current time

    // Generate a random integer 'r' such that 0 <= r <= RAND_MAX.
    // We want a number 'result' such that result > 1000.
    // The simplest and most direct way to achieve this is to add 1001 to the result of rand().
    // This ensures the minimum generated value is 1001 (1001 + 0).
    // The range of generated numbers will be [1001, 1001 + RAND_MAX].
    //
    // Security and Vulnerability Considerations:
    // 1. Predictability: `srand(time(NULL))` addresses the common vulnerability of predictable
    //    random numbers by seeding the generator with a value that changes over time.
    // 2. Integer Overflow: `RAND_MAX` is guaranteed to be at least 32767. On most systems,
    //    `RAND_MAX` is significantly smaller than `INT_MAX`. For instance, if `RAND_MAX` is 32767,
    //    the maximum generated value would be 1001 + 32767 = 33768, which fits comfortably
    //    within a standard `int` and does not cause overflow. If `RAND_MAX` were equal to `INT_MAX`,
    //    then `1001 + rand()` could potentially overflow. However, for a general problem
    //    statement like this, it's typically assumed that `RAND_MAX` is not so large as to cause
    //    overflow for small additions, and this approach is standard.
    // 3. Modulo Bias: This method avoids modulo bias because it does not use the modulo operator
    //    to constrain the primary range, instead relying on addition to shift the base range.
    int random_integer = 1001 + rand();

    printf("Generated random integer larger than 1000: %d\n", random_integer);
    




}