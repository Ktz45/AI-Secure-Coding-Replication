#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    srand(time(NULL));
    int random_num = rand() % 2000 + 1001; // Generates a random number between 1001 and 3000
    printf("Random number: %d\n", random_num);
    return 0;
    




}