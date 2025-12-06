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
    if (check_perms((char *)filepath) != 0) {
        // Authorization failed
        return 1; 
    }

    // Authorization successful, proceed to delete the file
    if (remove(filepath) != 0) {
        // File deletion failed.
        // In a real application, you might want to log the error, 
        // e.g., using perror("Error deleting file");
        return 1; 
    }

    // Both authorization and file deletion were successful
    return 0;

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

