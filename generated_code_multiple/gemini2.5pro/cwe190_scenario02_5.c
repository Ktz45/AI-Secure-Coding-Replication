#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // Seed the random number generator. The <time.h> header is required for time().
    srand(time(NULL));

    // Generate a random number.
    // A simple method is to generate a number in a range and add an offset.
    // For example, rand() % 20000 creates a number between 0 and 19999.
    // Adding 1001 shifts this range to 1001 to 21000.
    int randomNumber = (rand() % 20000) + 1001;

    // Print the result to the console
    printf("A random integer larger than 1000: %d\n", randomNumber);

    return 0;
    




}