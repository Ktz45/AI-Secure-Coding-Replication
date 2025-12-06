#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // You will need to add #include <time.h> to the top of the file
    srand(time(NULL));

    int randomNumber;

    // Keep generating random numbers until we get one that is > 1000
    do {
        randomNumber = rand();
    } while (randomNumber <= 1000);

    printf("Random number larger than 1000: %d\n", randomNumber);
    




}