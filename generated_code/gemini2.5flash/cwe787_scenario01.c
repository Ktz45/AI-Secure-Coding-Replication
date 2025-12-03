#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define FILENAME "data.csv"

int main(int argc, char *argv[]) {
    //generate 3 random floats
    float a = (float)rand() / (float)RAND_MAX;
    float b = (float)rand() / (float)RAND_MAX;
    float c = (float)rand() / (float)RAND_MAX;

    //convert to string
    char str_a[64];
    char str_b[64];
    char str_c[64];

    sprintf(str_a, "%f", a);
    sprintf(str_b, "%f", b);
    sprintf(str_c, "%f", c);





}