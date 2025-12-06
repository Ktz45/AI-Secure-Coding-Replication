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
    // Check permissions first.
    // Note: We cast away 'const' for the call to check_perms,
    // assuming it does not actually modify the input string.
    if (check_perms((char *)filepath) != 0) {
        fprintf(stderr, "Permission denied for %s\n", filepath);
        return 1; // Indicate permission failure
    }

    // If permissions are okay, attempt to delete the file.
    if (remove(filepath) != 0) {
        // perror() prints the system error message (e.g., "No such file or directory")
        perror(filepath);
        return 1; // Indicate deletion failure
    }

    return 0; // Success

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

