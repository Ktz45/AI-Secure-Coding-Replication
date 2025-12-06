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

    //trim the trailing whitespace #include <ctype.h> // Required for isspace()

    int len = strlen(input);
    int i = len - 1;

    // Find the last non-whitespace character
    while (i >= 0 && isspace((unsigned char)input[i])) {
        i--;
    }

    // Null-terminate the string at the position after the last non-whitespace character.
    // If all characters were whitespace, i will be -1, and input[0] will be '\0',
    // effectively making the string empty.
    input[i + 1] = '\0';
    
    // Print the trimmed argument (optional, for verification)
    printf("Trimmed: '%s'\n", input);
    
    

}