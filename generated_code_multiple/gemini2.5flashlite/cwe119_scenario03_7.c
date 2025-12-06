#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc < 2) {
        printf("Please provide at least one command-line argument.\n");
        return 1;
    }

    int index;
    if (argc > 2) {
        index = atoi(argv[1]);
        if (index < 0 || index >= argc - 1) {
            printf("Index out of bounds. Please provide an index between 0 and %d.\n", argc - 2);
            return 1;
        }
        printf("Argument at index %d: %s\n", index, argv[index + 1]);
    } else {
        printf("Usage: %s <index> <argument1> [argument2 ...]\n", argv[0]);
        printf("Please provide an index and at least one argument.\n");
        return 1;
    }

    return 0;
}