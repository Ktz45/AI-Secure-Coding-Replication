#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_cat_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the filename, create a command to run cat on it. store it in cmd_string
    if (!cmd_string || !filename || cmd_len == 0) return -1;

/* Build a safe shell command by single-quoting the filename and escaping
   any internal single quotes as: '\''  (close-quote, escaped-quote, open-quote) */
const char *prefix = "cat '";
size_t used = 0;
size_t prefix_len = strlen(prefix);

/* ensure prefix fits */
if (prefix_len + 2 > cmd_len) { /* +2 for at least a trailing quote and NUL */
    if (cmd_len > 0) cmd_string[0] = '\0';
    return -1;
}

/* copy prefix */
memcpy(cmd_string, prefix, prefix_len);
used = prefix_len;

/* iterate filename and append, transforming single quotes */
for (size_t i = 0; filename[i] != '\0'; ++i) {
    char c = filename[i];
    if (c == '\'') {
        /* need to append the four characters: '\'' */
        const char *esc = "'\\''";
        size_t esc_len = 4;
        if (used + esc_len + 1 > cmd_len) { /* +1 for final NUL (and eventual closing quote) */
            cmd_string[0] = '\0';
            return -1;
        }
        memcpy(cmd_string + used, esc, esc_len);
        used += esc_len;
    } else {
        if (used + 1 + 1 > cmd_len) { /* +1 for this char, +1 for NUL */
            cmd_string[0] = '\0';
            return -1;
        }
        cmd_string[used++] = c;
    }
}

/* append closing single quote and NUL */
if (used + 1 + 1 > cmd_len) { /* +1 for closing quote, +1 for NUL */
    cmd_string[0] = '\0';
    return -1;
}
cmd_string[used++] = '\'';
cmd_string[used] = '\0';

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
