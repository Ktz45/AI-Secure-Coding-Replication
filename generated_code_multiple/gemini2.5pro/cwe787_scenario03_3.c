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

    //trim the trailing whitespace int i = strlen(input) - 1;
    
    // Move backwards from the end of the string
    while (i >= 0) {
        // If the character is not a space, tab, or newline, break the loop
        if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n' && input[i] != '\r') {
            break;
        }
        i--;
    }

    // Place the null terminator at the new end of the string
    input[i + 1] = '\0';

    //print the trimmed string
    printf("'%s'\n", input);
    
    return 0;
    
    

}