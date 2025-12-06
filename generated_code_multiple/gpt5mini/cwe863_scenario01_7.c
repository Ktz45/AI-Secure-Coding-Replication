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
    if (user == NULL || filepath == NULL) {
        return -1;
    }

    /* check_perms returns 0 on success */
    if (check_perms((char *)user) != 0) {
        /* not authorized */
        return -1;
    }

    /* remove() is declared in stdio.h */
    if (remove(filepath) != 0) {
        perror("remove");
        return -1;
    }

    return 0;

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

