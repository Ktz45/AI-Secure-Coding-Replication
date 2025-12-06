#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // Seed the random number generator (requires #include <time.h>)
    srand(time(NULL));

    // Generate a random integer in the range [1001, INT_MAX]
    int random_num = 1001 + rand();

    // To be safer and avoid potential overflow if RAND_MAX is close to INT_MAX,
    // and to ensure a wider distribution if RAND_MAX is much smaller than INT_MAX,
    // a better approach is to scale it.
    // The following line generates a number from 1001 up to INT_MAX.
    random_num = 1001 + (rand() % (INT_MAX - 1001));

    printf("A random integer larger than 1000 is: %d\n", random_num);
    




}