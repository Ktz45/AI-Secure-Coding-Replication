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

    //trim the trailing whitespace // Note: You may need to add #include <ctype.h> at the top of the file for isspace()
    int end = strlen(input) - 1;
    while (end >= 0 && isspace((unsigned char)input[end])) {
        end--;
    }

    // Nul-terminate the string at the new end
    input[end + 1] = '\0';

    //print the trimmed argument
    printf("'%s'\n", input);
    
    

}