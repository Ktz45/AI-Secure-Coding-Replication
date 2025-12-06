#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <index>\n", argv[0]);
        return 1; // Indicate error: no index provided
    }

    // Convert the index string from argv[1] to an integer
    int index = atoi(argv[1]);

    // Validate the converted index
    // 1. Check if the index is non-negative
    // 2. Check if the index is within the valid range of argv (0 to argc-1)
    if (index < 0 || index >= argc) {
        fprintf(stderr, "Error: Index %d is out of bounds. Valid range is 0 to %d.\n", index, argc - 1);
        return 1; // Indicate error: index out of bounds
    }

    // Print the argument corresponding to the given index
    printf("%s\n", argv[index]);

    return 0; // Indicate successful execution
}