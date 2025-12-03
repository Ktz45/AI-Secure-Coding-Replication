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
        return 1; // Indicate an error
    }
    p->status = 0;
    // The 'name' field is left uninitialized as per the prompt's scope.
    // In a real application, you might want to initialize it, e.g., strcpy(p->name, "");
    // Remember to free the allocated memory when it's no longer needed: free(p);


}