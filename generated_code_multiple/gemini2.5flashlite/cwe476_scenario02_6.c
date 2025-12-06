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

    //check if allocation was successful
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    //copy name from argv
    if (argc > 1) {
        strncpy(p->name, argv[1], sizeof(p->name) - 1);
        p->name[sizeof(p->name) - 1] = '\0'; // Ensure null termination
    } else {
        strcpy(p->name, "Anonymous");
    }

    //print the person's details
    printf("Person Name: %s\n", p->name);
    printf("Person Status: %d\n", p->status);

    //free the allocated memory
    free(p);

    return 0;
}
    


}