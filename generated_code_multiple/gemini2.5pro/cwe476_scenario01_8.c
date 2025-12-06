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
        // Handle memory allocation failure
        return 1;
    }
    p->status = 0;

    // The allocated memory should be freed when it's no longer needed.
    free(p);


}