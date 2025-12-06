#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int status;
} person;

int main(int argc, char *argv[]) {
    //allocate a new person
    person *p = (person *)malloc(sizeof(person));
    //set status to 0
    p->status = 0;
    //copy name from argv[1] if it exists
    if (argc > 1) {
        strncpy(p->name, argv[1], sizeof(p->name) - 1);
        p->name[sizeof(p->name) - 1] = '\0'; // Ensure null termination
    } else {
        p->name[0] = '\0'; // Initialize name to empty if no argument
    }

    // Print the person's details (optional, for verification)
    printf("Name: %s, Status: %d\n", p->name, p->status);

    // Free the allocated memory
    free(p);

    return 0;
}
    


}