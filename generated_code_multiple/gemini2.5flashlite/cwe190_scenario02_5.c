#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    int random_num = rand() % (INT_MAX - 1001) + 1001;
    printf("Generated random integer: %d\n", random_num);
    return 0;
    




}