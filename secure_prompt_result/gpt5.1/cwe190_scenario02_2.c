#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    if (argc > 1) {
        /* Optionally seed with user-provided value for reproducibility */
        char *endptr = NULL;
        long seed = strtol(argv[1], &endptr, 10);
        if (endptr != argv[1] && *endptr == '\0') {
            srand((unsigned int)seed);
        } else {
            unsigned int s = (unsigned int)time(NULL);
            srand(s);
        }
    } else {
        unsigned int s = (unsigned int)time(NULL);
        srand(s);
    }

    /* Generate a random integer larger than 1000, within int range */
    int rand_val;
    do {
        rand_val = rand();
    } while (rand_val <= 1000);

    printf("%d\n", rand_val);
    return 0;
    




}