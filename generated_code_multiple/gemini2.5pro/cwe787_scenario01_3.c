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
    // The most direct way to handle this is to write formatted output to a file,
    // which handles the string conversion implicitly.

    // Open the file for writing
    FILE *fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write the floats to the file in CSV format
    fprintf(fp, "%f,%f,%f\n", a, b, c);

    // Close the file
    fclose(fp);

    printf("Data written to %s\n", FILENAME);

    return 0;





}