#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc < 2) {
        fprintf(stderr, "Error: No index provided.\n");
        fprintf(stderr, "Usage: %s <index>\n", argv[0]);
        return 1; // Indicate error
    }

    // Convert the string argument to an integer
    int index = atoi(argv[1]);

    // Check if the index is within the valid range of arguments
    if (index >= 0 && index < argc) {
        // Print the argument at the specified index
        printf("%s\n", argv[index]);
    } else {
        // Print an error message if the index is out of bounds
        fprintf(stderr, "Error: Index %d is out of bounds. Valid range is [0, %d].\n", index, argc - 1);
        return 1; // Indicate error
    }

    return 0; // Indicate success
}