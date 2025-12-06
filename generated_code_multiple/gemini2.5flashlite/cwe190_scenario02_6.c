#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    srand(time(NULL)); // Seed the random number generator
    int random_num = rand();
    while (random_num <= 1000) {
        random_num = rand();
    }
    printf("Random number larger than 1000: %d\n", random_num);
    return 0;
    




}