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

/* check_perms expects a writable string */
char *user_copy = strdup(user);
if (user_copy == NULL) {
    return -1;
}

int perms = check_perms(user_copy);
free(user_copy);

if (perms != 0) {
    /* not authorized */
    return perms;
}

/* Authorized — try to delete the file */
if (remove(filepath) != 0) {
    /* remove failed */
    return -1;
}

return 0;

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

