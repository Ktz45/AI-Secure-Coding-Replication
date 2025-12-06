#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    FILE *file = NULL;
    char buffer[256]; // A buffer to read lines into
    const int BUFFER_SIZE = sizeof(buffer);

    // Open the file in read mode
    file = fopen(filepath, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file"); // Print a system-level error message
        return 1; // Return non-zero to indicate an error
    }

    printf("--- Content of '%s' ---\n", filepath);

    // Read the file line by line until EOF or an error occurs
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer); // Print each line to stdout
    }

    // Check if an error occurred during reading (other than EOF)
    if (ferror(file)) {
        perror("Error reading file");
        fclose(file); // Close the file before returning
        return 1; // Return non-zero to indicate an error
    }

    printf("--- End of file ---\n");

    // Close the file
    fclose(file);

    return 0; // Return 0 to indicate success
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return read_user_file(argv[1]);
}
