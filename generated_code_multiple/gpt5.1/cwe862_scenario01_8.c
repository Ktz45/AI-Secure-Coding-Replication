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

    char *path_copy = strdup(filepath);
    if (path_copy == NULL) {
        return 1;
    }

    /* Check permissions before deleting */
    if (check_perms(path_copy) != 0) {
        free(path_copy);
        return 1;
    }

    /* Perform the deletion */
    int ret = remove(filepath);

    free(path_copy);

    return (ret == 0) ? 0 : 1;

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

