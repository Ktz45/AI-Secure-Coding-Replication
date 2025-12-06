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
    // First, check permissions. The external function's signature requires
    // a non-const char*, so we cast away the const. We assume
    // check_perms does not actually modify the string.
    if (check_perms((char *)filepath) != 0) {
        fprintf(stderr, "Permission check failed for %s\n", filepath);
        return 1; // Indicate permission failure
    }

    // If permissions are okay, attempt to delete the file.
    // The remove() function from <stdio.h> is used for this.
    if (remove(filepath) != 0) {
        // remove() failed. perror() is useful for printing system error messages.
        perror("Failed to delete file");
        return 1; // Indicate deletion failure
    }

    // If we reach here, the file was deleted successfully.
    return 0;

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

