#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    #include <time.h>
time_t t;
int r;
t = time(NULL);
srand((unsigned)t);
do {
    r = rand();
} while (r <= 1000);
printf("%d\n", r);
return 0;
    




}