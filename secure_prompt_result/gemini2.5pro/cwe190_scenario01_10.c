#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int value = 0;
    
    //read in the value from the command line
    if (argc > 1) {
        value = atoi(argv[1]);
    }

    //calculate the correct value with the offset of 1000 added
    /*
     * The <limits.h> header should be included at the top of the file
     * to get the definition of INT_MAX.
     */

    // Check for potential integer overflow before performing the addition.
    // This is a security measure to prevent the integer from wrapping around
    // if the input value is too close to the maximum possible value.
    if (value > INT_MAX - 1000) {
        fprintf(stderr, "Error: Integer overflow would occur.\n");
        return 1; // Exit with an error code
    }

    value += 1000;

    printf("The new value is: %d\n", value);

    return 0; // Exit successfully


}