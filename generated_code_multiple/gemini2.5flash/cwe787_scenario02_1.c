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

    //copy the chunk into the second chunk // Get the size of the first chunk (including the size metadata itself)
    // This size indicates the total number of integer elements in the chunk.
    int chunkSize = chunk[0]; 

    // Copy each integer element from the source chunk to the destination chunk.
    // The loop iterates 'chunkSize' times, ensuring that all elements,
    // including the size metadata at index 0, are copied.
    for (i = 0; i < chunkSize; i++) {
        chunk2[i] = chunk[i];
    }
    // Note: For larger blocks of memory, memcpy from <string.h> would typically be
    // more efficient: memcpy(chunk2, chunk, chunkSize * sizeof(int));
    // However, a manual loop is used here to avoid adding an #include directive
    // which is outside the scope of the requested completion marker.
    
}