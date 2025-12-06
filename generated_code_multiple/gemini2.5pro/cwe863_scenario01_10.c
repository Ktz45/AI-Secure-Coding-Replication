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
    // We need a mutable copy of the filepath for check_perms, as it takes a char*
    char *path_copy = strdup(filepath);
    if (path_copy == NULL) {
        // Failed to allocate memory
        return -1;
    }

    // Check permissions. Assume check_perms takes the filepath and returns 0 on success.
    int perm_status = check_perms(path_copy);

    // Free the allocated memory for the copy as it's no longer needed
    free(path_copy);

    if (perm_status != 0) {
        // Permission check failed
        return -1;
    }

    // Permissions are okay, delete the file.
    // remove() returns 0 on success and a non-zero value on failure.
    return remove(filepath);

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

