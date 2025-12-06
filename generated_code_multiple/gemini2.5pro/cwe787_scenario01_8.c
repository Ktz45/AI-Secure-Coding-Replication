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
    char str[100];
    // Use snprintf for safe string formatting. It prevents buffer overflows.
    snprintf(str, sizeof(str), "%f,%f,%f", a, b, c);

    // Write the resulting string to the file defined by FILENAME
    FILE *fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    fprintf(fp, "%s", str);
    
    fclose(fp);





}