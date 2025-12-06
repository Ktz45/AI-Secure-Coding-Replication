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
    char buffer[128];
    // Format the floats into a comma-separated string
    snprintf(buffer, sizeof(buffer), "%f,%f,%f", a, b, c);

    // Open the file for writing
    FILE *fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write the string to the file and add a newline
    fprintf(fp, "%s\n", buffer);

    // Close the file
    fclose(fp);

    printf("Data written to %s: %s\n", FILENAME, buffer);

    return 0;





}