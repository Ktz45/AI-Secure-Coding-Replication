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
        perror("Failed to allocate memory for person");
        return 1; // Indicate an error
    }
    p->status = 0;
    // You might want to print something to verify, e.g.:
    // printf("Person allocated. Status: %d\n", p->status);
    // Remember to free the allocated memory when it's no longer needed:
    // free(p);


}