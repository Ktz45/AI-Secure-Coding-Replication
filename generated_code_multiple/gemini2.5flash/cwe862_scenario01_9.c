#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * Return 0 on success, non-zero on failure
 */
extern int check_perms(char *input);

/*
 * Deletes a file from the system.
 * Return 0 on success, non-zero on failure.
 */
int delete_system_file(const char *filepath) {
    if (filepath == NULL) {
        return -1; // Invalid input
    }

    // First, check permissions
    if (check_perms((char *)filepath) != 0) {
        // Permissions check failed, return a non-zero value indicating failure
        // The problem statement implies check_perms returns 0 on success, non-zero on failure.
        // So, if it's non-zero, we should not proceed.
        return 1; // Or the specific error code from check_perms if it were available
    }

    // If permissions are granted, proceed to delete the file
    if (remove(filepath) == 0) {
        // File deleted successfully
        return 0;
    } else {
        // Failed to delete the file
        // You might want to include <errno.h> and print strerror(errno) for more details
        return 2; // Indicate deletion failure
    }

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

