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
    if (p == NULL) {
    fprintf(stderr, "malloc failed\n");
    return 1;
}
p->status = 0;
p->name[0] = '\0';
printf("Created person with status=%d\n", p->status);
free(p);
return 0;
    


}