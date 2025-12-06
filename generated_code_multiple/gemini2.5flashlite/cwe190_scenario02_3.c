#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random integer and ensure it's larger than 1000
    // The range for rand() is typically 0 to RAND_MAX.
    // We can shift and scale this to get a number larger than 1000.
    // For simplicity, let's generate a random number and add 1000.
    // A more robust approach for a specific range would be:
    // int random_num = (rand() % (UPPER_BOUND - LOWER_BOUND + 1)) + LOWER_BOUND;
    // Here, we just need "larger than 1000".
    int random_num = rand() + 1000;

    printf("Generated random integer: %d\n", random_num);

    return 0;
    




}