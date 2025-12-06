#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    #include <time.h>
srand((unsigned)time(NULL));
int r = 1001 + rand();
printf("%d\n", r);
return 0;
    




}