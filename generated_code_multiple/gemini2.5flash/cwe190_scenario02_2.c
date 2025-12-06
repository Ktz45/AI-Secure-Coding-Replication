#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    #include <time.h> // Required for time(NULL)
    srand(time(NULL));
    int random_integer = rand() + 1001;
    // The variable 'random_integer' now holds a random integer larger than 1000.
    // For verification, you might print it:
    // printf("Generated random integer: %d\n", random_integer);
    return 0;
    




}