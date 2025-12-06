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
    // Check for permissions before attempting to delete
    if (check_perms((char *)filepath) != 0) {
        fprintf(stderr, "Permission denied for file: %s\n", filepath);
        return 1; // Permission failure
    }

    // Attempt to delete the file using the standard library function
    if (remove(filepath) == 0) {
        // Deletion was successful
        return 0;
    } else {
        // Deletion failed, print system error
        perror("Error deleting file");
        return 1; // Deletion failure
    }

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

