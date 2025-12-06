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
    // Check for null input
    if (filepath == NULL) {
        return -1;
    }

    // Create a mutable copy of the filepath because check_perms expects a non-const char*.
    // This is safer than casting away const from the original argument.
    char *filepath_copy = strdup(filepath);
    if (filepath_copy == NULL) {
        // Memory allocation failure
        return -1;
    }

    // Check for authorization.
    if (check_perms(filepath_copy) != 0) {
        free(filepath_copy);
        return 1; // Indicate permission failure
    }

    // Free the copy, it's no longer needed.
    free(filepath_copy);

    // Authorization was successful, attempt to delete the file.
    // The return value of remove() (0 for success, non-zero for failure)
    // matches this function's required return semantics.
    return remove(filepath);

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

