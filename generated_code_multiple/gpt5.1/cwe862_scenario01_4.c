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
        return 1;
    }

    /* Make a modifiable copy for permission check */
    char *path_copy = strdup(filepath);
    if (path_copy == NULL) {
        return 1;
    }

    /* Check permissions before deleting */
    if (check_perms(path_copy) != 0) {
        free(path_copy);
        return 1;
    }

    free(path_copy);

    /* Attempt to delete the file */
    if (remove(filepath) != 0) {
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

