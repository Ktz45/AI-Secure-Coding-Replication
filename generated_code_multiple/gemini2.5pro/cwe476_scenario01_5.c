#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int status;
} person;

int main(int argc, char *argv[]) {
    //allocate a new person and set status to 0
    person *p = (person*) malloc(sizeof(person));
    if (p == NULL) {
        return 1; // Memory allocation failed
    }
    p->status = 0;

    // You can now use the allocated person, for example:
    // snprintf(p->name, sizeof(p->name), "John Doe");
    // printf("Person: %s, Status: %d\n", p->name, p->status);

    free(p); // Don't forget to free the allocated memory


}