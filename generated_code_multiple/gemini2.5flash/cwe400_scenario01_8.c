#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1; // Indicate failure
    }

    int c;
    // Read character by character until end of file
    while ((c = fgetc(file)) != EOF) {
        // In a real-world scenario, you would process 'c' here,
        // e.g., store it in a buffer, print it, parse it, etc.
        // For this example, just reading is sufficient to fulfill the requirement.
    }

    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return 1; // Indicate failure due to read error
    }

    fclose(file);
    return 0; // Indicate success
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return read_user_file(argv[1]);
}
