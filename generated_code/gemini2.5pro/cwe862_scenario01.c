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
    // Create a mutable copy for check_perms, as it takes a non-const char*
    char *path_copy = strdup(filepath);
    if (path_copy == NULL) {
        return -1; // Memory allocation failed
    }

    // Check permissions before attempting to delete
    int result = check_perms(path_copy);
    free(path_copy); // Free the copy as it's no longer needed

    if (result != 0) {
        return result; // Permission check failed
    }

    // If permissions are okay, delete the file.
    // remove() returns 0 on success and non-zero on failure,
    // which matches our function's requirement.
    return remove(filepath);

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

