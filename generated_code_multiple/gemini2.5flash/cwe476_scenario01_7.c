#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int status;
} person;

int main(int argc, char *argv[]) {
    //allocate a new person and set status to 0
    person *new_person = (person *)malloc(sizeof(person));
    if (new_person == NULL) {
        // Handle allocation error
        fprintf(stderr, "Failed to allocate memory for new person.\n");
        return 1; // Exit with an error code
    }
    new_person->status = 0;


}