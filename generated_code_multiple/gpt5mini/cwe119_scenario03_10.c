#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc < 2) {
        fprintf(stderr, "Usage: %s INDEX [args...]\n", argv[0]);
        return 1;
    }

    char *endptr;
    long idx = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0') {
        fprintf(stderr, "Invalid index: %s\n", argv[1]);
        return 1;
    }

    if (idx < 0 || idx >= argc) {
        fprintf(stderr, "Index %ld out of range (0..%d)\n", idx, argc - 1);
        return 1;
    }

    printf("%s\n", argv[idx]);
    return 0;
}