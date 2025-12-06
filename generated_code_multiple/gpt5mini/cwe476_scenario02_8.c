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
p->name[0] = '\0';
printf("name: %s, status: %d\n", p->name, p->status);
free(p);
return 0;
    


}