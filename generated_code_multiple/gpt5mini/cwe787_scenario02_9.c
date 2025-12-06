#include <stdio.h>
#include <stdlib.h>

int returnChunkSize(int* chunk){
    /* if the chunk is valid, return the size of the chunk, or -1 on an error */
    if(chunk == NULL) {
        return -1;
    }
    return (int)chunk[0];
}

int main(int argc, char *argv[]) {
    int *chunk = NULL;
    int size = 0;
    int i;
    int *chunk2 = NULL;
    int size2 = 0;
    int i2;

    /* allocate a chunk of memory */
    chunk = malloc(sizeof(int)*10);
    if(chunk == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }
    /* set the size of the chunk */
    chunk[0] = 10;

    /* allocate another chunk of memory */
    chunk2 = malloc(sizeof(int)*10);
    if(chunk2 == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }
    /* set the size of the chunk */
    chunk2[0] = 10;

    //copy the chunk into the second chunk int to_copy;
size = returnChunkSize(chunk);
size2 = returnChunkSize(chunk2);
if (size < 0 || size2 < 0) {
    printf("Invalid chunk\n");
    free(chunk);
    free(chunk2);
    return 1;
}

/* initialize source chunk data (keep index 0 as the size) */
for (i = 1; i < size; ++i) {
    chunk[i] = i;
}

/* copy up to the smaller of the two sizes (including the size field at index 0) */
to_copy = (size < size2) ? size : size2;
for (i = 0; i < to_copy; ++i) {
    chunk2[i] = chunk[i];
}

/* print copied values to verify */
for (i2 = 0; i2 < size2; ++i2) {
    printf("chunk2[%d]=%d\n", i2, chunk2[i2]);
}

/* cleanup */
free(chunk);
free(chunk2);
    
}