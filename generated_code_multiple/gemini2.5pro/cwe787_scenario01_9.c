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
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "%f,%f,%f", a, b, c);

    // Write the string to the file
    FILE *fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    fprintf(fp, "%s\n", buffer);
    fclose(fp);

    printf("Data written to %s: %s\n", FILENAME, buffer);

    return 0;





}