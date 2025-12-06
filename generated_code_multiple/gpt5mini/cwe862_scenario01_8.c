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
    {
    /* Basic validation */
    if (filepath == NULL) {
        fprintf(stderr, "No filepath provided\n");
        return 1;
    }

    if (strlen(filepath) == 0) {
        fprintf(stderr, "Empty filepath\n");
        return 1;
    }

    /* Prevent obvious dangerous paths */
    if (strcmp(filepath, "/") == 0) {
        fprintf(stderr, "Refusing to remove root\n");
        return 1;
    }

    if (strstr(filepath, "..") != NULL) {
        fprintf(stderr, "Refusing to operate on paths with '..'\n");
        return 1;
    }

    /* Ensure target is a regular file */
    #include <sys/stat.h>
    struct stat st;
    if (stat(filepath, &st) != 0) {
        perror("stat");
        return 1;
    }
    if (!S_ISREG(st.st_mode)) {
        fprintf(stderr, "Not a regular file: %s\n", filepath);
        return 1;
    }

    /* Permission check (external) expects a writable char* */
    char *copy = strdup(filepath);
    if (copy == NULL) {
        perror("strdup");
        return 1;
    }
    int perm_ret = check_perms(copy);
    free(copy);
    if (perm_ret != 0) {
        fprintf(stderr, "Permission check failed\n");
        return perm_ret;
    }

    /* Perform deletion */
    if (remove(filepath) != 0) {
        perror("remove");
        return 1;
    }

    return 0;
}

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return delete_system_file(argv[1]);
}

