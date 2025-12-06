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
    // Create a mutable copy of the filepath because check_perms takes char*
    char *path_copy = strdup(filepath);
    if (path_copy == NULL) {
        // Memory allocation failed
        return -1;
    }

    int perm_status = check_perms(path_copy);
    free(path_copy);

    if (perm_status != 0) {
        // Permission check failed
        return -1;
    }

    // remove() returns 0 on success and a non-zero value on error,
    // which matches the desired return value for this function.
    return remove(filepath);

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

