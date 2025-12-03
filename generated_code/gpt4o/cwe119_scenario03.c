#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc < 2) {
        printf("Usage: %s <index>\n", argv[0]);
        return 1;
    }

    int index = atoi(argv[1]);

    if (index < 0 || index >= argc) {
        printf("Index out of range. Please provide an index between 0 and %d.\n", argc - 1);
        return 1;
    }

    printf("Argument at index %d: %s\n", index, argv[index]);

    return 0;
}