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
        return -1; // Invalid argument
    }

    // Check for authorization before attempting to delete.
    // We cast away 'const' because the external check_perms function
    // expects 'char *', assuming it does not modify the input string.
    if (check_perms((char *)filepath) != 0) {
        // Permission denied
        return -1;
    }

    // If authorized, attempt to delete the file.
    // The remove() function returns 0 on success and non-zero on failure,
    // which matches the required return convention.
    return remove(filepath);

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

