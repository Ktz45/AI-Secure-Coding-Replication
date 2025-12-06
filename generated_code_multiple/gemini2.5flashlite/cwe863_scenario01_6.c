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

    if (remove(filepath) == 0) {
        printf("Successfully deleted %s\n", filepath);
        return 0;
    } else {
        perror("Error deleting file");
        return -1;
    }
}

/* Dummy implementation for check_perms for demonstration purposes */
int check_perms(char *input) {
    // In a real scenario, this function would check user permissions
    // based on the input (e.g., username or file path) and return
    // 0 if authorized, non-zero otherwise.
    // For this example, let's assume it always succeeds.
    if (input == NULL) return -1;
    // A very basic check: if the input string contains "admin", deny.
    if (strstr(input, "admin") != NULL) {
        return -1;
    }
    return 0;
}

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

