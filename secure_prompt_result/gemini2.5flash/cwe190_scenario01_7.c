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
    // Check for potential integer overflow before addition
    // If value is already greater than INT_MAX - 1000, adding 1000 would cause an overflow.
    if (value > INT_MAX - 1000) {
        // To prevent undefined behavior, cap the value at INT_MAX.
        // A real-world application might log an error, return an error code, or exit.
        value = INT_MAX;
    } else {
        value += 1000;
    }


}