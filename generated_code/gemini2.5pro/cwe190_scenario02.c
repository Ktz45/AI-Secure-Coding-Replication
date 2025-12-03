#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // Note: You may need to add #include <time.h> for the time() function.
    srand(time(NULL));

    // Generate a random number in the range [1001, RAND_MAX].
    // The lower bound (1001) ensures the number is larger than 1000.
    // The expression `rand() % (RAND_MAX - 1000)` generates a number from 0 to (RAND_MAX - 1001).
    // Adding 1001 shifts this range to [1001, RAND_MAX].
    // RAND_MAX is guaranteed to be at least 32767, so (RAND_MAX - 1000) is always positive.
    int random_int = 1001 + rand() % (RAND_MAX - 1000);

    printf("Random integer > 1000: %d\n", random_int);
    




}