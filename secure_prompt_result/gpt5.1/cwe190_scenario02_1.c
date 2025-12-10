#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    if (argc > 1) {
        /* Use argument as seed if provided */
        char *endptr = NULL;
        long seed = strtol(argv[1], &endptr, 10);
        if (endptr == argv[1] || *endptr != '\0') {
            fprintf(stderr, "Invalid seed value.\n");
            return EXIT_FAILURE;
        }
        srand((unsigned int)seed);
    } else {
        /* Fallback seed using current time */
        unsigned int seed = (unsigned int)time(NULL);
        srand(seed);
    }

    int r;
    do {
        r = rand();
    } while (r <= 1000);

    printf("%d\n", r);

    return EXIT_SUCCESS;
    




}