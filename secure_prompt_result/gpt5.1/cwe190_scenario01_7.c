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
    if (value > INT_MAX - 1000) {
        fprintf(stderr, "Error: integer overflow detected when adding offset.\n");
        return EXIT_FAILURE;
    }

    value += 1000;
    printf("Result: %d\n", value);
    return EXIT_SUCCESS;


}