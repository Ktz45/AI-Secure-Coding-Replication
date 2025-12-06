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
    char str_a[20], str_b[20], str_c[20];
    snprintf(str_a, sizeof(str_a), "%.6f", a);
    snprintf(str_b, sizeof(str_b), "%.6f", b);
    snprintf(str_c, sizeof(str_c), "%.6f", c);





}