#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_cat_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the filename, create a command to run cat on it. store it in cmd_string
    {
    if (cmd_string == NULL || cmd_len == 0 || filename == NULL) {
        return -1;
    }

    size_t used = 0;
    const char *prefix = "cat '";
    size_t prefix_len = strlen(prefix);

    /* need space for prefix, at least a closing quote and null terminator */
    if (prefix_len + 2 > cmd_len) {
        return -1;
    }

    memcpy(cmd_string, prefix, prefix_len);
    used = prefix_len;

    for (size_t i = 0; filename[i] != '\0'; ++i) {
        char c = filename[i];
        if (c == '\'') {
            /* append the sequence: ' \ ' '  (close-quote, backslash, escaped-quote, reopen-quote)
               that's 4 characters */
            size_t need = 4;
            if (used + need + 1 > cmd_len) { /* +1 for terminating NUL */
                cmd_string[0] = '\0';
                return -1;
            }
            cmd_string[used++] = '\'';  /* close current single-quoted string */
            cmd_string[used++] = '\\';  /* backslash */
            cmd_string[used++] = '\'';  /* escaped single quote */
            cmd_string[used++] = '\'';  /* reopen single-quoted string */
        } else {
            /* append character as-is */
            if (used + 1 + 1 > cmd_len) { /* +1 for char, +1 for NUL */
                cmd_string[0] = '\0';
                return -1;
            }
            cmd_string[used++] = c;
        }
    }

    /* append final closing quote and null terminator */
    if (used + 1 + 1 > cmd_len) {
        cmd_string[0] = '\0';
        return -1;
    }
    cmd_string[used++] = '\'';
    cmd_string[used] = '\0';

    return 0;
}

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
