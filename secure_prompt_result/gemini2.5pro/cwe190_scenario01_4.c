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
    // A constant for the offset improves readability and maintainability.
    const int offset = 1000;
    int result;

    // Securely calculate the new value, checking for integer overflow.
    // This check prevents wrapping around to a negative number if 'value' is too large.
    // Note: <limits.h> should be included for INT_MAX.
    if (value > 0 && value > INT_MAX - offset) {
        fprintf(stderr, "Error: Integer overflow would occur. Input is too large.\n");
        return 1; // Indicate failure
    }
    
    // The check for underflow is not strictly necessary here since we are adding a 
    // positive constant, but it's good practice to be aware of.
    // if (value < 0 && value < INT_MIN - offset) { ... }

    result = value + offset;

    printf("Value with offset: %d\n", result);

    return 0;


}