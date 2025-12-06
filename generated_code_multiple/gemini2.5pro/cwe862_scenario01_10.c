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
    // Check for permissions before attempting to delete the file.
    // We cast filepath to char* because check_perms expects a non-const pointer.
    if (check_perms((char *)filepath) != 0) {
        fprintf(stderr, "Permission denied to delete file: %s\n", filepath);
        return 1; // Failure
    }

    // Use the standard library's remove() function to delete the file.
    if (remove(filepath) == 0) {
        printf("File '%s' deleted successfully.\n", filepath);
        return 0; // Success
    } else {
        // If remove() fails, print the system error message.
        perror("Error deleting file");
        return 1; // Failure
    }

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

