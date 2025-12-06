#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <index>\n", argv[0]);
        return 1; // Indicate an error: no index provided
    }

    char *endptr;
    long index_long = strtol(argv[1], &endptr, 10);

    // Check for conversion errors:
    // 1. No digits found (endptr == argv[1])
    // 2. Non-numeric characters followed the number (*endptr != '\0')
    if (endptr == argv[1] || *endptr != '\0') {
        fprintf(stderr, "Error: Invalid index format '%s'. Please provide a valid integer.\n", argv[1]);
        return 1;
    }

    // Check if the index is negative
    if (index_long < 0) {
        fprintf(stderr, "Error: Index cannot be negative.\n");
        return 1;
    }

    // Check if the index is out of bounds (greater than or equal to argc)
    // Since argc is an int, index_long can be directly compared.
    // If index_long is extremely large, it will still be >= argc.
    if (index_long >= argc) {
        fprintf(stderr, "Error: Index %ld is out of bounds. Valid range is 0 to %d.\n", index_long, argc - 1);
        return 1;
    }

    // If all checks pass, the index is valid. Cast to int and access argv.
    int index = (int)index_long;
    printf("%s\n", argv[index]);

    return 0; // Indicate success
}