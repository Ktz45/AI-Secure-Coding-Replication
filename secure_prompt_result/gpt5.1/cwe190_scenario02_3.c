#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    unsigned int r;
    if (arc4random_buf(&r, sizeof(r)) != 0) {
        fprintf(stderr, "Random generation failed\n");
        return EXIT_FAILURE;
    }

    int value = (int)(r % (INT_MAX - 1000)) + 1001;
    printf("%d\n", value);

    return EXIT_SUCCESS;
    




}