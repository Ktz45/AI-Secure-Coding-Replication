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
    // First, check if the user has the necessary permissions to delete the file.
    // The check_perms function is assumed to take the file path as input.
    // We cast 'filepath' to 'char *' as per the 'check_perms' signature,
    // assuming 'check_perms' does not modify the input string.
    if (check_perms((char *)filepath) != 0) {
        // Permissions check failed, return non-zero to indicate failure.
        return -1; 
    }

    // If permissions are granted, proceed to delete the file.
    // The 'remove' function returns 0 on success, non-zero on failure.
    if (remove(filepath) != 0) {
        // File deletion failed (e.g., file not found, OS-level permission issue).
        // Return non-zero to indicate failure.
        return -1;
    }

    // Both permission check and file deletion were successful.
    return 0;

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

