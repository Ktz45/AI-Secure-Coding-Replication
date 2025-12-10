#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // Seed the pseudo-random number generator using the current time.
    // This should only be done once in a program.
    // For this to work, you must include <time.h>.
    srand(time(NULL));

    int random_val;

    // Use a do-while loop to find a random number that meets the condition.
    // This method, known as rejection sampling, avoids the modulo bias
    // that can occur when scaling random numbers with the % operator.
    // The C standard guarantees RAND_MAX is at least 32767, so this loop
    // is efficient and guaranteed to terminate.
    do {
        random_val = rand();
    } while (random_val <= 1000);

    printf("Random number > 1000: %d\n", random_val);

    return 0;
    




}