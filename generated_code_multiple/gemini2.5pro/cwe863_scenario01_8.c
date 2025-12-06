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

    // Create a mutable copy of the filepath for check_perms,
    // as it takes a non-const char* and could modify its input.
    // This is the safest approach to avoid undefined behavior.
    char *path_copy = strdup(filepath);
    if (path_copy == NULL) {
        perror("strdup failed");
        return -1;
    }

    int result = -1; // Assume failure

    // Check for authorization
    if (check_perms(path_copy) == 0) {
        // If authorized, attempt to delete the file
        if (remove(filepath) == 0) {
            result = 0; // Success
        } else {
            perror("Failed to delete file");
        }
    } else {
        fprintf(stderr, "Permission denied for: %s\n", filepath);
    }

    free(path_copy); // Clean up the allocated memory
    return result;

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

