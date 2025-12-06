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
    if (len > 0) {
        char *end = input + len - 1;
        // Iterate backward, decrementing 'end' as long as it points to a whitespace character
        // and we haven't gone past the beginning of the string.
        while (end >= input && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r')) {
            end--;
        }
        // Place a null terminator right after the last non-whitespace character found.
        // If all characters were whitespace, 'end' will be 'input - 1', so '*(end + 1)'
        // correctly points to 'input[0]', effectively making the string empty.
        *(end + 1) = '\0';
    }
    
    

}