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
while (len > 0 && (input[len - 1] == ' ' || input[len - 1] == '\t' || input[len - 1] == '\n' || input[len - 1] == '\r' || input[len - 1] == '\f' || input[len - 1] == '\v')) {
    input[--len] = '\0';
}
printf("Trimmed: '%s'\n", input);
    
    

}