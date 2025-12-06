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
    int perm_check_result = check_perms((char *)filepath);
    if (perm_check_result != 0) {
        // Permission check failed, return the error code from check_perms
        return perm_check_result;
    }

    // Permissions are granted, proceed to delete the file
    int delete_result = remove(filepath);
    if (delete_result != 0) {
        // File deletion failed, return the error code from remove
        // (Optional: You might want to add perror("Error deleting file"); here for debugging)
        return delete_result;
    }

    // Both permission check and file deletion were successful
    return 0;

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

