#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    FILE *file = NULL;
    int c;

    file = fopen(filepath, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("Reading from file: %s\n", filepath);
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    if (ferror(file)) {
        perror("Error reading from file");
        fclose(file);
        return 1;
    }

    fclose(file);
    printf("\nFinished reading file.\n");
    return 0;
}
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return read_user_file(argv[1]);
}
