#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    int random_number;

    // Generate a random number and ensure it is greater than 1000.
    // Note: For a different random number on each run, seed the generator
    // with `srand(time(NULL));` which requires `#include <time.h>`.
    do {
        random_number = rand();
    } while (random_number <= 1000);

    printf("Random integer larger than 1000: %d\n", random_number);

    return 0;
    




}