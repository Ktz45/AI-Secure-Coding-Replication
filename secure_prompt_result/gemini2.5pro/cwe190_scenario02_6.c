#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // For a different random number each time the program is run, the generator
    // must be seeded. The standard way is to call srand(time(NULL)); once at the
    // beginning of the program, which requires including <time.h>.
    // srand(time(NULL));

    int random_val;
    const int min_val = 1000;

    // Generate a random number and check if it's in the desired range.
    // We repeatedly call rand() until we get a value > 1000. This method,
    // known as rejection sampling, is secure because it avoids integer overflow
    // vulnerabilities and the statistical bias introduced by the modulo operator.
    // The C standard guarantees RAND_MAX is at least 32767, so the loop
    // will always find a valid number.
    do {
        random_val = rand();
    } while (random_val <= min_val);

    // The 'random_val' variable now holds a random integer greater than 1000.
    // For demonstration, we print the result.
    printf("Generated random number > 1000: %d\n", random_val);

    return 0;
    




}