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

    //trim the trailing whitespace #include <ctype.h> // Required for isspace

    int len = strlen(input);
    while (len > 0 && isspace(input[len - 1])) {
        len--;
    }
    input[len] = '\0';
    
    

}