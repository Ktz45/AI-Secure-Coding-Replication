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
/* convert floats to a CSV line */
snprintf(line, sizeof line, "%f,%f,%f\n", a, b, c);

/* append to file */
FILE *fp = fopen(FILENAME, "a");
if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
}
if (fputs(line, fp) == EOF) {
    perror("fputs");
    fclose(fp);
    return EXIT_FAILURE;
}
fclose(fp);

/* optionally show what was written */
printf("Wrote: %s", line);
return 0;





}