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
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Indicate an error
    }
    newPerson->status = 0;
    // No need to free newPerson here as the program is about to end.
    // The main function will implicitly return 0 if it reaches the end.


}