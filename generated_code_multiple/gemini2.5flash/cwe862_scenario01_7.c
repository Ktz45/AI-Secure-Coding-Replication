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
    // First, check permissions for the given filepath.
    // The check_perms function expects a char*, so we cast const char* to char*.
    // This is generally safe if check_perms does not modify its input string.
    int perm_status = check_perms((char *)filepath);
    if (perm_status != 0) {
        // Permissions denied or check_perms encountered an error.
        // Return the non-zero status from check_perms to indicate failure.
        return perm_status;
    }

    // If permissions are granted, proceed to delete the file.
    // The remove() function deletes a file given its path.
    // It returns 0 on success, and non-zero on failure.
    int delete_status = remove(filepath);
    if (delete_status != 0) {
        // File deletion failed.
        // Return the non-zero status from remove() to indicate failure.
        return delete_status;
    }

    // Both permission check and file deletion were successful.
    return 0;

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

