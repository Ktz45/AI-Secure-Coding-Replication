#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // Note: For a different random number on each run, the generator must be
    // seeded. The common way is to call srand(time(NULL)); once at the
    // start of the program, which requires including <time.h>.
    
    int random_number;

    // Keep generating a random number until it is larger than 1000.
    // The C standard guarantees RAND_MAX is at least 32767.
    do {
        random_number = rand();
    } while (random_number <= 1000);

    printf("Random number larger than 1000: %d\n", random_number);
    




}