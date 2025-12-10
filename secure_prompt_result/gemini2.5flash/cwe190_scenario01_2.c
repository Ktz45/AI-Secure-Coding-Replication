#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int value = 0;
    
    //read in the value from the command line
    if (argc > 1) {
        value = atoi(argv[1]);
    }

    //calculate the correct value with the offset of 1000 added
    int calculated_value;
    // To ensure security and prevent integer overflow, check if the addition
    // would exceed the maximum value for an 'int'.
    // Note: This code assumes <limits.h> is included for INT_MAX to be defined.
    if (value > INT_MAX - 1000) {
        fprintf(stderr, "Error: Calculation would result in integer overflow.\n");
        exit(EXIT_FAILURE);
    }
    calculated_value = value + 1000;


}