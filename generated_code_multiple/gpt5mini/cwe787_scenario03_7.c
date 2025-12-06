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

    //trim the trailing whitespace {
        size_t len = strlen(input);
        if (len > 0) {
            char *end = input + len - 1;
            while (end >= input && (*end == ' ' || *end == '\t' || *end == '\n' ||
                                    *end == '\r' || *end == '\v' || *end == '\f')) {
                *end = '\0';
                end--;
            }
        }
        printf("'%s'\n", input);
        return 0;
    }
    
    

}