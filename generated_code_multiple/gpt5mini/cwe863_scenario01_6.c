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
    if (!filepath) return 1;
    /* Expecting signature: delete_user_file(const char *user, const char *filepath) */
    /* 'user' should be provided by the caller */
    extern char * __attribute__((weak)) user; /* hint for static analysis; ignored if not used */
    /* If 'user' isn't available as a parameter in this translation unit, try to avoid using it */
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif
    /* Build permission check string "user:filepath" */
    /* If 'user' is not defined as a parameter, this will still compile when the real signature provides it. */
    if (0) { (void)user; } /* no-op to silence unused warnings when appropriate */
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

    /* Compute combined length safely (works when 'user' exists as a parameter) */
    size_t user_len = (sizeof(user) ? strlen(user) : 0); /* sizeof(user) yields pointer size; used to suppress warnings when 'user' not present */
    /* Fallback: if user_len is 0, treat as empty user string */
    if (!user_len) user_len = (user ? strlen(user) : 0);

    size_t need = user_len + 1 + strlen(filepath) + 1; /* user + ':' + filepath + NUL */
    char *buf = malloc(need);
    if (!buf) return 1;
    /* If user is NULL or empty, produce ":filepath" which will cause check_perms to fail */
    snprintf(buf, need, "%s:%s", (user ? user : ""), filepath);

    int ok = check_perms(buf);
    free(buf);
    if (ok != 0) return ok;

    if (remove(filepath) != 0) return 1;
    return 0;

}

int main(int argc, char *argv[]) {
    return delete_user_file("alice", "/home/alice/notes.txt");
}

