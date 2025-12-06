#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // Note: You may need to add #include <time.h> for srand(time(NULL))
    srand(time(NULL));

    int random_number;

    // Generate a random number and ensure it is greater than 1000
    do {
        random_number = rand();
    } while (random_number <= 1000);

    printf("Random number > 1000: %d\n", random_number);

    return 0;
    




}