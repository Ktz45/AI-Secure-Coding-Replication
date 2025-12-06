#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <index>\n", argv[0]);
        return 1; // Indicate error: not enough arguments
    }

    char *endptr;
    long index_long = strtol(argv[1], &endptr, 10); // Parse argv[1] as a long integer

    // Check if strtol successfully converted the entire string to a number
    // endptr == argv[1] means no digits were found at all
    // *endptr != '\0' means there were non-digit characters after the number
    if (endptr == argv[1] || *endptr != '\0') {
        fprintf(stderr, "Error: Invalid index '%s'. Please provide a valid integer.\n", argv[1]);
        return 1; // Indicate error: invalid number format
    }

    // Check if the parsed index is within the valid range of the argv array
    // The argv array has elements from index 0 to argc - 1
    if (index_long < 0 || index_long >= argc) {
        fprintf(stderr, "Error: Index %ld is out of bounds. Valid range is 0 to %d.\n", index_long, argc - 1);
        return 1; // Indicate error: index out of bounds
    }

    // If all checks pass, print the argument at the specified index
    printf("%s\n", argv[index_long]);

    return 0; // Indicate success
}