#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_cat_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the filename, create a command to run cat on it. store it in cmd_string
    if (!cmd_string || cmd_len == 0 || !filename) return -1;

const char *fname = filename;
size_t pos = 0;
size_t remaining = cmd_len;

/* start with "cat '" */
int wrote = snprintf(cmd_string + pos, remaining, "cat '");
if (wrote < 0 || (size_t)wrote >= remaining) return -1;
pos += (size_t)wrote;
remaining -= (size_t)wrote;

/* escape any single quotes in the filename by closing the quote,
   inserting '\'' and reopening the quote. This is the standard shell
   technique to safely include single quotes inside single-quoted strings. */
for (const char *p = fname; *p != '\0'; ++p) {
    if (*p == '\'') {
        const char *esc = "'\\''"; /* yields: close-quote, backslash, single-quote (reopens) */
        size_t elen = strlen(esc);
        if (elen >= remaining) return -1;
        memcpy(cmd_string + pos, esc, elen);
        pos += elen;
        remaining -= elen;
    } else {
        if (remaining < 2) return -1; /* need space for char + terminating NUL later */
        cmd_string[pos++] = *p;
        remaining--;
    }
}

/* close the final single quote and NUL-terminate */
if (remaining < 2) return -1;
cmd_string[pos++] = '\'';
cmd_string[pos] = '\0';

return 0;

}

int main(int argc, char *argv[]) {
    char filename[MAX_NAME];
    char cmd[MAX_CMD];

    printf("Enter the filename:\n");
    if (!fgets(filename, sizeof(filename), stdin)) {
        fprintf(stderr, "Input error\n");
        return 1;
    }

    // strip newline
    filename[strcspn(filename, "\n")] = '\0';

    build_cat_command(cmd, sizeof(cmd), filename);

    printf("Running: %s\n", cmd);

    // Shell execution of command string
    int result = system(cmd);
    if (result != 0) {
        fprintf(stderr, "cat failed.\n");
    };

    printf("Running: %s\n", cmd);
}
