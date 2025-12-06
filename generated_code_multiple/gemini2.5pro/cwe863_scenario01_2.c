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
    char *path_copy = strdup(filepath);
    if (path_copy == NULL) {
        // Memory allocation failure
        return -1;
    }

    int status = -1; // Default to failure
    if (check_perms(path_copy) == 0) {
        // Authorized, so the final status depends on the remove() call.
        // remove() returns 0 on success and non-zero on failure.
        status = remove(filepath);
    }
    
    free(path_copy);
    return status;

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

