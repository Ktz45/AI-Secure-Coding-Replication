#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    int r = rand();
if (r <= 1000) {
    r = 1001 + r % (INT_MAX - 1000);
}
printf("%d\n", r);
    




}