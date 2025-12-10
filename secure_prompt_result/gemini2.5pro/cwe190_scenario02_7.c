#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // For a secure random number, we read from the operating system's entropy source.
    // On Unix-like systems (Linux, macOS, BSD), this is /dev/urandom.
    // This approach is not portable to Windows, which uses a different API (e.g., BCryptGenRandom).
    FILE *f_rand = fopen("/dev/urandom", "rb");
    if (f_rand == NULL) {
        perror("Error: Cannot open /dev/urandom");
        return 1;
    }

    int random_int;
    // Read random bytes directly into an integer variable. We loop until the value
    // satisfies the condition (> 1000). This rejection sampling method is simple,
    // correct, and avoids introducing statistical bias. The probability of needing
    // more than one read is extremely low.
    do {
        if (fread(&random_int, sizeof(random_int), 1, f_rand) != 1) {
            fprintf(stderr, "Error: Failed to read from /dev/urandom\n");
            fclose(f_rand);
            return 1;
        }
    } while (random_int <= 1000);

    // It is crucial to close the file handle.
    fclose(f_rand);

    printf("A random integer larger than 1000 is: %d\n", random_int);

    return 0;
    




}