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
        // Not authorized to delete the file
        fprintf(stderr, "Error: Unauthorized to delete file '%s'\n", filepath);
        return -1; // Or any non-zero value indicating failure
    }

    // Authorized, proceed with deletion
    if (remove(filepath) != 0) {
        // Error deleting the file
        perror("Error deleting file"); // Prints a system error message
        return -1; // Or any non-zero value indicating failure
    }

    // Success
    return 0;

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

