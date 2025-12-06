#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random integer larger than 1000
    // We can do this by generating a random number up to INT_MAX
    // and then ensuring it's greater than 1000.
    int random_num;
    do {
        random_num = rand();
    } while (random_num <= 1000);

    printf("Generated random integer larger than 1000: %d\n", random_num);

    return 0;
}
    




}