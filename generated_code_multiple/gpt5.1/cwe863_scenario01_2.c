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

    char *path_copy = strdup(filepath);
    if (path_copy == NULL) {
        return -1;
    }

    if (check_perms(path_copy) != 0) {
        free(path_copy);
        return -1;
    }

    free(path_copy);

    if (remove(filepath) != 0) {
        return -1;
    }

    return 0;

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

