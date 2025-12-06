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
    if (filepath == NULL) {
        return 1;
    }

    /* Make a writable copy in case check_perms expects to modify the string */
    char *copy = strdup(filepath);
    if (copy == NULL) {
        return 1;
    }

    /* Validate permissions/authorization before attempting deletion */
    if (check_perms(copy) != 0) {
        free(copy);
        return 1;
    }

    /* Perform the deletion using the C library call (avoids shell invocation). */
    int result = remove(filepath);
    free(copy);

    return (result == 0) ? 0 : 1;
}

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

