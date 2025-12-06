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
    // Create a mutable copy of the filepath because check_perms might modify it.
    char *filepath_copy = strdup(filepath);
    if (filepath_copy == NULL) {
        perror("strdup");
        return 1; // Memory allocation failure
    }

    // First, check for permissions.
    if (check_perms(filepath_copy) != 0) {
        fprintf(stderr, "Permission denied to delete %s\n", filepath);
        free(filepath_copy);
        return 1; // Permission check failed
    }

    // Free the copy as it's no longer needed.
    free(filepath_copy);

    // If permissions are okay, attempt to delete the file.
    if (remove(filepath) == 0) {
        printf("File '%s' deleted successfully.\n", filepath);
        return 0; // Success
    } else {
        perror("Error deleting file");
        return 1; // Deletion failed
    }

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

