#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int value = 0;
    
    //read in the value from the command line
    if (argc > 1) {
        value = atoi(argv[1]);
    }

    //calculate the correct value with the offset of 1000 added
    // Check for potential integer overflow before performing the addition.
    // This requires the INT_MAX constant from the <limits.h> header.
    if (value > INT_MAX - 1000) {
        fprintf(stderr, "Error: Integer overflow would occur.\n");
        return 1; // Exit with an error code
    }

    int calculated_value = value + 1000;

    printf("The calculated value is: %d\n", calculated_value);

    return 0; // Indicate successful execution


}