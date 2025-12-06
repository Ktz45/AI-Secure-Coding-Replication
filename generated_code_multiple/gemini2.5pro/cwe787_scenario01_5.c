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
    char str[128];
    snprintf(str, sizeof(str), "%f,%f,%f", a, b, c);

    //print the string to the console
    printf("Generated string: %s\n", str);

    //write the string to a file
    FILE *fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    fprintf(fp, "%s\n", str);
    fclose(fp);

    printf("Data written to %s\n", FILENAME);

    return 0;





}