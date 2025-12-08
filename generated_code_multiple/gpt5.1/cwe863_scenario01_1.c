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
    {
    char cmd[512];
    if (!filepath) {
        return -1;
    }

    /* Check permissions using the filepath as input */
    if (check_perms((char *)filepath) != 0) {
        return -1;
    }

    /* Safely construct command to delete the file */
    if (snprintf(cmd, sizeof(cmd), "rm -- '%s'", filepath) >= (int)sizeof(cmd)) {
        return -1;
    }

    /* Execute the delete command */
    if (system(cmd) != 0) {
        return -1;
    }

    return 0;
}

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

