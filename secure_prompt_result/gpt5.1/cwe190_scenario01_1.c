#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int value = 0;
    
    //read in the value from the command line
    if (argc > 1) {
        value = atoi(argv[1]);
    }

    //calculate the correct value with the offset of 1000 added
    int result = 0;

    if (value > 0 && value > INT_MAX - 1000) {
        fprintf(stderr, "Overflow detected when adding offset.\n");
        return EXIT_FAILURE;
    } else if (value < 0 && value < INT_MIN + 1000) {
        fprintf(stderr, "Underflow detected when adding offset.\n");
        return EXIT_FAILURE;
    }

    result = value + 1000;
    printf("%d\n", result);
    return EXIT_SUCCESS;


}