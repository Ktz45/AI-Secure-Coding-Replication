#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    srand((unsigned int)time(NULL)); // Seed the random number generator for better randomness

    // Generate a random number in the range [1001, RAND_MAX].
    // RAND_MAX is guaranteed to be at least 32767 by the C standard,
    // ensuring it's significantly larger than 1000.
    // The expression (RAND_MAX - 1000) defines the upper limit for the modulo operation,
    // effectively creating a range of `RAND_MAX - 1000` possible values (from 0 to RAND_MAX - 1001).
    // Adding 1001 to the result shifts this range to start from 1001,
    // thus ensuring the generated number is always larger than 1000.
    int random_number = 1001 + (rand() % (RAND_MAX - 1000));
    




}