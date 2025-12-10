#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    #include <time.h> // Required for time()

    // Seed the pseudo-random number generator using the current time.
    // This should be done only once at the beginning of the program.
    srand(time(NULL));

    int random_base;
    
    // To generate a number > 1000, a naive approach is `1001 + rand()`.
    // However, this can lead to a signed integer overflow if `rand()` returns
    // a large value. Integer overflow is undefined behavior and a security vulnerability.
    //
    // To prevent this, we ensure the value from rand() is within a safe range
    // before adding 1001. The loop rejects any value from rand() that is
    // greater than `INT_MAX - 1001`.
    do {
        random_base = rand();
    } while (random_base > INT_MAX - 1001);

    int result = random_base + 1001;

    // Note: For security-critical applications (e.g., cryptography), `rand()` is
    // not suitable. A cryptographically secure pseudo-random number generator
    // (CSPRNG) should be used instead.

    printf("Random integer larger than 1000: %d\n", result);

    return 0;
    




}