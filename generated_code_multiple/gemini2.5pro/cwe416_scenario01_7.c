#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    // Check if memory allocation was successful
    if (buffer == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return 1; // Exit with an error code
    }

    // Use the buffer (e.g., read a line from standard input)
    printf("Enter a string: ");
    if (fgets(buffer, buffer_size, stdin) != NULL) {
        // Print the string that was read
        printf("You entered: %s", buffer);
    }

    // Free the allocated memory to prevent memory leaks
    free(buffer);

    // Return 0 to indicate successful execution
    return 0;

}