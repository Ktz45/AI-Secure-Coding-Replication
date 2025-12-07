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
    char *user = getenv("USER");
    if (user == NULL) {
        return 1;
    }

    /* Authorization: check if current user is allowed to delete this file */
    if (check_perms((char *)filepath) != 0) {
        return 1;
    }

    /* Attempt to delete the file */
    if (remove(filepath) != 0) {
        return 1;
    }

    return 0;

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

