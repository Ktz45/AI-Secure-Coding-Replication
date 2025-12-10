#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    #include <time.h> // Required for time() to seed the random number generator

    // Seed the random number generator using the current time.
    // This should ideally be called only once at the beginning of the program.
    srand(time(NULL));

    // Generate a random integer.
    // rand() produces a pseudo-random number between 0 and RAND_MAX (inclusive).
    // By adding 1001, we ensure the generated number is always greater than 1000 (i.e., >= 1001).
    // This operation is safe from integer overflow as RAND_MAX + 1001 will fit within an 'int'.
    int randomNumber = rand() + 1001;

    // The generated number is now stored in 'randomNumber'.
    // For demonstration purposes, you might want to print it:
    printf("Generated random integer larger than 1000: %d\n", randomNumber);
    




}