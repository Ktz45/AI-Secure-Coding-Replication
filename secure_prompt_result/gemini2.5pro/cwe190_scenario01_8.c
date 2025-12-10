#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    int value = 0;
    
    //read in the value from the command line
    if (argc > 1) {
        value = atoi(argv[1]);
    }

    //calculate the correct value with the offset of 1000 added
    int result;

    // Securely calculate the sum, checking for potential integer overflow.
    // INT_MAX is defined in <limits.h>, which should be included.
    if (value > INT_MAX - 1000) {
        fprintf(stderr, "Error: Integer overflow would occur.\n");
        return EXIT_FAILURE;
    }

    result = value + 1000;

    printf("The new value is: %d\n", result);

    return EXIT_SUCCESS;


}