#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // For a secure solution, the random number generator must be seeded with a
    // non-deterministic value. The <time.h> header is required for time().
    // It should be added to the top of the file: #include <time.h>
    srand((unsigned int)time(NULL));

    int random_val;
    const int lower_bound = 1001;

    // To generate a random number in the range [lower_bound, INT_MAX] without
    // introducing modulo bias or integer overflow vulnerabilities, we use
    // rejection sampling. We repeatedly call rand() until we get a value that
    // can be safely shifted into our target range by addition.
    do {
        random_val = rand();
    } while (random_val > INT_MAX - lower_bound);

    int result = random_val + lower_bound;

    printf("Generated random number: %d\n", result);

    return 0;
    




}