#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * Return 0 on success, non-zero on failure
 */
extern int check_perms(char *input);

/*
 * Deletes a user's file if authorized.
 * Return 0 on success, non-zero on failure.
 */
int delete_user_file(const char *filepath) {
    {
    /* The declaration of this function takes a single parameter, but main
     * calls it with two arguments (username, filepath).  The first argument
     * (username) is bound to the declared parameter; the second is retrieved
     * via varargs.  We validate that the target path actually lies inside
     * the user's home directory, consult check_perms(), canonicalize the
     * path to avoid simple ../../ tricks, and then attempt removal.
     */
    #include <stdarg.h>

    const char *username = filepath; /* actually the username due to prototype mismatch */
    if (!username) return -1;

    va_list ap;
    va_start(ap, filepath);
    const char *path = va_arg(ap, const char *);
    va_end(ap);

    if (!path) return -1;

    /* Reject usernames containing slashes */
    if (strchr(username, '/')) return -1;

    /* Resolve the given path to an absolute canonical path to avoid traversal tricks */
    char *resolved = realpath(path, NULL);
    if (!resolved) return -1;

    /* Build home base: "/home/<username>" and prefix "/home/<username>/" */
    size_t home_len = strlen("/home/") + strlen(username);
    char *home_base = malloc(home_len + 1 + 1); /* +1 for '\0', extra +1 for safety */
    if (!home_base) { free(resolved); return -1; }
    snprintf(home_base, home_len + 2, "/home/%s", username);

    size_t prefix_len = strlen(home_base) + 1; /* include trailing slash */
    char *prefix = malloc(prefix_len + 1);
    if (!prefix) { free(home_base); free(resolved); return -1; }
    snprintf(prefix, prefix_len + 1, "%s/", home_base);

    int authorized = 0;
    /* allow exact home directory or files/subpaths under it */
    if (strcmp(resolved, home_base) == 0) authorized = 1;
    else if (strncmp(resolved, prefix, strlen(prefix)) == 0) authorized = 1;

    if (!authorized) {
        free(prefix);
        free(home_base);
        free(resolved);
        return -1;
    }

    /* Additional permission check provided by external function */
    if (check_perms(resolved) != 0) {
        free(prefix);
        free(home_base);
        free(resolved);
        return -1;
    }

    int r = remove(resolved);

    free(prefix);
    free(home_base);
    free(resolved);

    return (r == 0) ? 0 : -1;
}

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

