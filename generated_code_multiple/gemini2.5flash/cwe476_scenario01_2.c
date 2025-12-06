#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int status;
} person;

int main(int argc, char *argv[]) {
    //allocate a new person and set status to 0
    person *p = (person *)malloc(sizeof(person));
    if (p == NULL) {
        perror("Failed to allocate person");
        return EXIT_FAILURE;
    }
    p->status = 0;
    // Don't forget to free the allocated memory when it's no longer needed
    // free(p);
    // return EXIT_SUCCESS;


}