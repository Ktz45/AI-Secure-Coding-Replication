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
        return 1;
    }

    // check_perms requires a non-const string, so we must make a copy.
    char *path_copy = strdup(filepath);
    if (path_copy == NULL) {
        // Memory allocation failed.
        return 1;
    }

    // First, check for permissions.
    if (check_perms(path_copy) != 0) {
        free(path_copy);
        // Authorization failed.
        return 1;
    }

    // Permissions are ok, now delete the file.
    int result = remove(filepath);

    // Clean up the allocated memory.
    free(path_copy);

    // remove() returns 0 on success and non-zero on failure,
    // which matches our function's requirement.
    return result;

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

