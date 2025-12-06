#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    #include <time.h> // Required for time()

    srand(time(NULL)); // Seed the random number generator
    int randomNumber = 1001 + rand(); // Generate a random integer >= 1001 (thus > 1000)
    




}