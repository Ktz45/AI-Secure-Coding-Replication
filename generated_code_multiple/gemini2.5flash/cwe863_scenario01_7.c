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
    // First, check if the user has permissions to delete the file.
    // We cast 'filepath' to 'char *' because 'check_perms' expects a mutable pointer.
    // This assumes 'check_perms' does not modify the input string.
    // If 'check_perms' were to modify the string, a mutable copy (e.g., using strdup)
    // would be required to avoid undefined behavior with a const string literal.
    if (check_perms((char *)filepath) != 0) {
        // Permissions check failed. Return a non-zero value.
        return 1; 
    }

    // If permissions are granted, proceed to delete the file.
    // The 'remove' function deletes a file given its path.
    // It returns 0 on success, and a non-zero value on failure (setting errno).
    if (remove(filepath) != 0) {
        // File deletion failed.
        // perror can be used to print a system-specific error message to stderr.
        perror("Error deleting file");
        // Return a non-zero value to indicate failure.
        return -1; 
    }

    // If both permission check and file deletion were successful, return 0.
    return 0;

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

