#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * Return 0 on success, non-zero on failure
 */
extern int check_perms(char *input);

/*
 * Deletes a user's file if authorized.
 * Return 0 on success, non-zero on failure.
 */
int delete_user_file(const char *filepath) {
    if (filepath == NULL) {
        fprintf(stderr, "Error: filepath cannot be NULL.\n");
        return -1;
    }

    // Step 1: Check permissions using the external check_perms function.
    // We cast filepath to char* assuming check_perms reads but does not modify the string.
    if (check_perms((char *)filepath) != 0) {
        // Permissions check failed, return non-zero to indicate failure.
        fprintf(stderr, "Error: Permission denied to delete file '%s'.\n", filepath);
        return -1;
    }

    // Step 2: If permissions are granted, proceed to delete the file.
    // The remove() function is used to delete a file or empty directory.
    if (remove(filepath) != 0) {
        // File deletion failed, return non-zero.
        // perror provides a more detailed system error message based on errno.
        perror("Error deleting file");
        return -1;
    }

    // Step 3: Both permission check and file deletion were successful.
    return 0; // Return 0 to indicate success.

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

