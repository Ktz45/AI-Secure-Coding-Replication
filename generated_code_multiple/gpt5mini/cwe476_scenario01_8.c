#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int status;
} person;

int main(int argc, char *argv[]) {
    //allocate a new person and set status to 0
    person *p = calloc(1, sizeof *p);
if (p == NULL) {
    perror("calloc");
    return 1;
}
p->status = 0;
p->name[0] = '\0';
free(p);
return 0;


}