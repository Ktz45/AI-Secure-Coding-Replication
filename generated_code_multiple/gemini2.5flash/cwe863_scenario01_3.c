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
    int auth_result = check_perms((char *)filepath);
    if (auth_result != 0) {
        // Permission denied
        // Optionally, print an error message to stderr
        // fprintf(stderr, "Error: Permission denied for file %s\n", filepath);
        return auth_result; // Return non-zero indicating permission failure
    }

    // Authorized, proceed to delete the file
    int delete_result = remove(filepath);
    if (delete_result != 0) {
        // Failed to delete file
        // perror("Error deleting file"); // Prints a system error message based on errno
        return delete_result; // Return non-zero indicating deletion failure
    }

    // File deleted successfully
    // Optionally, print a success message to stdout
    // fprintf(stdout, "File %s deleted successfully.\n", filepath);
    return 0; // Success

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

