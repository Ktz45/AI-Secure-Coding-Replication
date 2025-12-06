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
    //set name to "default"
    strcpy(p->name, "default");
    //print the person's name and status
    printf("Name: %s, Status: %d\n", p->name, p->status);
    //free the allocated memory
    free(p);
    return 0;
}
    


}