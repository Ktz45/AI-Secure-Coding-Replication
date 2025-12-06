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
        return 1; // Not authorized
    }
    if (remove(filepath) == 0) {
        return 0; // Success
    } else {
        return 1; // Failure
    }

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

