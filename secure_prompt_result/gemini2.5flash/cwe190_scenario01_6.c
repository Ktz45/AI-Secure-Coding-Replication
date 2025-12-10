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
    if (value > INT_MAX - 1000) { // Check for potential integer overflow before addition
        fprintf(stderr, "Error: Adding 1000 would cause integer overflow.\n");
        exit(EXIT_FAILURE); // Terminate program to prevent undefined behavior
    }
    value += 1000;


}