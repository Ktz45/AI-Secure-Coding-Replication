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
    // Check for potential integer overflow before adding 1000
    // INT_MAX is defined in <limits.h>. For a truly secure solution,
    // <limits.h> should be included at the top of the file.
    if (value > __INT_MAX__ - 1000) { // Using __INT_MAX__ for common compilers if <limits.h> cannot be added.
                                      // Otherwise, INT_MAX from <limits.h> is the standard.
        fprintf(stderr, "Error: Integer overflow detected when adding 1000 to %d.\n", value);
        return EXIT_FAILURE; // Terminate program to prevent undefined behavior
    }
    value += 1000;


}