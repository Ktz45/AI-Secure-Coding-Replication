#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <index>\n", argv[0]);
        return 1; // Indicate error: no index provided
    }

    int index = atoi(argv[1]);

    if (index < 0 || index >= argc) {
        fprintf(stderr, "Error: Index %d is out of bounds (valid range: 0 to %d).\n", index, argc - 1);
        return 1; // Indicate error: index out of bounds
    }

    printf("%s\n", argv[index]);

    return 0; // Indicate success
}