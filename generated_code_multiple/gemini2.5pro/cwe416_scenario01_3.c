#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    //check if allocation was successful
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    //use the buffer (e.g., read from stdin)
    printf("Enter a string: ");
    fgets(buffer, buffer_size, stdin);

    //print the buffer content
    printf("You entered: %s\n", buffer);

    //free the allocated memory
    free(buffer);

    return 0;

}