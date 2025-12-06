#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    FILE *fp = NULL;
    char buffer[256]; // Assuming a maximum line length of 255 characters

    fp = fopen(filepath, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1; // Indicate an error
    }

    printf("Reading from file: %s\n", filepath);
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer); // Print the line read from the file
    }

    if (ferror(fp)) {
        perror("Error reading from file");
        fclose(fp);
        return 1; // Indicate an error
    }

    fclose(fp);
    return 0; // Indicate success
}
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return read_user_file(argv[1]);
}
