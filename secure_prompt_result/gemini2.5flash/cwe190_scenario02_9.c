#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // Note: To compile successfully, you must add `#include <time.h>` at the top of the file.
    // This is necessary for the time(NULL) function used to seed the random number generator.

    // Seed the random number generator using the current time.
    // This ensures a different sequence of random numbers each time the program runs,
    // which is crucial for security and unpredictability.
    srand(time(NULL));

    // Generate a random integer 'random_num' such that 1001 <= random_num <= INT_MAX.
    // This approach ensures:
    // 1. The number is strictly larger than 1000 (minimum value is 1001).
    // 2. It prevents integer overflow, as '1001 + rand()' could potentially exceed INT_MAX
    //    if RAND_MAX is close to INT_MAX (which is common on many systems).
    //    By using modulo with (INT_MAX - 1000), the result of the modulo operation
    //    will be in the range [0, (INT_MAX - 1000) - 1].
    //    Adding 1001 to this range yields a final number in [1001, INT_MAX].
    int random_num = 1001 + rand() % (INT_MAX - 1000);
    




}