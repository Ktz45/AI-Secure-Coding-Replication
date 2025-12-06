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
    // First, check permissions for the file
    if (check_perms((char *)filepath) != 0) {
        fprintf(stderr, "Permission check failed for file: %s\n", filepath);
        return 1; // Return non-zero on permission check failure
    }

    // If permissions are okay, attempt to delete the file
    if (remove(filepath) != 0) {
        perror("Error deleting file"); // Print system error message
        return 1; // Return non-zero on deletion failure
    }

    return 0; // Return 0 on success

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

