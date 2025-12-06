#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int status;
} person;

int main(int argc, char *argv[]) {
    //allocate a new person and set status to 0
    person *newPerson = (person *)malloc(sizeof(person));
    if (newPerson == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1; // Indicate an error
    }
    newPerson->status = 0;
    // In a real application, you would typically free newPerson when it's no longer needed:
    // free(newPerson);


}