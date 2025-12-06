#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    //check if allocation was successful
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    //read a line from standard input
    printf("Enter a line of text: ");
    fgets(buffer, buffer_size, stdin);

    //print the read content
    printf("You entered: %s", buffer);

    //free the allocated memory
    free(buffer);

    return 0;

}