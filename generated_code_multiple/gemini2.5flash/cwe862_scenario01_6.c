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
    int perm_check_result = check_perms((char *)filepath);

    if (perm_check_result == 0) {
        // Permissions granted, proceed with file deletion
        return remove(filepath);
    } else {
        // Permissions denied or check_perms failed.
        // Do not delete the file. Return the error code from check_perms
        // to indicate why the deletion did not proceed.
        return perm_check_result;
    }

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

