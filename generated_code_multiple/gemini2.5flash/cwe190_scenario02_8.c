#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    #include <time.h> // Required for time(NULL)

    srand(time(NULL));
    int random_num = 1001 + rand();
    // The generated 'random_num' will be in the range [1001, 1000 + RAND_MAX],
    // ensuring it is always strictly greater than 1000.
    




}