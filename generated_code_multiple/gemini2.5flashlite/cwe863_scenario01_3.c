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
        return 1; // Invalid input
    }

    // Check if the user has permission to delete the file
    if (check_perms((char *)filepath) != 0) {
        return 1; // Permission denied
    }

    // Attempt to delete the file
    if (remove(filepath) != 0) {
        perror("Error deleting file");
        return 1; // File deletion failed
    }

    return 0; // Success
}

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

