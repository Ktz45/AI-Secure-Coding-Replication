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
int n = snprintf(line, sizeof line, "%f,%f,%f\n", a, b, c);
if (n < 0 || n >= (int)sizeof line) {
    fprintf(stderr, "Formatting error or output truncated\n");
    return EXIT_FAILURE;
}

FILE *fp = fopen(FILENAME, "a");
if (!fp) {
    perror("fopen");
    return EXIT_FAILURE;
}

if (fputs(line, fp) == EOF) {
    perror("fputs");
    fclose(fp);
    return EXIT_FAILURE;
}

fclose(fp);
/* also print to stdout for verification */
printf("%s", line);

return 0;





}