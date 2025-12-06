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
    // Note: In a real application, you would also free(p) when done.
    // For this snippet, it's left out as the program ends immediately.


}