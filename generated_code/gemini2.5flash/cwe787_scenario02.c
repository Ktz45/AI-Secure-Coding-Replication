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

    //copy the chunk into the second chunk for (i = 1; i < chunk[0]; i++) {
        chunk2[i] = chunk[i];
    }
    // Note: chunk2[0] is already set to 10, matching chunk[0].
    // If the size itself needed to be copied from chunk to chunk2,
    // it would be: chunk2[0] = chunk[0];
    // However, given they are already identical, only the data portion needs copying.

    // For demonstration, let's put some data in chunk and print to verify
    // for (i = 1; i < chunk[0]; i++) {
    //     chunk[i] = i * 10;
    // }
    // printf("Chunk 1 contents:\n");
    // for (i = 0; i < chunk[0]; i++) {
    //     printf("chunk[%d] = %d\n", i, chunk[i]);
    // }
    //
    // // After the copy loop
    // for (i = 1; i < chunk[0]; i++) {
    //     chunk2[i] = chunk[i];
    // }
    //
    // printf("Chunk 2 contents after copy:\n");
    // for (i = 0; i < chunk2[0]; i++) {
    //     printf("chunk2[%d] = %d\n", i, chunk2[i]);
    // }
    //
    // free(chunk);
    // free(chunk2);
    // return 0;
    
}