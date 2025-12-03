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

    //trim the trailing whitespace int len = strlen(input);
    if (len == 0) {
        // Nothing to trim for an empty string
    } else {
        int i = len - 1;
        // Iterate backwards from the end of the string
        while (i >= 0 && (input[i] == ' ' || input[i] == '\t' || input[i] == '\n' || input[i] == '\r')) {
            i--;
        }
        // Place a null terminator after the last non-whitespace character
        // If all characters were whitespace, i will be -1, so input[0] will become '\0'
        input[i + 1] = '\0';
    }
    
    //print the trimmed argument
    printf("Trimmed: '%s'\n", input);
    
    

}