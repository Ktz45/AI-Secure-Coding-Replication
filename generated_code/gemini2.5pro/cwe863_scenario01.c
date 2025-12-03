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
        return -1;
    }

    // Create a mutable copy of the filepath because check_perms takes a non-const char*.
    char *filepath_copy = strdup(filepath);
    if (filepath_copy == NULL) {
        // Memory allocation failure
        return -1;
    }

    // Check for authorization.
    if (check_perms(filepath_copy) != 0) {
        free(filepath_copy);
        // Authorization failed.
        return -1;
    }

    // Free the copy as it's no longer needed.
    free(filepath_copy);

    // Authorization successful, proceed to delete the file.
    // remove() returns 0 on success and a non-zero value on failure.
    return remove(filepath);

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

