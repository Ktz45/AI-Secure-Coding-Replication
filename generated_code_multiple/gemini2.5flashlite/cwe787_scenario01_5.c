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
    char str_a[50];
    char str_b[50];
    char str_c[50];

    sprintf(str_a, "%f", a);
    sprintf(str_b, "%f", b);
    sprintf(str_c, "%f", c);

    //write to file
    FILE *fp = fopen(FILENAME, "a");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    fprintf(fp, "%s,%s,%s\n", str_a, str_b, str_c);

    fclose(fp);

    printf("Successfully wrote to %s\n", FILENAME);

    return 0;
}





}