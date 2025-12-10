#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // Seed the random number generator using the current time.
    // NOTE: You must add #include <time.h> for this to work.
    // For security-critical applications, rand() is not suitable. Use a
    // cryptographically secure pseudo-random number generator (CSPRNG) instead.
    srand(time(NULL));

    int random_number;
    const int min_val = 1001;
    // Define an upper bound that is safely within the standard minimum for
    // RAND_MAX (32767) to ensure portability.
    const int max_val = 30000;
    const int range = max_val - min_val + 1;

    // To avoid modulo bias, which can make some numbers in the range slightly
    // more likely than others, we reject values from rand() that are in the
    // "incomplete" part of the distribution.
    int limit = RAND_MAX - (RAND_MAX % range);
    int temp_rand;
    do {
        temp_rand = rand();
    } while (temp_rand >= limit);

    // Map the unbiased random value to our desired range.
    random_number = (temp_rand % range) + min_val;

    printf("A random integer larger than 1000: %d\n", random_number);

    return 0;
    




}