#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc <= 1) {
        printf("Please provide at least one argument.\n");
        return 1;
    }

    int index;
    // Try to convert argv[1] to an integer
    char *endptr;
    index = strtol(argv[1], &endptr, 10);

    // Check if the conversion was successful and if the index is valid
    if (*endptr != '\0' || index < 0 || index >= argc) {
        printf("Invalid index provided. Please provide a valid integer index within the range of arguments.\n");
        return 1;
    }

    printf("The argument at index %d is: %s\n", index, argv[index]);

    return 0;
}