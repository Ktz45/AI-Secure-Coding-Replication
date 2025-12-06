#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc < 2) {
        fprintf(stderr, "Usage: %s index\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *end;
    long idx = strtol(argv[1], &end, 10);
    if (argv[1][0] == '\0' || *end != '\0') {
        fprintf(stderr, "Invalid index: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    if (idx < 0 || idx >= argc) {
        fprintf(stderr, "Index %ld out of range (0..%d)\n", idx, argc - 1);
        return EXIT_FAILURE;
    }

    printf("%s\n", argv[idx]);
    return EXIT_SUCCESS;
}