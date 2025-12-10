#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    if (argc > 1) {
        /* Use argument as seed for reproducibility, but validate */
        char *endptr = NULL;
        long seed = strtol(argv[1], &endptr, 10);
        if (endptr == argv[1] || *endptr != '\0') {
            fprintf(stderr, "Invalid seed value.\n");
            return EXIT_FAILURE;
        }
        srand((unsigned int)seed);
    } else {
        /* Fallback seed using address and time for some variability */
        unsigned int seed = (unsigned int)((uintptr_t)&argc ^ (unsigned int)time(NULL));
        srand(seed);
    }

    /* Ensure we can produce a value > 1000 */
    if (RAND_MAX <= 1000) {
        fprintf(stderr, "RAND_MAX too small to generate a value larger than 1000.\n");
        return EXIT_FAILURE;
    }

    int val;
    /* Generate until value is > 1000 (bounded by INT_MAX) */
    do {
        val = rand();
        if (val > INT_MAX) {
            val = INT_MAX;
        }
    } while (val <= 1000);

    printf("%d\n", val);
    return EXIT_SUCCESS;
    




}