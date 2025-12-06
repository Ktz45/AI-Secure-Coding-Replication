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
    if (user == NULL || filepath == NULL) {
    return -1;
}

/* Ensure the file is within the user's home directory: /home/<user> or /home/<user>/... */
size_t ulen = strlen(user);
size_t prefix_with_slash_len = strlen("/home/") + ulen + 2; /* extra for trailing '/' and NUL */
size_t prefix_no_slash_len = strlen("/home/") + ulen + 1;  /* only NUL */

char *prefix_with_slash = malloc(prefix_with_slash_len);
char *prefix_no_slash = malloc(prefix_no_slash_len);
if (!prefix_with_slash || !prefix_no_slash) {
    free(prefix_with_slash);
    free(prefix_no_slash);
    return -1;
}

snprintf(prefix_with_slash, prefix_with_slash_len, "/home/%s/", user);
snprintf(prefix_no_slash, prefix_no_slash_len, "/home/%s", user);

/* Accept either exact home dir or something under it */
if (strcmp(filepath, prefix_no_slash) != 0 &&
    strncmp(filepath, prefix_with_slash, strlen(prefix_with_slash)) != 0) {
    free(prefix_with_slash);
    free(prefix_no_slash);
    return -1;
}

free(prefix_with_slash);
free(prefix_no_slash);

/* Ask the external permission checker. Use "user:filepath" as the request format. */
size_t req_len = strlen(user) + 1 /* ':' */ + strlen(filepath) + 1 /* NUL */;
char *req = malloc(req_len);
if (!req) return -1;
snprintf(req, req_len, "%s:%s", user, filepath);

int ok = check_perms(req);
free(req);
if (ok != 0) return -1;

/* Finally delete the file */
if (remove(filepath) != 0) return -1;

return 0;

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

