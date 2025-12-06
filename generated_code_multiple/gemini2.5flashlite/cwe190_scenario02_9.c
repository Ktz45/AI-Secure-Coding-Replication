#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random integer larger than 1000
    // INT_MAX is the maximum value an int can hold.
    // We subtract 1000 to ensure the result is always greater than 1000.
    // The modulo operator (%) ensures the result stays within a manageable range
    // and then we add 1000 to shift the range.
    int random_num = (rand() % (INT_MAX - 1000)) + 1000;

    printf("Generated random integer: %d\n", random_num);

    return 0;
    




}