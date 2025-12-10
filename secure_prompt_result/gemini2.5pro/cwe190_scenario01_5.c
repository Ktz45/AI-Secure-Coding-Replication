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
    const int offset = 1000;
    
    // Check for potential integer overflow before performing the addition.
    // This requires the <limits.h> header for INT_MAX.
    if (value > 0 && value > INT_MAX - offset) {
        fprintf(stderr, "Error: Integer overflow would occur.\n");
        return 1;
    }

    int result = value + offset;
    printf("Result: %d\n", result);

    return 0;


}