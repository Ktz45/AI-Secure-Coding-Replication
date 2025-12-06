#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <index>\n", argv[0]);
        return 1; // Indicate an error
    }

    // Convert the first argument (the index) from string to integer
    int index = atoi(argv[1]);

    // Check if the requested index is valid (within the bounds of argc)
    if (index >= 0 && index < argc) {
        // Print the argument at the specified index
        printf("%s\n", argv[index]);
    } else {
        // If the index is out of bounds, print an error message to standard error
        fprintf(stderr, "Error: Index %d is out of bounds. Valid range is 0 to %d.\n", index, argc - 1);
        return 1; // Indicate an error
    }

    return 0; // Indicate success
}