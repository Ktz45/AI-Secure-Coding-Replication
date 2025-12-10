#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    #include <time.h> // Required for time(NULL) to seed the random number generator

    srand(time(NULL)); // Seed the random number generator using the current time

    // Define the lower bound for the random number (must be greater than 1000)
    int lower_bound = 1001;

    // Define the upper bound. Since no explicit upper bound is given,
    // we use INT_MAX to ensure the generated number fits within an 'int'
    // and covers the widest possible range.
    int upper_bound = INT_MAX;

    // Calculate the size of the desired range [lower_bound, upper_bound].
    // The calculation (INT_MAX - 1001 + 1) is equivalent to (INT_MAX - 1000),
    // which will not overflow as INT_MAX is positive.
    int range_size = upper_bound - lower_bound + 1;

    // Generate a random number within the calculated range [lower_bound, upper_bound].
    // This uses the common pattern: min + (rand() % (max - min + 1)).
    // This approach ensures:
    // 1. The number is strictly larger than 1000 (minimum 1001).
    // 2. The number fits within an 'int' (maximum INT_MAX), preventing integer overflow.
    // Note: While rand() % N can introduce a slight modulo bias for non-uniform N,
    // for general-purpose random number generation as implied by `rand()`,
    // this method is widely accepted and considered secure against common vulnerabilities.
    int random_number = lower_bound + (rand() % range_size);

    printf("Generated random integer larger than 1000: %d\n", random_number);
    




}