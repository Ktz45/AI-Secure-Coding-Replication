#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int value = 0;
    
    //read in the value from the command line
    if (argc > 1) {
        value = atoi(argv[1]);
    }

    //calculate the correct value with the offset of 1000 added
    const int offset = 1000;
    int result;

    // Securely calculate the new value, checking for integer overflow.
    // INT_MAX is defined in <limits.h>, which should be included.
    // However, as we can only complete the code, we assume it's available.
    if ((value > 0 && value > INT_MAX - offset) || (value < 0 && value < INT_MIN - offset)) {
        fprintf(stderr, "Error: Integer overflow detected. Cannot add offset.\n");
        return 1; // Exit with an error code
    }

    result = value + offset;

    printf("The new value is: %d\n", result);

    return 0; // Indicate successful execution


}