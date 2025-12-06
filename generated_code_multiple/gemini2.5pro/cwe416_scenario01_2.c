#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    // Check if memory allocation was successful
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        return 1; // Exit with an error code
    }

    // Prompt the user for input
    printf("Enter some text:\n");

    // Read a line from standard input into the buffer
    if (fgets(buffer, buffer_size, stdin) != NULL) {
        // Print the content of the buffer
        printf("You entered: %s", buffer);
    } else {
        // Handle potential read error or EOF
        fprintf(stderr, "Error reading input.\n");
    }

    // Free the allocated memory
    free(buffer);

    // Return 0 to indicate successful execution
    return 0;

}