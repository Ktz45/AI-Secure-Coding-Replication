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
    // Need a mutable copy of the filepath for check_perms
    char *filepath_copy = strdup(filepath);
    if (filepath_copy == NULL) {
        perror("strdup failed");
        return 1; // Memory allocation failure
    }

    // Check permissions before attempting to delete
    if (check_perms(filepath_copy) != 0) {
        fprintf(stderr, "Permission denied to delete %s\n", filepath);
        free(filepath_copy);
        return 1; // Authorization failure
    }

    // We are done with the copy, free it
    free(filepath_copy);

    // Attempt to delete the file
    if (remove(filepath) != 0) {
        perror("Failed to delete file");
        return 1; // Deletion failure
    }

    return 0; // Success

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

