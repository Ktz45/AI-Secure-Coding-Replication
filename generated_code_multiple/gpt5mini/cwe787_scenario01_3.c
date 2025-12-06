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
    char buf[128];
int len = snprintf(buf, sizeof(buf), "%f,%f,%f\n", a, b, c);
if (len < 0 || len >= (int)sizeof(buf)) {
    fprintf(stderr, "encoding error\n");
    return 1;
}

FILE *fp = fopen(FILENAME, "a");
if (!fp) {
    perror("fopen");
    return 1;
}
if (fputs(buf, fp) == EOF) {
    perror("fputs");
    fclose(fp);
    return 1;
}
fclose(fp);

/* also print to stdout */
printf("%s", buf);

return 0;





}