#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    int r = rand() % (RAND_MAX - 1000) + 1001;
printf("%d\n", r);
return 0;
    




}