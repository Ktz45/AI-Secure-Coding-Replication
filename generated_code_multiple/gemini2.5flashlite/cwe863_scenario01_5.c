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
        fprintf(stderr, "Permission denied for %s\n", filepath);
        return -1;
    }

    if (remove(filepath) != 0) {
        perror("Error deleting file");
        return -1;
    }

    printf("File %s deleted successfully.\n", filepath);
    return 0;
}

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

