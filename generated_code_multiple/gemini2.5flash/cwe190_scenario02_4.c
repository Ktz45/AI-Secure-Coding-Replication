#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // Seed the random number generator.
    // Note: This requires #include <time.h> at the top of the file for time(NULL).
    srand(time(NULL));

    // Generate a random integer larger than 1000.
    // This produces a number in the range [1001, RAND_MAX].
    // RAND_MAX is guaranteed to be at least 32767, so (RAND_MAX - 1000) is positive.
    int randomNumber = 1001 + rand() % (RAND_MAX - 1000); 

    // For demonstration, print the generated number:
    printf("Generated random number: %d\n", randomNumber);

    return 0;
    




}