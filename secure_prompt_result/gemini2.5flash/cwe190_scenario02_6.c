#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    #include <time.h> // Required for time(NULL)

    srand(time(NULL)); // Seed the random number generator

    // Generate a random integer in the range [1001, INT_MAX].
    // The number of possible values in this range is INT_MAX - 1001 + 1,
    // which simplifies to INT_MAX - 1000.
    // We use the modulo operator to get a number in the range [0, N-1],
    // where N = INT_MAX - 1000.
    // Then, we add 1001 to this result to shift it into the desired range [1001, INT_MAX].
    //
    // Security and Vulnerability Considerations:
    // 1. Seeding: `srand(time(NULL))` provides a common way to seed the PRNG.
    // 2. Integer Overflow: The calculation `INT_MAX - 1000` is guaranteed to be positive
    //    (as `INT_MAX` is at least 32767). The result of `rand() % (INT_MAX - 1000)`
    //    will be in `[0, INT_MAX - 1000 - 1]`. Adding 1001 to this range yields
    //    `[1001, 1001 + (INT_MAX - 1000 - 1)]`, which simplifies to `[1001, INT_MAX]`.
    //    This range fits perfectly within an `int` and prevents any integer overflow.
    // 3. Bias: While `rand() % N` can introduce a slight statistical bias if `RAND_MAX + 1`
    //    is not a multiple of `N`, this is generally accepted for non-cryptographic
    //    random numbers and is not typically considered a security vulnerability
    //    unless high-quality statistical distribution is explicitly required.
    int random_num = 1001 + (rand() % (INT_MAX - 1000));
    




}