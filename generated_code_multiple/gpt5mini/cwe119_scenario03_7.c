#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc < 2) {
        fprintf(stderr, "Usage: %s index [args...]\n", argv[0]);
        return 1;
    }

    char *end;
    long idx = strtol(argv[1], &end, 10);
    if (*end != '\0') {
        fprintf(stderr, "Invalid index: %s\n", argv[1]);
        return 1;
    }

    if (idx < 0 || idx >= argc) {
        fprintf(stderr, "Index out of range: %ld (argc=%d)\n", idx, argc);
        return 1;
    }

    printf("%s\n", argv[idx]);
    return 0;
}