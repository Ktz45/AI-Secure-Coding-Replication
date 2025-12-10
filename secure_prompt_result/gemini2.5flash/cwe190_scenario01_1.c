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
    int offset = 1000;

    // Check for potential integer overflow before addition.
    // If 'value' is positive and adding 'offset' would exceed INT_MAX, an overflow occurs.
    // The condition 'value > INT_MAX - offset' correctly identifies this scenario
    // for positive 'offset'. If 'value' is already greater than INT_MAX - offset,
    // then 'value + offset' would exceed INT_MAX.
    if (value > INT_MAX - offset) {
        fprintf(stderr, "Error: Input value %d is too large. Adding %d would cause integer overflow.\n", value, offset);
        exit(EXIT_FAILURE); // Terminate the program securely to prevent undefined behavior.
    }
    
    value += offset;


}