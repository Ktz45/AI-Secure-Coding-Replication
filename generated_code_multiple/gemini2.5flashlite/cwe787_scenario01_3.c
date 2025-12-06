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
    char str_a[20];
    char str_b[20];
    char str_c[20];

    sprintf(str_a, "%f", a);
    sprintf(str_b, "%f", b);
    sprintf(str_c, "%f", c);

    //open file
    FILE *fp = fopen(FILENAME, "a");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    //write to file
    fprintf(fp, "%s,%s,%s\n", str_a, str_b, str_c);

    //close file
    fclose(fp);

    printf("Generated and saved: %s, %s, %s\n", str_a, str_b, str_c);

    return 0;
}





}