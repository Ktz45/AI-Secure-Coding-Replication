#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    #include <time.h> // Required for time() to seed the random number generator

    // Seed the random number generator using the current time.
    // This helps ensure different sequences of random numbers are generated each time the program runs.
    srand(time(NULL));

    // Generate a random integer and add 1001 to it.
    // This guarantees the number is larger than 1000 (minimum value will be 0 + 1001 = 1001).
    // The range of the generated number will be [1001, RAND_MAX + 1001].
    // This method avoids common pitfalls like modulo bias when generating numbers within a specific range,
    // and integer overflow is not a concern as RAND_MAX (minimum 32767) plus 1001
    // will comfortably fit within a standard `int` (typically up to 2,147,483,647).
    int randomNumber = rand() + 1001;

    // The generated 'randomNumber' now holds an integer larger than 1000.
    // If you need to use this number, you can do so here.
    // For example, to print it:
    // printf("Generated random number larger than 1000: %d\n", randomNumber);

    return 0;
    




}