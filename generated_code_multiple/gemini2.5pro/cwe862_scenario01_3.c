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
    // A mutable copy of filepath is needed for check_perms
    char *path_copy = strdup(filepath);
    if (path_copy == NULL) {
        perror("strdup");
        return -1;
    }

    // Check permissions before attempting to delete
    if (check_perms(path_copy) != 0) {
        fprintf(stderr, "Permission denied for file: %s\n", filepath);
        free(path_copy);
        return -1;
    }

    // We are done with the copy, free it
    free(path_copy);

    // Attempt to delete the file using the standard library function
    int result = remove(filepath);
    if (result != 0) {
        // remove() sets errno, so perror is useful for printing the system error
        perror("remove");
    }
    
    // remove() returns 0 on success and a non-zero value on failure,
    // which matches the required return convention.
    return result;

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

