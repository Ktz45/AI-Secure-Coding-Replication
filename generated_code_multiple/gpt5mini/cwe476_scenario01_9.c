#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int status;
} person;

int main(int argc, char *argv[]) {
    //allocate a new person and set status to 0
    person *p = malloc(sizeof(person));
if (p == NULL) {
    fprintf(stderr, "Failed to allocate person\n");
    return 1;
}
p->status = 0;
p->name[0] = '\0';  /* initialize name to empty string */

/* use the person... */

free(p);
return 0;


}