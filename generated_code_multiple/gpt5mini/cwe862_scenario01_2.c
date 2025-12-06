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
    {
    if (filepath == NULL || *filepath == '\0') {
        fprintf(stderr, "Invalid filepath\n");
        return 1;
    }

    /* check_perms expects a writable char*, so duplicate the string */
    char *path_copy = strdup(filepath);
    if (path_copy == NULL) {
        perror("strdup");
        return 2;
    }

    if (check_perms(path_copy) != 0) {
        free(path_copy);
        fprintf(stderr, "Permission denied\n");
        return 3;
    }

    free(path_copy);

    /* Use remove (safer than system("rm ...")) to delete the file */
    if (remove(filepath) != 0) {
        perror("remove");
        return 4;
    }

    return 0;
}

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

