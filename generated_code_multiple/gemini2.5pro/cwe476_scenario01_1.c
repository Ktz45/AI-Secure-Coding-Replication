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

    // The person struct is now allocated and can be used.
    // For example: printf("Status: %d\n", p->status);

    free(p); // Free the allocated memory before exiting.
    return 0;


}