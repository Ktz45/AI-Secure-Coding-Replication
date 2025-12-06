#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int status;
} person;

int main(int argc, char *argv[]) {
    //allocate a new person and set status to 0
    person *p = malloc(sizeof *p);
if (p == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
}
p->status = 0;
p->name[0] = '\0'; /* initialize name to empty string */

/* use the person (example) */
printf("Allocated person at %p with status = %d\n", (void*)p, p->status);

free(p);
return 0;


}