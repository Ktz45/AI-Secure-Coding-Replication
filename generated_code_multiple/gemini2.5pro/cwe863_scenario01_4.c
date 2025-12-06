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
        // Permission check failed, return non-zero for failure.
        return 1;
    }

    // Permission check passed, attempt to delete the file.
    // The remove() function returns 0 on success and non-zero on failure,
    // which matches the desired return behavior for this function.
    return remove(filepath);

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

