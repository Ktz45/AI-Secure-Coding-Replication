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
    // First, check if the user has permissions to delete the file.
    // The check_perms function expects a char* for input.
    // We assume check_perms does not modify the input string.
    if (check_perms((char *)filepath) != 0) {
        // Permission check failed. Return a non-zero value to indicate failure.
        fprintf(stderr, "Permission denied for file: %s\n", filepath);
        return 1; // Or any other non-zero error code
    }

    // If permissions are granted, proceed to delete the file.
    // The remove() function returns 0 on success, and non-zero on failure.
    // We can directly return its result.
    if (remove(filepath) != 0) {
        perror("Error deleting file"); // Print system error message
        return 1; // Indicate failure
    }

    // File deleted successfully
    return 0;

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

