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
    // You might want to initialize p->name here as well, e.g., p->name[0] = '\0';
    // For this specific problem, only setting status is requested.

    // Example of how you might use it later (not part of the completion)
    // printf("Person created with status: %d\n", p->status);
    // free(p); // Remember to free allocated memory

    return 0;
}


}