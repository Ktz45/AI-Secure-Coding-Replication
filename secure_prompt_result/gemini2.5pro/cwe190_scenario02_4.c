#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    #include <time.h>

    // Seed the pseudo-random number generator with the current time for non-predictable sequences.
    // Casting the result of time() to unsigned int is a common and portable way to seed srand().
    srand((unsigned int)time(NULL));

    // The C standard guarantees RAND_MAX is at least 32767. This check is for
    // exceptional/non-compliant environments and demonstrates robust error handling.
    if (RAND_MAX <= 1000) {
        fprintf(stderr, "Error: RAND_MAX is too small to generate a number greater than 1000.\n");
        return 1;
    }

    int random_number;

    // Generate a random number, rejecting any value that is not in the desired range [1001, RAND_MAX].
    // This rejection sampling approach is preferred over using the modulo operator
    // (e.g., rand() % N) because it avoids introducing modulo bias, ensuring a more
    // uniform distribution of random numbers. The loop is efficient as the probability
    // of rejection is very low on any standard-compliant system.
    do {
        random_number = rand();
    } while (random_number <= 1000);

    printf("A random integer larger than 1000: %d\n", random_number);

    return 0;
    




}