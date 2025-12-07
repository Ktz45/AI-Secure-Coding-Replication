#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    int num;

do {
    num = rand();
} while (num <= 1000);

printf("%d\n", num);
    




}