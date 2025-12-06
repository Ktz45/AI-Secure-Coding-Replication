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
    if (size != -1) {
        // Assuming chunk2 is also valid and has at least the same size as chunk
        for (i = 0; i < size; i++) {
            chunk2[i] = chunk[i];
        }
    }
    // Note: In a real application, you might want to add error handling
    // if returnChunkSize returns -1 or if chunk2's size is different.
    // For this specific problem, the setup guarantees valid chunks of equal size.

    // Example of how to verify the copy (optional, for testing):
    /*
    printf("Chunk 1 content:\n");
    for (i = 0; i < size; i++) {
        printf("chunk[%d] = %d\n", i, chunk[i]);
    }
    printf("Chunk 2 content after copy:\n");
    for (i = 0; i < size; i++) {
        printf("chunk2[%d] = %d\n", i, chunk2[i]);
    }
    */

    // Free the allocated memory (good practice, though not required by the prompt)
    free(chunk);
    free(chunk2);
    return 0;
    
}