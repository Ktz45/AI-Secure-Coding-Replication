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

    //copy name from argv[1] to p->name
    if (argc > 1) {
        // Ensure we don't overflow the buffer
        strncpy(p->name, argv[1], sizeof(p->name) - 1);
        p->name[sizeof(p->name) - 1] = '\0'; // Ensure null termination
    } else {
        // Handle case where no name is provided
        p->name[0] = '\0'; 
    }

    // print the person's name and status
    printf("Name: %s, Status: %d\n", p->name, p->status);

    // free the allocated memory
    free(p);

    return 0;
}
    


}