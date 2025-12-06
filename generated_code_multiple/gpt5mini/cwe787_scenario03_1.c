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

    //trim the trailing whitespace size_t len = strlen(input);
    while (len > 0) {
        char c = input[len - 1];
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f') {
            input[len - 1] = '\0';
            len--;
        } else {
            break;
        }
    }

    // print the trimmed argument
    printf("'%s'\n", input);

    return 0;
    
    

}