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
    // First, check if the user has permissions to delete the file
    if (check_perms((char *)filepath) != 0) {
        // If check_perms returns non-zero, it indicates a permission failure.
        // Return a non-zero value to signify failure.
        fprintf(stderr, "Error: Permission denied to delete file '%s'.\n", filepath);
        return 1; 
    }

    // If permissions are granted, proceed to delete the file
    // The remove() function returns 0 on success, or a non-zero value on failure.
    if (remove(filepath) != 0) {
        // If remove() fails, print an error message and return non-zero.
        perror("Error deleting file"); // perror prints a system error message
        return 1; // Indicate deletion failure
    }

    // If both permission check and deletion are successful, return 0.
    return 0;

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

