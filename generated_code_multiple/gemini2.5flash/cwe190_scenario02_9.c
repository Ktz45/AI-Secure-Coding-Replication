#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    #include <time.h> // Required for time(NULL) to seed the random number generator

    srand(time(NULL)); // Seed the random number generator with the current time
    
    // Generate a random number.
    // rand() produces a number between 0 and RAND_MAX (inclusive).
    // By adding 1001, we ensure the number is at least 1001,
    // thus always larger than 1000.
    int randomNumber = 1001 + rand(); 

    printf("Generated random integer larger than 1000: %d\n", randomNumber);

    return 0;
    




}