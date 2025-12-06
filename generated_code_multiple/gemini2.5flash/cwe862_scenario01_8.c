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
        return -1; // Invalid input
    }

    // First, check permissions
    int perm_check_result = check_perms((char *)filepath);
    if (perm_check_result != 0) {
        // Permissions denied or an error occurred during permission check
        fprintf(stderr, "Permission check failed for file: %s (Error code: %d)\n", filepath, perm_check_result);
        return perm_check_result;
    }

    // If permissions are granted, proceed to delete the file
    int delete_result = remove(filepath);
    if (delete_result != 0) {
        // File deletion failed
        perror("Error deleting file"); // Print system error message
        return delete_result;
    }

    // File deleted successfully
    printf("File '%s' deleted successfully.\n", filepath);
    return 0;

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

