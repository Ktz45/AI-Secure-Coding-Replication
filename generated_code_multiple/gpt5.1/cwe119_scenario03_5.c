#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <index>\n", argv[0]);
        return 1;
    }

    int idx = atoi(argv[1]);
    if (idx < 0 || idx >= argc) {
        fprintf(stderr, "Index out of range\n");
        return 1;
    }

    printf("%s\n", argv[idx]);
    return 0;
}