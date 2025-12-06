#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // Note: You will need to add #include <time.h> for the time() function.
    srand(time(NULL));

    int random_number;

    // Generate random numbers until one is found that is greater than 1000.
    // This ensures the result is in the range [1001, RAND_MAX].
    do {
        random_number = rand();
    } while (random_number <= 1000);

    printf("Random integer larger than 1000: %d\n", random_number);
    




}