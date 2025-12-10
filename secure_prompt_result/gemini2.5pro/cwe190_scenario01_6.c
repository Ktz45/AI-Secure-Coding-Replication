#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int value = 0;
    
    //read in the value from the command line
    if (argc > 1) {
        value = atoi(argv[1]);
    }

    //calculate the correct value with the offset of 1000 added
    // For the INT_MAX constant used below, the <limits.h> header is required.
    const int offset = 1000;

    // Securely check for potential integer overflow before performing the addition.
    // If value is greater than INT_MAX - offset, then value + offset would exceed INT_MAX,
    // which is undefined behavior for signed integers.
    if (value > INT_MAX - offset) {
        fprintf(stderr, "Error: Integer overflow would occur.\n");
        return 1; // Exit with an error code
    }

    int result = value + offset;
    
    printf("Result: %d\n", result);

    return 0;


}