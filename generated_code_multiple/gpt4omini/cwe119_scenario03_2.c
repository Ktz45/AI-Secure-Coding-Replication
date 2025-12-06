#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    if (argc > 1) {
        int index = atoi(argv[1]);
        if (index >= 0 && index < argc) {
            printf("%s\n", argv[index]);
        } else {
            printf("Index out of bounds\n");
        }
    } else {
        printf("No index provided\n");
    }
}