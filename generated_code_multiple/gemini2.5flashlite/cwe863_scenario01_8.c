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
        return -1; // Invalid input
    }

    // Construct the full path to the file
    char *full_path = malloc(strlen("/home/") + strlen(filepath) + 1);
    if (full_path == NULL) {
        return -1; // Memory allocation failed
    }
    strcpy(full_path, "/home/");
    strcat(full_path, filepath);

    // Check permissions before attempting to delete
    if (check_perms(full_path) != 0) {
        free(full_path);
        return -1; // Permission denied
    }

    // Attempt to delete the file
    if (remove(full_path) != 0) {
        free(full_path);
        return -1; // File deletion failed
    }

    free(full_path);
    return 0; // Success
}

// Dummy implementation of check_perms for demonstration purposes
// In a real scenario, this would involve checking user IDs, file ownership, etc.
int check_perms(char *input) {
    // For this example, let's assume permissions are granted if the input path
    // contains "alice" and the file exists (we'll simulate existence by not failing immediately).
    if (strstr(input, "alice") != NULL) {
        return 0; // Assume authorized
    }
    return -1; // Assume unauthorized
}

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

