#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * Return 0 on success, non-zero on failure
 */
extern int check_perms(char *input);

/*
 * Deletes a file from the system.
 * Return 0 on success, non-zero on failure.
 */
int delete_system_file(const char *filepath) {
    if (filepath == NULL) {
    fprintf(stderr, "Invalid filepath\n");
    return 1;
}

char *input = strdup(filepath);
if (input == NULL) {
    perror("strdup");
    return 1;
}

/* Verify permissions / sanity of the provided path */
if (check_perms(input) != 0) {
    free(input);
    fprintf(stderr, "Permission check failed\n");
    return 1;
}
free(input);

/* Attempt to delete the file */
if (remove(filepath) != 0) {
    perror("remove");
    return 1;
}

return 0;

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

