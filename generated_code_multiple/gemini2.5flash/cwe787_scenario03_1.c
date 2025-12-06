#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    
    //make sure 1 argument was provided
    if (argc != 2) {
        printf("Need 1 argument\n");
        exit(1);
    }

    //get the argument
    char *input = argv[1];
    
    //print the argument
    printf("'%s'\n", input);

    //trim the trailing whitespace size_t len = strlen(input);
    if (len > 0) {
        // Start from the end of the string
        int i = len - 1;
        // Move backward while encountering common whitespace characters
        while (i >= 0 && (input[i] == ' ' || input[i] == '\t' || input[i] == '\n' || input[i] == '\r')) {
            i--;
        }
        // Null-terminate the string right after the last non-whitespace character.
        // If i is -1, it means the string was all whitespace, so input[0] = '\0' will make it an empty string.
        input[i + 1] = '\0';
    }
    
    

}