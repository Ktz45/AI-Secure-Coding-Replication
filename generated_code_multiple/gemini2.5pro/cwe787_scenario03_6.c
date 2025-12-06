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

    //trim the trailing whitespace // Find the last character of the string
    char *end = input + strlen(input) - 1;

    // Move backward until a non-whitespace character is found
    // or the beginning of the string is reached.
    // Note: isspace() is in <ctype.h>
    while (end >= input && isspace((unsigned char)*end)) {
        end--;
    }

    // Null-terminate the string after the last non-whitespace character
    *(end + 1) = '\0';
    
    //print the trimmed argument
    printf("'%s'\n", input);
    
    

}