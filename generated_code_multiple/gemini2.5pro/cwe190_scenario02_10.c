#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // Seed the random number generator. Note: this requires adding #include <time.h>
    srand(time(NULL));

    // Generate a random number and add 1001 to ensure the result is > 1000.
    // We can use the modulo operator to keep the number within a specific range
    // and prevent potential integer overflow.
    // This example generates a number between 1001 and 31000.
    int random_num = 1001 + (rand() % 30000);

    // Print the generated number
    printf("Random number > 1000: %d\n", random_num);
    




}