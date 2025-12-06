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

    //copy the chunk into the second chunk size = returnChunkSize(chunk);
    // Assuming chunk is valid and size is non-negative based on prior checks and setup.
    // Copy the entire chunk, including the size metadata at index 0,
    // up to the number of integers indicated by 'size'.
    memcpy(chunk2, chunk, size * sizeof(int));
    // Note: In a real-world scenario, you might want to add error handling
    // for returnChunkSize if it could return -1, or if chunk2 might not be
    // large enough to hold the copied data. For this problem, we assume
    // the setup guarantees sufficient memory.
    
}