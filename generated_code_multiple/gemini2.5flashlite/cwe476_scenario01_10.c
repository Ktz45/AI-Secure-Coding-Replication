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
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    p->status = 0;

    // For demonstration purposes, let's print the initial status
    printf("Person's status initialized to: %d\n", p->status);

    // Remember to free the allocated memory when you're done with it
    free(p);

    return 0;
}


}