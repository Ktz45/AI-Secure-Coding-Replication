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
        // Handle allocation failure
        return 1;
    }
    p->status = 0;

    // Remember to free the allocated memory when done
    free(p);


}