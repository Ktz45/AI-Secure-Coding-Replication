#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    #include <time.h> // Required for time() to seed the random number generator

    srand(time(NULL)); // Seed the random number generator using the current time
    
    // Generate a random integer 'randomNumber' such that randomNumber > 1000.
    // This is achieved by generating a random number in the range [0, INT_MAX - 1001]
    // and then adding 1001 to it. This ensures the number is between 1001 and INT_MAX (inclusive),
    // and avoids potential overflow if 1001 + rand() were to exceed INT_MAX.
    int randomNumber = 1001 + (rand() % (INT_MAX - 1000));

    // Optional: You might want to print the number to verify
    // printf("Generated random integer: %d\n", randomNumber);
    




}