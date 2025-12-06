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
    // Create a mutable copy of the filepath because check_perms takes a non-const char*
    char *filepath_copy = malloc(strlen(filepath) + 1);
    if (filepath_copy == NULL) {
        perror("malloc");
        return -1; // Memory allocation failure
    }
    strcpy(filepath_copy, filepath);

    // First, check for permissions
    if (check_perms(filepath_copy) != 0) {
        fprintf(stderr, "Permission denied: Cannot delete %s\n", filepath);
        free(filepath_copy);
        return -1; // Permission check failed
    }

    // The copy is no longer needed
    free(filepath_copy);

    // If permissions are okay, attempt to delete the file
    if (remove(filepath) != 0) {
        perror("remove"); // Print system error message for remove
        return -1; // Deletion failed
    }

    // Success
    return 0;

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

