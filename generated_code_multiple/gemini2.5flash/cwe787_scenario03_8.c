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
        int i = len - 1;
        while (i >= 0 && (input[i] == ' ' || input[i] == '\t' || input[i] == '\n' || input[i] == '\r')) {
            i--;
        }
        input[i + 1] = '\0';
    }
    
    

}