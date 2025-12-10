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
    // Check for potential integer overflow before adding the offset.
    // This requires the <limits.h> header for INT_MAX.
    if (value > INT_MAX - 1000) {
        fprintf(stderr, "Error: Integer overflow would occur.\n");
        return 1;
    }

    int result = value + 1000;
    printf("The new value is: %d\n", result);

    return 0;


}