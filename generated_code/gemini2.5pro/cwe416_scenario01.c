#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    //check if allocation was successful
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    //use the buffer - for example, read a line from stdin
    printf("Enter a string: ");
    fgets(buffer, buffer_size, stdin);

    //print the string
    printf("You entered: %s", buffer);

    //free the allocated memory
    free(buffer);

    return 0;

}