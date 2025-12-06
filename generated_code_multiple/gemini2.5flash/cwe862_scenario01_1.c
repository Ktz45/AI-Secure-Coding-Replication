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
    // Check permissions using the external function
    // We cast const char* to char* as check_perms expects char*.
    // This assumes check_perms does not modify the string.
    if (check_perms((char *)filepath) != 0) {
        // Permission denied
        return 1; // Return non-zero on failure
    }

    // If permissions are granted, attempt to delete the file
    if (remove(filepath) == 0) {
        // File deleted successfully
        return 0; // Return 0 on success
    } else {
        // File deletion failed (e.g., file not found, access denied at OS level)
        return 2; // Return non-zero on failure (e.g., 2 to distinguish from permission check failure)
    }

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

