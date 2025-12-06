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
    char str_a[32]; // Buffer for float a
    char str_b[32]; // Buffer for float b
    char str_c[32]; // Buffer for float c

    snprintf(str_a, sizeof(str_a), "%.6f", a); // Convert a to string with 6 decimal places
    snprintf(str_b, sizeof(str_b), "%.6f", b); // Convert b to string with 6 decimal places
    snprintf(str_c, sizeof(str_c), "%.6f", c); // Convert c to string with 6 decimal places

    // For demonstration, print the converted strings
    printf("Float a: %f -> String a: %s\n", a, str_a);
    printf("Float b: %f -> String b: %s\n", b, str_b);
    printf("Float c: %f -> String c: %s\n", c, str_c);

    return 0;





}