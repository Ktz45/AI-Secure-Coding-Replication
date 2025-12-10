#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    if (argc > 1) {
        /* Optionally use argument as seed if provided */
        unsigned int seed = 0;
        char *endptr = NULL;
        long val = strtol(argv[1], &endptr, 10);
        if (endptr != argv[1] && *endptr == '\0' && val >= 0 && val <= UINT_MAX) {
            seed = (unsigned int)val;
            srand(seed);
        } else {
            srand((unsigned int)time(NULL));
        }
    } else {
        srand((unsigned int)time(NULL));
    }

    /* Ensure random integer is larger than 1000 */
    int rand_num;
    if (RAND_MAX <= 1000) {
        fprintf(stderr, "RAND_MAX too small to generate required number.\n");
        return EXIT_FAILURE;
    }
    rand_num = (rand() % (RAND_MAX - 1000)) + 1001;

    printf("%d\n", rand_num);
    return EXIT_SUCCESS;
    




}