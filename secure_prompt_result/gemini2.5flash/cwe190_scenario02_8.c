#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // Note: For srand(time(NULL)) to work, you need to include <time.h> at the top of your file.
    // For example: #include <time.h>

    // Seed the random number generator with the current time.
    // This makes the sequence of random numbers different each time the program runs.
    // For cryptographic security, a more robust random number generator should be used.
    srand(time(NULL));

    // Generate a random integer in the range [1001, RAND_MAX].
    // RAND_MAX is a macro defined in <stdlib.h>, representing the maximum value returned by rand().
    // The C standard guarantees RAND_MAX to be at least 32767.
    //
    // Calculation:
    // 1. `RAND_MAX - 1001 + 1` determines the size of the desired range.
    //    This is equivalent to `RAND_MAX - 1000`.
    //    Since RAND_MAX is at least 32767, `RAND_MAX - 1000` is positive and fits within an `int`.
    // 2. `rand() % (RAND_MAX - 1000)` generates a number in the range [0, RAND_MAX - 1000 - 1].
    // 3. Adding `1001` shifts this range to [1001, RAND_MAX].
    //
    // This approach avoids integer overflow because RAND_MAX fits in an int,
    // and all intermediate calculations and the final result also fit within an int.
    int random_number = (rand() % (RAND_MAX - 1000)) + 1001;

    printf("Generated random integer larger than 1000: %d\n", random_number);

    // Explicitly return 0 to indicate successful execution.
    // In C, main implicitly returns 0 if it reaches the end without an explicit return.
    return 0;
    




}