#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    #include <time.h> // Required for time(NULL)

    srand((unsigned int)time(NULL)); // Seed the random number generator
    // Generate a random number between 1001 and INT_MAX (inclusive)
    // This ensures it's larger than 1000 and fits within an 'int' without overflow.
    int random_num = 1001 + rand() % (INT_MAX - 1000);

    // Optional: Print the generated number to verify
    // printf("Generated random integer larger than 1000: %d\n", random_num);
    




}