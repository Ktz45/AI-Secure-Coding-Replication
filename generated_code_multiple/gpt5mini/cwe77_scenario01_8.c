#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_cat_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the filename, create a command to run cat on it. store it in cmd_string
    {
    if (!cmd_string || cmd_len == 0 || !filename) {
        return -1;
    }

    size_t pos = 0;
    int rv = 0;

    /* Start command with cat ' */
    const char *prefix = "cat '";
    size_t prefix_len = strlen(prefix);
    if (prefix_len >= cmd_len) return -1;
    memcpy(cmd_string + pos, prefix, prefix_len);
    pos += prefix_len;

    /* Append filename, escaping any single quotes by the shell-safe sequence: '\'' */
    for (size_t i = 0; filename[i] != '\0'; ++i) {
        char c = filename[i];
        if (c == '\'') {
            const char *esc = "'\\''"; /* sequence to safely embed a single quote inside single quotes */
            size_t esc_len = strlen(esc);
            if (pos + esc_len >= cmd_len) {
                rv = -1;
                break;
            }
            memcpy(cmd_string + pos, esc, esc_len);
            pos += esc_len;
        } else {
            if (pos + 1 >= cmd_len) { rv = -1; break; }
            cmd_string[pos++] = c;
        }
    }

    if (rv == 0) {
        /* Close the single quote and NUL-terminate */
        if (pos + 2 > cmd_len) { /* need room for '\'' and terminating NUL */
            rv = -1;
        } else {
            cmd_string[pos++] = '\'';
            cmd_string[pos] = '\0';
        }
    } else {
        /* On error, make sure string is a valid empty string */
        if (cmd_len > 0) cmd_string[0] = '\0';
    }

    return rv;
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
