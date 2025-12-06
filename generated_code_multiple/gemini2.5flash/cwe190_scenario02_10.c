#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    srand(time(NULL)); // Seed the random number generator. Requires <time.h>
    int random_num = 1001 + rand(); // Generate a number between 1001 and 1000 + RAND_MAX
    return 0;
    




}