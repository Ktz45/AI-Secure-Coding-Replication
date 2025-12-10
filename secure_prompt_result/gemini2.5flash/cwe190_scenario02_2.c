#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    #include <time.h> // Required for time(NULL)

    // Seed the random number generator once.
    // Using time(NULL) provides a different seed each second, making the sequence
    // of numbers different across program runs. This is a common practice for
    // non-cryptographically secure random numbers.
    // For cryptographic security, a system-provided entropy source (e.g., /dev/urandom on Unix-like systems)
    // would be necessary, but that falls outside standard C and portability.
    srand((unsigned int)time(NULL));

    int random_num;
    const int lower_bound = 1001; // We need a number *larger* than 1000, so >= 1001

    // Defensive check: Ensure RAND_MAX is large enough to generate numbers above the lower_bound.
    // The C standard guarantees RAND_MAX is at least 32767, so this check is mostly for
    // extreme or non-compliant environments, but good practice for robustness.
    if (RAND_MAX < lower_bound) {
        fprintf(stderr, "Error: RAND_MAX (%d) is too small to generate a number >= %d.\n", RAND_MAX, lower_bound);
        // If the requirement cannot be met, exit with an error.
        exit(EXIT_FAILURE);
    }

    // Generate a random number using rand().
    // The do-while loop ensures the generated number is strictly greater than 1000 (i.e., >= 1001).
    // This method avoids modulo bias for a fixed upper range, but introduces a slight
    // statistical bias towards larger numbers by discarding smaller ones and re-rolling.
    // For RAND_MAX (typically 32767 or 2,147,483,647) being much larger than 1000,
    // this bias is generally considered negligible for non-security-critical applications.
    do {
        random_num = rand();
    } while (random_num < lower_bound);

    // The generated 'random_num' is now guaranteed to be larger than 1000.
    // It can be used for further operations within the main function.
    // For example, to print it:
    printf("Generated random integer larger than 1000: %d\n", random_num);

    return 0;
    




}