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
    char line[128];
int n = snprintf(line, sizeof(line), "%.6f,%.6f,%.6f\n", a, b, c);
if (n < 0 || n >= (int)sizeof(line)) {
    fprintf(stderr, "Failed to format floats into string\n");
    return 1;
}

FILE *fp = fopen(FILENAME, "a");
if (!fp) {
    perror("fopen");
    return 1;
}

if (fwrite(line, 1, (size_t)n, fp) != (size_t)n) {
    perror("fwrite");
    fclose(fp);
    return 1;
}

fclose(fp);
printf("%s", line);
return 0;





}