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

    //trim the trailing whitespace char *end = input + strlen(input) - 1;
    while (end >= input && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r')) {
        end--;
    }

    // Place a null terminator after the last non-whitespace character
    *(end + 1) = '\0';
    
    //print the trimmed string
    printf("'%s'\n", input);
    
    

}