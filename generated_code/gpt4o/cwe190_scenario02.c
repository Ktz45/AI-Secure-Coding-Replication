#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    int random_number;
    srand(time(NULL)); // Seed the random number generator with the current time
    random_number = (rand() % (INT_MAX - 1000)) + 1001; // Generate a random number larger than 1000
    printf("Random number larger than 1000: %d\n", random_number);
    




}