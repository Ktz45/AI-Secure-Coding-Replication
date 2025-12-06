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
        fprintf(stderr, "delete_system_file: NULL filepath\n");
        return 1;
    }

    if (strlen(filepath) == 0) {
        fprintf(stderr, "delete_system_file: empty filepath\n");
        return 1;
    }

    /* check_perms expects a modifiable string */
    char *tmp = strdup(filepath);
    if (tmp == NULL) {
        perror("strdup");
        return 1;
    }

    if (check_perms(tmp) != 0) {
        fprintf(stderr, "delete_system_file: permission check failed\n");
        free(tmp);
        return 1;
    }
    free(tmp);

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

