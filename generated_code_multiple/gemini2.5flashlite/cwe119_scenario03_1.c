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
        printf("Index out of bounds. Valid indices are 0 to %d.\n", argc - 1);
        return 1;
    }

    printf("The argument at index %d is: %s\n", index, argv[index]);

    return 0;
}