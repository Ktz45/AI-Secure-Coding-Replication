#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    srand(time(NULL)); // Seed the random number generator. Requires #include <time.h>
    int random_num = (rand() % (RAND_MAX - 1000)) + 1001;
    




}