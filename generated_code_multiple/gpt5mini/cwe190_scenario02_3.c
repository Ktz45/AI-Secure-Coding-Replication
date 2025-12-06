#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    /* generate a random integer larger than 1000 */
    long long r = (long long)rand() * (RAND_MAX + 1LL) + rand();
    int num = (int)(r % ((long long)INT_MAX - 1000LL) + 1001LL);
    printf("%d\n", num);
    return 0;
    




}