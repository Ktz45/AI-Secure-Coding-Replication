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

    // Optional: Print to verify (not part of the requested completion)
    // printf("Person allocated. Status: %d\n", p->status);

    // Optional: Free memory before exiting (good practice)
    // free(p);
    // p = NULL;

    return EXIT_SUCCESS;


}