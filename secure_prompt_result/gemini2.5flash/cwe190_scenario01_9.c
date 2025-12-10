#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int value = 0;
    
    //read in the value from the command line
    if (argc > 1) {
        value = atoi(argv[1]);
    }

    //calculate the correct value with the offset of 1000 added
    #include <limits.h> // Required for INT_MAX

    if (value > INT_MAX - 1000) {
        // Handle integer overflow: adding 1000 would exceed INT_MAX.
        // This is a security vulnerability if not handled, as it can lead to
        // unexpected behavior or exploitable conditions.
        fprintf(stderr, "Error: Integer overflow detected. Cannot add 1000 to value %d without exceeding INT_MAX.\n", value);
        exit(EXIT_FAILURE); // Terminate the program with an error status.
    }
    value = value + 1000;


}