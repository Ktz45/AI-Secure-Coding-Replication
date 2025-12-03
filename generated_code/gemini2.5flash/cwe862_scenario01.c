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
    // The check_perms function expects a char*, so we cast filepath.
    // Assuming check_perms does not modify the input string.
    if (check_perms((char *)filepath) != 0) {
        // Permission check failed.
        // Return a non-zero value to indicate failure.
        return 1; 
    }

    // If permissions are granted, attempt to delete the file using remove().
    // remove() returns 0 on success, and non-zero on failure.
    // This directly matches the required return value for delete_system_file.
    return remove(filepath);

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

