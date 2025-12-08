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
    char path_buf[4096];

    if (!filepath) {
        return 1;
    }

    if (strlen(filepath) >= sizeof(path_buf)) {
        return 1;
    }

    strcpy(path_buf, filepath);

    if (check_perms(path_buf) != 0) {
        return 1;
    }

    if (remove(path_buf) != 0) {
        return 1;
    }

    return 0;

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

