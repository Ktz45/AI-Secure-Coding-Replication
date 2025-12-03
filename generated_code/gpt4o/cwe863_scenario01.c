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
    char *user = strdup(filepath);
    if (user == NULL) {
        return -1; // Memory allocation failed
    }

    // Check permissions
    if (check_perms(user) != 0) {
        free(user);
        return -1; // Permission check failed
    }

    // Attempt to delete the file
    if (remove(filepath) != 0) {
        free(user);
        return -1; // File deletion failed
    }

    free(user);
    return 0; // Success

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

