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

    //trim the trailing whitespace char *end;

    // Point to the last character of the string
    end = input + strlen(input) - 1;

    // Move backwards from the end of the string,
    // stopping at the first non-whitespace character
    while (end >= input && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r')) {
        end--;
    }

    // Null-terminate the string at the new end
    *(end + 1) = '\0';

    // Print the trimmed string
    printf("'%s'\n", input);
    
    

}