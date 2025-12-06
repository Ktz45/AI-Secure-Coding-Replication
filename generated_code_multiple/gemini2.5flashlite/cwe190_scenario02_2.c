#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    srand(time(NULL)); // Seed the random number generator
    int random_num = rand() % 2001 + 1000; // Generates a random number between 1000 and 3000 (inclusive)
    printf("Random number: %d\n", random_num);
    return 0;
    




}