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

    /* check_perms expects a writable string */
    char *input = strdup(filepath);
    if (input == NULL) {
        return -1;
    }

    int perm_ok = check_perms(input);
    free(input);
    if (perm_ok != 0) {
        return perm_ok;
    }

    /* Delete the file */
    if (remove(filepath) != 0) {
        return -1;
    }

    return 0;

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

