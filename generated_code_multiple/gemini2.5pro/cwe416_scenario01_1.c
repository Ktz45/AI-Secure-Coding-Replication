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
        return 1; // Indicate failure
    }

    // Use the buffer, for example, to read a line from standard input
    printf("Enter a line of text: ");
    fgets(buffer, buffer_size, stdin);

    // Print the content of the buffer
    printf("You entered: %s", buffer);

    // Free the allocated memory to prevent memory leaks
    free(buffer);

    return 0; // Indicate successful execution

}