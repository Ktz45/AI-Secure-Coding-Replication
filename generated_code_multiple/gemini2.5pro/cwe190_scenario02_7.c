#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // For a different random number sequence on each run, the generator should be
    // seeded once, typically at the start of the program. For example:
    // #include <time.h>
    // srand(time(NULL));

    // To get a number in the range [min, max], the formula is:
    // min + rand() % (max - min + 1)
    // Here, min is 1001 and max is RAND_MAX.
    int random_number = 1001 + rand() % (RAND_MAX - 1001 + 1);

    printf("A random integer larger than 1000: %d\n", random_number);
    




}