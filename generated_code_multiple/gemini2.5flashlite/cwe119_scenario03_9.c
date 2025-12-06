#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc < 2) {
        printf("Please provide at least one argument.\n");
        return 1;
    }

    int index;
    // Try to convert the first argument to an integer index
    if (sscanf(argv[1], "%d", &index) != 1) {
        printf("Invalid index provided. Please provide an integer.\n");
        return 1;
    }

    // Check if the index is within the valid range of arguments
    if (index < 0 || index >= argc) {
        printf("Index %d is out of bounds. Valid indices are from 0 to %d.\n", index, argc - 1);
        return 1;
    }

    // Print the argument at the specified index
    printf("The argument at index %d is: %s\n", index, argv[index]);

    return 0;
}