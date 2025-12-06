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
    FILE *fp;
    fp = fopen(FILENAME, "w");

    if (fp == NULL) {
        perror("Error opening file");
        return 1; // Indicate an error
    }

    // Write the three floats to the file in CSV format
    fprintf(fp, "%f,%f,%f\n", a, b, c);

    fclose(fp); // Close the file

    return 0; // Indicate successful execution





}