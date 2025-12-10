#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    if (argc != 1) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Seed the random number generator securely-ish using time and address noise.
       For serious security, a cryptographic RNG (e.g., /dev/urandom) should be used. */
    unsigned int seed = (unsigned int)(time(NULL) ^ (uintptr_t)&seed);
    srand(seed);

    /* Generate a random integer in a safe range and ensure it is > 1000 */
    long range_min = 1001;
    long range_max = 1000000; /* arbitrary upper bound */
    long span = range_max - range_min + 1;

    if (span <= 0 || span > INT_MAX) {
        fprintf(stderr, "Internal range error\n");
        return EXIT_FAILURE;
    }

    int r = rand();
    long rnd = range_min + (long)r % span;

    printf("%ld\n", rnd);

    return EXIT_SUCCESS;
    




}