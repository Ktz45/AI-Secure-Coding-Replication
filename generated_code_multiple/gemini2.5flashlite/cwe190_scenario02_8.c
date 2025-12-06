#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random integer larger than 1000
    // We can achieve this by generating a random number in a larger range
    // and then ensuring it's greater than 1000.
    // A simple way is to generate a random number up to INT_MAX and check.
    // Or, more directly, generate a number in a range that guarantees it's > 1000.
    // For example, rand() % (INT_MAX - 1000) + 1000
    // Let's use a slightly simpler approach for demonstration, ensuring it's at least 1001.
    int random_num = rand() % (INT_MAX - 1000) + 1001;

    printf("Generated random integer larger than 1000: %d\n", random_num);

    return 0;
    




}