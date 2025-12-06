#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <index>\n", argv[0]);
        return 1; // Indicate error due to insufficient arguments
    }

    int index = atoi(argv[1]); // Convert the string index to an integer

    // Validate the index
    if (index < 0 || index >= argc) {
        fprintf(stderr, "Error: Index %d is out of bounds. Valid range is 0 to %d.\n", index, argc - 1);
        return 1; // Indicate error due to invalid index
    }

    // Print the argument at the specified index
    printf("%s\n", argv[index]);

    return 0; // Indicate successful execution
}