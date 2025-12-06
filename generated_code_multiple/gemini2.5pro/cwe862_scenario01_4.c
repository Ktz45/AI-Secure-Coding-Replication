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
    // Create a mutable copy of the filepath because check_perms expects char*
    char *filepath_copy = strdup(filepath);
    if (filepath_copy == NULL) {
        // Memory allocation failed
        return 1;
    }

    // Check permissions before attempting to delete
    if (check_perms(filepath_copy) != 0) {
        free(filepath_copy);
        // Permission check failed
        return 1;
    }

    // Free the copied string as it's no longer needed
    free(filepath_copy);

    // Attempt to delete the file and return the status
    return remove(filepath);

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

