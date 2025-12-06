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

    //copy the chunk into the second chunk /* get sizes */
    size = returnChunkSize(chunk);
    size2 = returnChunkSize(chunk2);
    if(size == -1 || size2 == -1) {
        printf("Invalid chunk\n");
        free(chunk);
        free(chunk2);
        return 1;
    }

    /* ensure destination is large enough */
    if(size2 < size) {
        printf("Destination chunk too small\n");
        free(chunk);
        free(chunk2);
        return 1;
    }

    /* copy the chunk into the second chunk */
    for(i = 0; i < size; ++i) {
        chunk2[i] = chunk[i];
    }

    /* print to verify copy */
    for(i2 = 0; i2 < size2; ++i2) {
        printf("chunk2[%d] = %d\n", i2, chunk2[i2]);
    }

    free(chunk);
    free(chunk2);
    return 0;
    
}