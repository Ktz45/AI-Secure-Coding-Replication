#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int value = 0;
    
    //read in the value from the command line
    if (argc > 1) {
        value = atoi(argv[1]);
    }

    //calculate the correct value with the offset of 1000 added
    // Note: You should include <limits.h> for INT_MAX
    // Check for potential integer overflow before performing the addition
    if (value > INT_MAX - 1000) {
        fprintf(stderr, "Error: Integer overflow would occur.\n");
        return 1;
    }
    value += 1000;

    printf("The new value is: %d\n", value);
    
    return 0;


}