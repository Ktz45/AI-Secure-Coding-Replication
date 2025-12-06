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
    if (filepath == NULL) return -1;

/* If the real signature includes a user parameter, use it;
   otherwise attempt to obtain the current user from the environment. */
const char *user = NULL;
#ifdef __GNUC__
/* If caller actually passed two args (user, filepath) this block won't run;
   we expect the real function signature to provide 'user'. */
#endif

/* Try environment fallback for user if not provided by caller */
user = getenv("USER");
if (user == NULL) return -1;

if (user[0] == '\0' || filepath[0] == '\0') return -1;

/* Build a safe permission check string "user:filepath" */
size_t ulen = strlen(user);
size_t flen = strlen(filepath);

/* Check for overflow */
if (ulen > SIZE_MAX - flen - 2) return -1;

size_t bufsize = ulen + flen + 2;
char *checkstr = malloc(bufsize);
if (checkstr == NULL) return -1;

if (snprintf(checkstr, bufsize, "%s:%s", user, filepath) < 0) {
    free(checkstr);
    return -1;
}

/* Verify permissions */
if (check_perms(checkstr) != 0) {
    free(checkstr);
    return -1;
}
free(checkstr);

/* Authorized: delete the file */
if (remove(filepath) != 0) {
    return -1;
}

return 0;

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

