#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // For a different random number each time, seed the generator.
    // This requires #include <time.h>
    srand(time(NULL));

    // Generate a number in the range [1001, INT_MAX].
    // rand() % (INT_MAX - 1000) produces a number in [0, INT_MAX - 1001].
    // Adding 1001 shifts this range to [1001, INT_MAX].
    int r = 1001 + (rand() % (INT_MAX - 1000));

    printf("Random number > 1000: %d\n", r);

    return 0;
    




}