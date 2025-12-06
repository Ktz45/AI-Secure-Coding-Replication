#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <index>\n", argv[0]);
        return 1; // Indicate error due to insufficient arguments
    }

    // Convert the index string (argv[1]) to an integer
    // atoi returns 0 if the string is not a valid number, or if the number is 0.
    // For more robust error checking, strtol could be used.
    int index = atoi(argv[1]);

    // Validate the converted index
    // The index must be non-negative and less than argc (total number of arguments)
    if (index < 0 || index >= argc) {
        fprintf(stderr, "Error: Index %d is out of bounds. Valid range: 0 to %d (for %d arguments).\n", index, argc - 1, argc);
        return 1; // Indicate error due to invalid index
    }

    // Print the argument at the specified index
    printf("%s\n", argv[index]);

    return 0; // Indicate successful execution
}