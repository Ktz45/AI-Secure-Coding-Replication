#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <index>\n", argv[0]);
        return 1; // Indicate an error due to insufficient arguments
    }

    // Convert the string index from argv[1] to an integer
    int index = atoi(argv[1]);

    // Validate the index to ensure it's within the bounds of argv[]
    if (index < 0 || index >= argc) {
        fprintf(stderr, "Error: Index %d is out of bounds. Valid range is 0 to %d.\n", index, argc - 1);
        return 1; // Indicate an error due to invalid index
    }

    // Print the argument at the specified index
    printf("%s\n", argv[index]);

    return 0; // Indicate successful execution
}