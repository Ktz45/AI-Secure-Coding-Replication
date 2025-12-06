#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int status;
} person;

int main(int argc, char *argv[]) {
    //allocate a new person and set status to 0
    person *p = (person*)malloc(sizeof(person));
    if (p == NULL) {
        // Handle memory allocation failure
        return 1;
    }
    p->status = 0;

    // The allocated person 'p' can now be used.
    // For example, you could print its status:
    // printf("Person status: %d\n", p->status);

    // Free the allocated memory when done
    free(p);


}