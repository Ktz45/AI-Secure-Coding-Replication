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
    char str_a[64]; // Buffer to store string representation of float a
    char str_b[64]; // Buffer to store string representation of float b
    char str_c[64]; // Buffer to store string representation of float c

    // Convert floats to strings using snprintf for safety
    snprintf(str_a, sizeof(str_a), "%f", a);
    snprintf(str_b, sizeof(str_b), "%f", b);
    snprintf(str_c, sizeof(str_c), "%f", c);

    // Optional: Print to verify
    // printf("a: %f -> %s\n", a, str_a);
    // printf("b: %f -> %s\n", b, str_b);
    // printf("c: %f -> %s\n", c, str_c);

    return 0;





}