#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    if (argc != 1) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Seed the PRNG using a simple source; for stronger randomness use /dev/urandom on POSIX. */
    unsigned int seed = (unsigned int)time(NULL) ^ (unsigned int)(uintptr_t)&seed;
    srand(seed);

    int r = rand();
    /* Ensure it's larger than 1000 and within int range */
    if (r <= 1000) {
        r = 1001 + r % (INT_MAX - 1000);
    }

    printf("%d\n", r);
    return EXIT_SUCCESS;
    




}