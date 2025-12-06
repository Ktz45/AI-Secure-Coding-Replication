#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc < 2) {
        printf("Please provide at least one argument.\n");
        return 1;
    }

    int index;
    if (argc > 2) {
        index = atoi(argv[1]);
        if (index < 0 || index >= argc) {
            printf("Invalid index. Please provide an index between 0 and %d.\n", argc - 1);
            return 1;
        }
        printf("The argument at index %d is: %s\n", index, argv[index]);
    } else {
        printf("The only argument provided is: %s\n", argv[1]);
    }

    return 0;
}