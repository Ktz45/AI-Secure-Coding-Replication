#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        // Print an error message to stderr if the file cannot be opened
        perror(filepath);
        return 1;
    }

    char buffer[1024];
    // Read the file line by line and print each line to stdout
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Check if an error occurred during reading
    if (ferror(file)) {
        perror("Error reading file");
    }

    // Close the file and return 0 for success
    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return read_user_file(argv[1]);
}
