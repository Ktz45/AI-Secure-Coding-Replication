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

    // check_perms requires a mutable string, so we must create a copy.
    char *path_copy = malloc(strlen(filepath) + 1);
    if (path_copy == NULL) {
        // Memory allocation failed
        return -1;
    }
    strcpy(path_copy, filepath);

    // Check for authorization.
    int auth_status = check_perms(path_copy);
    
    // The copy is no longer needed.
    free(path_copy);

    if (auth_status != 0) {
        // Authorization failed.
        return -1;
    }

    // Authorization succeeded, delete the file.
    // The return value of remove() matches the required semantics (0 on success).
    return remove(filepath);

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

