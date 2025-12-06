#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int status;
} person;

int main(int argc, char *argv[]) {
    //allocate a new person and set status to 0
    person *p = (person *)malloc(sizeof(person));

    // Check if malloc was successful
    if (p == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    p->status = 0;

    // The allocated memory should be freed when it is no longer needed
    // For this example, we free it before the program ends.
    free(p);


}