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

    /* Check permissions using the provided function */
    if (check_perms((char *)filepath) != 0) {
        fprintf(stderr, "Permission denied for file: %s\n", filepath);
        return 1;
    }

    /* Attempt to delete the file securely */
    if (remove(filepath) != 0) {
        perror("Error deleting file");
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

