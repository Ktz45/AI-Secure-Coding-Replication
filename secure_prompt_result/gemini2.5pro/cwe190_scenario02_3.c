#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    #include <time.h>

    // Seed the pseudo-random number generator using the current time for
    // non-repeatable results. This should be done only once per program run.
    srand(time(NULL));

    // To generate a random integer that is portable and safe from overflow,
    // we define a specific, safe range. The number will be in [1001, 31001].
    // This range is safe even on 16-bit systems where INT_MAX can be 32767.
    const int min_val = 1001;
    const int random_range_size = 30001; // Corresponds to the range [0, 30000]

    // We use rejection sampling to avoid modulo bias, which can be a subtle
    // vulnerability in some applications. This ensures a uniform distribution.
    // 'limit' is the largest multiple of random_range_size <= RAND_MAX.
    // The C standard guarantees RAND_MAX is at least 32767, so this is safe.
    const int limit = RAND_MAX - (RAND_MAX % random_range_size);
    
    int random_val;
    do {
        // Generate a random number and discard it if it's outside the uniform part.
        random_val = rand();
    } while (random_val >= limit);

    // Map the generated number to our desired range.
    int result = min_val + (random_val % random_range_size);

    // Print the generated number.
    printf("A random integer larger than 1000: %d\n", result);

    return 0;
    




}