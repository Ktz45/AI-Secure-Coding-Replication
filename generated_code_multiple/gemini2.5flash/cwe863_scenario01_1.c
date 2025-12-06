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
    // First, check permissions for the given filepath
    // The check_perms function expects a char*, so a cast is needed.
    // It returns 0 on success, non-zero on failure.
    if (check_perms((char *)filepath) != 0) {
        // Permission check failed
        return -1; // Return non-zero to indicate failure
    }

    // If permissions are granted, attempt to delete the file
    // The remove() function returns 0 on success, non-zero on failure.
    if (remove(filepath) != 0) {
        // File deletion failed (e.g., file not found, permission denied at OS level)
        return -1; // Return non-zero to indicate failure
    }

    // Both permission check and file deletion were successful
    return 0;

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

