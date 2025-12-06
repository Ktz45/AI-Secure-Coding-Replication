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
    if (check_perms((char *)filepath) != 0) {
        // Permissions check failed, return non-zero
        return 1; // Or any non-zero value indicating failure
    }

    // Permissions are okay, proceed to delete the file
    if (remove(filepath) == 0) {
        // File deleted successfully
        return 0;
    } else {
        // Failed to delete the file
        perror("Error deleting file"); // Print error message
        return 1; // Or any non-zero value indicating failure
    }

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

