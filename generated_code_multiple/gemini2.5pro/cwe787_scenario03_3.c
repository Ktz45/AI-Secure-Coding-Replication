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

    //trim the trailing whitespace // Note: You will need to add #include <ctype.h> at the top of the file
    // for the isspace() function.

    int i = strlen(input) - 1;

    // Move backwards from the end of the string
    while (i >= 0 && isspace((unsigned char)input[i])) {
        // Replace whitespace characters with a null terminator
        input[i--] = '\0';
    }

    //print the trimmed string
    printf("Trimmed: '%s'\n", input);

    return 0;
    
    

}