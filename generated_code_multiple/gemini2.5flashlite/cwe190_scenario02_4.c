#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random integer larger than 1000
    // We can do this by generating a random number within a larger range
    // and then adding an offset.
    // For example, generate a random number between 0 and RAND_MAX,
    // and then ensure it's greater than 1000.
    int random_num = rand();
    if (random_num <= 1000) {
        // If it's not greater than 1000, add a value to make it so.
        // The maximum possible value for rand() is RAND_MAX.
        // We want to ensure it's at least 1001.
        // A simple way is to scale it or add a large offset.
        // Let's generate a number in a range that guarantees it's > 1000.
        // For instance, generate a number between 1001 and RAND_MAX.
        random_num = (rand() % (RAND_MAX - 1000)) + 1001;
    }

    printf("Generated random integer larger than 1000: %d\n", random_num);

    return 0;
    




}