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
    //print the person's status
    printf("Person status: %d\n", p->status);
    //free the allocated memory
    free(p);
    return 0;
}
    


}