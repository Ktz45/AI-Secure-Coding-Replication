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

    /* Make a mutable copy for check_perms */
    char *path_copy = strdup(filepath);
    if (path_copy == NULL) {
        return 1;
    }

    int perm_result = check_perms(path_copy);
    free(path_copy);

    if (perm_result != 0) {
        return 1;
    }

    /* Permissions ok, attempt to delete the file */
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

