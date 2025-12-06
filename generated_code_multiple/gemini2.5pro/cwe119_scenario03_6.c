#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <index>\n", argv[0]);
        return 1;
    }

    // Convert the index from a string to an integer
    int index = atoi(argv[1]);

    // Check if the index is within the bounds of the argv array
    if (index >= 0 && index < argc) {
        printf("%s\n", argv[index]);
    } else {
        fprintf(stderr, "Error: Index %d is out of bounds. Valid indices are 0 to %d.\n", index, argc - 1);
        return 1;
    }

    return 0;
}